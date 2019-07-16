#include "Windows.h"
#include "../Command/CommandList.h"

std::shared_ptr<Windows> windowsPtr;

void Windows::setUpdateRigidBodyDataCommand(std::shared_ptr<Command> command)
{
	updateRigidBodyDataCommand = command;
}

void Windows::setSimulateTimeFlyDataCommand(std::shared_ptr<Command> command)
{
	simulateTimeFlyDataCommand = command;
}

void Windows::setAddForceFieldDataCommand(std::shared_ptr<Command> command)
{
	addForceFieldDataCommand = command;
}

void Windows::setClearUserRigidBodyCommand(std::shared_ptr<Command> command)
{
	clearUserRigidBodyCommand = command;
}





void Windows::onUpdateRigidBodyData(const int & actionMode, const RigidBody &rb, const int &id)
{
	updateRigidBodyDataCommand->set_parameters( std::static_pointer_cast<Parameter, RigidBodyParameter>
		(std::shared_ptr<RigidBodyParameter>(new RigidBodyParameter(id, actionMode, rb))));
	updateRigidBodyDataCommand->pass();
}

void Windows::onUpdateRigidBodyData(const int & actionMode, const int &id)
{
	updateRigidBodyDataCommand->set_parameters(std::static_pointer_cast<Parameter, RigidBodyParameter>
		(std::shared_ptr<RigidBodyParameter>(new RigidBodyParameter(id, actionMode, RigidBody()))));
	updateRigidBodyDataCommand->pass();
}


void Windows::onSimulateTimeFlyData(const int & turns)
{
	simulateTimeFlyDataCommand->set_parameters(std::static_pointer_cast<Parameter, IntParameter>
		(std::shared_ptr<IntParameter>(new IntParameter(turns))));
	simulateTimeFlyDataCommand->pass();
}

void Windows::onAddForceFieldData(const Vec &v)
{
	addForceFieldDataCommand->set_parameters( std::static_pointer_cast<Parameter, VecParameter>
		(std::shared_ptr<VecParameter>(new VecParameter(v))));
	addForceFieldDataCommand->pass();
}
void Windows::onClearUserRigidBodyCommand()
{
	clearUserRigidBodyCommand->pass();
}