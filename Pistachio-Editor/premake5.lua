project "Pistachio-Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Pistachio/vendor/spdlog/include",
		"%{wks.location}/Pistachio/src",
		"%{wks.location}/Pistachio/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Pistachio"
	}

	filter "system:windows"
		systemversion "latest"

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
