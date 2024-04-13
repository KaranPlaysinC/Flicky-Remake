#include <Windows.h>
#include <xaudio2.h>
#include <string>
#include <unordered_map>
#include "sound.h"

// MS chunk types
#define fourccRIFF 'FFIR'
#define fourccDATA 'atad'
#define fourccFMT ' tmf'
#define fourccWAVE 'EVAW'
#define fourccXWMA 'AMWX'
#define fourccDPDS 'sdpd'

// MS XAudio2 RIFF-parsing code
static HRESULT FindChunk(HANDLE hFile, DWORD fourcc, DWORD& dwChunkSize, DWORD& dwChunkDataPosition);
static HRESULT ReadChunkData(HANDLE hFile, void* buffer, DWORD buffersize, DWORD bufferoffset);
static HRESULT LoadChunkFile(const char* filename, WAVEFORMATEXTENSIBLE* wfx, XAUDIO2_BUFFER* buffer);
static HRESULT PlayAudio(IXAudio2* pXAudio2, WAVEFORMATEX* wfx, XAUDIO2_BUFFER* buffer);

class SoundSource {
public:
    std::string filename;
    WAVEFORMATEXTENSIBLE wfx = { 0 };
    XAUDIO2_BUFFER buffer = { 0 };
};

class SoundImpl {
public:
    SoundImpl(IXAudio2* pXAudio2, IXAudio2MasteringVoice* pMasterVoice) : pXAudio2(pXAudio2), pMasterVoice(pMasterVoice) {
        nextSound = 1;
    }

    int Load(const char* filename) {
        SoundSource sound;
        sound.filename = filename;

        HRESULT hr = LoadChunkFile(filename, &sound.wfx, &sound.buffer);
        if (FAILED(hr)) {
            return SOUND_NOSOUND;
        }

        mSounds[nextSound] = sound;

        return nextSound++;
    }

    void Unload(int soundId) {
        std::unordered_map<int, SoundSource>::iterator iter = mSounds.find(soundId);
        if (iter != mSounds.end()) {
            SoundSource& sound = (*iter).second;
            if (sound.buffer.pAudioData != nullptr) {
                delete[] sound.buffer.pAudioData;
                sound.buffer.pAudioData = nullptr;
            }
            mSounds.erase(iter);
        }
    }

    void Play(int soundId) {
        std::unordered_map<int, SoundSource>::iterator iter = mSounds.find(soundId);
        if (iter != mSounds.end()) {
            SoundSource& sound = (*iter).second;
            PlayAudio(pXAudio2, (WAVEFORMATEX*) &sound.wfx, &sound.buffer);
        }
    }

    IXAudio2* pXAudio2 = nullptr;
    IXAudio2MasteringVoice* pMasterVoice = nullptr;

private:
    std::unordered_map<int, SoundSource> mSounds;
    int nextSound;
};

SoundImpl* Sound::mInstance = NULL;

/**
 * @brief allocate sound system resources
 * @return 
*/
bool Sound::Init() {
    HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    if (FAILED(hr)) {
        return false;
    }

    IXAudio2* pXAudio2 = nullptr;
    hr = XAudio2Create(&pXAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR);
    if (FAILED(hr)) {
        return false;
    }

    IXAudio2MasteringVoice* pMasterVoice = nullptr;
    hr = pXAudio2->CreateMasteringVoice(&pMasterVoice);
    if (FAILED(hr)) {
        pXAudio2->Release();
        return false;
    }

    mInstance = new SoundImpl(pXAudio2, pMasterVoice);

    return true;
}

/**
 * @brief release sound system resources
 * @return 
*/
bool Sound::Shutdown() {
    mInstance->pXAudio2->Release();
    
    if (mInstance != NULL) {
        delete mInstance;
        mInstance = NULL;
    }

    return true;
}

/**
 * @brief Loads a clip from file into memory for playback
 * @param filename 
 * @return id which is a handle to the clip data
*/
int Sound::LoadSound(const char* filename) {
    return mInstance->Load(filename);
}

/**
 * @brief Releases resources associated w/ a loaded clip
 * @param soundId 
*/
void Sound::UnloadSound(int soundId) {
    mInstance->Unload(soundId);
}

/**
 * @brief Plays a clip loaded w/ LoadSound
 * @param soundId 
*/
void Sound::Playback(int soundId) {
    mInstance->Play(soundId);
}

/**
 * @brief FROM: https://learn.microsoft.com/en-us/windows/win32/xaudio2/how-to--load-audio-data-files-in-xaudio2
*/
static HRESULT FindChunk(HANDLE hFile, DWORD fourcc, DWORD& dwChunkSize, DWORD& dwChunkDataPosition)
{
    HRESULT hr = S_OK;
    if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN))
        return HRESULT_FROM_WIN32(GetLastError());

    DWORD dwChunkType;
    DWORD dwChunkDataSize;
    DWORD dwRIFFDataSize = 0;
    DWORD dwFileType;
    DWORD bytesRead = 0;
    DWORD dwOffset = 0;

    while (hr == S_OK)
    {
        DWORD dwRead;
        if (0 == ReadFile(hFile, &dwChunkType, sizeof(DWORD), &dwRead, NULL))
            hr = HRESULT_FROM_WIN32(GetLastError());

        if (0 == ReadFile(hFile, &dwChunkDataSize, sizeof(DWORD), &dwRead, NULL))
            hr = HRESULT_FROM_WIN32(GetLastError());

        switch (dwChunkType)
        {
        case fourccRIFF:
            dwRIFFDataSize = dwChunkDataSize;
            dwChunkDataSize = 4;
            if (0 == ReadFile(hFile, &dwFileType, sizeof(DWORD), &dwRead, NULL))
                hr = HRESULT_FROM_WIN32(GetLastError());
            break;

        default:
            if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, dwChunkDataSize, NULL, FILE_CURRENT))
                return HRESULT_FROM_WIN32(GetLastError());
        }

        dwOffset += sizeof(DWORD) * 2;

        if (dwChunkType == fourcc)
        {
            dwChunkSize = dwChunkDataSize;
            dwChunkDataPosition = dwOffset;
            return S_OK;
        }

        dwOffset += dwChunkDataSize;

        if (bytesRead >= dwRIFFDataSize) return S_FALSE;

    }

    return S_OK;

}

/**
 * @brief FROM: https://learn.microsoft.com/en-us/windows/win32/xaudio2/how-to--load-audio-data-files-in-xaudio2
*/
static HRESULT ReadChunkData(HANDLE hFile, void* buffer, DWORD buffersize, DWORD bufferoffset)
{
    HRESULT hr = S_OK;
    if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, bufferoffset, NULL, FILE_BEGIN))
        return HRESULT_FROM_WIN32(GetLastError());
    DWORD dwRead;
    if (0 == ReadFile(hFile, buffer, buffersize, &dwRead, NULL))
        hr = HRESULT_FROM_WIN32(GetLastError());
    return hr;
}

/**
 * @brief FROM: https://learn.microsoft.com/en-us/windows/win32/xaudio2/how-to--load-audio-data-files-in-xaudio2
*/
static HRESULT LoadChunkFile(const char* filename, WAVEFORMATEXTENSIBLE* wfx, XAUDIO2_BUFFER* buffer) {
    // Open the file
    HANDLE hFile = CreateFile(
        filename,
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        0,
        NULL);

    if (INVALID_HANDLE_VALUE == hFile) {
        return S_FALSE;
    }

    if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN)) {
        CloseHandle(hFile);
        return S_FALSE;
    }

    DWORD dwChunkSize;
    DWORD dwChunkPosition;
    //check the file type, should be fourccWAVE or 'XWMA'
    FindChunk(hFile, fourccRIFF, dwChunkSize, dwChunkPosition);
    DWORD filetype;
    ReadChunkData(hFile, &filetype, sizeof(DWORD), dwChunkPosition);
    if (filetype != fourccWAVE) {
        CloseHandle(hFile);
        return S_FALSE;
    }

    FindChunk(hFile, fourccFMT, dwChunkSize, dwChunkPosition);
    ReadChunkData(hFile, wfx, dwChunkSize, dwChunkPosition);

    //fill out the audio data buffer with the contents of the fourccDATA chunk
    FindChunk(hFile, fourccDATA, dwChunkSize, dwChunkPosition);
    BYTE* pDataBuffer = new BYTE[dwChunkSize];
    ReadChunkData(hFile, pDataBuffer, dwChunkSize, dwChunkPosition);

    buffer->AudioBytes = dwChunkSize;  //size of the audio buffer in bytes
    buffer->pAudioData = pDataBuffer;  //buffer containing audio data
    buffer->Flags = XAUDIO2_END_OF_STREAM; // tell the source voice not to expect any data after this buffer

    CloseHandle(hFile);

    return S_OK;
}

/**
 * @brief FROM: https://learn.microsoft.com/en-us/windows/win32/xaudio2/how-to--load-audio-data-files-in-xaudio2
*/
static HRESULT PlayAudio(IXAudio2* pXAudio2, WAVEFORMATEX* wfx, XAUDIO2_BUFFER* buffer) {
    HRESULT hr = S_OK;

    IXAudio2SourceVoice* pSourceVoice;
    hr = pXAudio2->CreateSourceVoice(&pSourceVoice, wfx);
    if(FAILED(hr)) {
        return hr;
    }

    hr = pSourceVoice->SubmitSourceBuffer(buffer);
    if (FAILED(hr)) {
        return hr;
    }

    hr = pSourceVoice->Start(0);

    return hr;
}
