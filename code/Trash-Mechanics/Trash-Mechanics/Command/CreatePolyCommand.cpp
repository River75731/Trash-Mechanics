#include "CreatePolyCommand.h"

void CreatePolyCommand::pass()
{
	Poly poly = std::static_pointer_cast<PolyParameter, Parameter>(Command::param_)->getPoly(); //withdraw the data
	viewmodel->execCreatePolyCommand(poly);
}
