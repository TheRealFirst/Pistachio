#pragma once

#include "Pistachio/Core/Core.h"

#include "Pistachio/Core/Window.h"
#include "Pistachio/Core/LayerStack.h"
#include "Pistachio/Events/Event.h"
#include "Pistachio/Events/ApplicationEvent.h"

#include "Pistachio/Core/Timestep.h"

#include "Pistachio/ImGui/ImGuiLayer.h"

namespace Pistachio 
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() {return *m_Window;}

		inline static Application& Get()
		{
			return *s_Instance;
		}
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
