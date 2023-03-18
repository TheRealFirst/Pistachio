include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

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
