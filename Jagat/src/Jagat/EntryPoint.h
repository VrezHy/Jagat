#pragma once

#ifdef JG_PLATFORM_WINDOWS

extern Jagat::Application* Jagat::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Jagat::CreateApplication();
	app->Run();
	delete app;
}
#endif