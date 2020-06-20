#pragma once
//Hooman:
//In computer programming, a precompiled header is a (C or C++) header file that is compiled into an intermediate form that is faster to process for the compiler. Usage of precompiled headers may significantly reduce compilation time, especially when applied to large header files, header files that include many other header files, or header files that are included in many translation units. 


//We are going to refactor our code and use hgepch.h precompiled header and remove all the includes from the rest of the code
//In this exercise we are going to change premake5.lua to add 	these two lines
//pchheader "hgepch.h"
//pchsource "GameEngine/src/hgepch.cpp"
//Make you add #include "hgepch.h" to every "cpp file" like Application.cpp...
//After you run the lua, 
//Right Click on hgepch.cpp and go to the properties --> Property Page C/C++ --> Precompiled Headers
//And check if "Precompiled Header File" is set to hgepch.h
//"Precompiled Header" is set to "Create"
//Also go to GameEngine project property --> C/C++ --> Precompiled Headers
//And check if "Precompiled Header File" is set to hgepch.h
//"Precompiled Header" is set to "Use"
//"Go to Tools > Options... > Projects and Solutions > VC++ Project Settings
//Build Timing" set to "Yes" 
//Look at your Project Performance Summary:
// 3326 ms  Hooman Game Engine\HGE\7 - HoomanGameEnginePrecompiledHeader\GameEngine\GameEngine.vcxproj   1 calls


//go to GameEngine project property-- > C / C++ -- > Precompiled Headers
//change "Precompiled Header"  set to "Not Using Precompiled Headers"
// Project Performance Summary shows a bit longer building time
// 3895 ms  Hooman Game Engine\HGE\7 - HoomanGameEnginePrecompiledHeader\GameEngine\GameEngine.vcxproj   1 calls






#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#ifdef HGE_PLATFORM_WINDOWS
#include <Windows.h>
#endif