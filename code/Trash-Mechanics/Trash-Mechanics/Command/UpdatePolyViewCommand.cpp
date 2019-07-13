#include "UpdatePolyViewCommand.h"

void UpdatePolyViewCommand::pass()
{
	Poly poly = std::static_pointer_cast<PolyParameter, Parameter>(Command::param_)->getPoly(); //withdraw the data
	int id = std::static_pointer_cast<PolyParameter, Parameter>(Command::param_)->getId();
	int actionMode = std::static_pointer_cast<PolyParameter, Parameter>(Command::param_)->getActionMode();
	viewmodel->execUpdatePolyViewCommand(poly, id, actionMode);
}