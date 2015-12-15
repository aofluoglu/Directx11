#include "Core.h"

Core::Core() {
	p_AppInput				= NULL;
	p_AppGraphics			= NULL;
	p_ApplicationHandle		= NULL;

	p_ApplicationHandle		= this;

	_mApplicationHInstance  = GetModuleHandle(NULL);
	_mApplicationName		= "Win32 Window";
}

Core :: ~Core() {
}

bool Core :: Initialize() {
	int x_iScreen, y_iScreen;
	bool result;

	x_iScreen = 0;
	y_iScreen = 0;

	InitializeWindow(x_iScreen, y_iScreen);

	p_AppInput = new Input;
	if(!p_AppInput)
		return false;
	p_AppInput->Initialize();

	p_AppGraphics = new Graphics;
	if(!p_AppGraphics)
		return false;
	result = p_AppGraphics->Initialize(x_iScreen, y_iScreen, _mApplicationHwnd);
	if(!result)
		return false;

	return true;
}

void Core :: ShutDown() {
	if(p_AppInput){
		delete p_AppInput;
		p_AppInput = NULL;
	}
	
	if(p_AppGraphics) {
		p_AppGraphics->ShutDown();
		delete p_AppGraphics;
		p_AppGraphics = NULL;
	}

	ShutDownWindow();
}

void Core :: Run() {
	MSG msg;
	bool done, result;

	ZeroMemory(&msg , sizeof(MSG));

	done = false;
	while (!done) {
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if(msg.message == WM_QUIT)
			done = true;
		else {
			result = Frame();
			if(!result)
				done = true;
		}
	}
}

bool Core :: Frame() {
	bool result;

	if(p_AppInput->IsKeyDown(VK_ESCAPE))
		return false;

	result = p_AppGraphics->Frame();
	if(!result)
		return false;

	return true;
}

LRESULT CALLBACK Core :: MessageHandler(HWND _hwnd, UINT _message, WPARAM _wParam, LPARAM _lParam) {
	switch (_message) {
		case WM_KEYDOWN:
			p_AppInput->KeyDown((unsigned int)_wParam);
			return 0;
		case WM_KEYUP:
			p_AppInput->KeyUp((unsigned int)_wParam);
			return 0;
		default:
			return DefWindowProc(_hwnd, _message, _wParam, _lParam);
	}
}

void Core :: InitializeWindow(int& x_iScreen, int& y_iScreen) {
	WNDCLASSEX wc;
	DEVMODE dm_ScreenSettngs;

	int xPosition, yPosition;

	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc		= WndProc;
	wc.lpszClassName	= _mApplicationName;
	wc.lpszMenuName		= NULL;
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm			= wc.hIcon;
	wc.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.hInstance		= _mApplicationHInstance;
	wc.cbSize			= sizeof(WNDCLASSEX);
	wc.cbClsExtra		= NULL;
	wc.cbWndExtra		= NULL;

	RegisterClassEx(&wc);

	x_iScreen = GetSystemMetrics(SM_CXSCREEN);
	y_iScreen = GetSystemMetrics(SM_CYSCREEN);

	if(IsFullScreen) {
		memset(&dm_ScreenSettngs, 0 , sizeof(dm_ScreenSettngs));
		dm_ScreenSettngs.dmSize			= sizeof(dm_ScreenSettngs);
		dm_ScreenSettngs.dmPelsWidth	= (unsigned long)x_iScreen;
		dm_ScreenSettngs.dmPelsHeight	= (unsigned long)y_iScreen;
		dm_ScreenSettngs.dmBitsPerPel	= 32;
		dm_ScreenSettngs.dmFields		= DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings(&dm_ScreenSettngs, CDS_FULLSCREEN);

		xPosition = 0;
		yPosition = 0;

		_mApplicationHwnd = CreateWindowEx(
			WS_EX_APPWINDOW,
			_mApplicationName,
			_mApplicationName,
			WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
			xPosition,
			yPosition,
			x_iScreen,
			y_iScreen,
			NULL,
			NULL,
			_mApplicationHInstance,
			NULL);
	}
	else {
		x_iScreen = 800;
		y_iScreen = 600;

		xPosition = (GetSystemMetrics(SM_CXSCREEN) - x_iScreen)/ 2;
		yPosition = (GetSystemMetrics(SM_CYSCREEN) - y_iScreen)/ 2;

		_mApplicationHwnd = CreateWindowEx(
			NULL,
			_mApplicationName,
			_mApplicationName,
			WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP | WS_OVERLAPPEDWINDOW,
			xPosition,
			yPosition,
			x_iScreen,
			y_iScreen,
			NULL,
			NULL,
			_mApplicationHInstance,
			NULL);
	}

	ShowWindow(_mApplicationHwnd, SW_SHOW);
	SetForegroundWindow(_mApplicationHwnd);
	SetFocus(_mApplicationHwnd);
}

void Core :: ShutDownWindow() {
	if(IsFullScreen)
		ChangeDisplaySettings(NULL, 0);

	DestroyWindow(_mApplicationHwnd);
	_mApplicationHwnd = NULL;

	UnregisterClass(_mApplicationName, _mApplicationHInstance);
	_mApplicationHInstance = NULL;

	p_ApplicationHandle = NULL;
}

LRESULT CALLBACK WndProc(HWND _hwnd, UINT _message, WPARAM _wParam, LPARAM _lParam) {
	switch (_message) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_CLOSE:
			PostQuitMessage(0);
			return 0;
		default:
			return p_ApplicationHandle->MessageHandler(_hwnd, _message, _wParam, _lParam);
	}
}