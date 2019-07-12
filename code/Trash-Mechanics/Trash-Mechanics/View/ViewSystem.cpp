#include "ViewSystem.h"

ViewSystem::ViewSystem()
{
}

int ViewSystem::getwindownum() const
{
	return m_windowset.size();
}

ViewWindow * ViewSystem::getWindow(const std::string & name)
{
	for (std::vector<ViewWindow>::iterator i = m_windowset.begin(); i != m_windowset.end(); i++)
		if (strcmp(i->getname(), name.c_str()) == 0) return &(*i);
	return nullptr;
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
		if(i->getwinvisible()) i->draw();
}

ViewSystem::~ViewSystem()
{
	return;
}
