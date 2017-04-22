#include "SceneTitle.h"
#include "SceneGame.h"

void SceneGame::Enter(InputList& inputs)
{
	inputs.Clear();
	inputs.Append("enter", VK_RETURN);
}

void SceneGame::Exit()
{

}

IScene* SceneGame::Update(InputList& inputs)
{
	IScene* scene = this;
	if (inputs.Get("enter").isPress())
	{
		scene = new SceneTitle();
	}
	return scene;
}

void SceneGame::Draw(HDC hdc)
{
	TextOut(hdc, 0, 0, L"Game", 4);
}
