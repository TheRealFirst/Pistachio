#pragma once
#include "Pistachio/Core/Base.h"
#include "Pistachio/Core/Application.h"

#ifdef PA_PLATFORM_WINDOWS

extern Pistachio::Application* Pistachio::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv) 
{
	Pistachio::Log::Init();

	// PA_PROFILE_BEGIN_SESSION("Startup", "PistachioProfile-Startup.json");
	auto app = Pistachio::CreateApplication({argc, argv});
	// PA_PROFILE_END_SESSION();
	
	// PA_PROFILE_BEGIN_SESSION("Startup", "PistachioProfile-Runtime.json");
	app->Run();
	// PA_PROFILE_END_SESSION();
	
	// PA_PROFILE_BEGIN_SESSION("Shutdown", "PistachioProfile-Shutdown.json");
	delete app;
	// PA_PROFILE_END_SESSION();
}

#endif
