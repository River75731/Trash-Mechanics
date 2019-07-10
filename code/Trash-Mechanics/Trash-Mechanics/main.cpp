#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <Fl_PNG_Image.H>
#include <Fl_Shared_Image.H>
#include <iostream>
#include <vector>
#include "Common.h"
#include "View-Polygon.h"
#include "ViewModel/MyFLTK.h"
#include "Model.h"

int main(int argc, char *argv[])
{

		fl_register_images();
		MyWindow* a = new MyWindow();
		Fl_Box        box(10, 10, 11, 11);
		Fl_Box box2(100, 100, 101, 101);
		Fl_PNG_Image  png(".//Images//1.png");
		box.image(png);
		box2.image(png);
		a->color(FL_RED);
		a->show();
		return(Fl::run());
}