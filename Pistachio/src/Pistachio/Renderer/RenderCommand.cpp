#include "papch.h"
#include "Pistachio/Renderer/RenderCommand.h"

namespace Pistachio
{
    Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}
