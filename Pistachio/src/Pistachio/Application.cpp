#include "papch.h"
#include "Application.h"

#include "Pistachio/Log.h"
#include "Pistachio/Events/ApplicationEvent.h"

namespace Pistachio 
{
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
