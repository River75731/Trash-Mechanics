#pragma once
#include "..\Common\Common.h"
#include "..\ViewModel\ViewModel.h"

class ClearUserRigidBodyCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;

public:
	ClearUserRigidBodyCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel

	~ClearUserRigidBodyCommand() {}
	void pass();
};