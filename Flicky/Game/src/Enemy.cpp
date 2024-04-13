#include <windows.h>											// Header File For Windows
#include <stdio.h>												// Header File For Standard Input / Output
#include <stdarg.h>												// Header File For Variable Argument Routines
#include <math.h>												// Header File For Math Operations
#include <gl\gl.h>												// Header File For The OpenGL32 Library
#include <gl\glu.h>												// Header File For The GLu32 Library
#include "glut.h"
#include "baseTypes.h"
#include "openglframework.h"	
#include "gamedefs.h"
#include "collInfo.h"
#include "object.h"
#include "inputmapper.h"
#include "ball.h"
#include "field.h"
#include "random.h"
#include "gameObjects.h"
#include "openGLStuff.h"
#include "game.h"
#include "StateManager.h"
#include "BallManager.h"
#include "FieldManager.h"
#include "InputManager.h"
#include "SpriteDemoManager.h"
#include "igame.h"
#include "ShapeDraw.h"
#include "drawPrimitives.h"
#include "chirp.h"
#include "Flicky.h"
#include "SOIL.h"
#include "exit.h"
#include "Enemy.h"

enemy* enemy::Ienemy = NULL;

enemy* enemy::CreateInstance()
{
	if (Ienemy != NULL)
	{
		return Ienemy;
	}
	else
	{
		Ienemy = new enemy;
	}
	return Ienemy;
}

enemy* enemy::GetInstance()
{
	return Ienemy;
}

enemy::enemy()
{
	DarkFlicky;

	EnX1 =1900; 
	EnY1 = 1600;

	EnX2 = 1900;
	EnY2 = 1400;

	EnX3 = 1900;
	EnY3 = 800;

	EnX4 = 1900;
	EnY4 = 500;

	EnX5 = 1900;
	EnY5 = 300;

	EnX6 = -1700;
	EnY6 = -300;

	EnX7 = -1700;
	EnY7 = -900;

	EnX8 = 0;
	EnX8 = 0;

	EnX9 = -1700;
	EnY9 = -700;

	EnX10 = -1700;
	EnY10 = -950;

	qheight = 350;
	qwidth = 350;

	float min = 10;
	float max = 5;

	speed1 = getRangedRandom(min, max);
	speed2 = getRangedRandom(min, max);
	speed3 = getRangedRandom(min, max);
	speed4 = getRangedRandom(min, max);
	speed5 = getRangedRandom(min, max);
	speed6 = getRangedRandom(min, max);
	speed7 = getRangedRandom(min, max);
	speed8 = getRangedRandom(min, max);
	speed9 = getRangedRandom(min, max);
	speed10 = getRangedRandom(min, max);
}


void enemy::moveRight1()
{
	if (EnX1 <= -2000)
	{
		right1 = true;
	}
	if (right1 == true)
	{
		EnX1 += speed1;
	}

	if (EnX1 >= 2000)
	{
		right1 = false;
	}
	if (right1 == false)
	{
		EnX1 -= speed1;
	}
}

void enemy::moveRight2()
{

	if (EnX2 <= -2000)
	{
		right2 = true;
	}
	if (right2 == true)
	{
		EnX2 += speed2;
	}

	if (EnX2 >= 2000)
	{
		right2 = false;
	}
	if (right2 == false)
	{
		EnX2 -= speed2;
	}
}

void enemy::moveRight3()
{
	if (EnX3 <= -2000)
	{
		right3 = true;
	}
	if (right3 == true)
	{
		EnX3 += speed3;
	}

	if (EnX3 >= 2000)
	{
		right3 = false;
	}
	if (right3 == false)
	{
		EnX3 -= speed3;
	}
}

void enemy::moveRight4()
{
	if (EnX4 <= -2000)
	{
		right4 = true;
	}
	if (right4 == true)
	{
		EnX4 += speed4;
	}

	if (EnX4 >= 2000)
	{
		right4 = false;
	}
	if (right4 == false)
	{
		EnX4 -= speed4;
	}
}

void enemy::moveRight5()
{
	if (EnX5 <= -2000)
	{
		right5 = true;
	}
	if (right5 == true)
	{
		EnX5 += speed5;
	}

	if (EnX5 >= 2000)
	{
		right5 = false;
	}
	if (right5 == false)
	{
		EnX5 -= speed5;
	}
}

void enemy::moveRight6()
{
	if (EnX6 <= -2000)
	{
		right6 = true;
	}
	if (right6 == true)
	{
		EnX6 += speed6;
	}

	if (EnX6 >= 2000)
	{
		right6 = false;
	}
	if (right6 == false)
	{
		EnX6 -= speed6;
	}
}

void enemy::moveRight7()
{
	if (EnX7 <= -2000)
	{
		right7 = true;
	}
	if (right7 == true)
	{
		EnX7 += speed7;
	}

	if (EnX7 >= 2000)
	{
		right7 = false;
	}
	if (right7 == false)
	{
		EnX7 -= speed7;
	}
}

void enemy::moveRight8()
{
	if (EnX8 <= -2000)
	{
		right8 = true;
	}
	if (right8 == true)
	{
		EnX8 += speed8;
	}
	if (EnX8 >= 2000)
	{
		right8 = false;
	}
	if (right8 == false)
	{
		EnX8 -= speed8;
	}
}

void enemy::moveRight9()
{

	if (EnX9 <= -2000)
	{
		right9 = true;
	}
	if (right9 == true)
	{
		EnX9 += speed9;
	}
	if (EnX9 >= 2000)
	{
		right9 = false;
	}
	if (right9 == false)
	{
		EnX9 -= speed9;
	}
}

void enemy:: moveRight10()
{
	if (EnX10 <= -2000)
	{
		right10 = true;
	}
	if (right10 == true)
	{
		EnX10 += speed10;
	}
	if (EnX10 >= 2000)
	{
		right10 = false;
	}
	if (right10 == false)
	{
		EnX10 -= speed10;
	}
}



void enemy::drawEnemy1()
{

	float_t quadWidth = qheight;
	float_t quadHeight = qwidth;

	float_t SpriteX = EnX1;
	float_t SpriteY = EnY1;

	float_t leftMostU = 0 / (float)667;  //leftmost x pixel 
	float_t rightMostU = 650 / (float)667; //rightmost x Pixel
	float_t highestV = 725 / (float)864; //Bottom y Pixel
	float_t lowesetV =  0/ (float)864; //top y pixel



	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, DarkFlicky);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glDisable(GL_CULL_FACE);


	glColor4ub(0xFF, 0xFF, 0xFF, 0xFF);

	glBegin(GL_QUADS);
	glTexCoord2f(leftMostU, 1 - highestV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - highestV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - lowesetV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glTexCoord2f(leftMostU, 1 - lowesetV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void enemy::drawEnemy2()
{

	float_t quadWidth = qheight;
	float_t quadHeight = qwidth;

	float_t SpriteX = EnX2;
	float_t SpriteY = EnY2;

	float_t leftMostU = 0 / (float)667;  //leftmost x pixel 
	float_t rightMostU = 650 / (float)667; //rightmost x Pixel
	float_t highestV = 725 / (float)864; //Bottom y Pixel
	float_t lowesetV = 0 / (float)864; //top y pixel



	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, DarkFlicky);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glDisable(GL_CULL_FACE);


	glColor4ub(0xFF, 0xFF, 0xFF, 0xFF);

	glBegin(GL_QUADS);
	glTexCoord2f(leftMostU, 1 - highestV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - highestV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - lowesetV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glTexCoord2f(leftMostU, 1 - lowesetV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void enemy::drawEnemy3()
{

	float_t quadWidth = qheight;
	float_t quadHeight = qwidth;

	float_t SpriteX = EnX3;
	float_t SpriteY = EnY3;

	float_t leftMostU = 0 / (float)667;  //leftmost x pixel 
	float_t rightMostU = 650 / (float)667; //rightmost x Pixel
	float_t highestV = 725 / (float)864; //Bottom y Pixel
	float_t lowesetV = 0 / (float)864; //top y pixel



	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, DarkFlicky);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glDisable(GL_CULL_FACE);


	glColor4ub(0xFF, 0xFF, 0xFF, 0xFF);

	glBegin(GL_QUADS);
	glTexCoord2f(leftMostU, 1 - highestV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - highestV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - lowesetV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glTexCoord2f(leftMostU, 1 - lowesetV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void enemy::drawEnemy4()
{

	float_t quadWidth = qheight;
	float_t quadHeight = qwidth;

	float_t SpriteX = EnX4;
	float_t SpriteY = EnY4;

	float_t leftMostU = 0 / (float)667;  //leftmost x pixel 
	float_t rightMostU = 650 / (float)667; //rightmost x Pixel
	float_t highestV = 725 / (float)864; //Bottom y Pixel
	float_t lowesetV = 0 / (float)864; //top y pixel



	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, DarkFlicky);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glDisable(GL_CULL_FACE);


	glColor4ub(0xFF, 0xFF, 0xFF, 0xFF);

	glBegin(GL_QUADS);
	glTexCoord2f(leftMostU, 1 - highestV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - highestV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - lowesetV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glTexCoord2f(leftMostU, 1 - lowesetV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void enemy::drawEnemy5()
{

	float_t quadWidth = qheight;
	float_t quadHeight = qwidth;

	float_t SpriteX = EnX5;
	float_t SpriteY = EnY5;

	float_t leftMostU = 0 / (float)667;  //leftmost x pixel 
	float_t rightMostU = 650 / (float)667; //rightmost x Pixel
	float_t highestV = 725 / (float)864; //Bottom y Pixel
	float_t lowesetV = 0 / (float)864; //top y pixel



	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, DarkFlicky);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glDisable(GL_CULL_FACE);


	glColor4ub(0xFF, 0xFF, 0xFF, 0xFF);

	glBegin(GL_QUADS);
	glTexCoord2f(leftMostU, 1 - highestV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - highestV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - lowesetV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glTexCoord2f(leftMostU, 1 - lowesetV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void enemy::drawEnemy6()
{

	float_t quadWidth = qheight;
	float_t quadHeight = qwidth;

	float_t SpriteX = EnX6;
	float_t SpriteY = EnY6;

	float_t leftMostU = 0 / (float)667;  //leftmost x pixel 
	float_t rightMostU = 650 / (float)667; //rightmost x Pixel
	float_t highestV = 725 / (float)864; //Bottom y Pixel
	float_t lowesetV = 0 / (float)864; //top y pixel



	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, DarkFlicky);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glDisable(GL_CULL_FACE);


	glColor4ub(0xFF, 0xFF, 0xFF, 0xFF);

	glBegin(GL_QUADS);
	glTexCoord2f(leftMostU, 1 - highestV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - highestV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - lowesetV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glTexCoord2f(leftMostU, 1 - lowesetV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void enemy::drawEnemy7()
{

	float_t quadWidth = qheight;
	float_t quadHeight = qwidth;

	float_t SpriteX = EnX7;
	float_t SpriteY = EnY7;

	float_t leftMostU = 0 / (float)667;  //leftmost x pixel 
	float_t rightMostU = 650 / (float)667; //rightmost x Pixel
	float_t highestV = 725 / (float)864; //Bottom y Pixel
	float_t lowesetV = 0 / (float)864; //top y pixel



	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, DarkFlicky);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glDisable(GL_CULL_FACE);


	glColor4ub(0xFF, 0xFF, 0xFF, 0xFF);

	glBegin(GL_QUADS);
	glTexCoord2f(leftMostU, 1 - highestV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - highestV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - lowesetV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glTexCoord2f(leftMostU, 1 - lowesetV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void enemy::drawEnemy8()
{

	float_t quadWidth = qheight;
	float_t quadHeight = qwidth;

	float_t SpriteX = EnX8;
	float_t SpriteY = EnY8;

	float_t leftMostU = 0 / (float)667;  //leftmost x pixel 
	float_t rightMostU = 650 / (float)667; //rightmost x Pixel
	float_t highestV = 725 / (float)864; //Bottom y Pixel
	float_t lowesetV = 0 / (float)864; //top y pixel



	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, DarkFlicky);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glDisable(GL_CULL_FACE);


	glColor4ub(0xFF, 0xFF, 0xFF, 0xFF);

	glBegin(GL_QUADS);
	glTexCoord2f(leftMostU, 1 - highestV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - highestV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - lowesetV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glTexCoord2f(leftMostU, 1 - lowesetV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void enemy::drawEnemy9()
{

	float_t quadWidth = qheight;
	float_t quadHeight = qwidth;

	float_t SpriteX = EnX9;
	float_t SpriteY = EnY9;

	float_t leftMostU = 0 / (float)667;  //leftmost x pixel 
	float_t rightMostU = 650 / (float)667; //rightmost x Pixel
	float_t highestV = 725 / (float)864; //Bottom y Pixel
	float_t lowesetV = 0 / (float)864; //top y pixel



	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, DarkFlicky);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glDisable(GL_CULL_FACE);


	glColor4ub(0xFF, 0xFF, 0xFF, 0xFF);

	glBegin(GL_QUADS);
	glTexCoord2f(leftMostU, 1 - highestV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - highestV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - lowesetV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glTexCoord2f(leftMostU, 1 - lowesetV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void enemy::drawEnemy10()
{

	float_t quadWidth = qheight;
	float_t quadHeight = qwidth;

	float_t SpriteX = EnX10;
	float_t SpriteY = EnY10;

	float_t leftMostU = 0 / (float)667;  //leftmost x pixel 
	float_t rightMostU = 650 / (float)667; //rightmost x Pixel
	float_t highestV = 725 / (float)864; //Bottom y Pixel
	float_t lowesetV = 0 / (float)864; //top y pixel



	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, DarkFlicky);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glDisable(GL_CULL_FACE);


	glColor4ub(0xFF, 0xFF, 0xFF, 0xFF);

	glBegin(GL_QUADS);
	glTexCoord2f(leftMostU, 1 - highestV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - highestV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY - (quadHeight / 2), 0.0);
	glTexCoord2f(rightMostU, 1 - lowesetV); glVertex3f(SpriteX + (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glTexCoord2f(leftMostU, 1 - lowesetV); glVertex3f(SpriteX - (quadWidth / 2), SpriteY + (quadHeight / 2), 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}



void enemy::init()
{
	DarkFlicky = SOIL_load_OGL_texture("asset/Badbirb.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}

int enemy::getEnX1()
{
	return EnX1;
}

int enemy::getEnY1()
{
	return EnY1;
}
//
int enemy::getqwidth()
{
	return qwidth;
}

int enemy::getqheight()
{
	return qheight;
}
int enemy::getEnX2()
{
	return EnX2;
}
int enemy::getEnY2()
{
	return EnY2;
}

int enemy::getEnX3()
{
	return EnX3;
}

int enemy::getEnY3()
{
	return EnY3;
}


int enemy::getEnX4()
{
	return EnX4;
}
int enemy::getEnY4()
{
	return EnY4;
}

int enemy::getEnX5()
{
	return EnX5;
}

int enemy::getEnY5()
{
	return EnY5;
}

int enemy::getEnX6()
{
	return EnX6;
}

int enemy::getEnY6()
{
	return EnY6;
}

int enemy::getEnX7()
{
	return EnX7;
}

int enemy::getEnY7()
{
	return EnY7;
}

int enemy::getEnY8()
{
	return EnY8;
}

int enemy::getEnX8()
{
	return EnX8;
}

int enemy::getEnX9()
{
	return EnX9;
}

int enemy::getEnX10()
{
	return EnX10;
}
int enemy::getEnY9()
{
	return EnY9;
}
int enemy::getEnY10()
{
	return EnY10;
}
int enemy::getEnX11()
{
	return EnX11;
}
int enemy::getEnY11()
	{
		return EnY11;
	}

int enemy::getEnX12()
{
	return EnX12;
}

int enemy::getEnY12()
{
	return EnY12;
}


