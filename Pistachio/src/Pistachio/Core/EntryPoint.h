#pragma once

#ifdef PA_PLATFORM_WINDOWS

extern Pistachio::Application* Pistachio::CreateApplication();

int main(int argc, char** argv) 
{
	Pistachio::Log::Init();
	PA_CORE_WARN("Initialized Log!");
	PA_INFO("Welcome to Pistachio Engine");

	auto app = Pistachio::CreateApplication();
	app->Run();
	delete app;
}

#endif