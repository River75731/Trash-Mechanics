#pragma once
#include "ViewShape.h"

class ViewSegment : public ViewShape {
private:
	ViewPoint m_p1, m_p2;
	int m_linewidth;
	Fl_Color m_linecolor;
public:
	ViewSegment(const ViewSegment &vs);
	ViewSegment(const Segment &s, const int &id, const bool &v = DEFAULT_VISIBLE, const int &lw = DEFAULT_LINEWIDTH, const Fl_Color &lc = DEFAULT_LINECOLOR);
	ViewSegment(const ViewPoint &p1, const ViewPoint &p2, const int &id, const bool &v = DEFAULT_VISIBLE, const int &lw = DEFAULT_LINEWIDTH, const Fl_Color &lc = DEFAULT_LINECOLOR);
	ViewSegment& operator =(const ViewSegment &vs);
	ViewPoint getp1() const;
	ViewPoint getp2() const;
	int getlinewidth() const;
	Fl_Color getlinecolor() const;
	bool setp1(const ViewPoint &p1);
	bool setp2(const ViewPoint &p2);
	bool setlinewidth(const int &lw = DEFAULT_LINEWIDTH);
	bool setlinecolor(const Fl_Color &lc = DEFAULT_LINECOLOR);
	bool setSegment(const ViewPoint &p1, const ViewPoint &p2, const int &id, const bool &v = DEFAULT_VISIBLE, const int &lw = DEFAULT_LINEWIDTH, const Fl_Color &lc = DEFAULT_LINECOLOR);
	bool setSegment(const Segment &s, const int &id, const bool &v, const int &lw, const Fl_Color &lc);
	bool setSegment(const Segment &s);
	bool setSegment(const Vec &p1, const Vec &p2);
	void draw();
	virtual ~ViewSegment();
};