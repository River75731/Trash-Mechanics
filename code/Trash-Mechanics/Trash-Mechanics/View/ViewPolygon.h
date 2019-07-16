#pragma once
#include "ViewShape.h"
#include "ViewPoint.h"

#include <vector>

class ViewPolygon :public ViewShape {
private:
	std::vector<ViewPoint> m_pointset;
	int m_edgewidth;
	Fl_Color m_edgecolor, m_fillcolor;
public:
	ViewPolygon(const ViewPolygon &ps);
	ViewPolygon(const Poly &p, const int &id, const bool &v = getVISIBLE(), const int &ew = getLINEWIDTH(), const Fl_Color &ec = getLINECOLOR(), const Fl_Color &fc = getFILLCOLOR());
	ViewPolygon(const std::vector<ViewPoint> &ps, const int &id, const bool &v = getVISIBLE(), const int &ew = getLINEWIDTH(), const Fl_Color &ec = getLINECOLOR(), const Fl_Color &fc = getFILLCOLOR());
	ViewPolygon& operator =(const ViewPolygon &vp);
	std::vector<ViewPoint> getpointset() const;
	int getedgewidth() const;
	Fl_Color getedgecolor() const;
	Fl_Color getfillcolor() const;
	bool setpointset(const std::vector<ViewPoint> &ps);
	bool setedgewidth(const int &ew = getLINEWIDTH());
	bool setedgecolor(const Fl_Color &ec = getLINECOLOR());
	bool setfillcolor(const Fl_Color &fc = getFILLCOLOR());
	bool setPolygon(const std::vector<ViewPoint> &ps, const int &id, const bool &v = getVISIBLE(), const int &ew = getLINEWIDTH(), const Fl_Color &ec = getLINECOLOR(), const Fl_Color &fc = getFILLCOLOR());
	bool setPolygon(const Poly &p, const int &id, const bool &v, const int &ew, const Fl_Color &ec, const Fl_Color &fc);
	bool setPolygon(const Poly &p);
	bool setPolygon(const std::vector<ViewPoint> &ps);
	void drawShape();
	virtual ~ViewPolygon();
};