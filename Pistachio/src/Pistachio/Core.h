#pragma once

#ifdef PA_PLATFORM_WINDOWS
	#ifdef PA_BUILD_DLL
		#define PISTACHIO_API __declspec(dllexport)
	#else
		#define PISTACHIO_API __declspec(dllimport)
	#endif
#else
	#error Pistachio only supports Windows!
#endif

#ifdef PA_DEBUG
	#define PA_ENABLE_ASSERTS
#endif


#ifdef PA_ENABLE_ASSERTS
	#define PA_ASSERT(x, ...) { if(!(x)) { PA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PA_CORE_ASSERT(x, ...) { if(!(x)) { PA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define Pa_ASSERT(x, ...)
	#define PA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define PA_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)