#include <Pistachio.h>
#include <Pistachio/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Pistachio
{
	class PistachioEditor : public Application {
	public:
		PistachioEditor() : Application("Pistachio Editor")
		{
			PushLayer(new EditorLayer());
		}
		~PistachioEditor() = default;
	};

	Application* CreateApplication() {
		return new PistachioEditor();
	}
}