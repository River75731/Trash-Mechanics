#include "CreatePolyViewCommand.h"
Poly CreatePolyViewCommand::getPoly() const
{
	return poly_;
}
int CreatePolyViewCommand::getId() const
{
	return id_;
}
void CreatePolyViewCommand::pass()
{
	Poly poly = std::static_pointer_cast<PolyParameter, Parameter>(Command::param_)->getPoly(); //withdraw the data
	int id = std::static_pointer_cast<PolyParameter, Parameter>(Command::param_)->getId();
	viewmodel->execCreatePolyViewCommand(poly, id);
}