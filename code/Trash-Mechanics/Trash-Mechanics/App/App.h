#pragma once
#include "../Model/Model.h"
#include "../View/View.h"
#include "../ViewModel/ViewModel.h"
#include "../Windows/Windows.h"
#include "../View/GUI.h"

class App
{
private:
	std::shared_ptr<View> view;
	std::shared_ptr<Model> model;
	ViewModel* viewmodel;
	std::shared_ptr<Windows> windows;
public:
	App();
	void startWorld();
	~App() {}
};