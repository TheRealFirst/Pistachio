#pragma once

namespace Pistachio
{
    typedef enum class MouseCode : uint16_t
    {
        // From glfw3.h
        Button0                = 0,
        Button1                = 1,
        Button2                = 2,
        Button3                = 3,
        Button4                = 4,
        Button5                = 5,
        Button6                = 6,
        Button7                = 7,

        ButtonLast             = Button7,
        ButtonLeft             = Button0,
        ButtonRight            = Button1,
        ButtonMiddle           = Button2
    } Mouse;

    inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
    {
        os << static_cast<int32_t>(mouseCode);
        return os;
    }
}

#define PA_MOUSE_BUTTON_0      ::Pistachio::Mouse::Button0
#define PA_MOUSE_BUTTON_1      ::Pistachio::Mouse::Button1
#define PA_MOUSE_BUTTON_2      ::Pistachio::Mouse::Button2
#define PA_MOUSE_BUTTON_3      ::Pistachio::Mouse::Button3
#define PA_MOUSE_BUTTON_4      ::Pistachio::Mouse::Button4
#define PA_MOUSE_BUTTON_5      ::Pistachio::Mouse::Button5
#define PA_MOUSE_BUTTON_6      ::Pistachio::Mouse::Button6
#define PA_MOUSE_BUTTON_7      ::Pistachio::Mouse::Button7
#define PA_MOUSE_BUTTON_LAST   ::Pistachio::Mouse::ButtonLast
#define PA_MOUSE_BUTTON_LEFT   ::Pistachio::Mouse::ButtonLeft
#define PA_MOUSE_BUTTON_RIGHT  ::Pistachio::Mouse::ButtonRight
#define PA_MOUSE_BUTTON_MIDDLE ::Pistachio::Mouse::ButtonMiddle
