#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace HGE {
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

