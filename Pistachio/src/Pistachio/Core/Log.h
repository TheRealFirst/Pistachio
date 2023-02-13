#pragma once

#include "Pistachio/Core/Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Pistachio {
	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger> GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}


//Core log macros
#define PA_CORE_TRACE(...)   ::Pistachio::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PA_CORE_INFO(...)    ::Pistachio::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PA_CORE_WARN(...)    ::Pistachio::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PA_CORE_ERROR(...)   ::Pistachio::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PA_CORE_CRITICAL(...)::Pistachio::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define PA_TRACE(...)        ::Pistachio::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PA_INFO(...)         ::Pistachio::Log::GetClientLogger()->info(__VA_ARGS__)
#define PA_WARN(...)         ::Pistachio::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PA_ERROR(...)        ::Pistachio::Log::GetClientLogger()->error(__VA_ARGS__)
#define PA_CRITICAL(...)     ::Pistachio::Log::GetClientLogger()->critical(__VA_ARGS__)