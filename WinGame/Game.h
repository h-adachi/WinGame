#pragma once

#include <Windows.h>
#include "Hdc.h"
#include "InputList.h"

class IScene;

class Game
{
public:
	Game();
	void Create(HINSTANCE instance, int width, int height, PTCHAR title);
	LRESULT Proc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
	int Run(IScene* scene);

private:
	HWND mHwnd;
	Hdc mHdc;
	InputList mInputs;
};
