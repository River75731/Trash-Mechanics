#pragma once
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <vector>
#include "../Common/Common.h"

class Fl_Poly :public Fl_Box {
protected:
	std::vector<Vec> m_Vertices;
	Fl_Color m_Color;
	Fl_Box * m_RelatedBox;
	void draw();
	/* Overwrite Fl_box::draw() */
public:
	Fl_Poly(std::vector<Vec> InputVertices, Fl_Color InputColor = FL_BLACK);
	Fl_Poly(const Poly &InputPoly, Fl_Color InputColor = FL_BLACK);
	Fl_Poly(const RigidBody &InputRigidBody, Fl_Color InputColor = FL_BLACK);
	/* First creates an box and then overwrite its draw() */
	~Fl_Poly();
};
/*
  * ----- Sample code of Fl_Poly -----
  create a black polygon using vertices in v1:
  >>> Fl_Poly *p1 = new Fl_Poly(v1);
  create a red polygon using vertices in v2: new Fl_Poly(v2,FL_RED)"
  >>> Fl_Poly *p2 = new Fl_Poly(v2);
  delete a polygon:
  >>> free(p1);
*/