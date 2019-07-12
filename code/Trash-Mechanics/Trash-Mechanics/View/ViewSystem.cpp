#include "ViewSystem.h"

ViewSystem::ViewSystem()
{
}

int ViewSystem::getwindownum() const
{
	return m_windowset.size();
}

std::vector<ViewWindow>::iterator ViewSystem::getWindow(const std::string & name)
{
	for (std::vector<ViewWindow>::iterator i = m_windowset.begin(); i != m_windowset.end(); i++)
		if (strcmp(i->getname(), name.c_str()) == 0) return i;
	return m_windowset.end();
}

std::vector<ViewWindow>::iterator ViewSystem::getnullwindow()
{
	return m_windowset.end();
}

bool ViewSystem::deletewindow(std::vector<ViewWindow>::const_iterator & temp)
{
	m_windowset.erase(temp);
	return true;
}

ViewWindow ViewSystem::getWINDOW() const
{
	return m_DEFAULT_WINDOW;
}

bool ViewSystem::setWINDOW(const ViewWindow & vw)
{
	m_DEFAULT_WINDOW = vw;
	return true;
}

bool ViewSystem::attach(const ViewWindow & vw)
{
	m_windowset.push_back(vw);
	return true;
}

void ViewSystem::draw()
{
	for (std::vector<ViewWindow>::iterator i = m_windowset.begin(); i != m_windowset.end(); i++)
	{
		i->draw();
		if (!(i->getwinvisible())) i->hide();
		else i->show();
	}
}

ViewSystem::~ViewSystem()
{
	return;
}
