#pragma once

#include "../Common/Common.h"


class Windows
{

public:
	Windows() {}

private:
	std::shared_ptr<Command> UpdateRigidBodyDataCommand;
	std::shared_ptr<Command> simulateTimeFlyDataCommand;
public:
	void setUpdateRigidBodyDataCommand(std::shared_ptr<Command> command);
	void setSimulateTimeFlyDataCommand(std::shared_ptr<Command> command);
	void test();

private: // the funtion to send message to ViewModel
	void onUpdateRigidBodyData(const RigidBody &rb); // the real data(Poly)
	void onSimulateTimeFlyData(const int &turns = 1);

private:  // callback function body
	void onUpdateRigidBodyTriggered();
	void onSimulateTimeFlyTriggered();
};