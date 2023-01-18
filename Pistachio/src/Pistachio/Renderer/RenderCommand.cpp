#include "papch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Pistachio
{
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();
}
