#pragma once

#include "GUI.h"

class View
{
private:

	ViewSystem m_system;
	static std::shared_ptr<Windows> windows;
	static std::shared_ptr<View> viewPtr;
public:
	static std::shared_ptr<Windows>getWindowsPtr() { return windows; }
	static std::shared_ptr<View>getViewPtr() { return viewPtr; }
	static Fl_Input *mass_Input;
	static Fl_Input *velocityX_Input;
	static Fl_Input *velocityY_Input;
	static Fl_Input *angvelocity_Input;
	static Fl_Input *forceX_Input;
	static Fl_Input *forceY_Input;
	static Fl_Multiline_Output *CMD_Output;
	static Fl_Multiline_Input *vertices_Input;
	static Fl_Button *createRB_Button;
	static bool simulating;
	static double fx;
	static double fy;
/* BASIC COMMAND */
	View();

	virtual ~View();
	void bind(std::shared_ptr<View> tempview);
	void bind(std::shared_ptr<Windows> tempwindows);

	ViewSystem & getsystem();
	void refresh();


/* WINDOW COMMAND */

	bool createViewWindow(
		const std::string &name,
		const Vec &topleft = ViewWindow::getTOPLEFT(),
		const int &w = ViewWindow::getWINWIDTH(),
		const int &h = ViewWindow::getWINHEIGHT(),
		const Fl_Color &c = ViewWindow::getWINCOLOR(),
		const bool &v = ViewWindow::getWINVISIBLE()
	);
/* 
	This function requires parameters to create a new window.
	If you don't have any parameter it will use the default setting.
	You can also change the default setting by other functions below.
	Initial default settings:
	Window's topleft corner: ViewPoint(Fl::w()/4,Fl::h()/4)
	Window width: Fl::w()/2
	Window height: Fl::h()/2
	Window background color: FL_WHITE
	Window visibility: visible
*/


/* SHAPE COMMAND */
/*
	Notice: ALL shape operation is based on the recent operating window
*/

	bool createViewPolygon(
		const int &id,
		const Poly &p,
		const int &ew = ViewShape::getLINEWIDTH(),
		const Fl_Color &ec = ViewShape::getLINECOLOR(),
		const Fl_Color &fc = ViewShape::getFILLCOLOR(),
		const bool &v = ViewShape::getVISIBLE()
	);
/*
	This function requires parameters , especially Poly & id to create a new polygon.
	If you don't have other parameters it will use the default setting.
	You can also change the default setting by other functions below.
	Initial default settings:
	Polygon edge width: 2
	Polygon edge color: FL_BLACK
	Polygon fill color: FL_WHITE
	Polygon visibility: visible
*/
	bool changeViewWindow(const Fl_Color & c);


	bool deleteViewPolygon(const int &id);
/*
	This function delete specific polygon
*/
	
	bool changeViewPolygon(const int &id, const Poly &p);
/*
	This function change the location of specific polygon
*/
	
	bool changeViewPolygon(const int &id, const int &lw);
/*
	This function change the linewidth of specific polygon
*/

	bool changeViewPolygon(const int &id, const Fl_Color &c, const bool status);
/*
	This function change the edgecolor or fillcolor of specific polygon
	status = 0 : change edgecolor
	status = 1 : change fillcolor
*/

	bool hideViewPolygon(const int &id);
/*
	This function set specific polygon invisible
*/
	bool resetFILLCOLOR(const Fl_Color &fc);
/*
	This function reset the default fillcolor
*/
	bool resetLINECOLOR(const Fl_Color & lc);

};

void onCreateRigidBodyTriggered(Fl_Widget* sender, void*);
void onSimulateTimeFlyTriggered(Fl_Widget* sender, void*);
void onApplyForceTriggered(Fl_Widget* sender, void*);
void onClearTriggered(Fl_Widget* sender, void*);
void simulate(void *sender);
void changecolor();