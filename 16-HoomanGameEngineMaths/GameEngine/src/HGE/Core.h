#pragma once
#ifdef HGE_PLATFORM_WINDOWS
	#ifdef HGE_BUILD_DLL
		#define HGE_API __declspec(dllexport)
	#else
		#define HGE_API __declspec(dllimport)
	#endif
#else
	#error HGE only supports Windows
#endif 

#ifdef HGE_DEBUG
#define HGE_ENABLE_ASSERTS
#endif

#ifdef HGE_ENABLE_ASSERTS
#define HGE_ASSERT(x, ...) { if(!(x)) { HGE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define HGE_CORE_ASSERT(x, ...) { if(!(x)) { HGE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define HGE_ASSERT(x, ...)
#define HGE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HGE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
