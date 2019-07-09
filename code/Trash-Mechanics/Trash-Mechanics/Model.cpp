#include "Model.h"

void RigidBodyModel::applyForce(Vec NewForce) {
	m_Force += NewForce;
}

void RigidBodyModel::removeForce(Vec NewForce) {
	m_Force -= NewForce;
}

void RigidBodyModel::move(double dt) {
	/* F=ma */
}