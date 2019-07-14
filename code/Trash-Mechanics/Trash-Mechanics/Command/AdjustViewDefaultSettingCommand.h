#pragma once

#include "..\Common\Common.h"
#include "..\ViewModel\ViewModel.h"


class AdjustViewDefaultSettingCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;

public:
	AdjustViewDefaultSettingCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel
	~AdjustViewDefaultSettingCommand() {}
	void pass();
};