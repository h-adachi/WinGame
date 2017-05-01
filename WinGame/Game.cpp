#include "IScene.h"
#include "Game.h"

LRESULT WINAPI WndProc(_In_ HWND hWnd,
	_In_ UINT Msg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam)
{
	static Game* pGame = nullptr;
	switch (Msg)
	{
		case WM_CREATE:
			{
				LPCREATESTRUCT lcs = (LPCREATESTRUCT)lParam;
				pGame = (Game*)lcs->lpCreateParams;
			}
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	if (pGame) return pGame->Proc(hWnd, Msg, wParam, lParam);
	else return DefWindowProc(hWnd, Msg, wParam, lParam);
}

Game::Game()
	:mHwnd(NULL)
{}

void Game::Create(HINSTANCE instance, int width, int height, PTCHAR title)
{
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.hInstance = instance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = title;
	RegisterClassEx(&wc);
	
	mHwnd = CreateWindow(title, title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, width, height, NULL, NULL, instance, this);
}

LRESULT Game::Proc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	if (msg == WM_PAINT)
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		BitBlt(hdc, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right, ps.rcPaint.bottom, mHdc.GetDC(), ps.rcPaint.left, ps.rcPaint.top, SRCCOPY);
		EndPaint(hwnd, &ps);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}

int Game::Run(IScene* scene)
{
	if (!mHwnd) return 0;

	mHdc.Create(mHwnd);
	scene->Enter(mInputs);

	MSG msg;
	DWORD time = GetTickCount();
	for (;;)
	{
		// メッセージ処理.
		PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
		if (msg.message == WM_QUIT) break;
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		// ゲーム処理.
		mInputs.Update();
		mHdc.Clear();
		IScene* next = scene->Update(mInputs);
		if (scene != next)
		{
			scene->Exit();
			next->Enter(mInputs);
			scene = next;
		}
		scene->Draw(mHdc.GetDC());
		InvalidateRect(mHwnd, NULL, TRUE);

		// Loop待機.
		DWORD now = GetTickCount();
		time += 16;
		if (now < time) Sleep(time - now);
		time = now;
	}

	delete scene;
	return 0;
}
