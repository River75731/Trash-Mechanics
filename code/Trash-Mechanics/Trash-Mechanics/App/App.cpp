#include "App.h"

App::App():view(new View), model(new Model), viewmodel(new ViewModel), windows(new Windows)
{
	viewmodel->bind(model);
	viewmodel->bind(view);
	viewmodel->bind(windows);

	windows->setCreateRigidBodyDataCommand(viewmodel->getCreateRigidBodyDataCommand()); // bind the view & viewmodel command
	windows->setSimulateTimeFlyDataCommand(viewmodel->getSimulateTimeFlyDataCommand());
	model->setCreatePolyViewCommand(viewmodel->getCreatePolyViewCommand()); // bind the view & viewmodel command
}

void App::StartWorld()
{
	return;
}

void App::test()
{
	windows->test();
	//model->test();
}

