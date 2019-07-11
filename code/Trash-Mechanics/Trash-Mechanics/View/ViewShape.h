#pragma once
#include "ViewPoint.h"

#include <FL/fl_draw.H>

#define DEFAULT_LINEWIDTH 2
#define DEFAULT_LINECOLOR FL_BLACK
#define DEFAULT_FILLCOLOR FL_WHITE
#define DEFAULT_VISIBLE true

class ViewShape  {
private:
	int m_id;
	bool m_visible;
public:
	ViewShape(const ViewShape &vs);
	ViewShape(const int &id,const bool &v=DEFAULT_VISIBLE);
	ViewShape& operator =(const ViewShape &vs);
	int getid() const;
	bool setid(const int &id);
	bool getvisible() const;
	bool setvisible(const bool &v);
	bool setShape(const int &id, const bool &v = DEFAULT_VISIBLE);
	bool setShape(const bool &v);
	virtual void draw() = 0;
	virtual ~ViewShape();
};