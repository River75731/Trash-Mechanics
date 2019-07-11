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



	Poly pa = Poly(Vec(100, 70), std::vector<Vec>{Vec(50, 50), Vec(150, 150), Vec(150, 50)});



	Poly pb = Poly(Vec(180, 180), std::vector<Vec>{Vec(100, 140), Vec(100, 200), Vec(200, 200), Vec(200, 140)});

	//RigidBody a = RigidBody(pa, 10, 50, Vec(10, 10), 0);

	//RigidBody b = RigidBody(pb, 10, 50, Vec(10, 10), 0);



	printf("Is (200,200) in a? %d\n", pa.inPoly_Vec(Vec(200, 200)));

	printf("Is b inserting into a? %d\n", pa.inPoly_PolyVec(pb));
	printf("Is a inserting into b? %d\n", pb.inPoly_PolyVec(pa));

	Vec intpnt = pa.getInterPoint(pb);

	printf("InterPoint: (%.2lf,%.2lf)\n", intpnt.getX(), intpnt.getY());
	intpnt = pb.getInterPoint(pa);

	printf("InterPoint: (%.2lf,%.2lf)\n", intpnt.getX(), intpnt.getY());

	Segment sg(pb.getInterSegment(pa));
	sg.getV1().show(); sg.getV2().show();
	//printf("InterSegment: (%.2lf,%.2lf), (%.2lf,%.2lf)\n", sg.

	//b.collide(a);

	window->show();

	return Fl::run();

}
