#include <Pistachio.h>

#include "imgui/imgui.h"

class ExampleLayer : public Pistachio::Layer
{
public:
	ExampleLayer() : Layer("Example"){}

	void OnUpdate() override
	{
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Pistachio::Event& event) override
	{
	}
};

class Sandbox : public Pistachio::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}
};

Pistachio::Application* Pistachio::CreateApplication() {
	return new Sandbox();
}
