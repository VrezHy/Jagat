workspace "Jagat"
	architecture "x64"

configurations
{
	"Debug",
	"Release",
	"Dist"
}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Jagat"
	location "jagat"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .."/%{prj.name}")
	objdir ("bin-int/" .. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"JG_PLATFORM_WINDOWS",
			"JG_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox" )
		}

	filter "configurations:Debug"
		defines "JG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "JG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "JG_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .."/%{prj.name}")
	objdir ("bin-int/" .. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Jagat/vendor/spdlog/include",
		"Jagat/src"
	}

	links
	{
		"Jagat"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"JG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "JG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "JG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "JG_DIST"
		optimize "On"