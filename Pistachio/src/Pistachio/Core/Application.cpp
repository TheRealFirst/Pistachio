#include "papch.h"
#include "Pistachio/Core/Application.h"

#include "Pistachio/Renderer/Renderer.h"

#include "Pistachio/Core/Input.h"

#include "GLFW/glfw3.h"

namespace Pistachio 
{
	Application* Application::s_Instance = nullptr;
	
	Application::Application()
	{
		PA_PROFILE_FUNCTION()
		
		PA_CORE_ASSERT(!s_Instance, "Application already exists!")
		s_Instance = this;
		
		m_Window = Window::Create();
		m_Window->SetEventCallback(PA_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
		PA_PROFILE_FUNCTION()

		Renderer::Shutdown();
	}

	void Application::Run()
	{
		PA_PROFILE_FUNCTION()

		while (m_Running)
		{
			PA_PROFILE_SCOPE("RunLoop")
			
			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if(!m_Minimized)
			{
				{
					PA_PROFILE_SCOPE("LayerStack OnUpdate")
					
					for(Layer* layer : m_LayerStack)
						layer->OnUpdate(timestep);
				}
			}
			
			{
				PA_PROFILE_SCOPE("Layerstack OnImGuiUpdate")
				m_ImGuiLayer->Begin();
				for(Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
				m_ImGuiLayer->End();
			
				m_Window->OnUpdate();
			}
		}
	}

	void Application::OnEvent(Event& e)
	{
		PA_PROFILE_FUNCTION()
		
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(PA_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(PA_BIND_EVENT_FN(Application::OnWindowResize));

		for(auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			(*it)->OnEvent(e);
			if(e.Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		PA_PROFILE_FUNCTION()

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		PA_PROFILE_FUNCTION()

		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		PA_PROFILE_FUNCTION()
		
		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
		
		return false;
	}
}