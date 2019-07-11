#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <iostream>
#include <vector>
#include "Common/Common.h"
#include "Others/View-Polygon.h"
#include "View/MyFLTK.h"
#include "Model/Model.h"
/*


//class CreatePolyCommand : public Command;



class Parameter // base Parameter class
{
private:

public:
	Parameter() {}
};

class PolyParameter : public Parameter 
{
private:
	Poly poly_;
public:
	PolyParameter(Poly poly) :poly_(poly) {}
	Poly getPoly() const { return poly_; }
};

class Command // base Command class
{
protected:
	std::shared_ptr<Parameter> param_;
public:
	Command() {}
	Command(std::shared_ptr<Parameter> param) : param_(param) {}
	void set_parameters(std::shared_ptr<Parameter> param) { param_ = param; }

	//    Parameters& get_params_handle();
	//    void set_view_model(std::shared_ptr<ViewModel> viewmodel);
	virtual void exec() = 0;
};

class Notification
{
protected:

public:
	Notification() {}
	virtual void exec() = 0;
};

class DrawPolylNotification : public Notification
{
private:
	std::shared_ptr<ViewModel> viewmodel;
public:
	DrawPolylNotification(std::shared_ptr<ViewModel> VM):viewmodel(VM){}
	void exec()
	{
		viewmodel->execDrawPolylNotification();
	}
};


class Model
{
private:
	Poly poly_; //test
public:
	Model() :poly_() {}
	void createPoly(Poly poly) // receiver funtion of Model from ViewModel
	{
		poly_.setPoly(poly);
	}
	void test()
	{
		std::cout << "PointNum = " << poly_.getPointNum() << std::endl;
	}
};




class ViewModel
{
private:
	std::shared_ptr<Model> model;
	std::shared_ptr<Command> createPolyCommand;

public:
	void bind(std::shared_ptr<Model> model)
	{
		this->model = model;
	}
	ViewModel();
public: // the functions for ViewModel to control Model
	void execCreatePolyCommand(Poly poly) 
	{
		model->createPoly(poly);
	} 
	void execDrawPolyCommand(Poly poly)
	{
		model->createPoly(poly);
	}

public: // the function to be binded with setfuntion in view
	std::shared_ptr<Command> getCreatePolyCommand() 
	{
		return createPolyCommand;
	}

};

class CreatePolyCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;
public:
	CreatePolyCommand(std::shared_ptr<ViewModel> vm) :viewmodel(vm) {} // bind to viewmodel
	~CreatePolyCommand() {}
	void exec()
	{
		Poly poly = std::static_pointer_cast<PolyParameter, Parameter>(Command::param_)->getPoly(); //withdraw the data
		viewmodel->execCreatePolyCommand(poly);
	}
};




class View
{
public:
	View() {}
	~View() {}
	void test()
	{
		onCreatePolyTriggered(); // assume a trigger
	}
	void setCreatePolyCommand(std::shared_ptr<Command> command) { createPolyCommand = command; }

private: // the funtion to send message to ViewModel
	void onCreatePoly(const Poly &poly) // the real data(Poly)
	{

		createPolyCommand->set_parameters( // create command parameter from data, then set command parameter
			std::static_pointer_cast<Parameter, PolyParameter>(std::shared_ptr<PolyParameter>(new PolyParameter(poly))));

		createPolyCommand->exec(); //pass to ViewModel

	}
private:  // callback function body
	void onCreatePolyTriggered() 
	{
		Poly poly(Vec(50, 50), std::vector<Vec>{Vec(10, 10), Vec(100, 100), Vec(100, 10)}); //test
		onCreatePoly(poly);
	}

private:
	std::shared_ptr<Command> createPolyCommand;
};

class App
{
private:
	std::shared_ptr<View> view;
	std::shared_ptr<Model> model;
	std::shared_ptr<ViewModel> viewmodel;

public:
	App():view(new View), model(new Model), viewmodel(new ViewModel)
	{
		viewmodel->bind(model);
		view->setCreatePolyCommand(viewmodel->getCreatePolyCommand()); // bind the view & viewmodel command
		//std::cout << "!";
	}
	void StartWorld()
	{
		//code here
	}
	void test()
	{
		view->test();
		model->test();
	}
};


ViewModel::ViewModel()
{
	createPolyCommand = std::static_pointer_cast<Command, CreatePolyCommand>
		(std::shared_ptr<CreatePolyCommand>(new CreatePolyCommand(std::shared_ptr<ViewModel>(this))));
}
/*
int main(int argc, char *argv[])
{
	App app;
	app.test();
	system("PAUSE");
	return 0;
}*/