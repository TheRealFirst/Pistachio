#pragma once
#include "Pistachio.h"

class Sandbox2D : public Pistachio::Layer
{
public:
    Sandbox2D();
    virtual ~Sandbox2D() = default;
    
    virtual void OnAttach() override;
    virtual void OnDetach() override;
    
    virtual void OnUpdate(Pistachio::Timestep ts) override;
    virtual void OnImGuiRender() override;
    virtual void OnEvent(Pistachio::Event& event) override;
private:
    Pistachio::OrthographicCameraController m_CameraController;

    // Temp
    Pistachio::Ref<Pistachio::VertexArray> m_SquareVA;
    Pistachio::Ref<Pistachio::Shader> m_FlatColorShader;

    Pistachio::Ref<Pistachio::Texture2D> m_Texture;
    
    glm::vec4 m_SquareColor = {0.2f, 0.3f, 0.8f, 1.0f};
};
