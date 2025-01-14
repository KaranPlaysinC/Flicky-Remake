/********************
*                   *
*   NeHeGL Header   *
*                   *
**********************************************************************************
*                                                                                *
*	You Need To Provide The Following Functions:                                 *
*                                                                                *
*	IGame *Initialize (GL_Window* window, Keys* keys);                           *
*		Performs All Your Initialization                                         *
*		Returns TRUE If Initialization Was Successful, FALSE If Not              *
*		'window' Is A Parameter Used In Calls To NeHeGL                          *
*		'keys' Is A Structure Containing The Up/Down Status Of keys              *
*                                                                                *
*	void Deinitialize (IGame *pGame);                                            *
*		Performs All Your DeInitialization                                       *
*                                                                                *
*********************************************************************************/

#ifndef GL_FRAMEWORK__INCLUDED
#define GL_FRAMEWORK__INCLUDED

#include <windows.h>								// Header File For Windows

typedef struct {									// Structure For Keyboard Stuff
	BOOL keyDown [256];								// Holds TRUE / FALSE For Each Key
} Keys;												// Keys

typedef struct {									// Contains Information Vital To Applications
	HINSTANCE		hInstance;						// Application Instance
	const char*		className;						// Application ClassName
} Application;										// Application

typedef struct {									// Window Creation Info
	Application*		application;				// Application Structure
	char*				title;						// Window Title
	int					width;						// Width
	int					height;						// Height
	int					bitsPerPixel;				// Bits Per Pixel
	BOOL				isFullScreen;				// FullScreen?
} GL_WindowInit;									// GL_WindowInit

typedef struct {									// Contains Information Vital To A Window
	Keys*				keys;						// Key Structure
	HWND				hWnd;						// Window Handle
	HDC					hDC;						// Device Context
	HGLRC				hRC;						// Rendering Context
	GL_WindowInit		init;						// Window Init
	BOOL				isVisible;					// Window Visible?
	ULONGLONG			lastTickCount;				// Tick Counter
} GL_Window;										// GL_Window



void TerminateApplication (GL_Window* window);		// Terminate The Application

void ToggleFullscreen (GL_Window* window);			// Toggle Fullscreen / Windowed Mode

//-----------------

extern int mouse_x;
extern int mouse_y;

extern char appTitle[];								// Stores Program Title
extern int screenInfo[3];							// Stores Screen Info (w,h,bpp)

extern GL_Window*	g_window;
extern Keys*		g_keys;

#endif												// GL_FRAMEWORK__INCLUDED
