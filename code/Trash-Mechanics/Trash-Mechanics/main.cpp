#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <Fl_PNG_Image.H>
#include <Fl_Shared_Image.H>
#include <iostream>
#include <vector>
#include "Common.h"
#include "View-Polygon.h"
using namespace std;
int main(int argc, char *argv[])
{
		fl_register_images();
		Fl_Window     win(720, 486);
		Fl_Box        box(10, 10, 11, 11);
		Fl_Box box2(100, 100, 101, 101);
		Fl_PNG_Image  png(".//Images//1.png");
		box.image(png);
		box2.image(png);
		win.show();
		box2.hide();
		win.redraw();
		return(Fl::run());
}