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
	void setForceField(const Vec &InputForce);
	void clearNonINFRigidBody();
	Vec getForceField();
	std::vector<RigidBody> getRigidBodys() const;
};


class Model
{
private:
	PhysicsSpace physicsSpace;

	std::shared_ptr<Command> updatePolyViewCommand;
	std::shared_ptr<Command> refreshViewCommand;

public:  // callback function body
	void setUpdatePolyViewCommand(std::shared_ptr<Command> command);
	void setRefreshViewCommand(std::shared_ptr<Command> command);

public:
	Model() {}
	void createRigidBodyData(const RigidBody rb);
	void adjustRigidBodyData(const RigidBody rb, const int &id);
	void deleteRigidBodyData(const int &id);
	void createInvisibleRigidBodyData(const RigidBody rb);
	void simulateTimeFlyData(const int &turns);
	void addForceFieldData(const Vec &v);
	void clearUserRigidBody();
	void test() { physicsSpace.getForceField().show(); }

private: // the funtion to send message to ViewModel
	void onCreatePolyView(const Poly &poly, const int &id);
	void onAdjustPolyView(const Poly &poly, const int &id); 
	void onDeletePolyView(const int &id);
	void onCreateInvisiblePolyView(const Poly &poly, const int &id);
	void onRefreshView();
};
