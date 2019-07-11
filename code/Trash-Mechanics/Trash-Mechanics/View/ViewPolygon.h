#pragma once
#include "ViewShape.h"

#include <vector>

class ViewPolygon :public ViewShape {
private:
	std::vector<ViewPoint> m_pointset;
	int m_edgewidth;
	Fl_Color m_edgecolor, m_fillcolor;
public:
	ViewPolygon(const ViewPolygon &ps);
	ViewPolygon(const Poly &p, const int &id, const bool &v = DEFAULT_VISIBLE, const int &ew = DEFAULT_LINEWIDTH, const Fl_Color &ec = DEFAULT_LINECOLOR, const Fl_Color &fc = DEFAULT_FILLCOLOR);
	ViewPolygon(const std::vector<ViewPoint> &ps, const int &id, const bool &v = DEFAULT_VISIBLE, const int &ew = DEFAULT_LINEWIDTH, const Fl_Color &ec = DEFAULT_LINECOLOR, const Fl_Color &fc = DEFAULT_FILLCOLOR);
	ViewPolygon& operator =(const ViewPolygon &vp);
	std::vector<ViewPoint> getpointset() const;
	int getedgewidth() const;
	Fl_Color getedgecolor() const;
	Fl_Color getfillcolor() const;
	bool setpointset(const std::vector<ViewPoint> &ps);
	bool setedgewidth(const int &ew = DEFAULT_LINEWIDTH);
	bool setedgecolor(const Fl_Color &ec = DEFAULT_LINECOLOR);
	bool setfillcolor(const Fl_Color &fc = DEFAULT_FILLCOLOR);
	bool setPolygon(const std::vector<ViewPoint> &ps, const int &id, const bool &v = DEFAULT_VISIBLE, const int &ew = DEFAULT_LINEWIDTH, const Fl_Color &ec = DEFAULT_LINECOLOR, const Fl_Color &fc = DEFAULT_FILLCOLOR);
	bool setPolygon(const Poly &p, const int &id, const bool &v, const int &ew, const Fl_Color &ec, const Fl_Color &fc);
	bool setPolygon(const Poly &p);
	bool setPolygon(const std::vector<ViewPoint> &ps);
	void draw();
	virtual ~ViewPolygon();
};