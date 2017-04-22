#include "InputList.h"

typedef std::map<std::string, Input*> InputMap;

InputList::InputList()
	: mDefault(0)
{}

void InputList::Update()
{
	for (InputMap::iterator ite = mInputList.begin(); ite != mInputList.end(); ++ite)
	{
		ite->second->Update();
	}
}

void InputList::Append(std::string action, int code)
{
	InputMap::iterator ite = mInputList.find(action);
	if (ite != mInputList.end()) return;
	mInputList.insert(InputMap::value_type(action, new Input(code)));
}

void InputList::Remove(std::string action)
{
	InputMap::iterator ite = mInputList.find(action);
	if (ite == mInputList.end()) return;
	mInputList.erase(action);
	delete ite->second;
}

void InputList::Clear()
{
	for (InputMap::iterator ite = mInputList.begin(); ite != mInputList.end(); ++ite)
	{
		delete ite->second;
	}
	mInputList.clear();
}

Input& InputList::Get(std::string action)
{
	Input &result = mDefault;
	InputMap::iterator ite = mInputList.find(action);
	if (ite != mInputList.end()) result = *ite->second;
	return result;
}
