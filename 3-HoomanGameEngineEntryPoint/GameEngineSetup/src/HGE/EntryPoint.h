#pragma once
//main entry point is going to create the engine
#ifdef HGE_PLATFORM_WINDOWS

//this is a function that we define  somewhere else which will actually return that application for us!
extern HGE::Application* HGE::CreateApplication();

int main(int argc, char** argv)
{
	std::cout << "Hooman Game Engine\n" << std::endl;
	//create it on the heap for now
	auto app = HGE::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif