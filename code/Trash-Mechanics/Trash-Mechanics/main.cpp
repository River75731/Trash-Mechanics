#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <iostream>
#include <vector>
#include "Common/CommonBase.h"
#include "Model/Model.h"
#include "View/View.h"
#include "App/App.h"

int main(int argc, char *argv[])
{
	App app;
	app.startWorld();
	return Fl::run();
}
