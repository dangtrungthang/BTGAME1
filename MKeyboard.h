#pragma once
#include <dinput.h>

class MKeyboard {
	// Doi tuong nhap 
	LPDIRECTINPUT8 di8;
	// thiet bi nhap khau 
	LPDIRECTINPUTDEVICE8 did8;
	// buffer lu tru lieu lay duoc  tu thiet bi.
	// o day la ban phim nen minh dung mang char de luu
	char key_buffer[256];
	// the hien cua chuong trinh
	HINSTANCE hInstance;
	// handle cua cua so ve
	HWND h
};
