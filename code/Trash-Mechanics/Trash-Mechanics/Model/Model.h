#pragma once
#include "../Common/Common.h"

const int RB_MAXN = 100;
const double DEFAULT_STEPSIZE = 0.01;

class PhysicsSpace {
private:
	std::vector<RigidBody> m_RigidBodySet;
	Vec m_Force;
	double m_StepSize;
public:
	PhysicsSpace();
	void addRigidBody(const RigidBody InputRigidBody);
	void addRigidBody(const Poly &InputShape, const double &InputMass, const double &InputInertiaConstant, const Vec &InputVelocity, const double &InputAngularVelocity);
	void deleteRigidBody(const int &InputId);
	void setStepSize(const double &dt);
	void goStep(const int &n);
	void addForceField(const Vec &InputForce);
	Vec getForceField();
	std::vector<RigidBody> getRigidBodys();
};


class Model
{
private:
	Poly poly_; //test
public:
	Model() :poly_() {}
	void createPoly(Poly poly) // receiver funtion of Model from ViewModel
	{
		poly_.setPoly(poly);
	}
	void test()
	{
		std::cout << "PointNum = " << poly_.getPointNum() << std::endl;
	}
};	