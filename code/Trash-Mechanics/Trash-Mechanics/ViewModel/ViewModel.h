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

	std::shared_ptr<Command> updateRigidBodyDataCommand;
	std::shared_ptr<Command> updatePolyViewCommand;
	std::shared_ptr<Command> simulateTimeFlyDataCommand;
	std::shared_ptr<Command> addForceFieldDataCommand;
	std::shared_ptr<Command> refreshViewCommand;

public: // the function to be binded with setfuntion in view
	std::shared_ptr<Command> getUpdateRigidBodyDataCommand();
	std::shared_ptr<Command> getUpdatePolyViewCommand();
	std::shared_ptr<Command> getSimulateTimeFlyDataCommand();
	std::shared_ptr<Command> getAddForceFieldDataCommand();
	std::shared_ptr<Command> getRefreshViewCommand();

public: // the functions for ViewModel to control Model

	void execUpdateRigidBodyDataCommand(const RigidBody &rb, const int &id, const int &actionMode);
	void execUpdatePolyViewCommand(Poly poly, int id, int actionMode);
	void execSimulateTimeFlyDataCommand(int turns);
	void execAddForceFieldDataCommand(Vec v);
	void execRefreshViewCommand();
};