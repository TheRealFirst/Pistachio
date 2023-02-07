#pragma once
#include "Pistachio/Core/Core.h"
#include "Pistachio/Core/Layer.h"

#include <vector>

namespace Pistachio
{
    class LayerStack
    {
    public:
        LayerStack() = default;
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* layer);

        std::vector<Layer*>::iterator begin() {return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() {return m_Layers.end(); }

    private:
        std::vector<Layer*> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}
