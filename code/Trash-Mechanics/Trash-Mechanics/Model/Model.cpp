#include "Model.h"

PhysicsSpace::PhysicsSpace() {
	m_StepSize = DEFAULT_STEPSIZE; /* 10ms */
	m_Force = originPoint;
}

void PhysicsSpace::addRigidBody(const RigidBody InputRigidBody) {
	if(m_RigidBodySet.size()<RB_MAXN) m_RigidBodySet.push_back(InputRigidBody);
	else printf("You cannot have more than %d rigid bodies.", RB_MAXN);
}

void PhysicsSpace::addRigidBody(const Poly &InputShape, const double &InputMass, const Vec &InputVelocity, const double &InputAngularVelocity) {
	m_RigidBodySet.push_back(RigidBody(InputShape, InputMass, InputVelocity, InputAngularVelocity));
}

void PhysicsSpace::deleteRigidBody(const int & InputId) {
	for (std::vector<RigidBody>::iterator i = m_RigidBodySet.begin(); i != m_RigidBodySet.end(); ) {
		if (i->getId() == InputId)
			i = m_RigidBodySet.erase(i);
		else
			i++;
	}
}

void PhysicsSpace::setStepSize(const double &dt) {
	m_StepSize = dt;
}

void PhysicsSpace::goStep(const int &n) {
	for (int i = 0; i < n; i++) {
		for (std::vector<RigidBody>::iterator i = m_RigidBodySet.begin(); i != m_RigidBodySet.end(); i++) {			
			if (i->m() < 0.5*INF)
				i->applyForce(m_Force * i->m());
			i->move(m_StepSize);
			i->accelerate(m_StepSize);		
			i->rotate(m_StepSize);
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

void PhysicsSpace::setForceField(const Vec & InputForce)
{
	m_Force = InputForce;
}

void PhysicsSpace::clearNonINFRigidBody()
{
	for (std::vector<RigidBody>::iterator i = m_RigidBodySet.begin(); i != m_RigidBodySet.end(); ) {
		if (i->m() < 0.5 * INF)
			i = m_RigidBodySet.erase(i);
		else
			i++;
	}
}

Vec PhysicsSpace::getForceField() {
	return m_Force;
}

std::vector<RigidBody> PhysicsSpace::getRigidBodys() const{
	return m_RigidBodySet;
}



void Model::createRigidBodyData(const RigidBody rb)
{
	physicsSpace.addRigidBody(rb);
	onCreatePolyView(rb.getShape(), rb.getIdCount());
}

void Model::adjustRigidBodyData(const RigidBody rb, const int & id)
{
	physicsSpace.deleteRigidBody(id);
	physicsSpace.addRigidBody(rb);
	onAdjustPolyView(rb.getShape(), id);
}

void Model::deleteRigidBodyData(const int & id)
{
	physicsSpace.deleteRigidBody(id);
	onDeletePolyView(id);
}

void Model::createInvisibleRigidBodyData(const RigidBody rb)
{
	physicsSpace.addRigidBody(rb);
	onCreateInvisiblePolyView(rb.getShape(), rb.getIdCount());
}

void Model::simulateTimeFlyData(const int &turns)
{
	physicsSpace.goStep(turns);
	std::vector<RigidBody> RigidBodySet = physicsSpace.getRigidBodys();
	for (std::vector<RigidBody>::iterator i = RigidBodySet.begin(); i != RigidBodySet.end(); i++) 
	{
		if (i->m() < 0.5 * INF)
			onAdjustPolyView(i->getShape(), i->getId());
	}
	onRefreshView();
}

void Model::addForceFieldData(const Vec & v)
{
	physicsSpace.addForceField(v);
}


void Model::clearUserRigidBody()
{
	std::vector<RigidBody> rbs = physicsSpace.getRigidBodys();
	for (std::vector<RigidBody>::iterator i = rbs.begin(); i != rbs.end(); i++) {
		if (i->m() < 0.5 * INF)
			onDeletePolyView(i->getId());
	}
	physicsSpace.clearNonINFRigidBody();
	physicsSpace.setForceField(originPoint);
	onRefreshView();
}


void Model::setUpdatePolyViewCommand(std::shared_ptr<Command> command)
{
	updatePolyViewCommand = command;
}

void Model::setRefreshViewCommand(std::shared_ptr<Command> command)
{
	refreshViewCommand = command;
}

void Model::onCreatePolyView(const Poly &poly, const int &id)
{
	updatePolyViewCommand->set_parameters( std::static_pointer_cast<Parameter, PolyParameter>
		(std::shared_ptr<PolyParameter>(new PolyParameter(id, createMode, poly))));
	updatePolyViewCommand->pass();
}

void Model::onAdjustPolyView(const Poly &poly, const int &id)
{
	updatePolyViewCommand->set_parameters(std::static_pointer_cast<Parameter, PolyParameter>
		(std::shared_ptr<PolyParameter>(new PolyParameter(id, adjustMode, poly))));
	updatePolyViewCommand->pass();
}

void Model::onDeletePolyView(const int &id)
{
	updatePolyViewCommand->set_parameters(std::static_pointer_cast<Parameter, PolyParameter>
		(std::shared_ptr<PolyParameter>(new PolyParameter(id, deleteMode))));
	updatePolyViewCommand->pass();
}

void Model::onCreateInvisiblePolyView(const Poly & poly, const int & id)
{
	updatePolyViewCommand->set_parameters(std::static_pointer_cast<Parameter, PolyParameter>
		(std::shared_ptr<PolyParameter>(new PolyParameter(id, createInvisibleMode, poly))));
	updatePolyViewCommand->pass();
}

void Model::onRefreshView()
{
	refreshViewCommand->pass();
}


