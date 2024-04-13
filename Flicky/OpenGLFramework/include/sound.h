#pragma once

#define SOUND_NOSOUND 0

class SoundImpl;

class Sound {
public:
    static bool Init();
    static bool Shutdown();
    static int LoadSound(const char* filename);
    static void UnloadSound(int soundId);
    static void Playback(int soundId);

private:
    static SoundImpl* mInstance;
};