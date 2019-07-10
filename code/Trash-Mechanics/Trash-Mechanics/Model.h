#pragma once
#include "Common.h"

class PhysicsSpace {
private:
	std::vector<RigidBody> m_RigidBodySet;
	double m_StepSize;
public:
	PhysicsSpace();
	void addRigidBody(Poly InputShape, double InputMass, double InputInertiaConstant, Vec InputVelocity, double InputAngularVelocity);
	void setStepSize(double dt);
	void flyTime(double dt);
	std::vector<RigidBody> getRigidBodys();
};