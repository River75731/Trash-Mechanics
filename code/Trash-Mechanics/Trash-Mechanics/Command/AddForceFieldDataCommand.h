#pragma once
#include "..\Common\Common.h"
#include "..\ViewModel\ViewModel.h"

class AddForceFieldDataCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;

public:
	AddForceFieldDataCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel

	~AddForceFieldDataCommand() {}
	void pass();
};