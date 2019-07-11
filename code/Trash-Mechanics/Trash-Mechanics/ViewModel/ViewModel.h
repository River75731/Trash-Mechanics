#pragma once
#include "../Common/Common.h"
#include "../View/View.h"
#include "../Model/Model.h"
#include "../Windows/Windows.h"


class ViewModel
{
private:
	std::shared_ptr<Model> model;
	std::shared_ptr<View> view;
	//std::shared_ptr<Windows> windows;
	std::shared_ptr<Command> createPolyCommand;

public:
	void bind(std::shared_ptr<Model> model);
	void bind(std::shared_ptr<View> view);
	void bind(std::shared_ptr<Windows> windows);

	ViewModel();
public: // the functions for ViewModel to control Model
	void execCreatePolyCommand(Poly poly);

public: // the function to be binded with setfuntion in view
	std::shared_ptr<Command> getCreatePolyCommand();

};