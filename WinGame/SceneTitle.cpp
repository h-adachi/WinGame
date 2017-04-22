#include "SceneGame.h"
#include "SceneTitle.h"

void SceneTitle::Enter(InputList& inputs)
{
	inputs.Clear();
	inputs.Append("start", VK_SPACE);
}

void SceneTitle::Exit()
{

}

IScene* SceneTitle::Update(InputList& inputs)
{
	IScene* scene = this;
	if (inputs.Get("start").isPress())
	{
		scene = new SceneGame();
	}
	return scene;
}

void SceneTitle::Draw(HDC hdc)
{
	TextOut(hdc, 0, 0, L"Title", 5);
}
