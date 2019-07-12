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
	ShapeParameter(int id) : id_(id) {}
	int getId() const { return id_; }
};

class PolyParameter : public ShapeParameter
{
private:
	Poly poly_;
public:
	PolyParameter(int id, Poly poly) :ShapeParameter(id), poly_(poly) {}
	Poly getPoly() const { return poly_; }
};