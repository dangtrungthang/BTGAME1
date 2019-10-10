#pragma once
#include "GameObject.h"
#define SCREEN_WIDTH GetSystemMetrics(SM_CXSCREEN)
#define SCREEN_HEIGHT GetSystemMetrics(SM_CYSCREEN)

class Paddle :public CGameObject {

public:
	Paddle(LPCWSTR texturePath) :CGameObject(texturePath) {};
	void Update(DWORD dt);
	void UpdateR(DWORD dt,int xs,int ys);
};
