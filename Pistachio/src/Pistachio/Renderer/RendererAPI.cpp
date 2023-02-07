#include "papch.h"
#include "Pistachio/Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Pistachio
{
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

    Scope<RendererAPI> RendererAPI::Create()
    {
        switch (s_API)
        {
        case RendererAPI::API::None: PA_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
        case RendererAPI::API::OpenGL: return CreateScope<OpenGLRendererAPI>();
        }

        PA_CORE_ASSERT(false, "Unknown RendererAPI!")
        return nullptr;
    }
}
