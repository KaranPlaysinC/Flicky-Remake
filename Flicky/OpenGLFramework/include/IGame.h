#pragma once
#include "baseTypes.h"
#include "openGLFramework.h"

class IGame
{
public:
	// initialize/deinitialize connect the game to the GL framework
	virtual bool Initialize(GL_Window* window, Keys* keys) = 0;
	virtual void Deinitialize() = 0;

	// these methods are available any time
	virtual const char8_t* GetGameTitle() = 0;
	virtual uint32_t GetScreenWidth() = 0;
	virtual uint32_t GetScreenHeight() = 0;
	virtual uint32_t GetBitsPerPixel() = 0;

	// these are only available while intialized
	virtual void DrawScene() = 0;
	virtual void UpdateFrame(uint32_t milliseconds) = 0;
};