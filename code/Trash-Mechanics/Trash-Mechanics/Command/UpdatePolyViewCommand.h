#pragma once
#include "..\Common\Common.h"
#include "..\ViewModel\ViewModel.h"

class UpdatePolyViewCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;
	Poly poly_;
	int id_;
public:
	UpdatePolyViewCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel
	Poly getPoly() const;
	int getId() const;
	~UpdatePolyViewCommand() {}
	void pass();
};