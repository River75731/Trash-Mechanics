#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <Fl_JPEG_Image.H>
#include <iostream>
#include "Common.h"

int main(int argc, char *argv[])
{
	Vec cen(5, 5), a(1, 1), b(3, 2), c(1, 3);
	cen.rotate(a, pi / 4);
	cen.show();
	b *= 1.1;
	(b / 1.1).show();
	std::vector<Vec> p{ a, b, c };
	Poly pol(cen, p);
	Vec pp(2.8, 1.9);

	Fl_Window  *window;
	Fl_Box  *box;
	window = new  Fl_Window(450, 330, "First App!");
	box = new Fl_Box(20, 40, 360, 200, "Hello World");
	box->box(FL_FLAT_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD + FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show(argc, argv);
//	std::cout << 
	return  Fl::run();
}