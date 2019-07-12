#pragma once
#include "..\Common\Common.h"
#include "..\ViewModel\ViewModel.h"

class CreatePolyViewCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;

public:
	CreatePolyViewCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel

	~CreatePolyViewCommand() {}
	void pass();
};