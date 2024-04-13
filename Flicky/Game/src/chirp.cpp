
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
#include "SOIL.h"
#include "Flicky.h"
#include "exit.h"
#include "Enemy.h"

chirp* chirp::Ichirp = NULL;

chirp* chirp::CreateInstance()
{
	if (Ichirp != NULL)
	{
		return Ichirp;
	}
	else
	{
		Ichirp = new chirp();
		return Ichirp;
	}
		
}

chirp* chirp::GetInstance()
{
	return Ichirp;
}

void chirp::initialize()
{
	ChirpSprite = SOIL_load_OGL_texture("asset/Chirp.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

}

static const Coord2D initialPositions[NUM_CHIRPS] = {
	{-1500,800},
	{-1800,800},
	//...
	{-1800,800},
	{-1800,800},
	{-1800,800},
	{-1800,800},
	{-1800,800},
	{-1800,800},
	{-1800,800},
	{-1800,800},
	{-1800,800},
	{-1800,800},
	//...
	{900,1200}
};

chirp::chirp()
{
	// this would be much nicer & less error prone... this kind of pattern would be useful throughout your program
	for (int i = 0; i < NUM_CHIRPS; ++i) {
		chirps[i].X = initialPositions[i].x;
		chirps[i].Y = initialPositions[i].y;
		chirps[i].colFlag = false;
		chirps[i].colExit = false;
		chirps[i].h = false;
	}

	 chirpX = -1500;
	 chirpY = 800;

	 chirpX2 = -1800;
	 chirpY2 = 800;

	 chirpX3=100;
	 chirpY3=500;

	 chirpX4=1800;
	 chirpY4=800;

	 chirpX5=1200;
	 chirpY5=800;

	 chirpX6= 1200;
	 chirpY6= 200;

	 chirpX7= -1500;
	 chirpY7= -0;

	 chirpX10 = -1800;
	 chirpY10 = -0;

	 chirpX8= -1500;
	 chirpY8= -800;

	 chirpX9 = -1800;
	 chirpY9 = -800;

	 chirpX11 = 100;
	 chirpY11 = 500;

	 chirpX12 = 400;
	 chirpY12 = 1200;

	 chirpX13 = 900;
	 chirpY13 = 1200;



	 FcolX = Flicky::GetInstance()->getFPosX();
	 FcolY = Flicky::GetInstance()->getFPosY();
	 FWidth = Flicky::GetInstance()->getFwidthX();
	 FHeight = Flicky::GetInstance()->getFheightY();

	 //chirpX9=;
	 //chirpY9=;

	 //chirpX10=;
	 //chirpY10=;
	chirpSpeed = 5;
	
	quadH = 150;
	quadW = 280;

	EX = Exit::GetInstance()->getExitX();
	EY = Exit::GetInstance()->getExitY();
	EW = Exit::GetInstance()->getWidth();
	EH = Exit::GetInstance()->getHeight();

	colFlag1 = 0;
	colFlag2 = 0;
	colFlag3 = 0;
	colFlag4 = 0;
	colFlag5 = 0;
	colFlag6 = 0;
	colFlag7 = 0;
	colFlag8 = 0;
	colFlag9 = 0;
	colFlag10 = 0;
	colFlag11 = 0;
	colFlag12 = 0;
	colFlag13 = 0;

	WinFlag;

	exitFlag = Exit::GetInstance()->getcolFlag();

	colExit1=0;
	colExit2=0;
	colExit3=0;
	colExit4=0;
	colExit5=0;
	colExit6=0;
	colExit7=0;
	colExit8=0;
	colExit9=0;
	colExit10=0;
	colExit11=0;
	colExit12=0;
	colExit13 = 0;

	h1 = Flicky::GetInstance()->gethit1();
	h2 = Flicky::GetInstance()->gethit2();
	h3 = Flicky::GetInstance()->gethit3();
	h4 = Flicky::GetInstance()->gethit4();
	h5 = Flicky::GetInstance()->gethit5();
	h6 = Flicky::GetInstance()->gethit6();
	h7 = Flicky::GetInstance()->gethit7();
	h8 = Flicky::GetInstance()->gethit8();
	h9 = Flicky::GetInstance()->gethit9();
	h10 = Flicky::GetInstance()->gethit10();
	h11 = Flicky::GetInstance()->gethit11();
	h12 = Flicky::GetInstance()-> gethit12();


}

void chirp::lerptoExit()
{
	int EX = Exit::GetInstance()->getExitX();
	int EY = Exit::GetInstance()->getExitY();
	int EW = Exit::GetInstance()->getWidth();
	int EH = Exit::GetInstance()->getHeight();

	if (exitFlag == 1)
	{

		colFlag1 = 0;
		colFlag2 = 0;
		colFlag3 = 0;
		colFlag4 = 0;
		colFlag5 = 0;
		colFlag6 = 0;
		colFlag7 = 0;
		colFlag8 = 0;
		colFlag9 = 0;
		colFlag10 = 0;


		chirpX = lerpchirp(chirpX, EX, 0.04f);
		chirpY = lerpchirp(chirpY, EY, 0.04f);

	
		chirpX2 = lerpchirp(chirpX2, EX, 0.04f);
		chirpY2 = lerpchirp(chirpY2, EY, 0.04f);

		chirpX3 = lerpchirp(chirpX3, EX, 0.04f);
		chirpY3 = lerpchirp(chirpY3, EY, 0.04f);

		chirpX4 = lerpchirp(chirpX4, EX, 0.04f);
		chirpY4 = lerpchirp(chirpY4, EY, 0.04f);

		chirpX5 = lerpchirp(chirpX5, EX, 0.04f);
		chirpY5 = lerpchirp(chirpY5, EY, 0.04f);

		chirpX6 = lerpchirp(chirpX6, EX, 0.04f);
		chirpY6 = lerpchirp(chirpY6, EY, 0.04f);

		chirpX7 = lerpchirp(chirpX7, EX, 0.04f);
		chirpY7 = lerpchirp(chirpY7, EY, 0.04f);

		chirpX8 = lerpchirp(chirpX8, EX, 0.04f);
		chirpY8 = lerpchirp(chirpY8, EY, 0.04f);

		//chirpX9 = lerpchirp(chirpX9, EX, 0.04f);
		//chirpY9 = lerpchirp(chirpY9, EY, 0.04f);

		//chirpX10 = lerpchirp(chirpX10, EX, 0.04f);
		//chirpY10 = lerpchirp(chirpY10, EY, 0.04f);

		//chirpX = lerpchirp(chirpX, EX, 0.04f);
		//chirpY = lerpchirp(chirpY, EY, 0.04f);


	}

}

void chirp::collidewithExit()
{
	int checkX1 = 0;
	int checkX2 = 0;
	int checkX3 = 0;
	int checkX4 = 0;
	int checkX5 = 0;
	int checkX6 = 0;
	int checkX7 = 0;
	int checkX8 = 0;
	int checkX9 = 0;
	int checkX10 = 0;
	int checkX11 = 0;
	int checkX12 = 0;

	int checkY1 = 0;
	int checkY2 = 0;
	int checkY3 = 0;
	int checkY4 = 0;
	int checkY5 = 0;
	int checkY6 = 0;
	int checkY7 = 0;
	int checkY8 = 0;
	int checkY9 = 0;
	int checkY10 = 0;
	int checkY11 = 0;
	int checkY12 = 0;

	if (chirpX + quadW / 2 >= EX - EH / 2 && chirpX - quadW / 2 <= EX + EW / 2)
	{
		checkX1 = 1;
	}
	if (chirpY - quadH / 2 <= EY + EH / 2 && chirpY + quadH / 2 >= EY - EH / 4)
	{
		checkY1 = 1;
	}
	if (checkX1 == 1 && checkY1 == 1)
	{
		colExit1 = 1;
	}
	//else if (exitFlag == 1)
	//{
	//	colExit1 = 0;
	//}
	if (chirpX2 + quadW / 2 >= EX - EW / 2 && chirpX2 - quadW / 2 <= EX + EW)
	{
		checkX2 = 1;
	}
	if (chirpY2 - quadH / 2 <= EY +EH / 2 && chirpY2 + quadH / 2 >= EY - EH)
	{
		checkY2 = 1;
	}
	if (checkX2 == 1 && checkY2 == 1)
	{
		colExit2 = 1;
	}
	//else
	//{
	//	colFlag2 = 0;
	//}
	if (chirpX3 + quadW / 2 >= EX - EW / 2 && chirpX3 - quadW / 2 <= EX + EW)
	{
		checkX3 = 1;
	}
	if (chirpY3 - quadH / 2 <= EY + EH / 2 && chirpY3 + quadH / 2 >= EY - EH)
	{
		checkY3 = 1;
	}
	if (checkX3 == 1 && checkY3 == 1)
	{
		colExit3 = 1;
	}
	if (chirpX4 + quadW / 2 >=  - EW / 2 && chirpX4 - quadW / 2 <= EX + EW)
	{
		checkX4 = 1;
	}
	if (chirpY4 - quadH / 2 <= EY + EH / 2 && chirpY4 + quadH / 2 >= EY - EH)
	{
		checkY4 = 1;
	}
	if (checkX4 == 1 && checkY4 == 1)
	{
		colExit4 = 1;
	}
	if (chirpX5 + quadW / 2 >= EX - EW / 2 && chirpX5 - quadW / 2 <= EX + EW)
	{
		checkX5 = 1;
	}
	if (chirpY5 - quadH / 2 <= EY + EH / 2 && chirpY5 + quadH / 2 >=EY - EH)
	{
		checkY5 = 1;
	}
	if (checkX5 == 1 && checkY5 == 1)
	{
		colExit5 = 1;
	}
	if (chirpX6 + quadW / 2 >= EX - EW / 2 && chirpX6 - quadW / 2 <= EX + EW)
	{
		checkX6 = 1;
	}
	if (chirpY6 - quadH / 2 <= EY+ EH / 2 && chirpY6 + quadH / 2 >= EY - EH)
	{
		checkY6 = 1;
	}
	if (checkX6 == 1 && checkY6 == 1)
	{
		colExit6 = 1;
	}
	if (chirpX7 + quadW / 2 >= EX- EW / 2 && chirpX7 - quadW / 2 <= EX + EW)
	{
		checkX7 = 1;
	}
	if (chirpY7 - quadH / 2 <= EY + EH / 2 && chirpY7 + quadH / 2 >= EY - EH)
	{
		checkY7 = 1;
	}
	if (checkX7 == 1 && checkY7 == 1)
	{
		colExit7 = 1;
	}
	if (chirpX8 + quadW / 2 >= EX - EW / 2 && chirpX8 - quadW / 2 <= EX + EW)
	{
		checkX8 = 1;
	}
	if (chirpY8 - quadH / 2 <= EY + EH / 2 && chirpY8 + quadH / 2 >= EY - EH)
	{
		checkY8 = 1;
	}
	if (checkX8 == 1 && checkY8 == 1)
	{
		colExit8 = 1;
	}
	if (chirpX9 + quadW / 2 >= EX - EW / 2 && chirpX9 - quadW / 2 <= EX + EW)
	{
		checkX9 = 1;
	}
	if (chirpY9 - quadH / 2 <= EY + EH / 2 && chirpY9 + quadH / 2 >= EY - EH)
	{
		checkY9 = 1;
	}
	if (checkX9 == 1 && checkY9 == 1)
	{
		colExit9 = 1;
	}
	if (chirpX10 + quadW / 2 >= EX - EW / 2 && chirpX10 - quadW / 2 <= EX + EW)
	{
		checkX10 = 1;
	}
	if (chirpY10 - quadH / 2 <= EY + EH / 2 && chirpY10 + quadH / 2 >= EY - EH)
	{
		checkY10 = 1;
	}
	if (checkX10 == 1 && checkY10 == 1)
	{
		colExit10 = 1;
	}
	if (chirpX11 + quadW / 2 >= EX - EW / 2 && chirpX11 - quadW / 2 <= EX + EW)
	{
		checkX11 = 1;
	}
	if (chirpY11 - quadH / 2 <= EY + EH / 2 && chirpY11 + quadH / 2 >= EY - EH)
	{
		checkY11 = 1;
	}
	if (checkX11 == 1 && checkY11 == 1)
	{
		colExit11 = 1;
	}
	if (chirpX12 + quadW / 2 >= EX - EW / 2 && chirpX12 - quadW / 2 <= EX + EW)
	{
		checkX12 = 1;
	}
	if (chirpY12 - quadH / 2 <= EY + EH / 2 && chirpY12 + quadH / 2 >= EY - EH)
	{
		checkY12 = 1;
	}
	if (checkX12 == 1 && checkY12 == 1)
	{
		colExit12 = 1;
	}

	if (colExit1 == 1 && colExit2 == 1 && colExit3 == 1 && colExit4 == 1 && colExit5 == 1 && colExit6 == 1 && colExit7 == 1 && colExit8 == 1 && colExit9 == 1 && colExit10 == 1 && colExit11 == 1 && colExit12 == 1)
	{
		WinFlag = 1;
	}
}

void chirp::lerpWithFlicky()
{
	FcolX = Flicky::GetInstance()->getFPosX();
	FcolY = Flicky::GetInstance()->getFPosY();

	if (colFlag1 == 1)
	{
		if (colExit1 == 1)
		{
			chirpX = chirpX + 5000; //bye bye
		}
		if (g_keys->keyDown[VK_RIGHT])
		{
			chirpX = lerpchirp(chirpX, FcolX - 100, 0.04f);
			chirpY = lerpchirp(chirpY, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_LEFT])
		{
			chirpX = lerpchirp(chirpX, FcolX + 100, 0.04f);
			chirpY = lerpchirp(chirpY, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_UP])
		{
			chirpX = lerpchirp(chirpX, FcolX, 0.04f);
			chirpY = lerpchirp(chirpY, FcolY-100, 0.04f);
		}
		if (g_keys->keyDown[VK_DOWN])
		{
			chirpX = lerpchirp(chirpX, FcolX, 0.04f);
			chirpY = lerpchirp(chirpY, FcolY + 100, 0.04f);
		}
    
	}
	if (colFlag2 == 1)
	{
		if (colExit2 == 1)
		{
			chirpX2 = chirpX2 + 5000;
		}
		if (g_keys->keyDown[VK_RIGHT])
		{
			chirpX2 = lerpchirp(chirpX2, FcolX - 200, 0.04f);
			chirpY2 = lerpchirp(chirpY2, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_LEFT])
		{
			chirpX2 = lerpchirp(chirpX2, FcolX + 200, 0.04f);
			chirpY2 = lerpchirp(chirpY2, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_UP])
		{
			chirpX2 = lerpchirp(chirpX2, FcolX, 0.04f);
			chirpY2 = lerpchirp(chirpY2, FcolY - 200, 0.04f);
		}
		if (g_keys->keyDown[VK_DOWN])
		{
			chirpX2 = lerpchirp(chirpX2, FcolX, 0.04f);
			chirpY2 = lerpchirp(chirpY2, FcolY + 200, 0.04f);
		}
	}
	if (colFlag3 == 1)
	{
		if (colExit3 == 1)
		{
			chirpX3 = chirpX3 + 5000;
		}
		if (g_keys->keyDown[VK_RIGHT])
		{
			chirpX3 = lerpchirp(chirpX3, FcolX - 300, 0.04f);
			chirpY3 = lerpchirp(chirpY3, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_LEFT])
		{
			chirpX3 = lerpchirp(chirpX3, FcolX + 300, 0.04f);
			chirpY3 = lerpchirp(chirpY3, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_UP])
		{
			chirpX3 = lerpchirp(chirpX3, FcolX, 0.04f);
			chirpY3 = lerpchirp(chirpY3, FcolY - 300, 0.04f);
		}
		if (g_keys->keyDown[VK_DOWN])
		{
			chirpX3 = lerpchirp(chirpX3, FcolX, 0.04f);
			chirpY3 = lerpchirp(chirpY3, FcolY + 300, 0.04f);
		}

	}
	if (colFlag4 == 1)
	{ //face other way with FX -;
		if (colExit4 == 1)
		{
			chirpX4 = chirpX4 + 5000;
		}
		if (g_keys->keyDown[VK_RIGHT])
		{
			chirpX4 = lerpchirp(chirpX4, FcolX - 400, 0.04f);
			chirpY4 = lerpchirp(chirpY4, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_LEFT])
		{
			chirpX4 = lerpchirp(chirpX4, FcolX + 400, 0.04f);
			chirpY4 = lerpchirp(chirpY4, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_UP])
		{
			chirpX4 = lerpchirp(chirpX4, FcolX, 0.04f);
			chirpY4 = lerpchirp(chirpY4, FcolY - 400, 0.04f);
		}
		if (g_keys->keyDown[VK_DOWN])
		{
			chirpX4 = lerpchirp(chirpX4, FcolX, 0.04f);
			chirpY4 = lerpchirp(chirpY4, FcolY + 400, 0.04f);
		}
	}
	if (colFlag5 == 1)
	{
		if (colExit5 == 1)
		{
			chirpX5 = chirpX5 + 5000;
		}
		if (g_keys->keyDown[VK_RIGHT])
		{
			chirpX5 = lerpchirp(chirpX5, FcolX - 500, 0.04f);
			chirpY5 = lerpchirp(chirpY5, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_LEFT])
		{
			chirpX5 = lerpchirp(chirpX5, FcolX + 500, 0.04f);
			chirpY5 = lerpchirp(chirpY5, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_UP])
		{
			chirpX5 = lerpchirp(chirpX5, FcolX, 0.04f);
			chirpY5 = lerpchirp(chirpY5, FcolY - 500, 0.04f);
		}
		if (g_keys->keyDown[VK_DOWN])
		{
			chirpX5 = lerpchirp(chirpX5, FcolX, 0.04f);
			chirpY5 = lerpchirp(chirpY5, FcolY + 500, 0.04f);
		}
	}
	if (colFlag6 == 1)
	{
		if (colExit6 == 1)
		{
			chirpX6 = chirpX6 + 5000; //byebye
		}
		if (g_keys->keyDown[VK_RIGHT])
		{
			chirpX6 = lerpchirp(chirpX6, FcolX - 600, 0.04f);
			chirpY6 = lerpchirp(chirpY6, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_LEFT])
		{
			chirpX6 = lerpchirp(chirpX6, FcolX + 600, 0.04f);
			chirpY6 = lerpchirp(chirpY6, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_UP])
		{
			chirpX6 = lerpchirp(chirpX6, FcolX, 0.04f);
			chirpY6 = lerpchirp(chirpY6, FcolY - 600, 0.04f);
		}
		if (g_keys->keyDown[VK_DOWN])
		{
			chirpX6 = lerpchirp(chirpX6, FcolX, 0.04f);
			chirpY6 = lerpchirp(chirpY6, FcolY + 600, 0.04f);
		}
	}
	if (colFlag7 == 1)
	{
		if (colExit7 == 1)
		{
			chirpX7 = chirpX7 + 5000;  //byebye
		}
		if (g_keys->keyDown[VK_RIGHT])
		{
			chirpX7 = lerpchirp(chirpX7, FcolX - 700, 0.04f);
			chirpY7 = lerpchirp(chirpY7, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_LEFT])
		{
			chirpX7 = lerpchirp(chirpX7, FcolX + 700, 0.04f);
			chirpY7 = lerpchirp(chirpY7, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_UP])
		{
			chirpX7 = lerpchirp(chirpX7, FcolX, 0.04f);
			chirpY7 = lerpchirp(chirpY7, FcolY - 700, 0.04f);
		}
		if (g_keys->keyDown[VK_DOWN])
		{
			chirpX7 = lerpchirp(chirpX7, FcolX, 0.04f);
			chirpY7 = lerpchirp(chirpY7, FcolY + 700, 0.04f);
		}
	}
	if (colFlag8 == 1)
	{
		if (colExit8 == 1)
		{
			chirpX8 = chirpX8 + 5000; //byebye
		}
		if (g_keys->keyDown[VK_RIGHT])
		{
			chirpX8 = lerpchirp(chirpX8, FcolX - 800, 0.04f);
			chirpY8 = lerpchirp(chirpY8, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_LEFT])
		{
			chirpX8 = lerpchirp(chirpX8, FcolX + 800, 0.04f);
			chirpY8 = lerpchirp(chirpY8, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_UP])
		{
			chirpX8 = lerpchirp(chirpX8, FcolX, 0.04f);
			chirpY8 = lerpchirp(chirpY8, FcolY - 800, 0.04f);
		}
		if (g_keys->keyDown[VK_DOWN])
		{
			chirpX8 = lerpchirp(chirpX8, FcolX, 0.04f);
			chirpY8 = lerpchirp(chirpY8, FcolY + 800, 0.04f);
		}

	}
	if (colFlag9 == 1)
	{
		if (colExit9 == 1)
		{
			chirpX9 = chirpX9 + 5000; //byebye
		}
		if (g_keys->keyDown[VK_RIGHT])
		{
			chirpX9 = lerpchirp(chirpX9, FcolX - 900, 0.04f);
			chirpY9 = lerpchirp(chirpY9, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_LEFT])
		{
			chirpX9 = lerpchirp(chirpX9, FcolX + 900, 0.04f);
			chirpY9 = lerpchirp(chirpY9, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_UP])
		{
			chirpX9 = lerpchirp(chirpX9, FcolX, 0.04f);
			chirpY9 = lerpchirp(chirpY9, FcolY - 900, 0.04f);
		}
		if (g_keys->keyDown[VK_DOWN])
		{
			chirpX9 = lerpchirp(chirpX9, FcolX, 0.04f);
			chirpY9 = lerpchirp(chirpY9, FcolY + 900, 0.04f);
		}

	}
	if (colFlag10 == 1)
	{
		if (colExit10 == 1)
		{
			chirpX10 = chirpX10 + 5000; //byebye
		}
		if (g_keys->keyDown[VK_RIGHT])
		{
			chirpX10 = lerpchirp(chirpX10, FcolX - 1000, 0.04f);
			chirpY10 = lerpchirp(chirpY10, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_LEFT])
		{
			chirpX10 = lerpchirp(chirpX10, FcolX + 1000, 0.04f);
			chirpY10 = lerpchirp(chirpY10, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_UP])
		{
			chirpX10 = lerpchirp(chirpX10, FcolX, 0.04f);
			chirpY10 = lerpchirp(chirpY10, FcolY - 1000, 0.04f);
		}
		if (g_keys->keyDown[VK_DOWN])
		{
			chirpX10 = lerpchirp(chirpX10, FcolX, 0.04f);
			chirpY10 = lerpchirp(chirpY10, FcolY + 1000, 0.04f);
		}

	}
	if (colFlag11 == 1)
	{
		if (colExit11 == 1)
		{
			chirpX11 = chirpX11 + 5000; //byebye
		}
		if (g_keys->keyDown[VK_RIGHT])
		{
			chirpX11 = lerpchirp(chirpX11, FcolX - 1100, 0.04f);
			chirpY11 = lerpchirp(chirpY11, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_LEFT])
		{
			chirpX11 = lerpchirp(chirpX11, FcolX + 1100, 0.04f);
			chirpY11 = lerpchirp(chirpY11, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_UP])
		{
			chirpX11 = lerpchirp(chirpX11, FcolX, 0.04f);
			chirpY11 = lerpchirp(chirpY11, FcolY - 1100, 0.04f);
		}
		if (g_keys->keyDown[VK_DOWN])
		{
			chirpX11 = lerpchirp(chirpX11, FcolX, 0.04f);
			chirpY11 = lerpchirp(chirpY11, FcolY + 1100, 0.04f);
		}

	}
	if (colFlag12 == 1)
	{
		if (colExit12 == 1)
		{
			chirpX12 = chirpX12 + 5000; //byebye
		}
		if (g_keys->keyDown[VK_RIGHT])
		{
			chirpX12 = lerpchirp(chirpX12, FcolX - 1200, 0.04f);
			chirpY12 = lerpchirp(chirpY12, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_LEFT])
		{
			chirpX12 = lerpchirp(chirpX12, FcolX + 1200, 0.04f);
			chirpY12 = lerpchirp(chirpY12, FcolY, 0.04f);
		}
		if (g_keys->keyDown[VK_UP])
		{
			chirpX12 = lerpchirp(chirpX12, FcolX, 0.04f);
			chirpY12 = lerpchirp(chirpY12, FcolY - 1200, 0.04f);
		}
		if (g_keys->keyDown[VK_DOWN])
		{
			chirpX12 = lerpchirp(chirpX12, FcolX, 0.04f);
			chirpY12 = lerpchirp(chirpY12, FcolY + 1200, 0.04f);
		}

	}
	

}


void chirp::CollideWithFlicky()
{
	int checkX1=0;
	int checkY1=0;

	int checkX2 = 0;
	int checkY2 = 0;
	int checkX3 = 0;
	int checkY3 = 0;
	int checkX4 = 0;
	int checkY4 = 0;
	int checkX5 = 0;
	int checkY5 = 0;
	int checkX6 = 0;
	int checkY6 = 0;
	int checkX7 = 0;
	int checkY7 = 0;
	int checkX8 = 0;
	int checkY8 = 0;
	int checkX9 = 0;
	int checkY9 = 0;
	int checkX10 = 0;
	int checkY10 = 0;
	int checkX11 = 0;
	int checkY11 = 0;
	int checkX12 = 0;
	int checkY12 = 0;
	int checkX13 = 0;
	int checkY13 = 0;

	if (chirpX + quadW/2 >= FcolX - FWidth/2 && chirpX - quadW/2 <= FcolX +FWidth/2)
	{
		checkX1 = 1;
	}
	if (chirpY - quadH/2 <= FcolY + FHeight/2 && chirpY + quadH/2  >= FcolY - FHeight/4)
	{
		checkY1 = 1;
	}
	if (checkX1 == 1 && checkY1 == 1)
	{
		colFlag1 = 1;
	}
	if (chirpX2 + quadW / 2 >= FcolX - FWidth / 2 && chirpX2 - quadW / 2 <= FcolX + FWidth)
	{
		checkX2 = 1;
	}
	if (chirpY2 - quadH / 2 <= FcolY + FHeight / 2 && chirpY2 + quadH / 2 >= FcolY - FHeight)
	{
		checkY2 = 1;
	}
	if (checkX2 == 1 && checkY2 == 1)
	{
		colFlag2 = 1;
	}
	//else
	//{
	//	colFlag2 = 0;
	//}
	if (chirpX3 + quadW / 2 >= FcolX - FWidth / 2 && chirpX3 - quadW / 2 <= FcolX + FWidth)
	{
		checkX3 = 1;
	}
	if (chirpY3 - quadH / 2 <= FcolY + FHeight / 2 && chirpY3 + quadH / 2 >= FcolY - FHeight)
	{
		checkY3 = 1;
	}
	if (checkX3 == 1 && checkY3 == 1)
	{
		colFlag3 = 1;
	}
	if (chirpX4 + quadW / 2 >= FcolX - FWidth / 2 && chirpX4 - quadW / 2 <= FcolX + FWidth)
	{
		checkX4 = 1;
	}
	if (chirpY4 - quadH / 2 <= FcolY + FHeight / 2 && chirpY4 + quadH / 2 >= FcolY - FHeight)
	{
		checkY4 = 1;
	}
	if (checkX4 == 1 && checkY4 == 1)
	{
		colFlag4 = 1;
	}
	if (chirpX5 + quadW / 2 >= FcolX - FWidth / 2 && chirpX5 - quadW / 2 <= FcolX + FWidth)
	{
		checkX5 = 1;
	}
	if (chirpY5 - quadH / 2 <= FcolY + FHeight / 2 && chirpY5 + quadH / 2 >= FcolY - FHeight)
	{
		checkY5 = 1;
	}
	if (checkX5 == 1 && checkY5 == 1)
	{
		colFlag5 = 1;
	}
	if (chirpX6 + quadW / 2 >= FcolX - FWidth / 2 && chirpX6 - quadW / 2 <= FcolX + FWidth)
	{
		checkX6 = 1;
	}
	if (chirpY6 - quadH / 2 <= FcolY + FHeight / 2 && chirpY6 + quadH / 2 >= FcolY - FHeight)
	{
		checkY6 = 1;
	}
	if (checkX6 == 1 && checkY6 == 1)
	{
		colFlag6 = 1;
	}
	if (chirpX7 + quadW / 2 >= FcolX - FWidth / 2 && chirpX7 - quadW / 2 <= FcolX + FWidth)
	{
		checkX7 = 1;
	}
	if (chirpY7 - quadH / 2 <= FcolY + FHeight / 2 && chirpY7 + quadH / 2 >= FcolY - FHeight)
	{
		checkY7 = 1;
	}
	if (checkX7 == 1 && checkY7 == 1)
	{
		colFlag7 = 1;
	}
	if (chirpX8 + quadW / 2 >= FcolX - FWidth / 2 && chirpX8 - quadW / 2 <= FcolX + FWidth)
	{
		checkX8 = 1;
	}
	if (chirpY8 - quadH / 2 <= FcolY + FHeight / 2 && chirpY8 + quadH / 2 >= FcolY - FHeight)
	{
		checkY8 = 1;
	}
	if (checkX8 == 1 && checkY8 == 1)
	{
		colFlag8 = 1;
	}
	if (chirpX9 + quadW / 2 >= FcolX - FWidth / 2 && chirpX9 - quadW / 2 <= FcolX + FWidth)
	{
		checkX9 = 1;
	}
	if (chirpY9 - quadH / 2 <= FcolY + FHeight / 2 && chirpY9 + quadH / 2 >= FcolY - FHeight)
	{
		checkY9 = 1;
	}
	if (checkX9 == 1 && checkY9 == 1)
	{
		colFlag9 = 1;
	}
	if (chirpX10 + quadW / 2 >= FcolX - FWidth / 2 && chirpX10 - quadW / 2 <= FcolX + FWidth)
	{
		checkX10 = 1;
	}
	if (chirpY10 - quadH / 2 <= FcolY + FHeight / 2 && chirpY10 + quadH / 2 >= FcolY - FHeight)
	{
		checkY10 = 1;
	}
	if (checkX10 == 1 && checkY10 == 1)
	{
		colFlag10 = 1;
	}
	if (chirpX11 + quadW / 2 >= FcolX - FWidth / 2 && chirpX11 - quadW / 2 <= FcolX + FWidth)
	{
		checkX11 = 1;
	}
	if (chirpY11 - quadH / 2 <= FcolY + FHeight / 2 && chirpY11 + quadH / 2 >= FcolY - FHeight)
	{
		checkY11 = 1;
	}
	if (checkX11 == 1 && checkY11 == 1)
	{
		colFlag11 = 1;
	}
	if (chirpX12 + quadW / 2 >= FcolX - FWidth / 2 && chirpX12 - quadW / 2 <= FcolX + FWidth)
	{
		checkX12 = 1;
	}
	if (chirpY12 - quadH / 2 <= FcolY + FHeight / 2 && chirpY12 + quadH / 2 >= FcolY - FHeight)
	{
		checkY12 = 1;
	}
	if (checkX12 == 1 && checkY12 == 1)
	{
		colFlag12 = 1;
	}
	if (chirpX13 + quadW / 2 >= FcolX - FWidth / 2 && chirpX13 - quadW / 2 <= FcolX + FWidth)
	{
		checkX13 = 1;
	}
	if (chirpY13 - quadH / 2 <= FcolY + FHeight / 2 && chirpY13 + quadH / 2 >= FcolY - FHeight)
	{
		checkY13 = 1;
	}
	if (checkX13 == 1 && checkY13 == 1)
	{
		colFlag13 = 1;
	}

}

void chirp::drawChirps() {
	// really, this should be something like
	//for (int i = 0; i < NUM_CHIRPS; ++i) {
	//	drawOneChirp(&chirps[i]);
	//}
	// instead of duplicating your draw function 13 times
	drawChirp();
	drawChirp2();
	drawChirp3();
	drawChirp4();
	drawChirp5();
	drawChirp6();
	drawChirp7();
	drawChirp8();
	drawChirp9();
	drawChirp10();
	drawChirp11();
	drawChirp12();
	drawChirp13(); 
}

void chirp::drawChirp()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX;
	float_t SpriteY = chirpY;
	

	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV =  120 / (float)335; //Bottom y Pixel
	float_t lowesetV =  50/ (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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
void chirp::drawChirp2()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX2;
	float_t SpriteY = chirpY2;


	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV = 120 / (float)335; //Bottom y Pixel
	float_t lowesetV = 50 / (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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
void chirp::drawChirp3()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX3;
	float_t SpriteY = chirpY3;


	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV = 120 / (float)335; //Bottom y Pixel
	float_t lowesetV = 50 / (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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
void chirp::drawChirp4()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX4;
	float_t SpriteY = chirpY4;


	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV = 120 / (float)335; //Bottom y Pixel
	float_t lowesetV = 50 / (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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
void chirp::drawChirp5()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX5;
	float_t SpriteY = chirpY5;


	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV = 120 / (float)335; //Bottom y Pixel
	float_t lowesetV = 50 / (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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
void chirp::drawChirp6()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX6;
	float_t SpriteY = chirpY6;


	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV = 120 / (float)335; //Bottom y Pixel
	float_t lowesetV = 50 / (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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
void chirp::drawChirp7()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX7;
	float_t SpriteY = chirpY7;


	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV = 120 / (float)335; //Bottom y Pixel
	float_t lowesetV = 50 / (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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
void chirp::drawChirp8()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX8;
	float_t SpriteY = chirpY8;


	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV = 120 / (float)335; //Bottom y Pixel
	float_t lowesetV = 50 / (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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
void chirp::drawChirp9()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX9;
	float_t SpriteY = chirpY9;


	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV = 120 / (float)335; //Bottom y Pixel
	float_t lowesetV = 50 / (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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
void chirp::drawChirp10()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX10;
	float_t SpriteY = chirpY10;


	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV = 120 / (float)335; //Bottom y Pixel
	float_t lowesetV = 50 / (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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
void chirp::drawChirp11()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX11;
	float_t SpriteY = chirpY11;


	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV = 120 / (float)335; //Bottom y Pixel
	float_t lowesetV = 50 / (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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
void chirp::drawChirp12()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX12;
	float_t SpriteY = chirpY12;


	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV = 120 / (float)335; //Bottom y Pixel
	float_t lowesetV = 50 / (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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
void chirp::drawChirp13()
{

	float_t quadWidth = 150;
	float_t quadHeight = 280;
	float_t SpriteX = chirpX13;
	float_t SpriteY = chirpY13;


	float_t leftMostU = 312 / (float)614;  //leftmost x pixel 
	float_t rightMostU = 380 / (float)614; //rightmost x Pixel
	float_t highestV = 120 / (float)335; //Bottom y Pixel
	float_t lowesetV = 50 / (float)335; //top y pixel

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ChirpSprite);

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

int chirp::getcolFlag1()
{
	return colFlag1;
}

int chirp::getcolFlag2()
{
	return colFlag2;
}
int chirp::getcolFlag3()
{
	return colFlag3;
}
int chirp::getcolFlag4()
{
	return colFlag4;
}
int chirp::getcolFlag5()
{
	return colFlag5;
}
int chirp::getcolFlag6()
{
	return colFlag6;
}
int chirp::getcolFlag7()
{
	return colFlag7;
}
int chirp::getcolFlag8()
{
	return colFlag8;
}
int chirp::getcolFlag9()
{
	return colFlag9;
}
int chirp::getcolFlag10()
{
	return colFlag10;
}
int chirp::getcolFlag11()
{
	return colFlag11;
}
int chirp::getcolFlag12()
{
	return colFlag12;
}

void chirp::dropChirps()
{
	if (h1 == true)
	{
		colFlag1 = 0;
	}
	if (h2 == true)
	{
		colFlag2 = 0;
	}
	if (h3 == true)
	{
		colFlag3 = 0;
	}
	if (h4 == true)
	{
		colFlag4 = 0;
	}
	if (h5 == true)
	{
		colFlag5 = 0;
	}
	if (h6 == true)
	{
		colFlag6 = 0;
	}
	if (h7 == true)
	{
		colFlag7 = 0;

	}
	if (h8 == true)
	{
		colFlag8 = 0;
	}
	if (h9 == true)
	{
		colFlag9 = 0;
	}
	if (h10 == true)
	{
		colFlag10 = 0;
	}
	if (h11 == true)
	{
		colFlag11 = 0;
	}
	if (h12 == true)
	{
		colFlag12 = 0;
	}

}






