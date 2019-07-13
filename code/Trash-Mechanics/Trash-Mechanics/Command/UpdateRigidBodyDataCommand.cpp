#include "UpdateRigidBodyDataCommand.h"

void UpdateRigidBodyDataCommand::pass()
{
	RigidBody rb = std::static_pointer_cast<RigidBodyParameter, Parameter>(Command::param_)->getRigidBody(); //withdraw the data
	int id = std::static_pointer_cast<RigidBodyParameter, Parameter>(Command::param_)->getId();
	int actionMode = std::static_pointer_cast<RigidBodyParameter, Parameter>(Command::param_)->getActionMode();
	viewmodel->execUpdateRigidBodyDataCommand(rb, id, actionMode);
}