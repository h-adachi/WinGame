#include <Windows.h>
#include "SceneTitle.h"
#include "Game.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	Game game;
	game.Create(hInstance, 640, 480, L"Game");
	return game.Run(new SceneTitle());
}
