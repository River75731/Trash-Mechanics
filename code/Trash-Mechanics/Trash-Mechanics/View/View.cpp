#include "View.h"

std::shared_ptr<View> View::viewPtr = nullptr;
std::shared_ptr<Windows> View::windows = nullptr;
Fl_Input *View::mass_Input = nullptr;
Fl_Input *View::velocityX_Input = nullptr;
Fl_Input *View::velocityY_Input = nullptr;
Fl_Input *View::forceX_Input = nullptr;
Fl_Input *View::forceY_Input = nullptr;
Fl_Multiline_Input *View::vertices_Input = nullptr;
Fl_Button *View::createRB_Button = nullptr;
Fl_Input *View::angvelocity_Input = nullptr;
Fl_Multiline_Output *View::CMD_Output = nullptr;
double View::fx = 0;
double View::fy = 0;
bool View::simulating = false;

View::View()
{
}

View::~View()
{
}

void View::bind(std::shared_ptr<Windows> tempwindows)
{
	this->windows = tempwindows;
}

void View::bind(std::shared_ptr<View> tempview)
{
	this->viewPtr = tempview;
}

ViewSystem & View::getsystem()
{
	return m_system;
}

void View::refresh()
{
	m_system.drawSystem();
}

bool View::createViewWindow(const std::string & name, const Vec & topleft, const int & w, const int & h, const Fl_Color & c, const bool & v) 
{
	std::cout << "Try to build a new window.\n";
	ViewWindow* temp = new ViewWindow(topleft, w, h, v, name, c);
	// ------ Widgets ------
	const int gap = InputHeight / 2;
	mass_Input = new Fl_Input(w-MarginX, MarginY + 0 * InputHeight + 0 * gap, Width, InputHeight, "Mass(kg)=");
	mass_Input->value("100");
	mass_Input->labelcolor(fl_rgb_color(200, 200, 200));
	velocityX_Input = new Fl_Input(w - MarginX, MarginY + 1 * InputHeight + 1 * gap, Width, InputHeight, "Vx(m/s)=");
	velocityX_Input->value("30");
	velocityX_Input->labelcolor(fl_rgb_color(200, 200, 200));
	velocityY_Input = new Fl_Input(w - MarginX, MarginY + 2 * InputHeight + 2 * gap, Width, InputHeight, "Vy(m/s)=");
	velocityY_Input->value("25");
	velocityY_Input->labelcolor(fl_rgb_color(200, 200, 200));
	angvelocity_Input = new Fl_Input(w - MarginX, MarginY + 3 * InputHeight + 3 * gap, Width, InputHeight, "w(deg/s)=");
	angvelocity_Input->value("8");
	angvelocity_Input->labelcolor(fl_rgb_color(200, 200, 200));
	vertices_Input = new Fl_Multiline_Input(w - MarginX, MarginY + 4 * InputHeight + 4 * gap, Width, 6 * InputHeight, "Vertices=");
	vertices_Input->value("Sample input : \n50 50\n170 50\n200 200\n50 250\nAnti-Clockwise");
	vertices_Input->labelcolor(fl_rgb_color(200, 200, 200));
	createRB_Button = new Fl_Button(w - MarginX, MarginY + 10 * InputHeight + 5 * gap, Width, ButtonHeight, "Create\n Rigid Body");
	createRB_Button->callback(onCreateRigidBodyTriggered);
	createRB_Button->color(fl_rgb_color(100, 200, 100));
	
	forceX_Input = new Fl_Input(w - MarginX, MarginY + 10 * InputHeight + 1 * ButtonHeight + 6 * gap, Width, InputHeight, "ax(m/s^2)=");
	forceX_Input->value("0");
	forceX_Input->labelcolor(fl_rgb_color(200, 200, 200));

	forceY_Input = new Fl_Input(w - MarginX, MarginY + 11 * InputHeight + 1 * ButtonHeight + 7 * gap, Width, InputHeight, "ay(m/s^2)=");
	forceY_Input->value("9.8");
	forceY_Input->labelcolor(fl_rgb_color(200, 200, 200));

	Fl_Button *applyforce_Button = new Fl_Button(w - MarginX, MarginY + 12 * InputHeight + 1 * ButtonHeight + 8 * gap, Width, ButtonHeight, "Apply\nForce");
	applyforce_Button->callback(onApplyForceTriggered);
	applyforce_Button->color(fl_rgb_color(100, 200, 100));

	CMD_Output = new Fl_Multiline_Output(w - MarginX, MarginY + 12 * InputHeight + 2 * ButtonHeight + 9 * gap, Width, 4 * InputHeight, "CMD Says:");
	CMD_Output->labelcolor(fl_rgb_color(200, 200, 200));
	CMD_Output->color(fl_rgb_color(50, 20, 20));
	CMD_Output->textcolor(fl_rgb_color(250, 250, 250));
	CMD_Output->value("> Loading\n> Link start");

	Fl_Button *simulate_Button = new Fl_Button(w - MarginX, MarginY + 16 * InputHeight + 2 * ButtonHeight + 10 * gap, Width, ButtonHeight, "Simulate");
	simulate_Button->callback(onSimulateTimeFlyTriggered);
	simulate_Button->color(fl_rgb_color(250, 250, 100));

	Fl_Button *clear_Button = new Fl_Button(w - MarginX, MarginY + 16 * InputHeight + 3 * ButtonHeight + 11 * gap, Width, ButtonHeight, "Clear");
	clear_Button->callback(onClearTriggered);
	clear_Button->color(fl_rgb_color(250, 100, 100));
	Fl::add_timeout(0.1, simulate, temp);
	temp->end();
	// ------ Widgets ------
//	temp->show();
	
	if (!v) temp->hide();
	m_system.attach(temp);
	std::cout << "Successfully create window: \n";
	printf("Window name : %s\n", name.c_str());
	printf("Window topleft : (%d,%d)\n", (int)topleft.getX(), (int)topleft.getY());
	printf("Window width : %d\n", w);
	printf("Window height : %d\n", h);
	printf("Window visibility : %s\n", v?"visible":"invisible");
	m_system.setWINDOW(m_system.getWindow(name.c_str()));
	std::cout << "Successfully set " << name << " as operating window.\n\n";

	m_system.drawSystem();

	return true;
}

bool View::changeViewWindow(const Fl_Color & c)
{
	std::cout << "Try to change the background color of the operating window.\n";
	if (m_system.getwindownum() == 0)
	{
		std::cout << "ERROR: No window left.\n\n";
		return false;
	}
	if (m_system.getWINDOW() == nullptr)
	{
		std::cout << "ERROR: Default window point to unknown area.\n\n";
		return false;
	}
	if (c < 0)
	{
		std::cout << "ERROR: We don't have this color.\n\n";
		return false;
	}
	m_system.getWINDOW()->setcolor(c);
	std::cout << "Successfully change the default window background color to " << c << " .\n\n";
	m_system.drawSystem();
	return true;
}


bool View::createViewPolygon(const int & id, const Poly & p, const int & ew, const Fl_Color & ec, const Fl_Color & fc, const bool & v)
{
	std::cout << "Try to create a polygon ID : "<<id<<" .\n";
	if (m_system.getwindownum() == 0) 
	{
		std::cout << "ERROR: No window.\n\n" << std::endl;
		return false;
	}
	if (m_system.getWINDOW() == nullptr)
	{
		std::cout << "ERROR: Default window point to unknown area.\n\n";
		return false;
	}
	ViewShape* tempptr = m_system.getWINDOW()->getviewshape(id);
	if (tempptr != nullptr)
	{
		std::cout << "ERROR: Already exists shape ID : " << id << " .\n\n";
		return false;
	}
	ViewPolygon* temp = new ViewPolygon(p, id, v, ew, ec, fc);
	m_system.getWINDOW()->attach(temp);
	std::cout << "Successfully create polygon ID : " << id << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::deleteViewPolygon(const int & id)
{
	std::cout << "Try to delete polygon ID : "<<id<<" .\n";
	if (m_system.getwindownum() == 0)
	{
		std::cout << "ERROR: No window.\n\n" << std::endl;
		return false;
	}
	if (m_system.getWINDOW() == nullptr)
	{
		std::cout << "ERROR: Default window point to unknown area.\n\n";
		return false;
	}
	ViewShape* temp = m_system.getWINDOW()->getviewshape(id);
	if (temp == nullptr)
	{
		std::cout << "ERROR: Cannot find polygon ID : "<<id<<" .\n\n";
		return false;
	}
	else m_system.getWINDOW()->deleteshape(temp);
	std::cout << "Successfully delete polygon ID : " << id << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::changeViewPolygon(const int & id, const Poly & p)
{
	//std::cout << "Try to change the position of polygon ID : "<<id<<" .\n";
	if (m_system.getwindownum() == 0)
	{
		std::cout << "ERROR: No window.\n\n" << std::endl;
		return false;
	}
	if (m_system.getWINDOW() == nullptr)
	{
		std::cout << "ERROR: Default window point to unknown area.\n\n";
		return false;
	}
	ViewShape* temp = m_system.getWINDOW()->getviewshape(id);
	if (temp == nullptr)
	{
		std::cout << "ERROR: Cannot find polygon ID : " << id << " .\n\n";
		return false;
	}
	((ViewPolygon*)temp)->setPolygon(p);
	//std::cout << "Successfully change the position of polygon ID : " << id << " .\n\n";
	//m_system.drawSystem();
	return true;
}

bool View::changeViewPolygon(const int & id, const int & lw)
{
	std::cout << "Try to change the edge width of polygon ID : " << id << " .\n";
	if (m_system.getwindownum() == 0)
	{
		std::cout << "ERROR: No window.\n\n" << std::endl;
		return false;
	}
	if (m_system.getWINDOW() == nullptr)
	{
		std::cout << "ERROR: Default window point to unknown area.\n\n";
		return false;
	}
	ViewShape* temp = m_system.getWINDOW()->getviewshape(id);
	if (temp == nullptr)
	{
		std::cout << "ERROR: Cannot find polygon ID : " << id << " .\n\n";
		return false;
	} 
	if (lw > MAX_LINEWIDTH)
	{
		std::cout << "ERROR: Too big line width.\n\n";
		return false;
	}
	((ViewPolygon*)temp)->setedgewidth(lw);
	std::cout << "Successfully change the edge width of polygon ID : " << id << " to " << lw << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::changeViewPolygon(const int & id, const Fl_Color & c, const bool status)
{
	if (status)
		std::cout << "Try to change the fill color of polygon ID : " << id << " .\n";
	else
		std::cout << "Try to change the edge color of polygon ID : " << id << " .\n";
	if (m_system.getwindownum() == 0)
	{
		std::cout << "ERROR: No window.\n\n" << std::endl;
		return false;
	}
	if (m_system.getWINDOW() == nullptr)
	{
		std::cout << "ERROR: Default window point to unknown area.\n\n";
		return false;
	}
	ViewShape* temp = m_system.getWINDOW()->getviewshape(id);
	if (temp == nullptr)
	{
		std::cout << "ERROR: Cannot find polygon ID : " << id << " .\n\n";
		return false;
	}
	if (c < 0)
	{
		std::cout << "ERROR: We don't have this color.\n\n";
		return false;
	}
	if (status)
	{
		((ViewPolygon*)temp)->setfillcolor(c);
		std::cout << "Successfully change the fill color of polygon ID : " << id << " to " << c << " .\n\n";
	}
	else
	{
		((ViewPolygon*)temp)->setedgecolor(c);
		std::cout << "Successfully change the edge color of polygon ID : " << id << " to " << c << " .\n\n";
	}
	m_system.drawSystem();
	return true;
}

bool View::hideViewPolygon(const int & id)
{
	std::cout << "Try to set polygon ID : " << id << " invisible.\n";
	if (m_system.getwindownum() == 0)
	{
		std::cout << "ERROR: No window.\n\n" << std::endl;
		return false;
	}
	if (m_system.getWINDOW() == nullptr)
	{
		std::cout << "ERROR: Default window point to unknown area.\n\n";
		return false;
	}
	ViewShape* temp = m_system.getWINDOW()->getviewshape(id);
	if (temp == nullptr)
	{
		std::cout << "ERROR: Cannot find polygon ID : " << id << " .\n\n";
		return false;
	}
	((ViewPolygon*)temp)->setvisible(0);
	std::cout << "Successfully set polygon ID : " << id << " invisible.\n\n";
	m_system.drawSystem();
	return true;
}



bool View::resetLINECOLOR(const Fl_Color & lc)
{
	std::cout << "Try to change the default line color.\n";
	if (lc < 0)
	{
		std::cout << "ERROR: We don't have this color.\n\n";
		return false;
	}
	ViewShape::setLINECOLOR(lc);
	std::cout << "Successfully change the default line color to " << lc << " .\n\n";
	return true;
}

bool View::resetFILLCOLOR(const Fl_Color & fc)
{
	std::cout << "Try to change the default fill color.\n";
	if (fc < 0)
	{
		std::cout << "ERROR: We don't have this color.\n\n";
		return false;
	}
	ViewShape::setFILLCOLOR(fc);
	std::cout << "Successfully change the default fill color to " << fc << " .\n\n";
	return true;
}


void onCreateRigidBodyTriggered(Fl_Widget* sender, void*) {
	changecolor();
	const char * mass_Input_str = View::mass_Input->value();
	const char * velocityX_Input_str = View::velocityX_Input->value();
	const char * velocityY_Input_str = View::velocityY_Input->value();
	const char * angvelocity_Input_str = View::angvelocity_Input->value();
	const char * vertices_Input_str = View::vertices_Input->value();
	const char * str = View::mass_Input->value();
	if(strlen(mass_Input_str) == 0) {
		View::CMD_Output->value("> ERROR\n@ Creating RB:\nINVALID INPUT\nEmpty argument");
		return;
	}
	for (unsigned int i = 0; i < strlen(mass_Input_str); i++) {
		if (!(mass_Input_str[i] >= '0' && mass_Input_str[i] <= '9')) {
			View::CMD_Output->value("> ERROR\n@ Creating RB:\nINVALID INPUT");
			return;
		}
	}

	if (strlen(velocityX_Input_str) == 0) {
		View::CMD_Output->value("> ERROR\n@ Creating RB:\nINVALID INPUT\nEmpty argument");
		return;
	}
	if (!(velocityX_Input_str[0] >= '0' && velocityX_Input_str[0] <= '9' || velocityX_Input_str[0] == '-')) {
		View::CMD_Output->value("> ERROR\n@ Creating RB:\nINVALID INPUT");
		return;
	}
	for (unsigned int i = 1; i < strlen(velocityX_Input_str); i++) {
		if (!(velocityX_Input_str[i] >= '0' && velocityX_Input_str[i] <= '9')) {
			View::CMD_Output->value("> ERROR\n@ Creating RB:\nINVALID INPUT");
			return;
		}
	}

	if (strlen(velocityY_Input_str) == 0) {
		View::CMD_Output->value("> ERROR\n@ Creating RB:\nINVALID INPUT\nEmpty argument");
		return;
	}
	if (!(velocityY_Input_str[0] >= '0' && velocityY_Input_str[0] <= '9' || velocityY_Input_str[0] == '-')) {
		View::CMD_Output->value("> ERROR\n@ Creating RB:\nINVALID INPUT\nIllegal char");
		return;
	}
	for (unsigned int i = 1; i < strlen(velocityY_Input_str); i++) {
		if (!(velocityY_Input_str[i] >= '0' && velocityY_Input_str[i] <= '9')) {
			View::CMD_Output->value("> ERROR\n@ Creating RB:\nINVALID INPUT\nIllegal char");
			return;
		}
	}

	if (strlen(angvelocity_Input_str) == 0) {
		View::CMD_Output->value("> ERROR\n@ Creating RB:\nINVALID INPUT\nEmpty argument");
		return;
	}
	if (!(angvelocity_Input_str[0] >= '0' && angvelocity_Input_str[0] <= '9' || angvelocity_Input_str[0] == '-')) {
		View::CMD_Output->value("> ERROR\n@ Creating RB:\nINVALID INPUT\nIllegal char");
		return;
	}
	for (unsigned int i = 1; i < strlen(angvelocity_Input_str); i++) {
		if (!(angvelocity_Input_str[i] >= '0' && angvelocity_Input_str[i] <= '9')) {
			View::CMD_Output->value("> ERROR\n@ Creating RB:\nINVALID INPUT\nIllegal char");
			return;
		}
	}

	std::vector<Vec> vertices;
	double prenum = 0, curnum = 0;
	for (unsigned int i = 0; i < strlen(vertices_Input_str); i++) {
		if (vertices_Input_str[i] >= '0' && vertices_Input_str[i] <= '9') {
			curnum = 10 * curnum + vertices_Input_str[i] - '0';
		}
		if (i == strlen(vertices_Input_str) - 1 || !((vertices_Input_str[i] >= '0' && vertices_Input_str[i] <= '9'))) {
			if (curnum >= 1) {
				if (prenum < 1) {
					prenum = curnum;
				}
				else {
					vertices.push_back(Vec(prenum, curnum));
					prenum = 0;
				}
				curnum = 0;
			}
		}
	}

	RigidBody rb = RigidBody(
		Poly(vertices),
		atoi(mass_Input_str),
		Vec(atoi(velocityX_Input_str), atoi(velocityY_Input_str)),
		atoi(angvelocity_Input_str) / 180.0*pi
	);
	View::CMD_Output->value("> SUCCESS\n@ Creating RB\n");
	(View::getWindowsPtr())->onUpdateRigidBodyData(createMode, rb);
}

void onSimulateTimeFlyTriggered(Fl_Widget* sender, void*) {
	
	Fl_Button * but = (Fl_Button*)sender;
	if (strcmp((but->label()), "Simulate") == 0) {
		View::CMD_Output->value("> SUCCESS\n@ Simulating\nStarted");
		View::simulating = true;
		but->label("Stop");
	}
	else {
		View::CMD_Output->value("> SUCCESS\n@ Simulating\nStopped");
		View::simulating = false;
		but->label("Simulate");
	}
}

void simulate(void *sender) {
	if (View::simulating) {
		//printf("Simulating!\n");
		(View::getWindowsPtr())->onSimulateTimeFlyData(10);
	}
	Fl::add_timeout(0.005, simulate, sender);
}

void changecolor()
{
	int r, g, b;
	double a, q;
	do {
		r = 125 + rand() % 130;
		g = 125 + rand() % 130;
		b = 125 + rand() % 130;
		a = (double)r / (double)g;
		q = (double)g / (double)b;
	} while (a<1.1&&a>0.9&&q<1.1&&q>0.9);
	View::getViewPtr()->resetFILLCOLOR(fl_rgb_color(r, g, b));
}

void onApplyForceTriggered(Fl_Widget* sender, void*) {
	Fl_Button * but = (Fl_Button*)sender;
	const char * fx_Input_str = View::forceX_Input->value();
	const char * fy_Input_str = View::forceY_Input->value();
	double dfx = atof(fx_Input_str);
	double dfy = atof(fy_Input_str);
	View::fx += dfx; View::fy += dfy;
	char pos[32];
	sprintf_s(pos, "(%.3f,%.3f)", View::fx, View::fy);
	std::string str = "> SUCCESS\n@ Adding force\nCurrent force field:\n";
	str += pos;
	View::CMD_Output->value(str.c_str());
	(View::getWindowsPtr())->onAddForceFieldData(Vec(dfx, dfy));
}

void onClearTriggered(Fl_Widget* sender, void*) {
	View::fx = 0; View::fy = 0;
	View::CMD_Output->value("> SUCCESS\n@ Clearing RBs\nRBs deleted\nForce field cleaned");
	(View::getWindowsPtr())->onClearUserRigidBodyCommand();
}

