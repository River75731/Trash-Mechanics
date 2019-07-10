#include "View-Polygon.h"

void Fl_Poly::draw() {
	fl_color(m_Color);
	fl_begin_polygon();
	for (std::vector<Vec>::iterator i = m_Vertices.begin(); i != m_Vertices.end(); i++)
		fl_vertex(i->getX(), i->getY());
	fl_end_polygon();
	fl_color(FL_BLACK);
}

Fl_Poly::Fl_Poly(std::vector<Vec> InputVertices, Fl_Color InputColor) : Fl_Box(1, 1, 1, 1, "") {
	m_Vertices = InputVertices;
	m_Color = InputColor;
}

Fl_Poly::Fl_Poly(const Poly &InputPoly, Fl_Color InputColor) : Fl_Box(1, 1, 1, 1, "") {
	m_Vertices = InputPoly.getPoint();
	m_Color = InputColor;
}

Fl_Poly::Fl_Poly(const RigidBody &InputRigidBody, Fl_Color InputColor) : Fl_Box(1, 1, 1, 1, "") {
	m_Vertices = InputRigidBody.getShape().getPoint();
	m_Color = InputColor;
}

Fl_Poly::~Fl_Poly() {
	free(m_RelatedBox);
}