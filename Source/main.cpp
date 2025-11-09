#include <vector>

#include "Window/Window.h"
#include "Renderer/RenderManager.h"
#include "Object/Object.h"
#include "Object/Camera.h"


std::vector<VertexData> vertices1 =
{
	{ XMFLOAT3(-0.5f, -0.5, 0.0f), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f) },
	{ XMFLOAT3(0.0f, 0.5f, 0.0f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
	{ XMFLOAT3(0.5f, -0.5f, 0.0f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) }
};

std::vector<VertexData> vertices2 =
{
	{ XMFLOAT3(0.7f, 0.0, 0.0f), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f) },
	{ XMFLOAT3(0.8f, 0.8f, 0.0f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
	{ XMFLOAT3(0.9f, 0.0f, 0.0f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) }
};

std::vector<uint32_t> indicies1 =
{
	0, 1, 2
};

int main()
{
	// OBJECT ARRAY 
	std::vector<Object*> objects;

	// BASIC WINDOW INITIALIZATION
	Window* basicWindow = new Window({ 1200, 720 }, "FantasyEngineDX11");
	basicWindow->Initialize(); 

	// BASIC RENDER INITIALIZATION
	Renderer* basicRenderer = RenderManager::CreateRenderer(basicWindow);
	Camera* basicCamera = new Camera({0.0f, 0.0f, -3.0f});

	// BASIC TRIANGLE INITIALIZATION
	Object* triangle = new Object(vertices1, indicies1); 
	objects.push_back(triangle); 

	Object* triangle2 = new Object(vertices2, indicies1); 
	objects.push_back(triangle2); 

	// BASIC RENDER LOOP 
	while (basicWindow->IsVisible())
	{
		basicWindow->Run(); 
		basicRenderer->ClearColor({ 0.5f, 0.2f, 0.6f, 1.0f });
		basicCamera->ProcessTransformPosition(basicWindow->GetWindowHandler()); 
		basicRenderer->SetPipeline();  

		for (auto& object : objects)
		{
			object->SetProps(); 
			object->updateMatrix(basicCamera->GetViewMatrix(), basicCamera->GetProjectionMatrix()); 
			basicRenderer->Draw(object->GetIndexCount()); 
		}

		basicRenderer->Present(); 
	}

	delete basicCamera; 
	delete basicWindow; 
	delete basicRenderer; 
	 
	return 0;
}
