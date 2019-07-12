#pragma once

#include "../Common/Common.h"


class Windows
{
private:
	std::shared_ptr<Command> createPolyCommand;
public:
	void setCreatePolyCommand(std::shared_ptr<Command> command) { createPolyCommand = command; }
	void test();

private: // the funtion to send message to ViewModel
	void onCreatePolyData(const Poly &poly); // the real data(Poly)

private:  // callback function body
	void onCreatePolyTriggered();

};