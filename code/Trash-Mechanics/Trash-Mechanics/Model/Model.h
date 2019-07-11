#pragma once
#include "../Common/Common.h"

class PhysicsSpace {
private:
	std::vector<RigidBody> m_RigidBodySet;
	double m_StepSize;
public:
	PhysicsSpace();
	void addRigidBody(const RigidBody InputRigidBody);
	void addRigidBody(const Poly &InputShape, const double &InputMass, const double &InputInertiaConstant, const Vec &InputVelocity, const double &InputAngularVelocity);
	void setStepSize(double dt);
	void flyTime(double dt);
	std::vector<RigidBody> getRigidBodys();
};