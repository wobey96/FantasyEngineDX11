
#include "Window/Window.h"
#include "Renderer/Renderer.h"

int main()
{
	WindowSize mySize{ 1200, 720 };
	Window* basicWindow = new Window(mySize, "FantasyEngineDX11");
	basicWindow->Initialize(); 

	Renderer* basicRenderer = new Renderer(basicWindow);


	while (basicWindow->IsVisible())
	{
		basicWindow->Run(); 
		basicRenderer->ClearColor({ 0.5f, 0.2f, 0.6f, 1.0f });
		basicRenderer->Present(); 
	}

	delete basicWindow; 
	delete basicRenderer; 
	 
	return 0;
}
