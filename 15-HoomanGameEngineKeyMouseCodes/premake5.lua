workspace "HoomanGameEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (solution directory)
IncludeDir = {}
--Setting a compiler include directory
IncludeDir["GLFW"] = "../vendor/GLFW/include"
IncludeDir["Glad"] = "../vendor/Glad/include"
IncludeDir["ImGui"] = "../vendor/imgui"

group "Dependencies"
--this include premake file inside GLFW
	include "../vendor/GLFW"
	include "../vendor/Glad"
	include "../vendor/imgui"


group ""

project "GameEngine"
	location	"GameEngine"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hgepch.h"
	pchsource "GameEngine/src/hgepch.cpp"

    files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"../vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}
	--linking static libraries
	links
	{
		"GLFW",  
		"Glad",
		"ImGui",
		"opengl32.lib" 
	}

	postbuildcommands
    {
    	("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
    }


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HGE_PLATFORM_WINDOWS",
			"HGE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}


	filter "configurations:Debug"
		defines "HGE_DEBUG"
		buildoptions "/MDd"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HGE_RELEASE"
		buildoptions "/MD"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HGE_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
	{
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"../vendor/spdlog/include",
		"GameEngine/src",
	}	

	links		
	{
		"GameEngine"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HGE_PLATFORM_WINDOWS"
		}



	filter "configurations:Debug"
		defines "HGE_DEBUG"
		buildoptions "/MDd"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HGE_RELEASE"
		buildoptions "/MD"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HGE_DIST"
		buildoptions "/MD"
		runtime "Release"
		optimize "on"





