#include <Pistachio.h>

#include "../../Pistachio/vendor/ImGui/imgui.h"

class ExampleLayer : public Pistachio::Layer
{
public:
	ExampleLayer() : Layer("Example"){}

	void OnUpdate() override
	{
	}

	void OnEvent(Pistachio::Event& event) override
	{
	}
};

class Sandbox : public Pistachio::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Pistachio::ImGuiLayer());
	}
	~Sandbox() {

	}
};

Pistachio::Application* Pistachio::CreateApplication() {
	return new Sandbox();
}
