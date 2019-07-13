#include "AddForceFieldDataCommand.h"

void AddForceFieldDataCommand::pass()
{
	Vec v = std::static_pointer_cast<VecParameter, Parameter>(Command::param_)->getVec();
	viewmodel->execAddForceFieldDataCommand(v);
}
