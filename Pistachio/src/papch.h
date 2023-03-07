#pragma once


#include "Pistachio/Core/PlatformDetection.h"

#ifdef PA_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

#include "Pistachio/Core/Base.h"

#include "Pistachio/Core/Log.h"

#include "Pistachio/Debug/Instrumentor.h"

#ifdef PA_PLATFORM_WINDOWS
    #include <Windows.h>
#endif
