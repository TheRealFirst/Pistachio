#pragma once

#include "Pistachio/Core/Base.h"
#include "Pistachio/Core/Log.h"
#include "Pistachio/Scene/Scene.h"
#include "Pistachio/Scene/Entity.h"

namespace Pistachio
{
	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};
}

