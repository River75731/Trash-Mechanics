#include "App.h"

App::App():view(new View), model(new Model), viewmodel(new ViewModel), windows(new Windows)
{
	viewmodel->bind(model);
	windows->setCreatePolyCommand(viewmodel->getCreatePolyCommand()); // bind the view & viewmodel command
	//std::cout << "!";
}

void App::StartWorld()
{
	return;
}

void App::test()
{
	windows->test();
	model->test();
}

