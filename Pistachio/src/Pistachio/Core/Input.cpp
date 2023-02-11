#include "papch.h"
#include "Pistachio/Core/Input.h"

#ifdef PA_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsInput.h"
#endif

namespace Pistachio
{
    Scope<Input> Input::s_Instance = Input::Create();

    Scope<Input> Input::Create()
    {
#ifdef PA_PLATFORM_WINDOWS
        return CreateScope<WindowsInput>();
#else
        PA_CORE_ASSERT(false, "Unknown platform!")
        return nullptr;
#endif
    }

}
