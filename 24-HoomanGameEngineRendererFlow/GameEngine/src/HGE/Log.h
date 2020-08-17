#pragma once

#include "HGE/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace HGE {
	class Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Log macros
#define HGE_CORE_TRACE(...) ::HGE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HGE_CORE_INFO(...)  ::HGE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HGE_CORE_WARN(...)  ::HGE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HGE_CORE_ERROR(...) ::HGE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HGE_CORE_CRITICAL(...) ::HGE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log macros
#define HGE_TRACE(...) ::HGE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HGE_INFO(...)  ::HGE::Log::GetClientLogger()->info(__VA_ARGS__)
#define HGE_WARN(...)  ::HGE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HGE_ERROR(...) ::HGE::Log::GetClientLogger()->error(__VA_ARGS__)
#define HGE_CRITICAL(...) ::HGE::Log::GetClientLogger()->fatal(__VA_ARGS__)
