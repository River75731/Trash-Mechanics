#pragma once
#include "..\Common\Common.h"
#include "..\ViewModel\ViewModel.h"

class UpdatePolyViewCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;

public:
	UpdatePolyViewCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel

	~UpdatePolyViewCommand() {}
	void pass();
};