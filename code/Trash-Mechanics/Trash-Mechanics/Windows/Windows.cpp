#include "Windows.h"
#include "../Command/CommandList.h"

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

void Windows::test()
{
//	onUpdateRigidBodyTriggered(); // assume a trigger
//	onSimulateTimeFlyTriggered();
	onAddForceFieldData();
}



void Windows::onUpdateRigidBodyData(const RigidBody &rb)
{
	updateRigidBodyDataCommand->set_parameters( std::static_pointer_cast<Parameter, RigidBodyParameter>
		(std::shared_ptr<RigidBodyParameter>(new RigidBodyParameter(rb))));
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

void Windows::onUpdateRigidBodyTriggered()
{
	RigidBody rb(Poly(std::vector<Vec>{Vec(10, 10), Vec(100, 100), Vec(100, 10)}), 10.0, Vec(1.0, 1.0), 0.0); //test
	onUpdateRigidBodyData(rb);
}

void Windows::onSimulateTimeFlyTriggered()
{
	// TBD
	onSimulateTimeFlyData();
}

void Windows::onAddForceFieldTriggered()
{
	onAddForceFieldData();
}
