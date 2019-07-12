#include "Windows.h"
#include "../Command/CommandList.h"

void Windows::setCreateRigidBodyDataCommand(std::shared_ptr<Command> command)
{

	createRigidBodyDataCommand = command;
}

void Windows::test()
{
	onCreateRigidBodyTriggered(); // assume a trigger
}



void Windows::onCreateRigidBodyData(const RigidBody &rb)
{
	createRigidBodyDataCommand->set_parameters( // create command parameter from data, then set command parameter
		std::static_pointer_cast<Parameter, RigidBodyParameter>(std::shared_ptr<RigidBodyParameter>(new RigidBodyParameter(rb))));

	createRigidBodyDataCommand->pass();
}


void Windows::onCreateRigidBodyTriggered()
{

	RigidBody rb(Poly(std::vector<Vec>{Vec(10, 10), Vec(100, 100), Vec(100, 10)}), 10.0, Vec(1.0, 1.0), 0.0); //test
	onCreateRigidBodyData(rb);
}
