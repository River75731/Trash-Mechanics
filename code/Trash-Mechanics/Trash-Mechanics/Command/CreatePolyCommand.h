#pragma once
#include "..\Common\Command.h"
#include "..\ViewModel\ViewModel.h"

class CreatePolyCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;
public:
	CreatePolyCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel

	~CreatePolyCommand() {}
	void pass()
	{
		Poly poly = std::static_pointer_cast<PolyParameter, Parameter>(Command::param_)->getPoly(); //withdraw the data
		viewmodel->execCreatePolyCommand(poly);
	}
};