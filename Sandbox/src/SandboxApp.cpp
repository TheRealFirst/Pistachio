#include <Pistachio.h>

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
	}
	~Sandbox() {

	}
};

Pistachio::Application* Pistachio::CreateApplication() {
	return new Sandbox();
}
