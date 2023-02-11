#pragma once

namespace Pistachio
{
    typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space               = 32,
		Apostrophe          = 39, /* ' */
		Comma               = 44, /* , */
		Minus               = 45, /* - */
		Period              = 46, /* . */
		Slash               = 47, /* / */

		D0                  = 48, /* 0 */
		D1                  = 49, /* 1 */
		D2                  = 50, /* 2 */
		D3                  = 51, /* 3 */
		D4                  = 52, /* 4 */
		D5                  = 53, /* 5 */
		D6                  = 54, /* 6 */
		D7                  = 55, /* 7 */
		D8                  = 56, /* 8 */
		D9                  = 57, /* 9 */

		Semicolon           = 59, /* ; */
		Equal               = 61, /* = */

		A                   = 65,
		B                   = 66,
		C                   = 67,
		D                   = 68,
		E                   = 69,
		F                   = 70,
		G                   = 71,
		H                   = 72,
		I                   = 73,
		J                   = 74,
		K                   = 75,
		L                   = 76,
		M                   = 77,
		N                   = 78,
		O                   = 79,
		P                   = 80,
		Q                   = 81,
		R                   = 82,
		S                   = 83,
		T                   = 84,
		U                   = 85,
		V                   = 86,
		W                   = 87,
		X                   = 88,
		Y                   = 89,
		Z                   = 90,

		LeftBracket         = 91,  /* [ */
		Backslash           = 92,  /* \ */
		RightBracket        = 93,  /* ] */
		GraveAccent         = 96,  /* ` */

		World1              = 161, /* non-US #1 */
		World2              = 162, /* non-US #2 */

		/* Function keys */
		Escape              = 256,
		Enter               = 257,
		Tab                 = 258,
		Backspace           = 259,
		Insert              = 260,
		Delete              = 261,
		Right               = 262,
		Left                = 263,
		Down                = 264,
		Up                  = 265,
		PageUp              = 266,
		PageDown            = 267,
		Home                = 268,
		End                 = 269,
		CapsLock            = 280,
		ScrollLock          = 281,
		NumLock             = 282,
		PrintScreen         = 283,
		Pause               = 284,
		F1                  = 290,
		F2                  = 291,
		F3                  = 292,
		F4                  = 293,
		F5                  = 294,
		F6                  = 295,
		F7                  = 296,
		F8                  = 297,
		F9                  = 298,
		F10                 = 299,
		F11                 = 300,
		F12                 = 301,
		F13                 = 302,
		F14                 = 303,
		F15                 = 304,
		F16                 = 305,
		F17                 = 306,
		F18                 = 307,
		F19                 = 308,
		F20                 = 309,
		F21                 = 310,
		F22                 = 311,
		F23                 = 312,
		F24                 = 313,
		F25                 = 314,

		/* Keypad */
		KP0                 = 320,
		KP1                 = 321,
		KP2                 = 322,
		KP3                 = 323,
		KP4                 = 324,
		KP5                 = 325,
		KP6                 = 326,
		KP7                 = 327,
		KP8                 = 328,
		KP9                 = 329,
		KPDecimal           = 330,
		KPDivide            = 331,
		KPMultiply          = 332,
		KPSubtract          = 333,
		KPAdd               = 334,
		KPEnter             = 335,
		KPEqual             = 336,

		LeftShift           = 340,
		LeftControl         = 341,
		LeftAlt             = 342,
		LeftSuper           = 343,
		RightShift          = 344,
		RightControl        = 345,
		RightAlt            = 346,
		RightSuper          = 347,
		Menu                = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define PA_KEY_SPACE           ::Pistachio::Key::Space
#define PA_KEY_APOSTROPHE      ::Pistachio::Key::Apostrophe    /* ' */
#define PA_KEY_COMMA           ::Pistachio::Key::Comma         /* , */
#define PA_KEY_MINUS           ::Pistachio::Key::Minus         /* - */
#define PA_KEY_PERIOD          ::Pistachio::Key::Period        /* . */
#define PA_KEY_SLASH           ::Pistachio::Key::Slash         /* / */
#define PA_KEY_0               ::Pistachio::Key::D0
#define PA_KEY_1               ::Pistachio::Key::D1
#define PA_KEY_2               ::Pistachio::Key::D2
#define PA_KEY_3               ::Pistachio::Key::D3
#define PA_KEY_4               ::Pistachio::Key::D4
#define PA_KEY_5               ::Pistachio::Key::D5
#define PA_KEY_6               ::Pistachio::Key::D6
#define PA_KEY_7               ::Pistachio::Key::D7
#define PA_KEY_8               ::Pistachio::Key::D8
#define PA_KEY_9               ::Pistachio::Key::D9
#define PA_KEY_SEMICOLON       ::Pistachio::Key::Semicolon     /* ; */
#define PA_KEY_EQUAL           ::Pistachio::Key::Equal         /* = */
#define PA_KEY_A               ::Pistachio::Key::A
#define PA_KEY_B               ::Pistachio::Key::B
#define PA_KEY_C               ::Pistachio::Key::C
#define PA_KEY_D               ::Pistachio::Key::D
#define PA_KEY_E               ::Pistachio::Key::E
#define PA_KEY_F               ::Pistachio::Key::F
#define PA_KEY_G               ::Pistachio::Key::G
#define PA_KEY_H               ::Pistachio::Key::H
#define PA_KEY_I               ::Pistachio::Key::I
#define PA_KEY_J               ::Pistachio::Key::J
#define PA_KEY_K               ::Pistachio::Key::K
#define PA_KEY_L               ::Pistachio::Key::L
#define PA_KEY_M               ::Pistachio::Key::M
#define PA_KEY_N               ::Pistachio::Key::N
#define PA_KEY_O               ::Pistachio::Key::O
#define PA_KEY_P               ::Pistachio::Key::P
#define PA_KEY_Q               ::Pistachio::Key::Q
#define PA_KEY_R               ::Pistachio::Key::R
#define PA_KEY_S               ::Pistachio::Key::S
#define PA_KEY_T               ::Pistachio::Key::T
#define PA_KEY_U               ::Pistachio::Key::U
#define PA_KEY_V               ::Pistachio::Key::V
#define PA_KEY_W               ::Pistachio::Key::W
#define PA_KEY_X               ::Pistachio::Key::X
#define PA_KEY_Y               ::Pistachio::Key::Y
#define PA_KEY_Z               ::Pistachio::Key::Z
#define PA_KEY_LEFT_BRACKET    ::Pistachio::Key::LeftBracket   /* [ */
#define PA_KEY_BACKSLASH       ::Pistachio::Key::Backslash     /* \ */
#define PA_KEY_RIGHT_BRACKET   ::Pistachio::Key::RightBracket  /* ] */
#define PA_KEY_GRAVE_ACCENT    ::Pistachio::Key::GraveAccent   /* ` */
#define PA_KEY_WORLD_1         ::Pistachio::Key::World1        /* non-US #1 */
#define PA_KEY_WORLD_2         ::Pistachio::Key::World2        /* non-US #2 */

/* Function keys */
#define PA_KEY_ESCAPE          ::Pistachio::Key::Escape
#define PA_KEY_ENTER           ::Pistachio::Key::Enter
#define PA_KEY_TAB             ::Pistachio::Key::Tab
#define PA_KEY_BACKSPACE       ::Pistachio::Key::Backspace
#define PA_KEY_INSERT          ::Pistachio::Key::Insert
#define PA_KEY_DELETE          ::Pistachio::Key::Delete
#define PA_KEY_RIGHT           ::Pistachio::Key::Right
#define PA_KEY_LEFT            ::Pistachio::Key::Left
#define PA_KEY_DOWN            ::Pistachio::Key::Down
#define PA_KEY_UP              ::Pistachio::Key::Up
#define PA_KEY_PAGE_UP         ::Pistachio::Key::PageUp
#define PA_KEY_PAGE_DOWN       ::Pistachio::Key::PageDown
#define PA_KEY_HOME            ::Pistachio::Key::Home
#define PA_KEY_END             ::Pistachio::Key::End
#define PA_KEY_CAPS_LOCK       ::Pistachio::Key::CapsLock
#define PA_KEY_SCROLL_LOCK     ::Pistachio::Key::ScrollLock
#define PA_KEY_NUM_LOCK        ::Pistachio::Key::NumLock
#define PA_KEY_PRINT_SCREEN    ::Pistachio::Key::PrintScreen
#define PA_KEY_PAUSE           ::Pistachio::Key::Pause
#define PA_KEY_F1              ::Pistachio::Key::F1
#define PA_KEY_F2              ::Pistachio::Key::F2
#define PA_KEY_F3              ::Pistachio::Key::F3
#define PA_KEY_F4              ::Pistachio::Key::F4
#define PA_KEY_F5              ::Pistachio::Key::F5
#define PA_KEY_F6              ::Pistachio::Key::F6
#define PA_KEY_F7              ::Pistachio::Key::F7
#define PA_KEY_F8              ::Pistachio::Key::F8
#define PA_KEY_F9              ::Pistachio::Key::F9
#define PA_KEY_F10             ::Pistachio::Key::F10
#define PA_KEY_F11             ::Pistachio::Key::F11
#define PA_KEY_F12             ::Pistachio::Key::F12
#define PA_KEY_F13             ::Pistachio::Key::F13
#define PA_KEY_F14             ::Pistachio::Key::F14
#define PA_KEY_F15             ::Pistachio::Key::F15
#define PA_KEY_F16             ::Pistachio::Key::F16
#define PA_KEY_F17             ::Pistachio::Key::F17
#define PA_KEY_F18             ::Pistachio::Key::F18
#define PA_KEY_F19             ::Pistachio::Key::F19
#define PA_KEY_F20             ::Pistachio::Key::F20
#define PA_KEY_F21             ::Pistachio::Key::F21
#define PA_KEY_F22             ::Pistachio::Key::F22
#define PA_KEY_F23             ::Pistachio::Key::F23
#define PA_KEY_F24             ::Pistachio::Key::F24
#define PA_KEY_F25             ::Pistachio::Key::F25

/* Keypad */
#define PA_KEY_KP_0            ::Pistachio::Key::KP0
#define PA_KEY_KP_1            ::Pistachio::Key::KP1
#define PA_KEY_KP_2            ::Pistachio::Key::KP2
#define PA_KEY_KP_3            ::Pistachio::Key::KP3
#define PA_KEY_KP_4            ::Pistachio::Key::KP4
#define PA_KEY_KP_5            ::Pistachio::Key::KP5
#define PA_KEY_KP_6            ::Pistachio::Key::KP6
#define PA_KEY_KP_7            ::Pistachio::Key::KP7
#define PA_KEY_KP_8            ::Pistachio::Key::KP8
#define PA_KEY_KP_9            ::Pistachio::Key::KP9
#define PA_KEY_KP_DECIMAL      ::Pistachio::Key::KPDecimal
#define PA_KEY_KP_DIVIDE       ::Pistachio::Key::KPDivide
#define PA_KEY_KP_MULTIPLY     ::Pistachio::Key::KPMultiply
#define PA_KEY_KP_SUBTRACT     ::Pistachio::Key::KPSubtract
#define PA_KEY_KP_ADD          ::Pistachio::Key::KPAdd
#define PA_KEY_KP_ENTER        ::Pistachio::Key::KPEnter
#define PA_KEY_KP_EQUAL        ::Pistachio::Key::KPEqual

#define PA_KEY_LEFT_SHIFT      ::Pistachio::Key::LeftShift
#define PA_KEY_LEFT_CONTROL    ::Pistachio::Key::LeftControl
#define PA_KEY_LEFT_ALT        ::Pistachio::Key::LeftAlt
#define PA_KEY_LEFT_SUPER      ::Pistachio::Key::LeftSuper
#define PA_KEY_RIGHT_SHIFT     ::Pistachio::Key::RightShift
#define PA_KEY_RIGHT_CONTROL   ::Pistachio::Key::RightControl
#define PA_KEY_RIGHT_ALT       ::Pistachio::Key::RightAlt
#define PA_KEY_RIGHT_SUPER     ::Pistachio::Key::RightSuper
#define PA_KEY_MENU            ::Pistachio::Key::Menu