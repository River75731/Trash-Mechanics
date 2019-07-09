#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <iostream>
#include <vector>
#include "Common.h"
#include "View-Polygon.h"

int main(int argc, char *argv[])
{
	Fl_Window  *window;
	window = new  Fl_Window(450, 330, "First App!");
	window->end();
	window->show(argc, argv);
	return  Fl::run();
}