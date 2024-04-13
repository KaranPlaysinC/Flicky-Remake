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

Flicky* Flicky::IFlicky = NULL;

Flicky* Flicky::CreateInstance()
{
	if (IFlicky != NULL)
	{
		return IFlicky;
	}
	else
	{
		IFlicky = new Flicky;
		return IFlicky;
	}
}
Flicky* Flicky::GetInstance() {
	return IFlicky;
}



Flicky::Flicky()
{
	lives = 3;
	movespeed = 5;
	FPosX = -1500;
	FPosY = -1575;
	FwidthX = 210;
	FheightY = 410;

	jumpDistance = 20;
	jumpTime = 2;
	jumpSpeed = 8;
	jumpHeight = 1000;
	
	hit;

}

void Flicky::init()
{
	GameOver = SOIL_load_OGL_texture("asset/GameOver.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	FlickySprite = SOIL_load_OGL_texture("asset/Flicky.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}

//Lerp Function.
float Flicky::lerpFlicky(float a, float b, float k)
{
	return a + (b - a) * k;
}

//void Flicky::checkCol1(bool check1, bool check2, bool check3, bool check4)
//{
//	FieldC* field1 = FieldManagerC::GetInstance()->getFieldPtr1();
//
//	float_t rightSide1 = field1->getPosition()->x + ((float_t)field1->getWidth() / 2.0f);
//	float_t leftSide1 = field1->getPosition()->x - ((float_t)field1->getWidth() / 2.0f);
//	float_t topSide1 = field1->getPosition()->y + ((float_t)field1->getHeight() / 2.0f);
//	float_t bottomSide1 = field1->getPosition()->y - ((float_t)field1->getHeight() / 2.0f);
//
//	if (FPosX + FwidthX/2 >= leftSide1)
//	{
//		check1 = true;
//		colleft1 = true;
//
//	}
//	else {
//
//		colleft1 = false;
//	}
//	if (FPosX - FwidthX/2 <= rightSide1)
//	{
//		check2 = true;
//		colright1 = true;
//	}
//	else
//	{
//		colright1 = false;
//	}
//	if (FPosY + FheightY/2.0f >= bottomSide1)
//	{
//		check3 = true;
//		colbottom1 = true;
//	}
//	else
//	{
//		colbottom1 = false;
//	}
//	if (FPosY - FheightY/2.0f <= topSide1)
//	{
//		check4 = true;
//		coltop1 = true;
//	}
//	else
//	{
//		coltop1 = false;
//	}
//	if (check1 == true && check2 == true && check3 == true && check4 == true)
//	{
//		CollidedX1 = true;
//	}
//
//}
//
//void Flicky::checkCol2(bool check1, bool check2, bool check3, bool check4)
//{
//	FieldC* field2 = FieldManagerC::GetInstance()->getFieldPtr2();
//
//	float_t rightSide2 = field2->getPosition()->x + ((float_t)field2->getWidth() / 2.0f);
//	float_t leftSide2 = field2->getPosition()->x - ((float_t)field2->getWidth() / 2.0f);
//	float_t topSide2 = field2->getPosition()->y + ((float_t)field2->getHeight() / 2.0f);
//	float_t bottomSide2 = field2->getPosition()->y - ((float_t)field2->getHeight() / 2.0f);
//
//	if (FPosX + FwidthX >= leftSide2)
//	{
//		check1 = true;
//	}
//	if (FPosX - FwidthX <= rightSide2)
//	{
//		check2 = true;
//	}
//	if (FPosY + FheightY >= bottomSide2)
//	{
//		check3 = true;
//	}
//	if (FPosY - FheightY <= topSide2)
//	{
//		check4 = true;
//	}
//	if (check1 == true && check2 == true && check3 == true && check4 == true)
//	{
//		Collided2 = true;
//		printf("Collided");
//	}
//	else
//	{
//		Collided2 = false;
//	}
//}
//
//void Flicky::checkCol3(bool check1, bool check2, bool check3, bool check4)
//{
//	FieldC* field3 = FieldManagerC::GetInstance()->getFieldPtr3();
//
//	float_t rightSide3 = field3->getPosition()->x + ((float_t)field3->getWidth() / 2.0f);
//	float_t leftSide3 = field3->getPosition()->x - ((float_t)field3->getWidth() / 2.0f);
//	float_t topSide3 = field3->getPosition()->y + ((float_t)field3->getHeight() / 2.0f);
//	float_t bottomSide3 = field3->getPosition()->y - ((float_t)field3->getHeight() / 2.0f);
//
//	if (FPosX + FwidthX >= leftSide3)
//	{
//		check1 = true;
//	}
//	if (FPosX - FwidthX <= rightSide3)
//	{
//		check2 = true;
//	}
//	if (FPosY + FheightY >= bottomSide3)
//	{
//		check3 = true;
//	}
//	if (FPosY - FheightY <= topSide3)
//	{
//		check4 = true;
//	}
//	if (check1 == true && check2 == true && check3 == true && check4 == true)
//	{
//		Collided3 = true;
//		printf("Collided");
//	}
//	else
//	{
//		Collided3 = false;
//	}
//}
//
//void Flicky::checkCol4(bool check1, bool check2, bool check3, bool check4)
//{
//	FieldC* field4 = FieldManagerC::GetInstance()->getFieldPtr4();
//
//	float_t rightSide4 = field4->getPosition()->x + ((float_t)field4->getWidth() / 2.0f);
//	float_t leftSide4 = field4->getPosition()->x - ((float_t)field4->getWidth() / 2.0f);
//	float_t topSide4 = field4->getPosition()->y + ((float_t)field4->getHeight() / 2.0f);
//	float_t bottomSide4 = field4->getPosition()->y - ((float_t)field4->getHeight() / 2.0f);
//
//	if (FPosX + FwidthX >= leftSide4)
//	{
//		check1 = true;
//	}
//	if (FPosX - FwidthX <= rightSide4)
//	{
//		check2 = true;
//	}
//	if (FPosY + FheightY >= bottomSide4)
//	{
//		check3 = true;
//	}
//	if (FPosY - FheightY <= topSide4)
//	{
//		check4 = true;
//	}
//	if (check1 == true && check2 == true && check3 == true && check4 == true)
//	{
//		Collided4 = true;
//		printf("Collided");
//	}
//	else
//	{
//		Collided4 = false;
//	}
//}
//
//void Flicky::checkCol5(bool check1, bool check2, bool check3, bool check4)
//{
//	FieldC* field5 = FieldManagerC::GetInstance()->getFieldPtr5();
//
//	float_t rightSide5 = field5->getPosition()->x + ((float_t)field5->getWidth() / 2.0f);
//	float_t leftSide5 = field5->getPosition()->x - ((float_t)field5->getWidth() / 2.0f);
//	float_t topSide5 = field5->getPosition()->y + ((float_t)field5->getHeight() / 2.0f);
//	float_t bottomSide5 = field5->getPosition()->y - ((float_t)field5->getHeight() / 2.0f);
//
//	if (FPosX + FwidthX >= leftSide5)
//	{
//		check1 = true;
//	}
//	if (FPosX - FwidthX <= rightSide5)
//	{
//		check2 = true;
//	}
//	if (FPosY + FheightY >= bottomSide5)
//	{
//		check3 = true;
//	}
//	if (FPosY - FheightY <= topSide5)
//	{
//		check4 = true;
//	}
//	if (check1 == true && check2 == true && check3 == true && check4 == true)
//	{
//		Collided5 = true;
//		printf("Collided");
//	}
//	else
//	{
//		Collided5 = false;
//	}
//}
//
//void Flicky::checkCol6(bool check1, bool check2, bool check3, bool check4)
//{
//	FieldC* field6 = FieldManagerC::GetInstance()->getFieldPtr1();
//
//	float_t rightSide6 = field6->getPosition()->x + ((float_t)field6->getWidth() / 2.0f);
//	float_t leftSide6 = field6->getPosition()->x - ((float_t)field6->getWidth() / 2.0f);
//	float_t topSide6 = field6->getPosition()->y + ((float_t)field6->getHeight() / 2.0f);
//	float_t bottomSide6 = field6->getPosition()->y - ((float_t)field6->getHeight() / 2.0f);
//
//	if (FPosX + FwidthX >= leftSide6)
//	{
//		check1 = true;
//	}
//	if (FPosX - FwidthX <= rightSide6)
//	{
//		check2 = true;
//	}
//	if (FPosY + FheightY >= bottomSide6)
//	{
//		check3 = true;
//	}
//	if (FPosY - FheightY <= topSide6)
//	{
//		check4 = true;
//	}
//	if (check1 == true && check2 == true && check3 == true && check4 == true)
//	{
//		Collided6 = true;
//		printf("Collided");
//	}
//	else
//	{
//		Collided6 = false;
//	}
//}
//
//void Flicky::checkCol7(bool check1, bool check2, bool check3, bool check4)
//{
//	FieldC* field7 = FieldManagerC::GetInstance()->getFieldPtr1();
//
//	float_t rightSide7 = field7->getPosition()->x + ((float_t)field7->getWidth() / 2.0f);
//	float_t leftSide7 = field7->getPosition()->x - ((float_t)field7->getWidth() / 2.0f);
//	float_t topSide7 = field7->getPosition()->y + ((float_t)field7->getHeight() / 2.0f);
//	float_t bottomSide7 = field7->getPosition()->y - ((float_t)field7->getHeight() / 2.0f);
//
//	if (FPosX + FwidthX >= leftSide7)
//	{
//		check1 = true;
//	}
//	if (FPosX - FwidthX <= rightSide7)
//	{
//		check2 = true;
//	}
//	if (FPosY + FheightY >= bottomSide7)
//	{
//		check3 = true;
//	}
//	if (FPosY - FheightY <= topSide7)
//	{
//		check4 = true;
//	}
//	if (check1 == true && check2 == true && check3 == true && check4 == true)
//	{
//		Collided7 = true;
//		printf("Collided");
//	}
//	else
//	{
//		Collided7 = false;
//	}
//} //collision with platforms

/*void Flicky::checkCol1(bool check1, bool check2, bool check3, bool check4)
{
	FieldC* field1 = FieldManagerC::GetInstance()->getFieldPtr1();

	float_t rightSide1 = field1->getPosition()->x + ((float_t)field1->getWidth() / 2.0f);
	float_t leftSide1 = field1->getPosition()->x - ((float_t)field1->getWidth() / 2.0f);
	float_t topSide1 = field1->getPosition()->y + ((float_t)field1->getHeight() / 2.0f);
	float_t bottomSide1 = field1->getPosition()->y - ((float_t)field1->getHeight() / 2.0f);

	if (FPosX + FwidthX >= leftSide1)
	{
		check1 = true;
	}
	if (FPosX - FwidthX <= rightSide1)
	{
		check2 = true;
	}
	if (FPosY + FheightY >= bottomSide1)
	{
		check3 = true;
	}
	if (FPosY - FheightY <= topSide1)
	{
		check4 = true;
	}
	if (check1 == true && check2 == true && check3 == true && check4 == true)
	{
		CollidedX1 = true;
		printf("Collided");
	}
	else
	{
		CollidedX1 = false;
	}
}

void Flicky::checkCol1(bool check1, bool check2, bool check3, bool check4)
{
	FieldC* field1 = FieldManagerC::GetInstance()->getFieldPtr1();

	float_t rightSide1 = field1->getPosition()->x + ((float_t)field1->getWidth() / 2.0f);
	float_t leftSide1 = field1->getPosition()->x - ((float_t)field1->getWidth() / 2.0f);
	float_t topSide1 = field1->getPosition()->y + ((float_t)field1->getHeight() / 2.0f);
	float_t bottomSide1 = field1->getPosition()->y - ((float_t)field1->getHeight() / 2.0f);

	if (FPosX + FwidthX >= leftSide1)
	{
		check1 = true;
	}
	if (FPosX - FwidthX <= rightSide1)
	{
		check2 = true;
	}
	if (FPosY + FheightY >= bottomSide1)
	{
		check3 = true;
	}
	if (FPosY - FheightY <= topSide1)
	{
		check4 = true;
	}
	if (check1 == true && check2 == true && check3 == true && check4 == true)
	{
		CollidedX1 = true;
		printf("Collided");
	}
	else
	{
		CollidedX1 = false;
	}
}

void Flicky::checkCol1(bool check1, bool check2, bool check3, bool check4)
{
	FieldC* field1 = FieldManagerC::GetInstance()->getFieldPtr1();

	float_t rightSide1 = field1->getPosition()->x + ((float_t)field1->getWidth() / 2.0f);
	float_t leftSide1 = field1->getPosition()->x - ((float_t)field1->getWidth() / 2.0f);
	float_t topSide1 = field1->getPosition()->y + ((float_t)field1->getHeight() / 2.0f);
	float_t bottomSide1 = field1->getPosition()->y - ((float_t)field1->getHeight() / 2.0f);

	if (FPosX + FwidthX >= leftSide1)
	{
		check1 = true;
	}
	if (FPosX - FwidthX <= rightSide1)
	{
		check2 = true;
	}
	if (FPosY + FheightY >= bottomSide1)
	{
		check3 = true;
	}
	if (FPosY - FheightY <= topSide1)
	{
		check4 = true;
	}
	if (check1 == true && check2 == true && check3 == true && check4 == true)
	{
		CollidedX1 = true;
		printf("Collided");
	}
	else
	{
		CollidedX1 = false;
	}
}*/

void Flicky::MoveRight(bool right) //For horizontal movement
{
	if (right)
	{
		if (FPosX <= 1800)
		{
			FPosX += movespeed;
		}

	}
	else
	{
		if (FPosX >= -1800)
		{
			FPosX -= movespeed;
		}
	}
}

//bool checkLerp()
//{
//	
//}

int Flicky::Onground()
{
	 
	if (FPosY <= -1575)
	{
		onground=1;
	}
	return onground;
}


void Flicky::Jump()
{
	if (FPosY < 1700)
	{
		FPosY += jumpSpeed;
	}
}


//flicky is hit by enemy
void Flicky::FlickyHit()
{
	int Enx1 = enemy::GetInstance()->getEnX1();
	int Eny1 = enemy::GetInstance()->getEnY1();

	int Enx2 = enemy::GetInstance()->getEnX2();
	int Eny2 = enemy::GetInstance()->getEnY2();

	int Enx3 = enemy::GetInstance()->getEnX3();
	int Eny3 = enemy::GetInstance()->getEnY3();

	int Enx4 = enemy::GetInstance()->getEnX4();
	int Eny4 = enemy::GetInstance()->getEnY4();

	int Enx5 = enemy::GetInstance()->getEnX5();
	int Eny5 = enemy::GetInstance()->getEnY5();

	int Enx6 = enemy::GetInstance()->getEnX6();
	int Eny6 = enemy::GetInstance()->getEnY6();

	int Enx7 = enemy::GetInstance()->getEnX7();
	int Eny7 = enemy::GetInstance()->getEnY7();

	int Enx8 = enemy::GetInstance()->getEnX8();
	int Eny8 = enemy::GetInstance()->getEnY8();

	int Enx9 = enemy::GetInstance()->getEnX9();
	int Eny9 = enemy::GetInstance()->getEnY9();

	int Enx10 = enemy::GetInstance()->getEnX10();
	int Eny10 = enemy::GetInstance()->getEnY10();

	int Enx11 = enemy::GetInstance()->getEnX11();
	int Eny11 = enemy::GetInstance()->getEnY11();
	
	int Enx12 = enemy::GetInstance()->getEnX12();
	int Eny12 = enemy::GetInstance()->getEnY12();


	int C1 = chirp::GetInstance()->getcolFlag1();
	int C2 = chirp::GetInstance()->getcolFlag2();
	int C3 = chirp::GetInstance()->getcolFlag3();
	int C4 = chirp::GetInstance()->getcolFlag4();
	int C5 = chirp::GetInstance()->getcolFlag5();
	int C6 = chirp::GetInstance()->getcolFlag6();
	int C7 = chirp::GetInstance()->getcolFlag7();
	int C8 = chirp::GetInstance()->getcolFlag8();
	int C9 = chirp::GetInstance()->getcolFlag9();
	int C10 = chirp::GetInstance()->getcolFlag10();



	hit = collision(FPosX, FPosY, FwidthX, FheightY, Enx1, Eny1, 300, 300,h,v);
	hit2 = collision(FPosX, FPosY, FwidthX, FheightY, Enx2, Eny2, 300, 300, h, v);
	hit3 = collision(FPosX, FPosY, FwidthX, FheightY, Enx3, Eny3, 300, 300, h, v);
	hit4 = collision(FPosX, FPosY, FwidthX, FheightY, Enx4, Eny4, 300, 300, h, v);
	hit5 = collision(FPosX, FPosY, FwidthX, FheightY, Enx5, Eny5, 300, 300, h, v);
	hit6 = collision(FPosX, FPosY, FwidthX, FheightY, Enx6, Eny6, 300, 300, h, v);
	hit7 = collision(FPosX, FPosY, FwidthX, FheightY, Enx7, Eny7, 300, 300, h, v);
	hit8 = collision(FPosX, FPosY, FwidthX, FheightY, Enx8, Eny8, 300, 300, h, v);
	hit9 = collision(FPosX, FPosY, FwidthX, FheightY, Enx9, Eny9, 300, 300, h, v);
	hit10 = collision(FPosX, FPosY, FwidthX, FheightY, Enx10, Eny10, 300, 300, h, v);
	hit11 = collision(FPosX, FPosY, FwidthX, FheightY, Enx11, Eny11, 300, 300, h, v);
	hit12 = collision(FPosX, FPosY, FwidthX, FheightY, Enx12, Eny12, 300, 300, h, v);
	
	if (hit == true || hit2 == true || hit3 == true || hit4 == true || hit5 == true || hit6 == true || hit7 == true || hit8 == true || hit9 == true || hit10 == true || hit11 == true || hit12 == true)
	{
		lives--;

		FPosY = -1575;

	}
};


void Flicky::Descend()
{
	if (FPosY > -1700)
	{
		FPosY -= jumpSpeed;
	}
}


//getters
float_t Flicky::getFPosX()
{
	return FPosX;
}

int Flicky::getFPosY()
{
	return FPosY;
}

int Flicky::getFwidthX()
{
	return FwidthX;
}

int Flicky::getFheightY()
{
	return FheightY;
}

void Flicky::drawFlicky()
{
	float_t  Updated_PosX = FPosX;
	float_t  Updated_PosY = FPosY;

	float_t quadWidth = 210;
	float_t quadHeight = 410;
	float_t SpriteX = Updated_PosX;
	float_t SpriteY = Updated_PosY;

	float_t leftMostU = 20 / (float)667;  //leftmost x pixel 
	float_t rightMostU = 100 / (float)667; //rightmost x Pixel
	float_t highestV = 625 / (float)864; //Bottom y Pixel
	float_t lowesetV = 500 / (float)864; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, FlickySprite);

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


bool Flicky::gethit1()
{
	return hit;
}
bool Flicky::gethit2()
{
	return hit2;
}
bool Flicky::gethit3()
{
	return hit3;
}
bool Flicky::gethit4()
{
	return hit4;
}
bool Flicky::gethit5()
{
	return hit5;
}
bool Flicky::gethit6()
{
	return hit6;
}
bool Flicky::gethit7()
{
	return hit7;
}
bool Flicky::gethit8()
{
	return hit8;
}
bool Flicky::gethit9()
{
	return hit9;
}
bool Flicky::gethit10()
{
	return hit10;
}
bool Flicky::gethit11()
{
	return hit11;
}
bool Flicky::gethit12()
{
	return hit12;
}

void Flicky::drawLosingScreen()
{
	if (lives == 0)
	{
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_CULL_FACE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glBindTexture(GL_TEXTURE_2D, GameOver);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glColor4ub(0xFF, 0xFF, 0xFF, 0xFF);

		//Render Background Image
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-1000,-1000 );
		glTexCoord2f(1.0f, 0.0f); glVertex2f(1000, -1000);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(1000, 1000);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-1000, 1000);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
	}
}