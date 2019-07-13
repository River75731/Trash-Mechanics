#include "Windows.h"
#include "../Command/CommandList.h"

void Windows::setUpdateRigidBodyDataCommand(std::shared_ptr<Command> command)
{
	UpdateRigidBodyDataCommand = command;
}

void Windows::setSimulateTimeFlyDataCommand(std::shared_ptr<Command> command)
{
	simulateTimeFlyDataCommand = command;
}

void Windows::test()
{
	onUpdateRigidBodyTriggered(); // assume a trigger
	onSimulateTimeFlyTriggered();
}



void Windows::onUpdateRigidBodyData(const RigidBody &rb)
{
	UpdateRigidBodyDataCommand->set_parameters( // create command parameter from data, then set command parameter
		std::static_pointer_cast<Parameter, RigidBodyParameter>(std::shared_ptr<RigidBodyParameter>(new RigidBodyParameter(rb))));
	UpdateRigidBodyDataCommand->pass();
}

void Windows::onSimulateTimeFlyData(const int & turns)
{
	simulateTimeFlyDataCommand->set_parameters( // create command parameter from data, then set command parameter
		std::static_pointer_cast<Parameter, IntParameter>(std::shared_ptr<IntParameter>(new IntParameter(turns))));
	simulateTimeFlyDataCommand->pass();
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