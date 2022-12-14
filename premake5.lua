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
IncludeDir["glm"] = "Pistachio/vendor/glm"

 group "Dependencies"
 	include "Pistachio/vendor/GLFW"
 	include "Pistachio/vendor/Glad"
 	include "Pistachio/vendor/imgui"
 group ""

 


project "Pistachio"
	location "Pistachio"
	kind "StaticLib"
	language "C++"
 	cppdialect "C++17"
 	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
 	
 	pchheader "papch.h"
 	pchsource "%{prj.name}/src/papch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

 	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
			"PA_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

 	filter "configurations:Debug"
 		defines "PA_DEBUG" 
 		runtime "Debug"
 		symbols "on"

 	filter "configurations:Release"
 		defines "PA_RELEASE"
 		runtime "Release"
 		optimize "on"

 	filter "configurations:Dist"
 		defines "PA_DIST"
 		runtime "Release"
 		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
 	cppdialect "C++17"
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
		"Pistachio/vendor/spdlog/include",
		"Pistachio/src",
		"Pistachio/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Pistachio"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS"
		}


 	filter "configurations:Debug"
 		defines "PA_DEBUG"
 		runtime "Debug"
 		symbols "on"

 	filter "configurations:Release"
 		defines "PA_RELEASE"
 		runtime "Release"
 		optimize "on"

 	filter "configurations:Dist"
 		defines "PA_DIST"
 		runtime "Release"
 		optimize "on"