//step0: Rendering an OpenGL Context window
//Take a look at glfwMakeContextCurrent function in WindowsWindow.cpp and Conext.c
//GLFW supprots OpenGL and Vulkan, but what if we want to support DirectX, Metal, or PS4
//That's why we can't have glfwMakeContextCurrent inside void WindowsWindow::Init(const WindowProps& props)
//And we will abstact out glfwMakeContextCurrent function in an opengl conext file!

#include "HGE.h"  
#include "imgui/imgui.h"

class ExampleLayer : public HGE::Layer
{
public:
	ExampleLayer() :Layer("Example")
	{

	}

	void OnUpdate() override
	{
	
		//HGE_INFO("ExampleLayer::Update");

		if (HGE::Input::IsKeyPressed(HGE_KEY_TAB))
			HGE_TRACE("Tab Key is pressed!");
	}


	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(HGE::Event& event) override
	{
		//we don't want to log every event
		//HGE_TRACE("{0}", event);
		if (event.GetEventType() == HGE::EventType::KeyPressed)
		{
			HGE::KeyPressedEvent& e = (HGE::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HGE_KEY_TAB)
				HGE_TRACE("Tab key is pressed (event)!");
			HGE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};


class Sandbox :public HGE::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}
};


HGE::Application* HGE::CreateApplication()
{
	return new Sandbox();
}
