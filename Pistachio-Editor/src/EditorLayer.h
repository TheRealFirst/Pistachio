#pragma once
#include "Pistachio.h"

namespace Pistachio
{
    class EditorLayer : public Layer
    {
    public:
        EditorLayer();
        ~EditorLayer() override = default;
        
        virtual void OnAttach() override;
        virtual void OnDetach() override;
        
        virtual void OnUpdate(Timestep ts) override;
        virtual void OnImGuiRender() override;
        virtual void OnEvent(Event& event) override;
    private:
        OrthographicCameraController m_CameraController;

        // Temp
        Ref<VertexArray> m_SquareVA;
        Ref<Shader> m_FlatColorShader;
        Ref<Framebuffer> m_Framebuffer;

        Ref<Texture2D> m_Texture;

        glm::vec2 m_ViewportSize = {0, 0};
        
        glm::vec4 m_SquareColor = {0.2f, 0.3f, 0.8f, 1.0f};
    };
}
