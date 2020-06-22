#pragma once
//main entry point is going to create the engine
#ifdef HGE_PLATFORM_WINDOWS

extern HGE::Application* HGE::CreateApplication();

int main(int argc, char** argv)
{
	HGE::Log::Init();
	
	HGE_CORE_WARN("Initialized Log!");

	int a = 5;
	HGE_INFO("Hello Var = {0}", a);

	//create it on the heap for now
	auto app = HGE::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif