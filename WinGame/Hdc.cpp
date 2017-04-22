#include "Hdc.h"

Hdc::Hdc()
	: mHdc(NULL)
	, mBmp(NULL)
{}

Hdc::~Hdc()
{
	DeleteObject(mBmp);
	DeleteDC(mHdc);
}

void Hdc::Create(HWND hwnd)
{
	HDC hdc = ::GetDC(hwnd);
	mHdc = CreateCompatibleDC(hdc);
	RECT rect;
	GetClientRect(hwnd, &rect);
	mBmp = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
	SelectObject(mHdc, mBmp);
	ReleaseDC(hwnd, hdc);
}

HDC Hdc::GetDC()
{
	return mHdc;
}