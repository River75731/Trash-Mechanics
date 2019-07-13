#include "ViewSystem.h"

ViewSystem::ViewSystem()
{
	m_DEFAULT_WINDOW = new ViewWindow();
	m_DEFAULT_WINDOW->show();
	m_DEFAULT_WINDOW->hide();
}

int ViewSystem::getwindownum() const
{
	return m_windowset.size();
}

std::vector<ViewWindow>::iterator ViewSystem::getWindow(const char*  name) 
{
	if (m_windowset.empty()) return m_windowset.end();
	for (std::vector<ViewWindow>::iterator i = m_windowset.begin(); i != m_windowset.end(); i++)
		if (strcmp(i->getname(), name) == 0) return i;
	return m_windowset.end();
}

std::vector<ViewWindow>::iterator ViewSystem::getnullwindow() 
{
	return m_windowset.end();
}

bool ViewSystem::deletewindow(std::vector<ViewWindow>::iterator & temp)
{
	m_windowset.erase(temp);
	return true;
}

ViewWindow* ViewSystem::getWINDOW() const
{
	return m_DEFAULT_WINDOW;
}

bool ViewSystem::setWINDOW(std::vector<ViewWindow>::iterator  vw, const bool &v)
{
	if(v) m_DEFAULT_WINDOW = &(*vw);
	else m_DEFAULT_WINDOW = nullptr;
	return true;
}

bool ViewSystem::attach(const ViewWindow & vw)
{
	m_windowset.push_back(vw);
	return true;
}

void ViewSystem::draw()
{
	if (m_windowset.empty()) return;
	for (std::vector<ViewWindow>::iterator i = m_windowset.begin(); i != m_windowset.end(); i++)
	{
		i->draw();
		if (!(i->getwinvisible())) i->hide();
		else i->show();
	}
}

void ViewSystem::simpledraw()
{
	getWINDOW()->draw();
}

ViewSystem::~ViewSystem()
{
	//free(m_DEFAULT_WINDOW);
	return;
}
