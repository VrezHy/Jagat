#pragma once

#include "Core.h"

namespace Jagat {
		
	class JAGAT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be define in CLIENT
	Application* CreateApplication();

}