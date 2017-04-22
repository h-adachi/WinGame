#pragma once

#include "IDraw.h"
#include "InputList.h"

class IScene : public IDraw
{
public:
	virtual ~IScene() {}

	virtual void Enter(InputList& inputs) = 0;
	virtual void Exit() = 0;
	virtual IScene* Update(InputList& inputs) = 0;
};
