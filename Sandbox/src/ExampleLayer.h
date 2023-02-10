#pragma once

#include "Pistachio.h"

class ExampleLayer : public Pistachio::Layer
{
public:
    ExampleLayer();
    virtual ~ExampleLayer() = default;
    
    virtual void OnAttach() override;
    virtual void OnDetach() override;
    
    void OnUpdate(Pistachio::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(Pistachio::Event& e) override;
private:
    Pistachio::ShaderLibrary m_ShaderLibrary;
    Pistachio::Ref<Pistachio::Shader> m_Shader;
    Pistachio::Ref<Pistachio::VertexArray> m_VertexArray;

    Pistachio::Ref<Pistachio::Shader> m_FlatColorShader;
    Pistachio::Ref<Pistachio::VertexArray> m_SquareVA;

    Pistachio::Ref<Pistachio::Texture2D> m_Texture, m_TransparentTexture;

    Pistachio::OrthographicCameraController m_CameraController;
    glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};
