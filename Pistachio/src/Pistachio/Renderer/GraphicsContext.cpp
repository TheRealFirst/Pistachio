#include "papch.h"
#include "Pistachio/Renderer/GraphicsContext.h"

#include "Pistachio/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Pistachio {

    Scope<GraphicsContext> GraphicsContext::Create(void* window)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    PA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
        }

        PA_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}