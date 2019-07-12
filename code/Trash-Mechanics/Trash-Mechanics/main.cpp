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
#include "View/GUI.h"

int main(int argc, char *argv[])
{
/*	int w = Fl::w() / 2, h = Fl::h() / 2;
	MyWindow window(MyPoint(w/2,h/2),w,h,"TEST",FL_WHITE);
	MySegment line1(MyPoint(100, 50), MyPoint(300 , 50), 5, FL_BLUE);
	window.add(line1);
	MyPolygon r(5, FL_GREEN, FL_RED);
	r.add(MyPoint(100, 100));
	r.add(MyPoint(100, 200));
	r.add(MyPoint(200, 200));
	fl_register_images();
	Fl_Box        box(0, 0, 1, 1);
	Fl_PNG_Image  png(".//Images//1.png");
	box.image(png);
	Fl_Box box2(100, 100, 101, 101);
	window.show();
	box2.image(png);
	window.show();
	window.add(r);
	MyCircle c1(MyPoint(w, 0), 20, 5, FL_BLUE, FL_RED);
	window.add(c1);
	int x = 300, y = 50, dx = 1, dy = 1;
	int x2 = 400, y2 = 40, dx2 = 3, dy2 = 2;
	while (1)
	{
		x2 += dx2;
		y2 += dy2;
		x += dx;
		y += dy;
		box.resize(x2, y2, 1, 1);
		c1.redirect(MyPoint(x, y), 20);
		if (y2 >= 500||y2<=20) dy2 = -dy2;
		if (x2 >= 800 || x2 <= 20) dx2 = -dx2;
		if (y >= 500 || y <= 20) dy = -dy;
		if (x >= 700 || x <= 20) dx = -dx;
		Fl::check();
		Fl::redraw();
	}
	
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

	

	ViewWindow window(400,100,800,500,"NNN Page",FL_WHITE);

	
	std::vector<ViewPolygon>p;
	PhysicsSpace world;
	double INF = 1000000000000000;
	world.addRigidBody(Poly(Vec(200, 10), std::vector<Vec>{Vec(1, 1), Vec(1, 50), Vec(800, 50), Vec(800, 1)}), INF, INF, Vec(0, 0), 0);
	world.addRigidBody(Poly(Vec(200, 10), std::vector<Vec>{Vec(1, 400), Vec(1, 450), Vec(800, 450), Vec(800, 400)}), INF, INF, Vec(0, 0), 0);
	world.addRigidBody(Poly(Vec(200, 10), std::vector<Vec>{Vec(1, 50), Vec(1, 400), Vec(50, 400), Vec(50, 1)}), INF, INF, Vec(0, 0), 0);
	world.addRigidBody(Poly(Vec(200, 10), std::vector<Vec>{Vec(700, 50), Vec(700, 400), Vec(750, 400), Vec(750, 50)}), INF, INF, Vec(0, 0), 0);
	world.addRigidBody(Poly(Vec(350, 270), std::vector<Vec>{Vec(200, 250), Vec(200, 300), Vec(400, 300), Vec(400, 250)}), 10, 20000, Vec(0, 0), -0.1);
	world.addRigidBody(Poly(Vec(250, 150), std::vector<Vec>{Vec(200, 100), Vec(250, 200), Vec(300, 100)}), 10, 10000, Vec(10, 10), 0.2);
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
		return Fl::run();
}
