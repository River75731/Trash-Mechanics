#pragma once
#include "..\Common\CommonBase.h"


class Parameter
{
private:

public:
	Parameter(){}
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