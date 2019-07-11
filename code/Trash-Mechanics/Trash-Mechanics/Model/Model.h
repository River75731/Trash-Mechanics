#pragma once
#include "../Common/Common.h"

const int RB_MAXN = 100;

class PhysicsSpace {
private:
	std::vector<RigidBody> m_RigidBodySet;
	Vec m_Force;
	double m_StepSize;
public:
	PhysicsSpace();
	void addRigidBody(const RigidBody InputRigidBody);
	void addRigidBody(const Poly &InputShape, const double &InputMass, const double &InputInertiaConstant, const Vec &InputVelocity, const double &InputAngularVelocity);
	void setStepSize(double dt);
	void flyTime(int n);
	void addForceField(const Vec &InputForce);
	std::vector<RigidBody> getRigidBodys();
};