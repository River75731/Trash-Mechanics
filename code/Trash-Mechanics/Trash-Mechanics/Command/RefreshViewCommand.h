#pragma once

#include "..\Common\Common.h"
#include "..\ViewModel\ViewModel.h"


class RefreshViewCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;

public:
	RefreshViewCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel
	~RefreshViewCommand() {}
	void pass();
};