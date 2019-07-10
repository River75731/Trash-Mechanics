#include "Model.h"

PhysicsSpace::PhysicsSpace() {
	m_StepSize = 100; /* 100ms */
}

void PhysicsSpace::addRigidBody(Poly InputShape, double InputMass, double InputInertiaConstant, Vec InputVelocity = originPoint, double InputAngularVelocity = 0) {
	/* Default velocity = zero=vector and angular-velocity = 0 */
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