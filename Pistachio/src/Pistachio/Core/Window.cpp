#include "papch.h"
#include "Pistachio/Core/Window.h"

#ifdef PA_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.h"
#endif

namespace Pistachio
{
    Scope<Window> Window::Create(const WindowProbs& props)
    {
#ifdef PA_PLATFORM_WINDOWS
        return CreateScope<WindowsWindow>(props);
#else
        PA_CORE_ASSERT(false, "Unknown platform!");
        return nullptr;
#endif
    }
}
