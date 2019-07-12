#pragma once

#include "..\Common\Common.h"
#include "..\ViewModel\ViewModel.h"


class CreateRigidBodyDataCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;

public:
	CreateRigidBodyDataCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel

	~CreateRigidBodyDataCommand() {}
	void pass();
};