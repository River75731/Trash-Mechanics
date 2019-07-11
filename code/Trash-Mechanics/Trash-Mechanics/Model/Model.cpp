#include "Model.h"

PhysicsSpace::PhysicsSpace() {
	m_StepSize = 100; /* 100ms */
}

void PhysicsSpace::addRigidBody(const RigidBody InputRigidBody) {
	m_RigidBodySet.push_back(InputRigidBody);
}

void PhysicsSpace::addRigidBody(const Poly &InputShape, const double &InputMass, const double &InputInertiaConstant, const Vec &InputVelocity, const double &InputAngularVelocity) {
	m_RigidBodySet.push_back(RigidBody(InputShape, InputMass, InputInertiaConstant, InputVelocity, InputAngularVelocity));
}

void PhysicsSpace::setStepSize(double dt) {
	m_StepSize = dt;
}

void PhysicsSpace::flyTime(double dt) {
	for (std::vector<RigidBody>::iterator i = m_RigidBodySet.begin(); i != m_RigidBodySet.end(); i++) {
		i->accelerate(dt);
		i->move(dt);
		i->rotate(dt);
	}
}

std::vector<RigidBody> PhysicsSpace::getRigidBodys() {
	return m_RigidBodySet;
}