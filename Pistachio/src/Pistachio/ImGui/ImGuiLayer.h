#pragma once

#include "Pistachio/Core/Layer.h"
#include "Pistachio/Events/ApplicationEvent.h"
#include "Pistachio/Events/KeyEvent.h"
#include "Pistachio/Events/MouseEvent.h"

namespace Pistachio
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;

        void Begin();
        void End();
    private:
        float m_Time = 0.0f;
    };
}
