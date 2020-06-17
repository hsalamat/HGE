#pragma once
//Add HGE_PLATFORM_WINDOWS to both preprocessors macro (C++-->Preprocessor --> Preprocessor Definition) in the sanbox and GameEngine
#ifdef HGE_PLATFORM_WINDOWS
//Add HGE_BUILD_DLL to only GameEngine C++-->Preprocessor --> Preprocessor Definition
	#ifdef HGE_BUILD_DLL
		#define HGE_API __declspec(dllexport)
	#else
		#define HGE_API __declspec(dllimport)
	#endif
#else
	#error HGE only supports Windows
#endif 

