#include <Pistachio.h>
#include <Pistachio/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Pistachio
{
	class PistachioEditor : public Application {
	public:
		PistachioEditor(ApplicationCommandLineArgs args)
			: Application("Pistachio Editor", args)
		{
			PushLayer(new EditorLayer());
		}
		~PistachioEditor() = default;
	};

	Application* CreateApplication(ApplicationCommandLineArgs args) {
		return new PistachioEditor(args);
	}
}
