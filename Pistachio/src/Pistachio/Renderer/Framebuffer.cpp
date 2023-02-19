#include "papch.h"
#include "Framebuffer.h"

#include "Pistachio/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace Pistachio
{
    Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None: PA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
        case RendererAPI::API::OpenGL: return CreateRef<OpenGLFramebuffer>(spec);
        }

        PA_CORE_ASSERT(false, "Unknown RendererAPI")
        return nullptr;
    }
}
