#include "Resource.h"
#include "Core.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevHInstance, PSTR cmdShowLine, int cmdShow){
	Core* core;
	bool result;

	core = new Core;
	if(!core)
		return 0;

	result = core->Initialize();
	if(result)
		core->Run();

	core->ShutDown();
	delete core;
	core = NULL;
	return 0;
}