#include "papch.h"
#include "Pistachio/Renderer/Texture.h"

#include "Pistachio/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Pistachio
{
    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None: PA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
        case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture2D>(path);
        }
        
        PA_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}
