include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Pistachio"
	architecture "x86_64"
	startproject "Pistachio-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Pistachio/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Pistachio/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Pistachio/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Pistachio/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Pistachio/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Pistachio/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Pistachio/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Pistachio/vendor/ImGuizmo"

group "Dependencies"
	include "vendor/premake"
	include "Pistachio/vendor/GLFW"
	include "Pistachio/vendor/Glad"
	include "Pistachio/vendor/imgui"
	include "Pistachio/vendor/yaml-cpp"
group ""

include "Pistachio"
include "Sandbox"
include "Pistachio-Editor"
