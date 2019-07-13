#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <iostream>
#include <vector>
#include "Common/CommonBase.h"
//#include "Others/View-Polygon.h"
//#include "View/MyFLTK.h"
#include "Model/Model.h"
#include "View/View.h"
#include "App/App.h"

int main(int argc, char *argv[])
{	
	//window.color(FL_RED);
	/*Fl_Window     win(720, 486);
	fl_register_images();
	win.show();
	//MyWindow win;
	Fl_Box        box(0,0,400,400);
	Fl_PNG_Image  png(".//Images//1.png");
	box.image(png);
	win.redraw();
	win.show();
	win.resize(50, 100, 400, 400);*/

	
//	Poly pp(std::vector<Vec>{Vec(1, 1), Vec(2, 1), Vec(2, 2), Vec(1, 2)});
	//pp.getCenterPoint().show();
	//getTriangleCenter(Vec(1, 1), Vec(1, 50), Vec(800, 50)).show();
	//std::cout << getTriangleArea(Vec(1, 1), Vec(2, 2), Vec(2, 3)) << std::endl;
	//system("pause");
	/*
	ViewWindow window(400, 100, 800, 500, 1, "NNN Page", FL_BLACK);

	
	std::vector<ViewPolygon>p;
	PhysicsSpace world;
	double INF = 1000000000000000;
	std::cout << '!';
	world.addRigidBody(Poly(std::vector<Vec>{Vec(1, 1), Vec(1, 50), Vec(800, 50), Vec(800, 1)}), INF, Vec(0, 0), 0);
	std::cout << '!';
	world.addRigidBody(Poly(std::vector<Vec>{Vec(1, 400), Vec(1, 450), Vec(800, 450), Vec(800, 400)}), INF, Vec(0, 0), 0);
	world.addRigidBody(Poly(std::vector<Vec>{Vec(1, 50), Vec(1, 400), Vec(50, 400), Vec(50, 1)}), INF, Vec(0, 0), 0);
	world.addRigidBody(Poly(std::vector<Vec>{Vec(700, 50), Vec(700, 400), Vec(750, 400), Vec(750, 50)}), INF, Vec(0, 0), 0);
	world.addRigidBody(Poly(std::vector<Vec>{Vec(200, 250), Vec(200, 300), Vec(400, 300), Vec(400, 250)}), 10, Vec(0, 0), -0.1);
	world.addRigidBody(Poly(std::vector<Vec>{Vec(200, 100), Vec(250, 200), Vec(300, 100)}), 10, Vec(10, 10), 0.2);
	//world.addRigidBody(Poly(Vec(250, 150), std::vector<Vec>{Vec(200, 100), Vec(250, 200), Vec(300, 100)}), 10, 10000, Vec(10, 10), 0.2);
	int n = world.getRigidBodys().size();
	for (int i = 0; i < n; i++) {
		world.getRigidBodys()[i].cmdPrint();
		p.push_back(ViewPolygon(world.getRigidBodys()[i].getShape(), world.getRigidBodys()[i].getId()));
	}
	for (int i = 0; i < n; i++) {
		window.attach(p[i]);
	}


	window.show();
	window.setcolor(FL_YELLOW);

	while (1)
	{
		world.goStep(1);
		std::vector<RigidBody> drawvec=world.getRigidBodys();
		for (int i = 0; i < n; i++) {
			p[i].setPolygon(drawvec[i].getShape());
		}
		Fl::check();
		Fl::redraw();
	}
	{
		std::shared_ptr<int> p1(new(int));
		std::shared_ptr<in/t> p2(p1);

	}*/
	
	/*
	App app;
	app.test();
	std::cout << "success!\n";
	system("PAUSE");
	*/
	
	//View view;
	//view.createViewWindow();
	////view.m_system.getWINDOW()->show();
	//view.createViewWindow(Vec(900,500),700,600,"MIRACLE!!!");
	//view.createViewPolygon(1, Poly(std::vector<Vec>{Vec(10, 10), Vec(100, 100), Vec(200, 50)}));
	App app;
	app.test();

	/*
	
	ViewSystem sys;
	ViewPolygon poly1(Poly(std::vector<Vec>{Vec(10, 10), Vec(100, 100), Vec(200, 50)}), 1);
	sys.getWINDOW()->attach(poly1);
	sys.simpledraw();
	sys.getWINDOW()->show();
	*/
	/*
	View view;
	view.createViewPolygon(1, Poly(std::vector<Vec>{Vec(10, 10), Vec(100, 100), Vec(200, 50)}));
	system("pause");
	std::cout << "YEAH" << std::endl;*/
	return Fl::run();
}
