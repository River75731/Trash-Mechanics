#pragma once

#include "../Common/Common.h"


class Windows
{

public:
	Windows() {}

private:
	std::shared_ptr<Command> createRigidBodyDataCommand;
	std::shared_ptr<Command> simulateTimeFlyDataCommand;
public:
	void setCreateRigidBodyDataCommand(std::shared_ptr<Command> command);
	void setSimulateTimeFlyDataCommand(std::shared_ptr<Command> command);
	void test();

private: // the funtion to send message to ViewModel
	void onCreateRigidBodyData(const RigidBody &rb); // the real data(Poly)
	void onSimulateTimeFlyData(const int &turns = 1);

private:  // callback function body
	void onCreateRigidBodyTriggered();
	void onSimulateTimeFlyTriggered();
};