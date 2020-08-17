//step0: Shaders https://www.khronos.org/opengl/wiki/Shader_Compilation
//We copy the code from this link and create a new shader.cpp and place it in the Shader constructor


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
