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
        Ref<Framebuffer> m_Framebuffer;

        Ref<Scene> m_ActiveScene;
        entt::entity m_SquareEntity;

        Ref<Texture2D> m_Texture;

        bool m_ViewportFocused = false;
        bool m_ViewportHovered = false;
        glm::vec2 m_ViewportSize = {0, 0};
    };
}
