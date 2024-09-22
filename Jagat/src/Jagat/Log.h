#pragma once

#include <memory>	
#include "Core.h"
#include "spdlog/spdlog.h"


namespace Jagat {	

	class JAGAT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};
}

// Core log macro's
#define JG_CORE_TRACE(...)	::Jagat::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JG_CORE_INFO(...)	::Jagat::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JG_CORE_WARN(...)	::Jagat::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JG_CORE_ERROR(...)	::Jagat::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JG_CORE_FATAL(...)	::Jagat::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macro's
#define JG_TRACE(...)		::Jagat::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JG_INFO(...)		::Jagat::Log::GetClientLogger()->info(__VA_ARGS__)
#define JG_WARN(...)		::Jagat::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JG_ERROR(...)		::Jagat::Log::GetClientLogger()->error(__VA_ARGS__)
#define JG_FATAL(...)		::Jagat::Log::GetClientLogger()->fatal(__VA_ARGS__)