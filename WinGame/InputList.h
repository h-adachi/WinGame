#pragma once

#include <string>
#include <map>
#include "Input.h"

class InputList
{
public:
	InputList();
	void Update();
	void Append(std::string action, int code);
	void Remove(std::string action);
	void Clear();
	Input& Get(std::string action);

private:
	std::map<std::string, Input*> mInputList;
	Input mDefault;
};
