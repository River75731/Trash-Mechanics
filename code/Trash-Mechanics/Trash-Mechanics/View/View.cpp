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
	std::cout << "Successfully build window: " << std::endl;
	std::cout << "[Window ID : " << m_system.getwindownum() << "]" << std::endl;
	printf("Window topleft : (%d,%d)\n", (int)topleft.getX(), (int)topleft.getY());
	printf("Window width : %d\n", w);
	printf("Window height : %d\n", h);
	printf("Window name : %s\n", name.c_str());
	printf("Window visibility : %d\n", v);
	m_system.setWINDOW(m_system.getWindow(name.c_str()));
	std::cout << "Successfully set " << name << " as operating window." << std::endl;
	return true;
}

bool View::deleteViewWindow(const std::string & name)
{
	std::vector<ViewWindow>::iterator temp = m_system.getWindow(name.c_str());
	if (temp == m_system.getnullwindow())
	{
		std::cout << "Cannot find window '" << name << "' ." << std::endl;
		return false;
	}
	else
	{
		bool status = false;
		if (m_system.getWINDOW() != nullptr)
		{ 
			if (m_system.getWINDOW() == &(*temp))
			{
				if (m_system.getwindownum() > 1) status = true;
			}
		}
		m_system.deletewindow(temp);
		m_system.setWINDOW(m_system.getnullwindow() - 1);
		return true;
	}
}

bool View::createViewPolygon(const int & id, const Poly & p, const int & ew, const Fl_Color & ec, const Fl_Color & fc, const bool & v)
{
	/*if (m_system.getwindownum() == 0) //DEFAULT=empty
	{
		std::cout << "ERROR: No window ." << std::endl;
		return false;
	}*/
	ViewPolygon* temp = new ViewPolygon(p, id, v, ew, ec, fc);
	m_system.getWINDOW()->attach(*temp);
	m_system.getWINDOW()->redraw();
	return true;
}
