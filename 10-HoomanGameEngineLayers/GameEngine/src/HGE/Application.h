#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "HGE/Events/ApplicationEvent.h"
#include "Window.h"

//step5
#include "HGE/LayerStack.h"

namespace HGE {
	class  Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);

		//step6
		void PushLayer(Layer* Layer);
		void PushOverlay(Layer* Layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		//step7
		LayerStack m_LayerStack;
	};

	//To be defined in the client
	Application* CreateApplication();
}

