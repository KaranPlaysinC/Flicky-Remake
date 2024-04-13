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
#include "CollisionField.h"

CollisionField* CollisionField::ICol = NULL;

CollisionField* CollisionField::CreateInstance()
{
	if (ICol != NULL)
	{
		return ICol;
	}
	else
	{
		ICol = new CollisionField;
		return ICol;
	}
}
CollisionField* CollisionField::GetInstance() {
	return ICol;
}

CollisionField::CollisionField()
{

}



