/*efine STATE_MANAGER_CPP
#include <windows.h>											// Header File For Windows
#include <stdio.h>												// Header File For Standard Input / Output
#include <stdarg.h>												// Header File For Variable Argument Routines
#include <math.h>												// Header File For Math Operations
#include <gl\gl.h>												// Header File For The OpenGL32 Library
#include <gl\glu.h>												// Header File For The GLu32 Library
#include "glut.h"
#include <assert.h>
#include "baseTypes.h"
#include "openglframework.h"	
#include "gamedefs.h"
#include "spriteDemoManager.h"
#include "random.h"

#include "soil.h"

SpriteDemoManagerC* SpriteDemoManagerC::sInstance = NULL;


SpriteDemoManagerC* SpriteDemoManagerC::CreateInstance()
{
	if (sInstance != NULL)return sInstance;
	else

		sInstance = new SpriteDemoManagerC();
	return sInstance;
}
void SpriteDemoManagerC::init(int height, int width)
{



	/* load an image file directly as a new OpenGL texture 
	mSpriteTextureMap = SOIL_load_OGL_texture("asset/Area.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

		*/
