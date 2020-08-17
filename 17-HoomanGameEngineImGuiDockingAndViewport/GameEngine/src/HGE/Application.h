#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "HGE/Events/ApplicationEvent.h"
#include "Window.h"
#include "HGE/LayerStack.h"

//step5
#include "HGE/ImGui/ImGuiLayer.h"

namespace HGE {
	class  Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* Layer);
		void PushOverlay(Layer* Layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;

		//step6
		ImGuiLayer* m_ImGuiLayer;

		bool m_Running = true;

		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	//To be defined in the client
	Application* CreateApplication();
}

