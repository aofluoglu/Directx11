#include "Input.h"


Input :: Input() {
}


Input :: ~Input() {
}

void Input :: Initialize() {
	for (int i = 0; i < BOOL_KEYS; i++)
		_keys[i] = false;
}

void Input :: KeyDown(unsigned int _key) {
	_keys[_key] = true;
}

void Input :: KeyUp(unsigned int _key) {
	_keys[_key] = false;
}

bool Input :: IsKeyDown(unsigned int _key) {
	return _keys[_key];
}