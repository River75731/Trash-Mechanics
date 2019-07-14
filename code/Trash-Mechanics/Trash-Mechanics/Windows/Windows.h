#pragma once

#include "../Common/Common.h"


class Windows
{

public:
	Windows() {}

private:
	std::shared_ptr<Command> updateRigidBodyDataCommand;
	std::shared_ptr<Command> simulateTimeFlyDataCommand;
	std::shared_ptr<Command> addForceFieldDataCommand;
	std::shared_ptr<Command> clearUserRigidBodyCommand;
public:
	void setUpdateRigidBodyDataCommand(std::shared_ptr<Command> command);
	void setSimulateTimeFlyDataCommand(std::shared_ptr<Command> command);
	void setAddForceFieldDataCommand(std::shared_ptr<Command> command);
	void setClearUserRigidBodyCommand(std::shared_ptr<Command> command);
	void test();

public: // the funtion to send message to ViewModel
	void onUpdateRigidBodyData(const int & actionMode, const RigidBody &rb, const int &id = 0); // create & adjust
	void onUpdateRigidBodyData(const int & actionMode, const int &id); // delete
	void onSimulateTimeFlyData(const int & turns = 1);
	void onAddForceFieldData(const Vec &v);
	void onClearUserRigidBodyCommand();

public:  // callback function body
	/*void onCreateRigidBodyTriggered(Fl_Widget* sender, void*);
	void onSimulateTimeFlyTriggered();
	void onAddForceFieldTriggered();*/
};