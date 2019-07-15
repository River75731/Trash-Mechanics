#include "App.h"
#include <time.h>

App::App():view(new View), model(new Model), viewmodel(new ViewModel), windows(new Windows)
{
	viewmodel->bind(model);
	viewmodel->bind(view);
	viewmodel->bind(windows);
	view->bind(windows);
	view->bind(view);

	windows->setUpdateRigidBodyDataCommand(viewmodel->getUpdateRigidBodyDataCommand()); // bind the view & viewmodel command
	windows->setSimulateTimeFlyDataCommand(viewmodel->getSimulateTimeFlyDataCommand());
	windows->setAddForceFieldDataCommand(viewmodel->getAddForceFieldDataCommand());
	windows->setClearUserRigidBodyCommand(viewmodel->getClearUserRigidBodyCommand());

	model->setUpdatePolyViewCommand(viewmodel->getUpdatePolyViewCommand()); // bind the view & viewmodel command
	model->setRefreshViewCommand(viewmodel->getRefreshViewCommand());
}

void App::startWorld()
{
	srand((unsigned int)time(0));
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
		RigidBody(Poly(std::vector<Vec>{bottomLeft - dx * 100 - dy * 100, bottomLeft + dx - dy * 100, topLeft + dx + dy * 100, topLeft - dx * 100 + dy * 100}), INF, Vec(0, 0), 0));
	windows->onUpdateRigidBodyData(createMode, //up
		RigidBody(Poly(std::vector<Vec>{bottomLeft - dx * 100 - dy * 100, bottomRight + dx * 100 - dy * 100, bottomRight + dy + dx * 100, bottomLeft + dy - dx * 100}), INF, Vec(0, 0), 0));
	windows->onUpdateRigidBodyData(createMode, //right
		RigidBody(Poly(std::vector<Vec>{bottomRight + dx * 100 , bottomRight - dx, topRight - dx, topRight + dx * 100}), INF, Vec(0, 0), 0));
	windows->onUpdateRigidBodyData(createMode, //down
		RigidBody(Poly(std::vector<Vec>{topLeft - dx * 100 + dy *100, topLeft - dx * 100 - dy, topRight + dx * 100 - dy, topRight + dx * 100 + dy * 100}), INF, Vec(0, 0), 0));
	windows->onUpdateRigidBodyData(createMode,  //middle
		RigidBody(Poly(std::vector<Vec>{bottomRight - dMx - dx + dy, bottomRight - dMx + dy, topRight  - dMx - dy, topRight - dMx - dx - dy}), INF, Vec(0, 0), 0));
	windows->onUpdateRigidBodyData(createInvisibleMode, // invisible rectangle
		RigidBody(Poly(std::vector<Vec>{bottomRight - dx - dMx - dy * 100, bottomRight - dy * 100 + dx * 100, topRight + dy * 100 + dx * 100, topRight - dx - dMx + dy * 100}), INF, Vec(0, 0), 0));
	view->changeViewWindow(fl_rgb_color(50, 50, 50));
	view->resetLINECOLOR(FL_BLACK);
	view->resetFILLCOLOR(FL_WHITE);
	view->refresh();

	return;
}

