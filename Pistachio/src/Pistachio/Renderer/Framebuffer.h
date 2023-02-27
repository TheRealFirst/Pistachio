#pragma once

#include "glm/glm.hpp"
#include "Pistachio/Core/Base.h"

namespace Pistachio
{
    struct FramebufferSpecification
    {
        uint32_t Width = 0, Height = 0;
        uint32_t samples = 1;

        bool SwapChainTarget = false;
    };
    
    class Framebuffer
    {
    public:
        virtual ~Framebuffer() = default;
        
        virtual void Bind() = 0;
        virtual void UnBind() = 0;

        virtual void Resize(uint32_t width, uint32_t height) = 0;  

        virtual uint32_t GetColorAttachementRendererID() const = 0;
        
        virtual const FramebufferSpecification& GetSpecification() const = 0;
        
        static Ref<Framebuffer> Create(const FramebufferSpecification& spec);
    };
}
