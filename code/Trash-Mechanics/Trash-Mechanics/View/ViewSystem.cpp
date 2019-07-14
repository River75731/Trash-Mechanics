#include "ViewSystem.h"

ViewSystem::ViewSystem()
{
	m_DEFAULT_WINDOW = nullptr;
}

int ViewSystem::getwindownum() const
{
	return m_windowset.size();
}

ViewWindow* ViewSystem::getWindow(const char* name) 
{
	if (m_windowset.empty()) return nullptr;
	for (std::vector<ViewWindow*>::iterator i = m_windowset.begin(); i != m_windowset.end(); i++)
		if (strcmp((*i)->getname(), name) == 0) return *i;
	return nullptr;
}

bool ViewSystem::deletewindow(ViewWindow* &temp)
{
	for (std::vector<ViewWindow*>::iterator i = m_windowset.begin(); i != m_windowset.end(); i++)
	{
		if (*i == temp)
		{
			delete *i;
			m_windowset.erase(i);
			if (m_windowset.empty()) m_DEFAULT_WINDOW = nullptr;
			else m_DEFAULT_WINDOW = *(m_windowset.end() - 1);
			return true;
		}
	}
	return false;
}

ViewWindow* ViewSystem::getWINDOW() const
{
	return m_DEFAULT_WINDOW;
}

bool ViewSystem::setWINDOW(ViewWindow* vw)
{
	m_DEFAULT_WINDOW = vw;
	return true;
}

bool ViewSystem::attach(ViewWindow* vw)
{
	m_windowset.push_back(vw);
	return true;
}

void ViewSystem::drawSystem()
{
	if (m_windowset.empty()) return;
	for (std::vector<ViewWindow*>::iterator i = m_windowset.begin(); i != m_windowset.end(); i++)
	{
		(*i)->draw();
		if (!((*i)->getwinvisible())) (*i)->hide();
		else (*i)->show();
	}
}

ViewSystem::~ViewSystem()
{
	if(m_DEFAULT_WINDOW) delete m_DEFAULT_WINDOW;
	// now we don't free the winsowset
	return;
}
