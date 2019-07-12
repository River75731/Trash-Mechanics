#pragma once
#include "..\Common\Common.h"
#include "..\ViewModel\ViewModel.h"

class CreatePolyViewCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;
	Poly poly_;
	int id_;
public:
	CreatePolyViewCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel
	Poly getPoly() const;
	int getId() const;
	~CreatePolyViewCommand() {}
	void pass();
};