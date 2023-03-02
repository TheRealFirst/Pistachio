#pragma once

#include <memory>

#include "Pistachio/Core/PlatformDetection.h"

#ifdef PA_DEBUG
	#if defined(PA_PLATFORM_WINDOWS)
		#define PA_DEBUGBREAK() __debugbreak()
	#elif defined(PA_PLATFORM_LINUX)
		#include <signal.h>
		#define PA_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define PA_ENABLE_ASSERTS
#else
	#define PA_DEBUGBREAK()
#endif

#define PA_EXPAND_MACRO(x) x
#define PA_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define PA_BIND_EVENT_FN(fn)  [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Pistachio
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#include "Pistachio/Core/Log.h"
#include "Pistachio/Core/Assert.h"
