#include "RefreshViewCommand.h"

void RefreshViewCommand::pass()
{
	viewmodel->execRefreshViewCommand();
}
