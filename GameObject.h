#pragma once

#include <Windows.h>
#include <d3dx9.h>
#define MOVE_UP_KEYBOARD 10
#define MOVE_DOWN_KEYBOARD 20
#define MOVE_UP_MOUSE 15
#define MOVE_DOWN_MOUSE 30
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
	RECT rect;
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetState(int state) { this->state = state; }

	void GetPosition(float& x, float& y) { x = this->x; y = this->y; }
	int GetState() { return this->state; }
	D3DXIMAGE_INFO GetInfo() { return this->infoSquare; }
	CGameObject(LPCWSTR texturePath);
	void Update(DWORD dt);
	void Render();
	~CGameObject();
};

class Paddle : public CGameObject
{
public: 
	Paddle(LPCWSTR texturePath) :CGameObject(texturePath) {};
	void Update(DWORD dt);
	void UpdateR(DWORD dt,int x,int y);
};

