#pragma once

#ifdef JG_PLATFORM_WINDOWS

extern Jagat::Application* Jagat::CreateApplication();

int main(int argc, char** argv)
{

	Jagat::Log::Init();
	JG_CORE_WARN("Initialized Log!");
	int a = 5;
	JG_INFO("Hello! Var = {0}", a);
	

	auto app = Jagat::CreateApplication();
	app->Run();
	delete app;
}
#endif