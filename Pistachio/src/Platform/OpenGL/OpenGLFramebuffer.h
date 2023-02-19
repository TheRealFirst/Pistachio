#pragma once
#include "Pistachio/Renderer/Framebuffer.h"

namespace Pistachio
{
    class OpenGLFramebuffer : public Framebuffer
    {
    public:
        OpenGLFramebuffer(const FramebufferSpecification& spec);
        virtual ~OpenGLFramebuffer();

        void Invalidate();

        virtual void Bind() override;
        virtual void UnBind() override;

        virtual void Resize(uint32_t width, uint32_t height) override;

        virtual const FramebufferSpecification& GetSpecification() const override {return m_Specification;}

        virtual uint32_t GetColorAttachementRendererID() const override {return m_ColorAttachement;}
    private:
        uint32_t m_RendererID = 0;
        uint32_t m_ColorAttachement = 0;
        uint32_t m_DepthAttachement = 0;
        FramebufferSpecification m_Specification;
    };
}
