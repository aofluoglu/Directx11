#pragma once

#ifndef INPUT_H
#define INPUT_H

#include "Resource.h"

class Input {
	public:
		Input();
		~Input();

		void Initialize();
		void KeyDown(unsigned int);
		void KeyUp(unsigned int);

		bool IsKeyDown(unsigned int);
	private:
		bool _keys[BOOL_KEYS];
};


#endif //!INPUT_H