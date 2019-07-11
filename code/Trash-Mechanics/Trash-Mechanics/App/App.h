#pragma once
#include "../Model/Model.h"
#include "../View/View.h"
#include "../ViewModel/ViewModel.h"
#include "../Windows/Windows.h"

class App
{
private:
	std::shared_ptr<View> view;
	std::shared_ptr<Model> model;
	std::shared_ptr<ViewModel> viewmodel;
	std::shared_ptr<Windows> windows;
public:
	App();
	void StartWorld();
	void test();

};