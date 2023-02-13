#pragma once

#include "Timestep.h"
#include "Pistachio/Core/Core.h"
#include "Pistachio/Events/Event.h"

namespace Pistachio{
    class Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach(){}
        virtual void OnDetach(){}
        virtual void OnUpdate(Timestep ts){}
        virtual void OnImGuiRender(){}
        virtual void OnEvent(Event& e){}

        const std::string& GetName() const {return m_DebugName;}

    protected:
        std::string m_DebugName;
    };
}
