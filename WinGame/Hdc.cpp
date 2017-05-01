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

	GetClientRect(hwnd, &mRect);
	mBmp = CreateCompatibleBitmap(hdc, mRect.right, mRect.bottom);
	DeleteObject(SelectObject(mHdc, mBmp));
	ReleaseDC(hwnd, hdc);
}

void Hdc::Clear()
{
	FillRect(mHdc, &mRect, WHITE_BRUSH);
}

HDC Hdc::GetDC()
{
	return mHdc;
}
