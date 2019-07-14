#pragma once
#include "..\Common\CommonBase.h"


class Parameter
{
private:

public:
	Parameter(){}
};

class IntParameter : public Parameter
{
private:
	int val_;
public:
	IntParameter(int val) : val_(val) {}
	int getInt() const { return val_; }
};

class VecParameter : public Parameter
{
private:
	Vec v_;
public:
	VecParameter(Vec v) : v_(v) {}
	Vec getVec() const { return v_; }
};


class ShapeParameter : public Parameter
{
private:
	int id_;
	int actionMode_;
public:
	ShapeParameter(int actionMode = createMode, int id = 0) : id_(id), actionMode_(actionMode) {}
	int getId() const { return id_; }
	int getActionMode() const { return actionMode_; }
};

class PolyParameter : public ShapeParameter
{
private:
	Poly poly_;
public:
	PolyParameter(int id, int actionMode = createMode, Poly poly = Poly()) :ShapeParameter(actionMode, id), poly_(poly) {}
	Poly getPoly() const { return poly_; }
};


class RigidBodyParameter : public ShapeParameter
{
private:
	RigidBody rb_;
public:
	RigidBodyParameter(int id, int actionMode = createMode, RigidBody rb = RigidBody()) :ShapeParameter(actionMode, id), rb_(rb) {}
	RigidBody getRigidBody() const { return rb_; }
};

class ImageSettingParameter : public ShapeParameter
{
private:
	Fl_Color lineColor_;
	Fl_Color fillColor_;
	int lineWidth_;
	bool visibility_;
public:
	ImageSettingParameter(int id, Fl_Color linecolor, Fl_Color fillcolor, int linewidth, bool visibility) :
		ShapeParameter(adjustMode, id), lineColor_(linecolor), fillColor_(fillcolor), lineWidth_(linewidth), visibility_(visibility) {}
	Fl_Color getLineColor() const { return lineColor_; }
	Fl_Color getFillColor() const { return fillColor_; }
	int getLineWidth() const { return lineWidth_; }
	bool getVisibility() const { return visibility_; }
};