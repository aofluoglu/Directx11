#pragma once

#ifndef CORE_H 
#define CORE_H  

#include "Input.h"
#include "Graphics.h"
#include "Resource.h"

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

class Core {
	public:
		Core();
		~Core();

		bool Initialize();

		void ShutDown();
		void Run();

		LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);
	private:
		bool Frame();

		void InitializeWindow(int&, int&);
		void ShutDownWindow();
	private:
		LPCSTR		_mApplicationName;
		HINSTANCE	_mApplicationHInstance;
		HWND		_mApplicationHwnd;

		Input*		p_AppInput;
		Graphics*	p_AppGraphics;
};

static Core* p_ApplicationHandle;

#endif // !CORE_H 