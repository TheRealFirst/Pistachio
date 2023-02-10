#include <Pistachio.h>
#include <Pistachio/Core/EntryPoint.h>

#include "Sandbox2D.h"

#include <imgui/imgui.h>

#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"

#include "ExampleLayer.h"

class Sandbox : public Pistachio::Application {
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}
	~Sandbox() = default;
};

Pistachio::Application* Pistachio::CreateApplication() {
	return new Sandbox();
}
