//Layer Stack
//Determine what order things are drawn in.
//When a layer is enabled, it will appear on the screen in the order that exist in the layer stack.

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
	}
	~Sandbox()
	{

	}
};


HGE::Application* HGE::CreateApplication()
{
	return new Sandbox();
}
