#pragma once
#include "..\Common\Common.h"
#include "Parameter.h"



class Command // base Command class
{
protected:
	std::shared_ptr<Parameter> param_;
public:
	Command() {}
	Command(std::shared_ptr<Parameter> param) : param_(param) {}
	void set_parameters(std::shared_ptr<Parameter> param) { param_ = param;
	}
	virtual void pass() = 0;
};

