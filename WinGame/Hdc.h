#pragma once

#include <Windows.h>

class Hdc
{
public:
	Hdc();
	~Hdc();

	void Create(HWND hwnd);
	HDC GetDC();

private:
	HBITMAP mBmp;
	HDC mHdc;
};
