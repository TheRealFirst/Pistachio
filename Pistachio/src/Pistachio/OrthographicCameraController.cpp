#include "papch.h"
#include "OrthographicCameraController.h"

#include "Pistachio/Input.h"
#include "Pistachio/KeyCodes.h"

namespace Pistachio
{
    OrthographicCameraController::OrthographicCameraController(float asceptRatio, bool rotation) : m_AspectRatio(asceptRatio), m_Rotation(rotation), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel)
    {
    }

    void OrthographicCameraController::OnUpdate(Timestep ts)
    {
        if(Input::IsKeyPressed(PA_KEY_A))
            m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
        else if(Input::IsKeyPressed(PA_KEY_D))
            m_CameraPosition.x += m_CameraTranslationSpeed * ts;
		
        if(Input::IsKeyPressed(PA_KEY_W))
            m_CameraPosition.y += m_CameraTranslationSpeed * ts;
        else if(Input::IsKeyPressed(PA_KEY_S))
            m_CameraPosition.y -= m_CameraTranslationSpeed * ts;

        if(m_Rotation)
        {
            if(Input::IsKeyPressed(PA_KEY_Q))
                m_CameraRotation += m_CameraRotationSpeed * ts;
            else if(Input::IsKeyPressed(PA_KEY_E))
                m_CameraRotation -= m_CameraRotationSpeed * ts;
        }

        m_Camera.SetPosition(m_CameraPosition);
        m_Camera.SetRotation(m_CameraRotation);

        m_CameraTranslationSpeed = m_ZoomLevel * 2;
    }

    void OrthographicCameraController::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<MouseScrolledEvent>(PA_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
        dispatcher.Dispatch<WindowResizeEvent>(PA_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
    }

    bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
    {
        m_ZoomLevel -= e.GetYOffset() * 0.5f;
        m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
        m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        return false;
    }

    bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
    {
        m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
        m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        return false;
    }
}
