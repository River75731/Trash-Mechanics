#include "View.h"

View::View()
{
}

View::~View()
{
}

void View::refresh()
{
	m_system.drawSystem();
}

bool View::createViewWindow(const std::string & name, const Vec & topleft, const int & w, const int & h, const Fl_Color & c, const bool & v) 
{
	std::cout << "Try to build a new window.\n";
	ViewWindow* temp = new ViewWindow(topleft, w, h, v, name, c);
	temp->show();
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
	if (!m_system.getWINDOW()) std::cout << "Now the operating window is '" << m_system.getWINDOW()->getname() << "'.\n\n";
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
	if (v.getX() >= Fl::w() || v.getX() <= 0 || v.getY() >= Fl::h() || v.getY() <= 0)
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
	if (v.getX() >= Fl::w() || v.getX() <= 0 || v.getY() >= Fl::h() || v.getY() <= 0)
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
	m_system.drawSystem();
	std::cout << "Successfully create polygon ID : " << id << " .\n\n";
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
	m_system.drawSystem();
	std::cout << "Successfully delete a polygon ID : " << id << " .\n\n";
	return true;
}

bool View::changeViewPolygon(const int & id, const Poly & p)
{
	std::cout << "Try to change the position of polygon ID : "<<id<<" .\n";
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
	m_system.drawSystem();
	std::cout << "Successfully delete polygon ID : " << id << " .\n";
	return true;
}



