#define FIELD_MANAGER_CPP
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
#include "collinfo.h"
#include "object.h"
#include "inputMapper.h"
#include "field.h"
#include "FieldManager.h"
#include "Enemy.h"

FieldManagerC* FieldManagerC::sInstance=NULL;


FieldManagerC *FieldManagerC::CreateInstance()
{
	if(sInstance!=NULL)return sInstance;
	else

	sInstance = new FieldManagerC();
	return sInstance;
}
void FieldManagerC::init()
{
	mFieldPtr1 = new FieldC(0.0f,-800.0f,100,1260,0x00FF0000);
	mFieldPtr2 = new FieldC(-4.0f, 65.0f, 100, 1260, 0x00FF0000);
	mFieldPtr3 = new FieldC(-4.0f, 925.0f, 100, 1260, 0x00FF0000);
	mFieldPtr4 = new FieldC(-1790.0f, 1355.0f, 130, 1300, 0x00FF0000);
	mFieldPtr5 = new FieldC(-1790.0f, 500.0f, 130, 1300, 0x00FF0000);
	mFieldPtr6 = new FieldC(-1790.0f, -350.0f, 130, 1300, 0x00FF0000);
	mFieldPtr7 = new FieldC(-1790.0f, -1210.0f, 130, 1300, 0x00FF0000);
	mFieldPtr8 = new FieldC(1750.0f, 1355.0f, 130, 1300, 0x00FF0000);
	mFieldPtr9 = new FieldC(1750.0f, 500.0f, 130, 1300, 0x00FF0000);
	mFieldPtr10 = new FieldC(1750.0f, -350.0f, 130, 1300, 0x00FF0000);
	mFieldPtr11 = new FieldC(1750.0f, -1210.0f, 130, 1300, 0x00FF0000);
}
FieldC *FieldManagerC::getFieldPtr1()
{
	return mFieldPtr1;
}
FieldC* FieldManagerC::getFieldPtr2()
{
	return mFieldPtr2;
}
FieldC* FieldManagerC::getFieldPtr3()
{
	return mFieldPtr3;
}
FieldC* FieldManagerC::getFieldPtr4()
{
	return mFieldPtr4;
}
FieldC* FieldManagerC::getFieldPtr5()
{
	return mFieldPtr5;
}
FieldC* FieldManagerC::getFieldPtr6()
{
	return mFieldPtr6;
}
FieldC* FieldManagerC::getFieldPtr7()
{
	return mFieldPtr7;
}
FieldC* FieldManagerC::getFieldPtr8()
{
	return mFieldPtr8;
}
FieldC* FieldManagerC::getFieldPtr9()
{
	return mFieldPtr9;
}
FieldC* FieldManagerC::getFieldPtr10()
{
	return mFieldPtr10;
}
FieldC* FieldManagerC::getFieldPtr11()
{
	return mFieldPtr11;
}
void FieldManagerC::renderField()
{
	mFieldPtr1->render();
	mFieldPtr2->render();
	mFieldPtr3->render();
	mFieldPtr4->render();
	mFieldPtr5->render();
	mFieldPtr6->render();
	mFieldPtr7->render();
	mFieldPtr8->render();
	mFieldPtr9->render();
	mFieldPtr10->render();
	mFieldPtr11->render();
}
void FieldManagerC::shutdown()
{
	delete mFieldPtr1;
	delete mFieldPtr2;
	delete mFieldPtr3;
	delete mFieldPtr4;
	delete mFieldPtr5;
	delete mFieldPtr6;
	delete mFieldPtr7;
	delete mFieldPtr8;
	delete mFieldPtr9;
	delete mFieldPtr10;
	delete mFieldPtr11;
}