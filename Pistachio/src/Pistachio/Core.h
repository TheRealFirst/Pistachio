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