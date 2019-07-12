#include "SimulateTimeFlyDataCommand.h"

void SimulateTimeFlyDataCommand::pass() {
	int turns = std::static_pointer_cast<IntParameter, Parameter>(Command::param_)->getInt();
	viewmodel->execSimulateTimeFlyDataCommand(turns);
}