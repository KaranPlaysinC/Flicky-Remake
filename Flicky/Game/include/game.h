#include "IGame.h"

class CGame : public IGame
{
public:
	CGame();
	~CGame();

	bool Initialize(GL_Window* window, Keys* keys);
	void Deinitialize();

	const char8_t *GetGameTitle(){return mGameTitle;}
	uint32_t GetScreenWidth() { return 1024; }
	uint32_t GetScreenHeight() { return 768; }
	uint32_t GetBitsPerPixel() { return 32; }

	void DrawScene();
	void UpdateFrame(uint32_t milliseconds);
	void DestroyGame();
private:
	static const char8_t mGameTitle[20];
};