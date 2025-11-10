#pragma once 

#include <vector>
#include <Object/DataStructures.h>
#include "Renderer/RenderManager.h"

class Object
{
public: 
	Object(std::vector<VertexData> pArrayVertexData, std::vector <uint32_t> indexData);
	~Object() = default; 

	void SetProps(); 
	void SetPosition(XMFLOAT3 position) { mWorldData.Position = position; }
	void SetRotation(XMFLOAT3 rotation) { mWorldData.Rotation = rotation; }
	void SetScale(XMFLOAT3 scale) { mWorldData.Scale = scale; }
	void updateMatrix(XMMATRIX view, XMMATRIX projection); 
	uint32_t GetIndexCount() const { return mIndexCount;  }

private:
	ComPtr<ID3D11Buffer> mVertexBuffer;
	ComPtr<ID3D11Buffer> mIndexBuffer;
	uint32_t mIndexCount; 

	ComPtr<ID3D11Buffer> mConstantBuffer; 

	WorldData mWorldData; 
	TransformData mTransformData; 
};