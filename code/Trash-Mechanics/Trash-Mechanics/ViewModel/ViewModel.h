#pragma once
#include "../Common/Common.h"
#include "../View/View.h"
#include "../Model/Model.h"
#include "../Windows/Windows.h"


class ViewModel
{
public:
	void bind(std::shared_ptr<Model> model);
	void bind(std::shared_ptr<View> view);
	void bind(std::shared_ptr<Windows> windows);
	ViewModel();
private:
	std::shared_ptr<Model> model;
	std::shared_ptr<View> view;
	std::shared_ptr<Windows> windows;

	std::shared_ptr<Command> createRigidBodyDataCommand;
	std::shared_ptr<Command> createPolyViewCommand;
	std::shared_ptr<Command> simulateTimeFlyDataCommand;

public: // the function to be binded with setfuntion in view
	//std::shared_ptr<Command> getCreatePolyCommand();
	std::shared_ptr<Command> getCreateRigidBodyDataCommand();
	std::shared_ptr<Command> getCreatePolyViewCommand();
	std::shared_ptr<Command> getSimulateTimeFlyDataCommand();


public: // the functions for ViewModel to control Model

	void execCreateRigidBodyDataCommand(RigidBody rb);
	void execCreatePolyViewCommand(Poly poly, int id);
	void execSimulateTimeFlyDataCommand(int turns);
};