//Make sure you add $(SolutionDir)..\vendor\spdlog\include to both Sandbox and GameEngine 
//C++ --> general --> "additional include Directories"

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
