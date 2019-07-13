#pragma once

#include "..\Common\Common.h"
#include "..\ViewModel\ViewModel.h"


class UpdateRigidBodyDataCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;

public:
	UpdateRigidBodyDataCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel
	~UpdateRigidBodyDataCommand() {}
	void pass();
};