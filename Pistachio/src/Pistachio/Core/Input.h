#pragma once

#include <glm/glm.hpp>

#include "Pistachio/Core/KeyCodes.h"
#include "Pistachio/Core/MouseCodes.h"

namespace Pistachio
{
    class Input
    {
    public:
        static bool IsKeyPressed(KeyCode key);
        
        static bool IsMouseButtonPressed(MouseCode button);
        static glm::vec2 GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    };
}
