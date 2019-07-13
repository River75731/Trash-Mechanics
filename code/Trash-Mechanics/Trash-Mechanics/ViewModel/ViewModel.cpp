#include "ViewModel.h"
#include "../Command/CommandList.h"

void ViewModel::bind(std::shared_ptr<Model> model)
{
	this->model = model;
}

void ViewModel::bind(std::shared_ptr<View> view)
{
	this->view = view;
}

void ViewModel::bind(std::shared_ptr<Windows> windows)
{
	this->windows = windows;
}

ViewModel::ViewModel()
{
	createRigidBodyDataCommand = std::static_pointer_cast<Command, CreateRigidBodyDataCommand>
		(std::shared_ptr<CreateRigidBodyDataCommand>(new CreateRigidBodyDataCommand(std::shared_ptr<ViewModel>(this))));
	simulateTimeFlyDataCommand = std::static_pointer_cast<Command, SimulateTimeFlyDataCommand>
		(std::shared_ptr<SimulateTimeFlyDataCommand>(new SimulateTimeFlyDataCommand(std::shared_ptr<ViewModel>(this))));
	createPolyViewCommand = std::static_pointer_cast<Command, CreatePolyViewCommand>
		(std::shared_ptr<CreatePolyViewCommand>(new CreatePolyViewCommand(std::shared_ptr<ViewModel>(this))));
	
}

void ViewModel::execCreateRigidBodyDataCommand(RigidBody rb)
{
	model->createRigidBodyData(rb);
}

void ViewModel::execCreatePolyViewCommand(Poly poly, int id)
{
	//view->createPolyView(poly, id);
}

void ViewModel::execSimulateTimeFlyDataCommand(int turns)
{
	model->simulateTimeFlyData(turns);
}


std::shared_ptr<Command> ViewModel::getCreateRigidBodyDataCommand()
{
	return createRigidBodyDataCommand;
}

std::shared_ptr<Command> ViewModel::getCreatePolyViewCommand()
{
	return createPolyViewCommand;
}

std::shared_ptr<Command> ViewModel::getSimulateTimeFlyDataCommand()
{
	return simulateTimeFlyDataCommand;
}
