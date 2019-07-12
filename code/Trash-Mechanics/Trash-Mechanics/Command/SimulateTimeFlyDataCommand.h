#pragma once

#include "..\Common\Common.h"
#include "..\ViewModel\ViewModel.h"


class SimulateTimeFlyDataCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;

public:
	SimulateTimeFlyDataCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel
	~SimulateTimeFlyDataCommand() {}
	void pass();
};