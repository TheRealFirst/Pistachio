#pragma once
#include "Pistachio.h"
#include "Panels/SceneHierarchyPanel.h"

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
    	bool OnKeyPressed(KeyPressedEvent& e);

    	void NewScene();
    	void OpenScene();
    	void SaveSceneAs();
    	void CloseApplication();
    private:
        OrthographicCameraController m_CameraController;
        Ref<Framebuffer> m_Framebuffer;

        Ref<Scene> m_ActiveScene;
        Entity m_SquareEntity;
        Entity m_CameraEntity;
        Entity m_SecondCamera;

        Ref<Texture2D> m_Texture;

        bool m_ViewportFocused = false;
        bool m_ViewportHovered = false;
        glm::vec2 m_ViewportSize = {0, 0};

    	int m_GizmoType = -1;

    	// Panels
    	SceneHierarchyPanel m_SceneHierarchyPanel;
    };
}
