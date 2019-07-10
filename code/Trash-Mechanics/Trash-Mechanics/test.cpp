#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <Fl_PNG_Image.H>
#include <Fl_Shared_Image.H>
#include <iostream>
#include <vector>
#include "Common/Common.h"
#include "Others/View-Polygon.h"
#include "ViewModel/MyFLTK.h"
#include "Model/Model.h"

class Parameter
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
	PolyParameter(Poly poly, Fl_Color color = FL_BLACK) :poly_(poly) {}
	Poly getPoly() const { return poly_; }
};

class Command
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

class CreatePolyCommand : public Command {
private:
	std::shared_ptr<ViewModel> viewmodel;
public:
	CreatePolyCommand(std::shared_ptr<ViewModel> vm) {}
	~CreatePolyCommand() {}
	void exec()
	{
		Poly poly = std::static_pointer_cast<PolyParameter, Parameter>(Command::param_)->getPoly();
		viewmodel->execCreatePolyCommand(poly);
	}
};

class Model
{
public:
	Model() {}
};

class ViewModel
{
private:
	std::shared_ptr<Model> model;
	std::shared_ptr<Command> createPolyCommand;

public:
	void bind(std::shared_ptr<Model> model) {
		this->model = model;
	}
	void execCreatePolyCommand(Poly poly) {}
	std::shared_ptr<Command> getCreatePolyCommand() {}

};

class View
{
public:
	View() {}
	~View() {}
	void setCreatePolyCommand(std::shared_ptr<Command> command) { createPolyCommand = command; }


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
		view->setCreatePolyCommand(viewmodel->getCreatePolyCommand());
	}
	void CreateWorld()
	{
	}
};

int main(int argc, char *argv[])
{
	return 0;
}