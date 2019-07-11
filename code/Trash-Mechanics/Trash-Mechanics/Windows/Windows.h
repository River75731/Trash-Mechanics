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
	void onCreatePolyData(const Poly &poly) // the real data(Poly)
	{

		createPolyCommand->set_parameters( // create command parameter from data, then set command parameter
			std::static_pointer_cast<Parameter, PolyParameter>(std::shared_ptr<PolyParameter>(new PolyParameter(poly))));

		createPolyCommand->pass(); //pass to ViewModel

	}
private:  // callback function body
	void onCreatePolyTriggered()
	{
		Poly poly(Vec(50, 50), std::vector<Vec>{Vec(10, 10), Vec(100, 100), Vec(100, 10)}); //test
		onCreatePolyData(poly);
	}
};