//The problem with previous example is that we can't access to IsKeyPressed(GLFW_KEY_TAB) without including GLFW in our sandbox.
//The goal is to be able to somthing like
//if(HGE::Input::IsKeyPressed(GLFW_KEY_TAB))
//HGE_INFO("Tab Key is pressed!")
//
//Now we are going to use our key codes
//if(HGE::Input::IsKeyPressed(HGE_KEY_TAB))
//HGE_TRACE("Tab Key is pressed!");
//This removes the dependency of GLFW. For example in GFLW, tab key code is "258" , but microsoft Win32 is "9"

//Run the application and hit the tab key and check out the log


#include "HGE.h"  

class ExampleLayer : public HGE::Layer
{
public:
	ExampleLayer() :Layer("Example")
	{

	}

	void OnUpdate() override
	{
		//step4
		//HGE_INFO("ExampleLayer::Update");


		if (HGE::Input::IsKeyPressed(HGE_KEY_TAB))
			HGE_TRACE("Tab Key is pressed!");
	}
	void OnEvent(HGE::Event& event) override
	{
		//step5 we don't want to log every event
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
		PushOverlay(new HGE::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};


HGE::Application* HGE::CreateApplication()
{
	return new Sandbox();
}
