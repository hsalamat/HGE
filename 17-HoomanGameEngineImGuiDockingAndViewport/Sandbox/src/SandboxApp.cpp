//Notice that we are using imgui-docking under vendor folder!
//Remove ImGuiOpenGLRenderer.h/cpp from the platform/opengl
//Now you can drag ImGui even outside the main window!
//Go to examples -> Dockspace in ImGui and try to dock your window

#include "HGE.h"  
//step13
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


	//step15
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
		//step4
		//PushOverlay(new HGE::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};


HGE::Application* HGE::CreateApplication()
{
	return new Sandbox();
}
