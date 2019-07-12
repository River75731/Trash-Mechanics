#pragma once
#include "../Common/Common.h"

const int RB_MAXN = 100;
const double DEFAULT_STEPSIZE = 0.1;

class PhysicsSpace {
private:
	std::vector<RigidBody> m_RigidBodySet;
	Vec m_Force;
	double m_StepSize;
public:
	PhysicsSpace();
	void addRigidBody(const RigidBody InputRigidBody);
	void addRigidBody(const Poly &InputShape, const double &InputMass, const Vec &InputVelocity, const double &InputAngularVelocity);
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
	PhysicsSpace physicsSpace;

public:
	Model() {}
	void createRigidBodyData(RigidBody rb);
	void simulateTimeFlyData(int turns);
	void test() {}

public:  // callback function body
	void setCreatePolyViewCommand(std::shared_ptr<Command> command);

private: // the funtion to send message to ViewModel
	std::shared_ptr<Command> createPolyViewCommand;
	void onCreatePolyView(const Poly &poly, const int &id); // the real data(Poly)
	void onCreatePolyViewTriggered();
};
