#pragma once

#include <Windows.h>
#include <d3dx9.h>

class CGameObject
{
protected: 
	float x; 
	float y;
	float t;

	LPDIRECT3DTEXTURE9 texture;		
	D3DXIMAGE_INFO infoSquare;
public: 
	void SetPosition(float x, float y) { this->x = x, this->y = y; }

	CGameObject(LPCWSTR texturePath);
	void Update(DWORD dt);
	void Render();
	~CGameObject();
};

class Square : public CGameObject
{
public: 
	Square(LPCWSTR texturePath) :CGameObject(texturePath) {};
	void Update(DWORD dt);
};