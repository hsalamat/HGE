#include "HGE.h"  

class Sandbox :public HGE::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};


HGE::Application* HGE::CreateApplication()
{
	return new Sandbox();
}
