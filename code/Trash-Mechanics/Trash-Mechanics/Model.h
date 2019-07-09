#pragma once
#include "Common.h"

class RigidBodyModel {
protected:
	Poly m_Shape;
	Vec m_Force;
	Vec m_Velocity;
	double m_Mass;
	double m_InertiaConstant;
	double m_AngularVelocity;
public:
	void applyForce(Vec NewForce);
	void removeForce(Vec NewForce);
	void move(double dt);
};