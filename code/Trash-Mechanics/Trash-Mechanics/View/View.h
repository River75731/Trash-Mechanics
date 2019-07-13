#pragma once

#include "GUI.h"

class View
{
private:

public:

	ViewSystem m_system;


/* BASIC COMMAND */
	View();
	virtual ~View();



/* WINDOW COMMAND */

	bool createViewWindow(
		const Vec &topleft = ViewWindow::getTOPLEFT(),
		const int &w = ViewWindow::getWINWIDTH(),
		const int &h = ViewWindow::getWINHEIGHT(),
		const std::string &name = ViewWindow::getWINNAME(),
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
	Window name: New Page
	Window background color: FL_WHITE
	Window visibility: visible
*/

	bool deleteViewWindow(const std::string &name) ;
/*
	This function delete the window of specific name
*/

	bool changeViewWindow(const std::string &name) ;
/*
	This function change the operating window to a specific window
*/

	bool hideViewWindow() ;
/*
	This function set the operating window invisible
*/

	bool showViewWindow() ;
/*
	This function set the operating window visible
*/

	bool resetWINVISIBLE(const bool &v);
/*
	This function reset the default window visibility
*/

	bool resetWINTOPLEFT(const Vec &v);
/*
	This function reset the default top-left corner of window
*/

	bool resetWINWIDTH(const int &w);
/*
	This function reset the default window width
*/

	bool resetWINHEIGHT(const int &h);
/*
	This function reset the default window height
*/

	bool resetWINNAME(const std::string &name);
/*
	This function reset the default window name
*/

	bool resetWINCOLOR(const Fl_Color &c);
/*
	This function reset the default window background color
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

	bool showViewPolygon(const int &id);
/*
	This function set specific polygon visible
*/

	bool createViewSegment(
		const int &id,
		const Segment &p,
		const int &lw = ViewShape::getLINEWIDTH(),
		const Fl_Color &lc = ViewShape::getLINECOLOR(),
		const bool &v = ViewShape::getVISIBLE()
	);
/*
	This function requires parameters , especially Segment & id to create a new polygon.
	If you don't have other parameters it will use the default setting.
	You can also change the default setting by other functions below.
	Initial default settings:
	Segment line width: 2
	Segment line color: FL_BLACK
	Segment visibility: visible
*/

	bool deleteViewSegment(const int &id);
/*
	This function delete specific segment
*/

	bool changeViewSegment(const int &id, const int &lw);
/*
	This function change the linewidth of specific segment
*/

	bool changeViewSegment(const int &id, const Fl_Color &lc);
/*
	This function change the linecolor of specific segment
*/

	bool hideViewSegment(const int &id);
/*
	This function set specific segment invisible
*/

	bool showViewSegment(const int &id);
/*
	This function set specific segment visible
*/

	bool createViewCircle(
		const int &id,
		const Vec &center,
		const double &r,
		const int &ew = ViewShape::getLINEWIDTH(),
		const Fl_Color &ec = ViewShape::getLINECOLOR(),
		const Fl_Color &fc = ViewShape::getFILLCOLOR(),
		const bool &v = ViewShape::getVISIBLE()
	);
/*
	This function requires parameters , especially center & radius & id to create a new circle.
	If you don't have other parameters it will use the default setting.
	You can also change the default setting by other functions below.
	Initial default settings:
	Circle edge width: 2
	Circle edge color: FL_BLACK
	Circle fill color: FL_WHITE
	Circle visibility: visible
*/

	bool deleteViewCircle(const int &id);
/*
	This function delete specific circle
*/

	bool changeViewCircle(const int &id, const Vec &center);
/*
	This function change the center position of specific circle
*/

	bool changeViewCircle(const int &id, const double &radius);
/*
	This function change the radius of specific circle
*/

	bool changeViewCircle(const int &id, const int &lw);
/*
	This function change the linewidth of specific circle
*/

	bool changeViewCircle(const int &id, const Fl_Color &c, const bool &status);
/*
	This function change the edgecolor or fillcolor of specific circle
	status = 0 : change edgecolor
	status = 1 : change fillcolor
*/

	bool resetLINEWIDTH(const int &lw);
/*
	This function reset the default linewidth
*/

	bool resetLINECOLOR(const Fl_Color &lc);
/*
	This function reset the default linecolor
*/

	bool resetFILLCOLOR(const Fl_Color &fc);
/*
	This function reset the default fillcolor
*/

	bool resetVISIBLE(const bool &v);
/*
	This function reset the default visibility
*/


};


