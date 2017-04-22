#pragma once

#include "IDraw.h"
#include "IScene.h"

class SceneGame : public IScene
{
	void Enter(InputList& inputs);
	void Exit();
	IScene* Update(InputList& inputs);
	void Draw(HDC hdc);
};
