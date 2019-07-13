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

	//    Parameters& get_params_handle();
	//    void set_view_model(std::shared_ptr<ViewModel> viewmodel);
	virtual void pass() = 0;
};

