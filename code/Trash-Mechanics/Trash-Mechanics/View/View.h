#pragma once

#include "GUI.h"

class View
{
public:
	View() {}
	~View() {}
	//void setCreatePolyCommand(std::shared_ptr<Command> command) { createPolyCommand = command; }
	void createPolyView(Poly poly, int id){}

private:
 //BASIC COMMAND 
	View() {};
	virtual ~View() {};
// WINDOW COMMAND 
	//bool createViewWindow();
	//bool deleteViewWindow();

};


