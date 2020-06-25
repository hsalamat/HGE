//https://glm.g-truc.net/0.9.9/index.html
//OpenGL Mathematics(GLM) is a header only C++ mathematics library for graphics software based on the OpenGL Shading Language(GLSL) specifications.
//GLM provides classesand functions designedand implemented with the same naming conventionsand functionalities than GLSL so that anyone who knows GLSL, can use GLM as well in C++.
//We are going to add our git as a submodule!
//git submodule add https://github.com/g-truc/glm HGE/vendor/glm
//Hooman Salamat

#include "HGE.h"  

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
