#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"
#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D() : Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
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
    {
        PA_PROFILE_SCOPE("Renderer::Prep");
        Pistachio::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        Pistachio::RenderCommand::Clear();
    }

    {
        PA_PROFILE_SCOPE("Renderer::Draw");
        Pistachio::Renderer2D::BeginScene(m_CameraController.GetCamera());

        Pistachio::Renderer2D::DrawRotatedQuad({-1.0f, 0.0f}, {0.8f, 0.8f}, glm::radians(-45.0f), {0.8f, 0.2f, 0.3f, 1.0f});
        Pistachio::Renderer2D::DrawQuad({0.5f, -0.5f}, {0.5f, 0.75f}, {0.2f, 0.3f, 0.8f, 1.0f});
        Pistachio::Renderer2D::DrawQuad({0.0f, 0.0f, -0.1f}, {10.0f, 10.0f}, m_Texture, 10.0f, glm::vec4(1.0f, 0.9f, 0.9f, 1.0f));
        Pistachio::Renderer::EndScene();
    }
}

void Sandbox2D::OnImGuiRender()
{
    PA_PROFILE_FUNCTION()
    
    ImGui::Begin("Settings");
    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
    ImGui::End();
}

void Sandbox2D::OnEvent(Pistachio::Event& e)
{
    PA_PROFILE_FUNCTION()
    
    m_CameraController.OnEvent(e);
}
