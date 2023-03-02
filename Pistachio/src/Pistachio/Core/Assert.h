#pragma once

#include "Pistachio/Core/Base.h"
#include "Pistachio/Core/Log.h"
#include <filesystem>

#ifdef PA_ENABLE_ASSERTS


// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define PA_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { PA##type##ERROR(msg, __VA_ARGS__); PA_DEBUGBREAK(); } }
#define PA_INTERNAL_ASSERT_WITH_MSG(type, check, ...) PA_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define PA_INTERNAL_ASSERT_NO_MSG(type, check) PA_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", PA_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define PA_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define PA_INTERNAL_ASSERT_GET_MACRO(...) PA_EXPAND_MACRO( PA_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, PA_INTERNAL_ASSERT_WITH_MSG, PA_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define PA_ASSERT(...) PA_EXPAND_MACRO( PA_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define PA_CORE_ASSERT(...) PA_EXPAND_MACRO( PA_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define PA_ASSERT(...)
#define PA_CORE_ASSERT(...)
#endif
