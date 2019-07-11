#include "ViewModel.h"
#include "../Command/Command-List.h"

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
	createPolyCommand = std::static_pointer_cast<Command, CreatePolyCommand>
		(std::shared_ptr<CreatePolyCommand>(new CreatePolyCommand(std::shared_ptr<ViewModel>(this))));
}

void ViewModel::execCreatePolyCommand(Poly poly)
{
	model->createPoly(poly);
}
std::shared_ptr<Command> ViewModel:: getCreatePolyCommand()
{
	return createPolyCommand;
}