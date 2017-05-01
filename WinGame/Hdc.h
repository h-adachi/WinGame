#pragma once

#include <Windows.h>

class Hdc
{
public:
	Hdc();
	~Hdc();

	void Create(HWND hwnd);
	HDC GetDC();
	void Clear();

private:
	HBITMAP mBmp;
	HDC mHdc;
	RECT mRect;
};
