#pragma once

#include "Core.h"
namespace HGE {
	//instead of this class __declspec(dllexport) Application, we are using Macro!
	class HGE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:

	};

	//To be defined in the client
	Application* CreateApplication();
}

