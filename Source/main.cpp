
#include "Window/Window.h"

int main()
{
	Window* basicWindow = new Window({ 1200, 720 }, "FantasyEngineDX11");

	basicWindow->Initialize(); 

	while (basicWindow->IsVisible())
	{
		basicWindow->Run(); 
	}

	delete basicWindow; 
	 
	return 0;
}
