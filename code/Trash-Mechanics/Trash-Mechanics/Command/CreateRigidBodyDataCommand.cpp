#include "CreateRigidBodyDataCommand.h"

void CreateRigidBodyDataCommand::pass()
{
	RigidBody rb = std::static_pointer_cast<RigidBodyParameter, Parameter>(Command::param_)->getRigidBody(); //withdraw the data
	viewmodel->execCreateRigidBodyDataCommand(rb);
}
