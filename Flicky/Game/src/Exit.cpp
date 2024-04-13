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


Exit* Exit::IExit = NULL;

Exit* Exit::CreateInstance()
{
	if (IExit != NULL)
	{
		return IExit;
	}
	else
	{
		IExit = new Exit();
		return IExit;
	}

}

Exit* Exit::GetInstance()
{
	return IExit;
}

Exit::Exit()
{
	quadHeight=515;
	quadWidth=315;

	ExitX=0;

	ExitY=-1540;

	colExit = 0;
}

void Exit::collidewithFlicky()
{
	int check1 = 0;
	int check2 = 0;
	int FcolX = Flicky::GetInstance()->getFPosX();
	int FcolY = Flicky::GetInstance()->getFPosY();
	int FWidth = Flicky::GetInstance()->getFwidthX();
	int FHeight = Flicky::GetInstance()->getFheightY();

	if (FcolX + FWidth / 2 >= ExitX - quadWidth / 2 && FcolX - FWidth / 2 <= ExitX + quadWidth)
	{
		check1 = 1;
	}
	if (FcolY - FHeight / 2 <= ExitY+quadHeight / 2 && FcolY + FHeight / 2 >= ExitY - quadHeight)
	{
		check2 = 1;
	}
	if (check1 == 1 && check2 == 1)
	{
		colExit = 1;
	}
	else
	{
		colExit = 0;
	}
}

void Exit::OnCollision()
{

}

void Exit::drawExit()
{
	DrawRect(quadWidth, quadHeight, 47, -1450, 1, 1, 1);
}


int Exit::getExitX()
{
	return ExitX;
}
int Exit::getExitY()
{ 
	return ExitY;
}

int Exit::getcolFlag() { return colExit; }

int Exit::getHeight() { return quadHeight; }

int Exit::getWidth() { return quadWidth; }