#pragma once

#include "../Common/Common.h"


class Windows
{
private:
	
public:
	Windows() {}


private:
	std::shared_ptr<Command> createRigidBodyDataCommand;
public:
	void setCreateRigidBodyDataCommand(std::shared_ptr<Command> command);
	void test();

private: // the funtion to send message to ViewModel
	void onCreateRigidBodyData(const RigidBody rb); // the real data(Poly)

private:  // callback function body
	void onCreateRigidBodyTriggered();

};