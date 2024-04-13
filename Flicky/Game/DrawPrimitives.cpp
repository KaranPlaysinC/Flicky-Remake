#include <windows.h>											// Header File For Windows
#include <stdio.h>												// Header File For Standard Input / Output
#include <stdarg.h>												// Header File For Variable Argument Routines
#include <math.h>												// Header File For Math Operations
#include <gl\gl.h>												// Header File For The OpenGL32 Library
#include <gl\glu.h>												// Header File For The GLu32 Library
#include "glut.h"
#include "baseTypes.h"
#include "ShapeDraw.h"
#include "collInfo.h"
#include "object.h"
#include "inputmapper.h"
#include "ball.h"
#include "field.h"
#include "fieldmanager.h"
#include "gamedefs.h"
#include "gameobjects.h"
#include "random.h"
#include "stateManager.h"
#include "inputmanager.h"
#include "drawPrimitives.h"
#include "ShapeDraw.h"
#include"platform.h"
#include"Flicky.h"


drawPrimitives* drawPrimitives::Primitive = NULL;


drawPrimitives* drawPrimitives::CreateInstance()
{
	if (Primitive != NULL)return Primitive;
	else

		Primitive = new drawPrimitives();
	return Primitive;
}
void drawPrimitives::platform()
{	
	
}

void drawPrimitives::drawFlicky()
{

}