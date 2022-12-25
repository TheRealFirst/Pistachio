 workspace "Pistachio"
	architecture "x64"
 	startproject "Sandbox"	
 
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Pistachio/vendor/GLFW/include"
IncludeDir["Glad"] = "Pistachio/vendor/Glad/include"
IncludeDir["ImGui"] = "Pistachio/vendor/imgui"

 group "Dependencies"
 	include "Pistachio/vendor/GLFW"
 	include "Pistachio/vendor/Glad"
 	include "Pistachio/vendor/imgui"

 group ""

 


project "Pistachio"
	location "Pistachio"
	kind "SharedLib"
	language "C++"
 	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
 	
 	pchheader "papch.h"
 	pchsource "%{prj.name}/src/papch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
			"PA_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

 	filter "configurations:Debug"
 		defines "PA_DEBUG" 
 		runtime "Debug"
 		symbols "On"

 	filter "configurations:Release"
 		defines "PA_RELEASE"
 		runtime "Release"
 		optimize "On"

 	filter "configurations:Dist"
 		defines "PA_DIST"
 		runtime "Release"
 		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
 	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Pistachio/vendor/spdlog/include",
		"Pistachio/src"
	}

	links
	{
		"Pistachio"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS"
		}


 	filter "configurations:Debug"
 		defines "PA_DEBUG"
 		runtime "Debug"
 		symbols "On"

 	filter "configurations:Release"
 		defines "PA_RELEASE"
 		runtime "Release"
 		optimize "On"

 	filter "configurations:Dist"
 		defines "PA_DIST"
 		runtime "Release"
 		optimize "On"