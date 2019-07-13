#include "View.h"

View::View()
{
}

View::~View()
{
}

bool View::createViewWindow(const Vec & topleft, const int & w, const int & h, const std::string & name, const Fl_Color & c, const bool & v) 
{
	ViewWindow temp(topleft, w, h, v, name, c);
	temp.show();
	if (!v) temp.hide();
	m_system.attach(temp);
	std::cout << "attached" << std::endl;
	m_system.setWINDOW(temp);
	return true;
}

bool View::deleteViewWindow(const std::string & name)
{
	std::vector<ViewWindow>::iterator temp = m_system.getWindow(name);
	if (temp == m_system.getnullwindow())
	{
		std::cout << "Cannot find window '" << name << "' ." << std::endl;
		return false;
	}
	else
	{
		if (*temp == m_system.getWINDOW())
		{
			m_system.setWINDOW(*(m_system.getnullwindow() - 1));
		}
		m_system.deletewindow(temp);
		return true;
	}
}

bool View::createViewPolygon(const int & id, const Poly & p, const int & ew, const Fl_Color & ec, const Fl_Color & fc, const bool & v)
{
	if (m_system.getwindownum() == 0) //DEFAULT=empty
	{
		std::cout << "ERROR: No window ." << std::endl;
		return false;
	}
	ViewPolygon temp(p, id, v, ew, ec, fc);
	m_system.getWINDOW().attach(temp);
	return true;
}
