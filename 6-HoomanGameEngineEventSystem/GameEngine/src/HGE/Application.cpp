#include "Application.h"
#include "HGE/Events//ApplicationEvent.h"
#include "HGE/Log.h"

namespace HGE {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HGE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			HGE_TRACE(e);
		}
		while (true);
	}
}
