#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "HGE/Events/ApplicationEvent.h"
#include "Window.h"
#include "HGE/LayerStack.h"
#include "HGE/ImGui/ImGuiLayer.h"

//step3 
#include "HGE/Renderer/Shader.h"

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

		ImGuiLayer* m_ImGuiLayer;

		bool m_Running = true;

		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

		//step4
		std::unique_ptr<Shader> m_Shader;

		static Application* s_Instance;
	};

	//To be defined in the client
	Application* CreateApplication();
}

