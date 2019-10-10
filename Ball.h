#pragma once
#include "GameObject.h"
class Ball :public CGameObject {
	
public:
	int dx , dy;
	float speed;
	RECT rect;
	Ball(LPCWSTR texturePath) :CGameObject(texturePath) {};
	void Update(DWORD dt,int w,int h);
	void SetDxDy(int dx,int dy) { this->dx = dx; this->dy = dy; }
};
