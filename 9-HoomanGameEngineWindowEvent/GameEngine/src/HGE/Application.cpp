#include "hgepch.h"
#include "Application.h"
#include "HGE/Log.h"
#include <GLFW/glfw3.h>

namespace HGE {

	//step3
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());

		//step4
		//m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	//step2
	void Application::OnEvent(Event& e)
	{
		//step11
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch <WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		HGE_CORE_TRACE("{0}",e);
	}


	void Application::Run()
	{
		
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	//step 10
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
