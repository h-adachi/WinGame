#pragma once

#include <Windows.h>

class IDraw
{
public:
	virtual ~IDraw() {};
	virtual void Draw(HDC hdc) = 0;
};
