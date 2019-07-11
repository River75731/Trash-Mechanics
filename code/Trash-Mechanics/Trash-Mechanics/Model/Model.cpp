#include "Model.h"

PhysicsSpace::PhysicsSpace() {
	m_StepSize = 0.01; /* 100ms */
	m_Force = originPoint;
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

void PhysicsSpace::flyTime(int n) {
	while (n--) {
		for (std::vector<RigidBody>::iterator i = m_RigidBodySet.begin(); i != m_RigidBodySet.end(); i++) {
			i->applyForce(m_Force);
			i->accelerate(m_StepSize);
			i->move(m_StepSize);
			i->rotate(0);
		}
		/* Collision */
		for (std::vector<RigidBody>::iterator hsRB = m_RigidBodySet.begin(); hsRB != m_RigidBodySet.end(); hsRB++) {
			for (std::vector<RigidBody>::iterator inRB = m_RigidBodySet.begin(); inRB != m_RigidBodySet.end(); inRB++) {
				if (hsRB == inRB) continue;
				hsRB->collide(*inRB);
			}
		}
	}
}

void PhysicsSpace::addForceField(const Vec & InputForce) {
	m_Force += InputForce;
}

std::vector<RigidBody> PhysicsSpace::getRigidBodys() {
	return m_RigidBodySet;
}