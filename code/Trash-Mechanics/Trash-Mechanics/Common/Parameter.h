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
public:
	ShapeParameter(int id = 0) : id_(id) {}
	int getId() const { return id_; }
};

class PolyParameter : public ShapeParameter
{
private:
	Poly poly_;
public:
	PolyParameter(Poly poly, int id = 0) :ShapeParameter(id), poly_(poly) {}
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
