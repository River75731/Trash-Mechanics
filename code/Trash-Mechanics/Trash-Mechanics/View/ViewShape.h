#pragma once
#include "ViewPoint.h"

#include <FL/fl_draw.H>

#define DEFAULT_LINEWIDTH 2
#define DEFAULT_LINECOLOR FL_BLACK
#define DEFAULT_FILLCOLOR FL_WHITE
#define DEFAULT_VISIBLE true

#define MAX_LINEWIDTH 10

class ViewShape  {
private:
	int m_id;
	bool m_visible;
	static int m_DEFAULT_LINEWIDTH;
	static Fl_Color m_DEFAULT_LINECOLOR;
	static Fl_Color m_DEFAULT_FILLCOLOR;
	static bool m_DEFAULT_VISIBLE;
public:
	ViewShape(const ViewShape &vs);
	ViewShape(const int &id, const bool &v = m_DEFAULT_VISIBLE);
	ViewShape& operator =(const ViewShape &vs);
	static int getLINEWIDTH();
	static Fl_Color getLINECOLOR();
	static Fl_Color getFILLCOLOR();
	static bool getVISIBLE();
	static bool setLINEWIDTH(const int &lw);
	static bool setLINECOLOR(const Fl_Color &lc);
	static bool setFILLCOLOR(const Fl_Color &fc);
	static bool setVISIBLE(const bool &v);
	int getid() const;
	bool setid(const int &id);
	bool getvisible() const;
	bool setvisible(const bool &v);
	bool setShape(const int &id, const bool &v = m_DEFAULT_VISIBLE);
	bool setShape(const bool &v);
	virtual void drawShape() = 0;
	virtual ~ViewShape();
};