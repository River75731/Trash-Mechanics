#pragma once

#include "GUI.h"

class View
{
public:
	//void setCreatePolyCommand(std::shared_ptr<Command> command) { createPolyCommand = command; }
	void createPolyView(Poly poly, int id) { std::cout << "!"; }
	View() {};
	virtual ~View() {};

private:
 //BASIC COMMAND 
// WINDOW COMMAND 
	//bool createViewWindow();
	//bool deleteViewWindow();

};


