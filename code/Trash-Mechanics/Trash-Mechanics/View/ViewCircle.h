#pragma once
#include "ViewShape.h"

class ViewCircle : public ViewShape {
private:
	ViewPoint m_center;
	int m_radius, m_edgewidth;
	Fl_Color m_edgecolor, m_fillcolor;
public:
	ViewCircle(const ViewCircle &vc);
	ViewCircle(const ViewPoint &c, const int &r, const int &id, const bool &v = DEFAULT_VISIBLE, const int &ew = DEFAULT_LINEWIDTH, const Fl_Color &ec = DEFAULT_LINECOLOR, const Fl_Color &fc = DEFAULT_FILLCOLOR);
	ViewCircle& operator = (const ViewCircle &vc);
	ViewPoint getcenter() const;
	int getradius() const;
	int getedgewidth() const;
	Fl_Color getedgecolor() const;
	Fl_Color getfillcolor() const;
	bool setcenter(const ViewPoint &c);
	bool setradius(const int &r);
	bool setedgewidth(const int &ew);
	bool setedgecolor(const Fl_Color &ec);
	bool setfillcolor(const Fl_Color &fc);
	bool setCircle(const ViewPoint &c, const int &r, const int &id, const bool &v = DEFAULT_VISIBLE, const int &ew = DEFAULT_LINEWIDTH, const Fl_Color &ec = DEFAULT_LINECOLOR, const Fl_Color &fc = DEFAULT_FILLCOLOR);
	bool setCircle(const Vec &p, const int &r, const int &id, const bool &v, const int &ew, const Fl_Color &ec, const Fl_Color &fc);
	bool setCircle(const Vec &p, const int &r);
	bool setCircle(const Vec &p);
	void drawShape();
	virtual ~ViewCircle();
};