#include "papch.h"
#include "VertexArray.h"

#include <memory>

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Pistachio
{
    Ref<VertexArray> VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None: PA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
        case RendererAPI::API::OpenGL: return std::make_shared<OpenGLVertexArray>();
        }

        PA_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }

}
