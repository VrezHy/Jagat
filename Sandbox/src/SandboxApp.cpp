#include <Jagat.h>

class Sandbox : public Jagat::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}


};

Jagat::Application* Jagat::CreateApplication()
{
	return new Sandbox();
}