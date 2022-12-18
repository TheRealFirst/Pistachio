 workspace "Pistachio"
	architecture "x64"

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
IncludeDir["Glad"] = "Pistachio/vendor/GLAD/include"

include "Pistachio/vendor/GLFW"
include "Pistachio/vendor/Glad"

project "Pistachio"
	location "Pistachio"
	kind "SharedLib"
	language "C++"

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
		"%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"Glad",
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
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
		}

 	filter "configurations:Debug"
 		defines "PA_DEBUG" 
 		buildoptions "/MDd"
 		symbols "On"

 	filter "configurations:Release"
 		defines "PA_RELEASE"
 		buildoptions "/MD"
 		optimize "On"

 	filter "configurations:Dist"
 		defines "PA_DIST"
 		buildoptions "/MD"
 		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
 		buildoptions "/MDd"
 		symbols "On"

 	filter "configurations:Release"
 		defines "PA_RELEASE"
 		buildoptions "/MD"
 		optimize "On"

 	filter "configurations:Dist"
 		defines "PA_DIST"
 		buildoptions "/MD"
 		optimize "On"