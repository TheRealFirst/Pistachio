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
        virtual void OnEvent(Event& e) override;

        void Begin();
        void End();

        void BlockEvents(bool block) {m_BlockEvents = block;}
    	void SetDarkThemeColors();
    private:
        bool m_BlockEvents = true;
    };
}
