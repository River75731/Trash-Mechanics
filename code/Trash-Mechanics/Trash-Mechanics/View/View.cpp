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
	vertices_Input->value("Sample input : \n50 50\n200 50\n100 250\nAnti-Clockwise");
	vertices_Input->labelcolor(fl_rgb_color(200, 200, 200));
	createRB_Button = new Fl_Button(w - MarginX, MarginY + 10 * InputHeight + 5 * gap, Width, ButtonHeight, "Create\n Rigid Body");
	createRB_Button->callback(onCreateRigidBodyTriggered);
	createRB_Button->color(fl_rgb_color(100, 200, 100));
	
	forceX_Input = new Fl_Input(w - MarginX, MarginY + 10 * InputHeight + 1 * ButtonHeight + 6 * gap, Width, InputHeight, "Fx(m/s^2)=");
	forceX_Input->value("0");
	forceX_Input->labelcolor(fl_rgb_color(200, 200, 200));

	forceY_Input = new Fl_Input(w - MarginX, MarginY + 11 * InputHeight + 1 * ButtonHeight + 7 * gap, Width, InputHeight, "FY(m/s^2)=");
	forceY_Input->value("9.8");
	forceY_Input->labelcolor(fl_rgb_color(200, 200, 200));
	
	Fl_Button *applyforce_Button = new Fl_Button(w - MarginX, MarginY + 12 * InputHeight + 1 * ButtonHeight + 8 * gap, Width, ButtonHeight, "Apply\nForce");
	applyforce_Button->callback(onApplyForceTriggered);
	applyforce_Button->color(fl_rgb_color(100, 200, 100));

	Fl_Button *simulate_Button = new Fl_Button(w - MarginX, MarginY + 25 * InputHeight, Width, ButtonHeight, "Simulate");
	simulate_Button->callback(onSimulateTimeFlyTriggered);
	simulate_Button->color(fl_rgb_color(250, 250, 100));

	Fl_Button *clear_Button = new Fl_Button(w - MarginX, MarginY + 25 * InputHeight + 1* ButtonHeight + 1 * gap, Width, ButtonHeight, "Clear");
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

bool View::deleteViewWindow(const std::string & name)
{
	std::cout << "Try to delete a window.\n";
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
	ViewWindow *temp = m_system.getWindow(name.c_str()); //dangerous
	if (temp == nullptr)
	{
		std::cout << "ERROR: No window called '" << name << "'\n\n";
		return false;
	}
	std::cout << "Successfully delete window: " << name << "\n";
	m_system.deletewindow(temp);
	if (m_system.getWINDOW() != nullptr) std::cout << "Now the operating window is '" << m_system.getWINDOW()->getname() << "'.\n\n";
	else std::cout << "Now there is no window.\n\n";
	m_system.drawSystem();
	return true;
}

bool View::changeViewWindow(const std::string & name)
{
	std::cout << "Try to change operating window.\n";
	if (m_system.getwindownum() == 0)
	{
		std::cout << "ERROR: No window left.\n\n";
		return false;
	}
	ViewWindow *temp = m_system.getWindow(name.c_str()); //dangerous
	if (temp == nullptr)
	{
		std::cout << "ERROR: No window called '" << name << "'\n\n";
		return false;
	}
	std::cout << "Successfully change operating window from '" << m_system.getWINDOW()->getname();
	std::cout << "' to '" << name << "'.\n\n";
	m_system.setWINDOW(temp);
	m_system.drawSystem();
	return true;
}

bool View::changeViewWindow(const Vec &v)
{
	std::cout << "Try to change the topleft corner of the operating window.\n";
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
	if (v.getX() > MAX_WINWIDTH || v.getX() < 0 || v.getY() > MAX_WINHEIGHT || v.getY() < 0)
	{
		std::cout << "ERROR: Outside the computer window.\n\n";
		return false;
	}
	m_system.getWINDOW()->setsize(v, m_system.getWINDOW()->getwidth(), m_system.getWINDOW()->getheight());
	std::cout << "Successfully change the operating window topleft corner to ( ";
	std::cout << int(v.getX()) << " , " << int(v.getY()) << " ).\n\n";
	m_system.drawSystem();
	return true;
}

bool View::changeViewWindow(const int & d, const bool & status)
{
	if(status) std::cout << "Try to change the height of the operating window.\n";
	else std::cout << "Try to change the width of the operating window.\n";
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
	if (status)
	{
		if (m_system.getWINDOW()->gettopleftY() + d >= Fl::h())
		{
			std::cout << "ERROR: Too big height.\n\n";
			return false;
		}
		m_system.getWINDOW()->setsize(m_system.getWINDOW()->gettopleftX(), m_system.getWINDOW()->gettopleftY(), m_system.getWINDOW()->getwidth(), d);
		std::cout << "Successfully change the operating window height to " << d << " .\n\n";
	}
	else
	{
		if (m_system.getWINDOW()->gettopleftX() + d >= Fl::w())
		{
			std::cout << "ERROR: Woo big width.\n\n";
			return false;
		}
		m_system.getWINDOW()->setsize(m_system.getWINDOW()->gettopleftX(), m_system.getWINDOW()->gettopleftY(), d, m_system.getWINDOW()->getheight());
		std::cout << "Successfully change the operating window width to " << d << " .\n\n";
	}
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

bool View::hideViewWindow()
{
	std::cout << "Try to set the operating window invisible.\n";
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
	m_system.getWINDOW()->setwinvisible(false);
	std::cout << "Successfully set the operating window invisible.\n\n";
	m_system.drawSystem();
	return true;
}

bool View::showViewWindow()
{
	std::cout << "Try to set the operating window visible.\n";
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
	m_system.getWINDOW()->setwinvisible(true);
	std::cout << "Successfully set the operating window visible.\n\n";
	m_system.drawSystem();
	return true;
}

bool View::resetWINVISIBLE(const bool & v)
{
	std::cout << "Try to change the default window visibility.\n";
	ViewWindow::setWINVISIBLE(v);
	std::cout << "Successfully change the default window visibility to ";
	if (v) std::cout << "visible.\n\n";
	else std::cout << "invisible.\n\n";
	return true;
}

bool View::resetWINTOPLEFT(const Vec & v)
{
	std::cout << "Try to change the default window topleft corner.\n";
	if (v.getX() > MAX_WINWIDTH || v.getX() < 0 || v.getY() > MAX_WINHEIGHT || v.getY() < 0)
	{
		std::cout << "ERROR: Outside the computer window.\n\n";
		return false;
	}
	ViewWindow::setTOPLEFT(int(v.getX()),int(v.getY()));
	std::cout << "Successfully change the default window topleft corner to ( ";
	std::cout << int(v.getX()) << " , " << int(v.getY()) << " ).\n\n";
	return true;
}

bool View::resetWINWIDTH(const int & w)
{
	std::cout << "Try to change the default window width.\n";
	if (ViewWindow::getTOPLEFT().getintX() + w >= Fl::w())
	{
		std::cout << "ERROR: Too big width.\n\n";
		return false;
	}
	ViewWindow::setWINWIDTH(w);
	std::cout << "Successfully change the default window width to "<<w<<" .\n\n";
	return true;
}

bool View::resetWINHEIGHT(const int & h)
{
	std::cout << "Try to change the default window height.\n";
	if (ViewWindow::getTOPLEFT().getintY() + h >= Fl::h())
	{
		std::cout << "ERROR: Too big height.\n\n";
		return false;
	}
	ViewWindow::setWINHEIGHT(h);
	std::cout << "Successfully change the default window height to " << h << " .\n\n";
	return true;
}

bool View::resetWINNAME(const std::string & name)
{
	std::cout << "Try to change the default window name.\n";
	if (name.length() <= 0)
	{
		std::cout << "ERROR: Too short name.\n\n";
		return false;
	}
	ViewWindow::setWINNAME(name);
	std::cout << "Successfully change the default window name to " << name << " .\n\n";
	return true;
}

bool View::resetWINCOLOR(const Fl_Color & c)
{
	std::cout << "Try to change the default window background color.\n";
	if (c < 0)
	{
		std::cout << "ERROR: We don't have this color.\n\n";
		return false;
	}
	ViewWindow::setWINCOLOR(c);
	std::cout << "Successfully change the default window background color to " << c << " .\n\n";
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

bool View::showViewPolygon(const int & id)
{
	std::cout << "Try to set polygon ID : " << id << " visible.\n";
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
	((ViewPolygon*)temp)->setvisible(1);
	std::cout << "Successfully set polygon ID : " << id << " visible.\n\n";
	m_system.drawSystem();
	return true;
}

bool View::createViewSegment(const int & id, const Segment & p, const int & lw, const Fl_Color & lc, const bool & v)
{
	std::cout << "Try to create a segment ID : " << id << " .\n";
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
	ViewSegment* temp = new ViewSegment(p, id, v, lw, lc);
	m_system.getWINDOW()->attach(temp);
	std::cout << "Successfully create segment ID : " << id << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::deleteViewSegment(const int & id)
{
	std::cout << "Try to delete segment ID : " << id << " .\n";
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
		std::cout << "ERROR: Cannot find segment ID : " << id << " .\n\n";
		return false;
	}
	else m_system.getWINDOW()->deleteshape(temp);
	std::cout << "Successfully delete segment ID : " << id << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::changeViewSegment(const int & id, const Segment & s)
{
	std::cout << "Try to change the position of segment ID : " << id << " .\n";
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
		std::cout << "ERROR: Cannot find segment ID : " << id << " .\n\n";
		return false;
	}
	((ViewSegment*)temp)->setSegment(s);
	std::cout << "Successfully change the position of segment ID : " << id << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::changeViewSegment(const int & id, const int & lw)
{
	std::cout << "Try to change the line width of segment ID : " << id << " .\n";
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
		std::cout << "ERROR: Cannot find segment ID : " << id << " .\n\n";
		return false;
	}
	if (lw > MAX_LINEWIDTH)
	{
		std::cout << "ERROR: Too big line width.\n\n";
		return false;
	}
	((ViewSegment*)temp)->setlinewidth(lw);
	std::cout << "Successfully change the line width of segment ID : " << id << " to " << lw << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::changeViewSegment(const int & id, const Fl_Color & lc)
{
	std::cout << "Try to change the line color of polygon ID : " << id << " .\n";
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
		std::cout << "ERROR: Cannot find segment ID : " << id << " .\n\n";
		return false;
	}
	if (lc < 0)
	{
		std::cout << "ERROR: We don't have this color.\n\n";
		return false;
	}
	((ViewSegment*)temp)->setlinecolor(lc);
	std::cout << "Successfully change the line color of segment ID : " << id << " to " << lc << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::hideViewSegment(const int & id)
{
	std::cout << "Try to set segment ID : " << id << " invisible.\n";
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
		std::cout << "ERROR: Cannot find segment ID : " << id << " .\n\n";
		return false;
	}
	((ViewSegment*)temp)->setvisible(0);
	std::cout << "Successfully set segment ID : " << id << " invisible.\n\n";
	m_system.drawSystem();
	return true;
}

bool View::showViewSegment(const int & id)
{
	std::cout << "Try to set segment ID : " << id << " visible.\n";
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
		std::cout << "ERROR: Cannot find segment ID : " << id << " .\n\n";
		return false;
	}
	((ViewSegment*)temp)->setvisible(1);
	std::cout << "Successfully set segment ID : " << id << " visible.\n\n";
	m_system.drawSystem();
	return true;
}

bool View::createViewCircle(const int & id, const Vec & center, const double & r, const int & ew, const Fl_Color & ec, const Fl_Color & fc, const bool & v)
{
	std::cout << "Try to create a circle ID : " << id << " .\n";
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
	ViewCircle* temp = new ViewCircle(ViewPoint(center), int(r), id, v, ew, ec, fc);
	m_system.getWINDOW()->attach(temp);
	std::cout << "Successfully create circle ID : " << id << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::deleteViewCircle(const int & id)
{
	std::cout << "Try to delete circle ID : " << id << " .\n";
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
		std::cout << "ERROR: Cannot find circle ID : " << id << " .\n\n";
		return false;
	}
	else m_system.getWINDOW()->deleteshape(temp);
	std::cout << "Successfully delete circle ID : " << id << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::changeViewCircle(const int & id, const Vec & center)
{
	std::cout << "Try to change the center of circle ID : " << id << " .\n";
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
		std::cout << "ERROR: Cannot find circle ID : " << id << " .\n\n";
		return false;
	}
	((ViewCircle*)temp)->setCircle(center);
	std::cout << "Successfully change the center of circle ID : " << id << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::changeViewCircle(const int & id, const double & radius)
{
	std::cout << "Try to change the radius of circle ID : " << id << " .\n";
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
		std::cout << "ERROR: Cannot find circle ID : " << id << " .\n\n";
		return false;
	}
	((ViewCircle*)temp)->setCircle(ViewPoint(((ViewCircle*)temp)->getcenter()), radius, id);
	std::cout << "Successfully change the radius of circle ID : " << id << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::changeViewCircle(const int & id, const int & lw)
{
	std::cout << "Try to change the edge width of circle ID : " << id << " .\n";
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
		std::cout << "ERROR: Cannot find circle ID : " << id << " .\n\n";
		return false;
	}
	if (lw > MAX_LINEWIDTH)
	{
		std::cout << "ERROR: Too big edge width.\n\n";
		return false;
	}
	((ViewCircle*)temp)->setedgewidth(lw);
	std::cout << "Successfully change the edge width of circle ID : " << id << " to " << lw << " .\n\n";
	m_system.drawSystem();
	return true;
}

bool View::changeViewCircle(const int & id, const Fl_Color & c, const bool & status)
{
	if (status)
		std::cout << "Try to change the fill color of circle ID : " << id << " .\n";
	else
		std::cout << "Try to change the edge color of circle ID : " << id << " .\n";
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
		std::cout << "ERROR: Cannot find circle ID : " << id << " .\n\n";
		return false;
	}
	if (c < 0)
	{
		std::cout << "ERROR: We don't have this color.\n\n";
		return false;
	}
	if (status)
	{
		((ViewCircle*)temp)->setfillcolor(c);
		std::cout << "Successfully change the fill color of circle ID : " << id << " to " << c << " .\n\n";
	}
	else
	{
		((ViewCircle*)temp)->setedgecolor(c);
		std::cout << "Successfully change the edge color of circle ID : " << id << " to " << c << " .\n\n";
	}
	m_system.drawSystem();
	return true;
}

bool View::resetLINEWIDTH(const int & lw)
{
	std::cout << "Try to change the default line width.\n";
	if (lw > MAX_LINEWIDTH)
	{
		std::cout << "ERROR: Too big line width.\n\n";
		return false;
	}
	ViewShape::setLINEWIDTH(lw);
	std::cout << "Successfully change the default line width to " << lw << " .\n\n";
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

bool View::resetVISIBLE(const bool & v)
{
	std::cout << "Try to change the default shape visibility.\n";
	ViewShape::setVISIBLE(v);
	if (v)
		std::cout << "Successfully change the default shape visibility to visible .\n\n";
	else 
		std::cout << "Successfully change the default shape visibility to invisible .\n\n";
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
		View::createRB_Button->label("INVALID\nINPUT");
		return;
	}
	for (unsigned int i = 0; i < strlen(mass_Input_str); i++) {
		if (!(mass_Input_str[i] >= '0' && mass_Input_str[i] <= '9')) {
			View::createRB_Button->label("INVALID\nINPUT");
			return;
		}
	}

	if (strlen(velocityX_Input_str) == 0) {
		View::createRB_Button->label("INVALID\nINPUT");
		return;
	}
	if (!(velocityX_Input_str[0] >= '0' && velocityX_Input_str[0] <= '9' || velocityX_Input_str[0] == '-')) {
		View::createRB_Button->label("INVALID\nINPUT");
		return;
	}
	for (unsigned int i = 1; i < strlen(velocityX_Input_str); i++) {
		if (!(velocityX_Input_str[i] >= '0' && velocityX_Input_str[i] <= '9')) {
			View::createRB_Button->label("INVALID\nINPUT");
			return;
		}
	}

	if (strlen(velocityY_Input_str) == 0) {
		View::createRB_Button->label("INVALID\nINPUT");
		return;
	}
	if (!(velocityY_Input_str[0] >= '0' && velocityY_Input_str[0] <= '9' || velocityY_Input_str[0] == '-')) {
		View::createRB_Button->label("INVALID\nINPUT");
		return;
	}
	for (unsigned int i = 1; i < strlen(velocityY_Input_str); i++) {
		if (!(velocityY_Input_str[i] >= '0' && velocityY_Input_str[i] <= '9')) {
			View::createRB_Button->label("INVALID\nINPUT");
			return;
		}
	}

	if (strlen(angvelocity_Input_str) == 0) {
		View::createRB_Button->label("INVALID\nINPUT");
		return;
	}
	if (!(angvelocity_Input_str[0] >= '0' && angvelocity_Input_str[0] <= '9' || angvelocity_Input_str[0] == '-')) {
		View::createRB_Button->label("INVALID\nINPUT");
		return;
	}
	for (unsigned int i = 1; i < strlen(angvelocity_Input_str); i++) {
		if (!(angvelocity_Input_str[i] >= '0' && angvelocity_Input_str[i] <= '9')) {
			View::createRB_Button->label("INVALID\nINPUT");
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
					printf("(%lf,%lf)\n", prenum, curnum);
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
	View::createRB_Button->label("Create\nSuccessfully");
	(View::getWindowsPtr())->onUpdateRigidBodyData(createMode, rb);
}

void onSimulateTimeFlyTriggered(Fl_Widget* sender, void*) {
	
	Fl_Button * but = (Fl_Button*)sender;
	if (strcmp((but->label()), "Simulate") == 0) {
		View::simulating = true;
		but->label("Stop");
	}
	else {
		View::simulating = false;
		but->label("Simulate");
	}
}

void simulate(void *sender) {
	if (View::simulating) {
		//printf("Simulating!\n");
		(View::getWindowsPtr())->onSimulateTimeFlyData(1);
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
	double fx = atof(fx_Input_str);
	double fy = atof(fy_Input_str);

	(View::getWindowsPtr())->onAddForceFieldData(Vec(fx, fy));
}

void onClearTriggered(Fl_Widget* sender, void*) {
	(View::getWindowsPtr())->onClearUserRigidBodyCommand();
}

