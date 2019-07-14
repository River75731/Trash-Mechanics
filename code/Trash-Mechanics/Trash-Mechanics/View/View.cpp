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
	Fl::check(); Fl::redraw();	
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
	std::cout << "Successfully change the position of polygon ID : " << id << " .\n\n";
	m_system.drawSystem();
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
	ViewCircle* temp = new ViewCircle(ViewPoint(center), r, id, v, ew, ec, fc);
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








