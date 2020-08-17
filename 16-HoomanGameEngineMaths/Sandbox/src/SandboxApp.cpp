//https://glm.g-truc.net/0.9.9/index.html
//OpenGL Mathematics(GLM) is a header only C++ mathematics library for graphics software based on the OpenGL Shading Language(GLSL) specifications.
//GLM provides classesand functions designedand implemented with the same naming conventionsand functionalities than GLSL so that anyone who knows GLSL, can use GLM as well in C++.
//We are going to add our git as a submodule!
//git submodule add https://github.com/g-truc/glm vendor/glm
//Also, we update the premake5.lua to include glm as a dependency
//Hooman Salamat

#include "HGE.h"  

//step1: just to test if gml has been added correctly
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}
//end of step1

class ExampleLayer : public HGE::Layer
{
public:
	ExampleLayer() :Layer("Example")
	{
		//step2
		auto cam = camera(5.0f, { 0.5f,0.5f });

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
