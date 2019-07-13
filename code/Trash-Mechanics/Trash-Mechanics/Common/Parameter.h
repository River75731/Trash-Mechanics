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
	PolyParameter(int id = 0, int actionMode = createMode, Poly poly = Poly()) :ShapeParameter(createMode, id), poly_(poly) {}
	Poly getPoly() const { return poly_; }
};


class RigidBodyParameter : public ShapeParameter
{
private:
	RigidBody rb_;
public:
	RigidBodyParameter(RigidBody rb) :ShapeParameter(), rb_(rb) {}
	RigidBody getRigidBody() const { return rb_; }
};
