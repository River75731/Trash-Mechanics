#include "App.h"

App::App():view(new View), model(new Model), viewmodel(new ViewModel), windows(new Windows)
{
	viewmodel->bind(model);
	viewmodel->bind(view);
	viewmodel->bind(windows);

	windows->setUpdateRigidBodyDataCommand(viewmodel->getUpdateRigidBodyDataCommand()); // bind the view & viewmodel command
	windows->setSimulateTimeFlyDataCommand(viewmodel->getSimulateTimeFlyDataCommand());
	windows->setAddForceFieldDataCommand(viewmodel->getAddForceFieldDataCommand());
	model->setUpdatePolyViewCommand(viewmodel->getUpdatePolyViewCommand()); // bind the view & viewmodel command
}

void App::StartWorld()
{
	return;
}

void App::test()
{
	//View view;
	view->createViewWindow();
	//view->m_system.getWINDOW()->show();
	//view->createViewPolygon(1, Poly(std::vector<Vec>{Vec(10, 10), Vec(100, 100), Vec(200, 50)}));
	windows->onUpdateRigidBodyData(createMode,
		RigidBody(Poly(std::vector<Vec>{Vec(1, 400), Vec(1, 450), Vec(800, 450), Vec(800, 400)}), INF, Vec(0, 0), 0));
	windows->onUpdateRigidBodyData(createMode,
		RigidBody(Poly(std::vector<Vec>{Vec(200, 600), Vec(200, 800), Vec(900, 900), Vec(900, 800)}), INF, Vec(0, 0), 0));
//	windows->onUpdateRigidBodyData(adjustMode,
//		RigidBody(Poly(std::vector<Vec>{Vec(1, 1000), Vec(1, 450), Vec(800, 450), Vec(800, 400)}), INF, Vec(0, 0), 0)
//		,1);
//	windows->onUpdateRigidBodyData(deleteMode, 1);


	//windows->onUpdateRigidBodyData(adjustMode, RigidBody(), 1);
	//windows->onUpdateRigidBodyData(deleteMode, 1);
	//getchar();
	//Fl::check();
	//Fl::redraw();	//windows->test();
	//getchar();
	//while (1) {}
	//model->test();
}

