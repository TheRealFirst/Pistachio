#pragma once

#include "Core.h"

#include "Pistachio/Window.h"
#include "Pistachio/LayerStack.h"
#include "Pistachio/Events/Event.h"
#include "Pistachio/Events/ApplicationEvent.h"

#include "Pistachio/Core/Timestep.h"

#include "Pistachio/ImGui/ImGuiLayer.h"

namespace Pistachio 
{
	class PISTACHIO_API Application
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
		bool OnWindowClosed(WindowCloseEvent& e);

	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
