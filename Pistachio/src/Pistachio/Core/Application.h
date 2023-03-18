#pragma once

#include "Pistachio/Core/Base.h"

#include "Pistachio/Core/Window.h"
#include "Pistachio/Core/LayerStack.h"
#include "Pistachio/Events/Event.h"
#include "Pistachio/Events/ApplicationEvent.h"

#include "Pistachio/Core/Timestep.h"

#include "Pistachio/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Pistachio 
{
	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			PA_CORE_ASSERT(index < Count)
			return Args[index];
		}
	};
	
	class Application
	{
	public:
		Application(const std::string& name = "Pistachio Engine", ApplicationCommandLineArgs args = ApplicationCommandLineArgs());
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() {return *m_Window;}

		void Close();

		ImGuiLayer* GetImGuiLayer() {return m_ImGuiLayer;}

		static Application& Get()
		{
			return *s_Instance;
		}

		ApplicationCommandLineArgs GetCommandLineArgs() {return m_CommandLineArgs;}
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		ApplicationCommandLineArgs m_CommandLineArgs;
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication(ApplicationCommandLineArgs args);
}
