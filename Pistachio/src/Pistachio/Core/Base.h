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

#ifdef PA_ENABLE_ASSERTS
	#define PA_ASSERT(x, ...) { if(!(x)) { PA_ERROR("Assertion Failed: {0}", __VA_ARGS__); PA_DEBUGBREAK(); } }
	#define PA_CORE_ASSERT(x, ...) { if(!(x)) { PA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); PA_DEBUGBREAK(); } }
#else
	#define PA_ASSERT(x, ...)
	#define PA_CORE_ASSERT(x, ...)
#endif

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
