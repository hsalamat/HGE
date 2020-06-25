//Modern OpenGL Glad (https://glad.dav1d.de/)
//Glad is more modern than Glew
// it generates a loader for your exact needs based on the official specifications from the Khronos SVN.
//Let's add the Glad library to our vendor folder and update the premake file and create a premake file for Glad as well.

#include "HGE.h"  

class ExampleLayer : public HGE::Layer
{
public:
	ExampleLayer() :Layer("Example")
	{

	}

	void OnUpdate() override
	{
		HGE_INFO("ExampleLayer::Update");
	}
	void OnEvent(HGE::Event& event) override
	{
		HGE_TRACE("{0}", event);
	}
};


class Sandbox :public HGE::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		//step11
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
