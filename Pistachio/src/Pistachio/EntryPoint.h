#pragma once

#ifdef PA_PLATFORM_WINDOWS

extern Pistachio::Application* Pistachio::CreateApplication();

int main(int argc, char** argv) {
	printf("Pistachio Engine\n");
	auto app = Pistachio::CreateApplication();
	app->Run();
	delete app;
}

#endif