#pragma once


#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Resource.h"

const bool IsFullScreen  = false;
const bool IsVsyncEnable = true;
const float ScreenDepth  = SCREEN_DEPTH_1000;
const float ScreenNear   = SCREEN_NEAR_0001;

class Graphics {
	public:
		Graphics();
		~Graphics();

		bool Initialize(int, int, HWND);
		void ShutDown();
		bool Frame();
	private:
		bool Render();
};

#endif //!GRAPHICS_H