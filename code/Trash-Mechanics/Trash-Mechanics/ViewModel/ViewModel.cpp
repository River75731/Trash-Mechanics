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
	updateRigidBodyDataCommand = std::static_pointer_cast<Command, UpdateRigidBodyDataCommand>
		(std::shared_ptr<UpdateRigidBodyDataCommand>(new UpdateRigidBodyDataCommand(std::shared_ptr<ViewModel>(this))));
	simulateTimeFlyDataCommand = std::static_pointer_cast<Command, SimulateTimeFlyDataCommand>
		(std::shared_ptr<SimulateTimeFlyDataCommand>(new SimulateTimeFlyDataCommand(std::shared_ptr<ViewModel>(this))));
	updatePolyViewCommand = std::static_pointer_cast<Command, UpdatePolyViewCommand>
		(std::shared_ptr<UpdatePolyViewCommand>(new UpdatePolyViewCommand(std::shared_ptr<ViewModel>(this))));
	
}

void ViewModel::execUpdateRigidBodyDataCommand(const RigidBody &rb, const int &id, const int &actionMode)
{
	switch (actionMode)
	{
	case createMode:
		model->createRigidBodyData(rb);
		break;
	case deleteMode:
		model->deleteRigidBodyData(id);		
		break;
	case adjustMode:
		model->adjustRigidBodyData(rb, id);
		break;
	}
}

void ViewModel::execUpdatePolyViewCommand(Poly poly, int id, int actionMode)
{
	switch (actionMode)
	{
	case createMode:
		view->createViewPolygon(id, poly);
		break;
	case deleteMode:
	//	view->deleteViewPolygon(id);
		break;
	case adjustMode:
	//	view->changeViewPolygon(id, poly);
		break;
	}
}

void ViewModel::execSimulateTimeFlyDataCommand(int turns)
{
	model->simulateTimeFlyData(turns);
}


std::shared_ptr<Command> ViewModel::getUpdateRigidBodyDataCommand()
{
	return updateRigidBodyDataCommand;
}

std::shared_ptr<Command> ViewModel::getUpdatePolyViewCommand()
{
	return updatePolyViewCommand;
}

std::shared_ptr<Command> ViewModel::getSimulateTimeFlyDataCommand()
{
	return simulateTimeFlyDataCommand;
}
