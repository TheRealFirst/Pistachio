#include "Sandbox2D.h"

#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"
#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D() : Layer("Sandbox2D"), m_CameraController(3840.0f / 2160.0f), m_SquareColor({0.2f, 0.3f, 0.8f, 1.0f})
{
}

void Sandbox2D::OnAttach()
{
    PA_PROFILE_FUNCTION()
    
    m_Texture = Pistachio::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
    PA_PROFILE_FUNCTION()
}

void Sandbox2D::OnUpdate(Pistachio::Timestep ts)
{
    PA_PROFILE_FUNCTION()
    
    m_CameraController.OnUpdate(ts);
    
    // Render
    Pistachio::Renderer2D::ResetStats();
    {
        PA_PROFILE_SCOPE("Renderer::Prep");
        Pistachio::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        Pistachio::RenderCommand::Clear();
    }

    {
        static float rotation = 0.0f;
        rotation += ts * 50.0f;
        
        PA_PROFILE_SCOPE("Renderer::Draw");
        Pistachio::Renderer2D::BeginScene(m_CameraController.GetCamera());
        Pistachio::Renderer2D::DrawRotatedQuad({-2.0f, 0.0f}, {0.8f, 0.8f}, -45.0f, {0.8f, 0.2f, 0.3f, 1.0f});
        Pistachio::Renderer2D::DrawQuad({-1.0f, 0.0f}, {0.8f, 0.8f}, {0.8f, 0.2f, 0.3f, 1.0f});
        Pistachio::Renderer2D::DrawQuad({0.5f, -0.5f}, {0.5f, 0.75f}, m_SquareColor);
        Pistachio::Renderer2D::DrawQuad({0.0f, 0.0f, -0.1f}, {20.0f, 20.0f}, m_Texture, 10.0f);
        Pistachio::Renderer2D::DrawRotatedQuad({2.0f, 0.0f, 0.0f}, {1.0f, 1.0f}, rotation, m_Texture, 20.0f, {0.8f, 0.2f, 0.3f, 1.0f});
        Pistachio::Renderer2D::EndScene();

        Pistachio::Renderer2D::BeginScene(m_CameraController.GetCamera());
        for(float y = -5.0f; y < 5.0f; y += 0.5f)
        {
            for(float x = -5.0f; x < 5.0f; x += 0.5f)
            {
                glm::vec4 color = {(x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f};
                Pistachio::Renderer2D::DrawQuad({x, y}, {0.45f, 0.45}, color);
            }   
        }
        Pistachio::Renderer2D::EndScene();
    }
}

void Sandbox2D::OnEvent(Pistachio::Event& e)
{
    PA_PROFILE_FUNCTION()
    
    m_CameraController.OnEvent(e);
}
