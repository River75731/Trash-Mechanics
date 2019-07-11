#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <Fl_PNG_Image.H>
#include <Fl_Shared_Image.H>
#include <iostream>
#include <vector>
#include "Common/Common.h"
#include "Others/View-Polygon.h"
#include "ViewModel/MyFLTK.h"
#include "Model/Model.h"
int main()
{
	int w = Fl::w() / 2, h = Fl::h() / 2;

	Fl_Window *window = new Fl_Window(800, 600);

	Poly pa = Poly(Vec(100, 70), std::vector<Vec>{Vec(50, 50), Vec(150, 50), Vec(150, 150)});

	Poly pb = Poly(Vec(180, 180), std::vector<Vec>{Vec(100, 140), Vec(200, 140), Vec(200, 200), Vec(100, 200)});

	pa.inPoly_PolyVec(pb);

	pa.getInterPoint(pb);

	pa.getInterSegment(pb);

	//b.collide(a);

	window->show();

	return Fl::run();
}
