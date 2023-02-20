#pragma once

#include "Pistachio/Core/Base.h"
#include "Pistachio/Core/KeyCodes.h"
#include "Pistachio/Core/MouseCodes.h"

namespace Pistachio
{
    class Input
    {
    public:
        static bool IsKeyPressed(KeyCode key);
        
        static bool IsMouseButtonPressed(MouseCode button);
        static std::pair<float, float> GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    };
}
