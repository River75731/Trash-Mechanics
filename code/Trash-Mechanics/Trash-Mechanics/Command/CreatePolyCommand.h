#pragma once
#include "..\Common\CommandBase.h"
#include "..\ViewModel\ViewModel.h"

class CreatePolyCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;

public:
	CreatePolyCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel

	~CreatePolyCommand() {}
	void pass();
};

