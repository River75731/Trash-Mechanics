#include "App.h"


App::App():view(new View), model(new Model), viewmodel(new ViewModel), windows(new Windows)
{
	viewmodel->bind(model);
	viewmodel->bind(view);
	viewmodel->bind(windows);
	view->bind(windows);

	windows->setUpdateRigidBodyDataCommand(viewmodel->getUpdateRigidBodyDataCommand()); // bind the view & viewmodel command
	windows->setSimulateTimeFlyDataCommand(viewmodel->getSimulateTimeFlyDataCommand());
	windows->setAddForceFieldDataCommand(viewmodel->getAddForceFieldDataCommand());
	model->setUpdatePolyViewCommand(viewmodel->getUpdatePolyViewCommand()); // bind the view & viewmodel command
	model->setRefreshViewCommand(viewmodel->getRefreshViewCommand());
}

void App::startWorld()
{
	view->createViewWindow("Mini Mechanics");
	int w = view->getsystem().getWINDOW()->getwidth();
	int h = view->getsystem().getWINDOW()->getheight();
	int thick = 20;
	Vec bottomLeft(0, 0);
	Vec bottomRight(w, 0);
	Vec topLeft(0, h);
	Vec topRight(w, h);
	Vec dx(thick, 0);
	Vec dMx(1.5 * MarginX, 0);
	Vec dy(0, thick);
	view->resetLINECOLOR(fl_rgb_color(35, 35, 35));
	view->resetFILLCOLOR(fl_rgb_color(35, 35, 35));
	windows->onUpdateRigidBodyData(createMode, //left
		RigidBody(Poly(std::vector<Vec>{bottomLeft - dx * 10, bottomLeft + dx, topLeft + dx, topLeft - dx * 10}), INF, Vec(0, 0), 0));
	windows->onUpdateRigidBodyData(createMode, //up
		RigidBody(Poly(std::vector<Vec>{bottomLeft + dx - dy * 10, bottomRight - dx - dy * 10, bottomRight + dy - dx, bottomLeft + dy + dx}), INF, Vec(0, 0), 0));
	windows->onUpdateRigidBodyData(createMode, //right
		RigidBody(Poly(std::vector<Vec>{bottomRight + dx * 10, bottomRight - dx, topRight - dx, topRight + dx *10}), INF, Vec(0, 0), 0));
	windows->onUpdateRigidBodyData(createMode, //down
		RigidBody(Poly(std::vector<Vec>{topLeft + dx + dy *10, topRight - dx + dy * 10, topRight - dy - dx, topLeft - dy + dx}), INF, Vec(0, 0), 0));
	windows->onUpdateRigidBodyData(createMode,  //middle
		RigidBody(Poly(std::vector<Vec>{bottomRight - dMx + dy, bottomRight - dx - dMx + dy, topRight - dx - dMx - dy, topRight - dMx - dy}), INF, Vec(0, 0), 0));
	view->changeViewWindow(fl_rgb_color(50, 50, 50));
	view->resetLINECOLOR(FL_BLACK);
	view->resetFILLCOLOR(FL_WHITE);

	return;
}

