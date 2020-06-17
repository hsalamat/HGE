#include "HGE.h"  //make sure you add $(SolutionDir)GameEngineSetup\src to "c++-->general-->additional include directories"
//namespace HGE {
//	__declspec(dllimport) void Print();
//}

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
int main()
{
	//create it on the heap for now
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
	return 0;
}