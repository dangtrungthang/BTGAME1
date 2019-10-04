#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"

#define center_X GetSystemMetrics(SM_CXSCREEN)/2;
#define center_Y GetSystemMetrics(SM_CYSCREEN)/2;

#define SCREEN_WIDTH GetSystemMetrics(SM_CXSCREEN)
#define SCREEN_HEIGHT GetSystemMetrics(SM_CYSCREEN)

CGameObject::CGameObject(LPCWSTR texturePath)
{
	x = y = 0;
	t = 0;

	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(texturePath, &info);
	infoSquare = info;
	if (result != D3D_OK)
	{
		DebugOut(L"[ERROR] GetImageInfoFromFile failed: %s\n",texturePath);
		return;
	}

	LPDIRECT3DDEVICE9 d3ddv = CGame::GetInstance()->GetDirect3DDevice();

	result = D3DXCreateTextureFromFileEx(
		d3ddv,								// Pointer to Direct3D device object
		texturePath,						// Path to the image to load
		info.Width,							// Texture width
		info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255),			// Transparent color
		&info,
		NULL,
		&texture);								// Created texture pointer

	if (result != D3D_OK)
	{
		OutputDebugString(L"[ERROR] CreateTextureFromFile failed\n");
		return;
	}

	DebugOut(L"[INFO] Texture loaded Ok: %s \n", texturePath);
}

void CGameObject::Update(DWORD dt)
{
}

void CGameObject::Render()
{
	CGame::GetInstance()->Draw(x, y, texture);
}


CGameObject::~CGameObject()
{
	if (texture != NULL) texture->Release();
}

void Square::Update(DWORD dt)
{
	int X = SCREEN_WIDTH - infoSquare.Width;
	int Y = SCREEN_HEIGHT - infoSquare.Height;
	//Eclipse
	/*const double pi = 3.1415926535897;
	if (t < 2 * pi) {
		t += 0.1;
		x = 600 * cos(t) +center_X;
		y = 300 * sin(t) +center_Y;
	}
	if (t > 2 * pi) {
		t = 0;
	}*/

	//
	if (x < X&&y<=0) {
		x += 0.1f * dt;
	}if ((x >X) && y  <Y) {
		y += 0.1f * dt;
	}
	if ((y > Y)&&(x>=0)) {
		x -= 0.1f * dt;
	}
	if ((x <= 0) && (y >= 0)) {
		y -= 0.1f * dt;
	}
	
	
	
}
