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
    m_Texture = Pistachio::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Pistachio::Timestep ts)
{
    // Update
    m_CameraController.OnUpdate(ts);

    // Render
    Pistachio::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
    Pistachio::RenderCommand::Clear();

    Pistachio::Renderer2D::BeginScene(m_CameraController.GetCamera());

    Pistachio::Renderer2D::DrawQuad({-1.0f, 0.0f}, {0.8f, 0.8f}, {0.8f, 0.2f, 0.3f, 1.0f});
    Pistachio::Renderer2D::DrawQuad({0.5f, -0.5f}, {0.5f, 0.75f}, {0.2f, 0.3f, 0.8f, 1.0f});
    Pistachio::Renderer2D::DrawQuad({0.0f, 0.0f, -0.1f}, {10.5f, 10.0f}, m_Texture);
    Pistachio::Renderer::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
    ImGui::Begin("Settings");
    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
    ImGui::End();
}

void Sandbox2D::OnEvent(Pistachio::Event& e)
{
    m_CameraController.OnEvent(e);
}
