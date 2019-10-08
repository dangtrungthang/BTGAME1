#pragma once

#include <Windows.h>
#include <d3dx9.h>
#define MOVE_UP_KEYBOARD 10
#define MOVE_DOWN_KEYBOARD 20
#define IDLE 0
class CGameObject
{
protected: 
	float x; 
	float y;
	float t;

	int state;
	LPDIRECT3DTEXTURE9 texture;		
	D3DXIMAGE_INFO infoSquare;
public: 
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetState(int state) { this->state = state; }

	void GetPosition(float& x, float& y) { x = this->x; y = this->y; }
	int GetState() { return this->state; }
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