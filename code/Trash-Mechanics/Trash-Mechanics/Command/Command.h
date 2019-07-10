#pragma once
#include <memory>

class Parameters
{
public:
	Parameters();
};

class Command
{
protected:
	std::shared_ptr<Parameters> params;
public:
	Command();
	void set_parameters(std::shared_ptr<Parameters> parameters) {
		params = parameters;
	}
	virtual void exec() = 0;
};