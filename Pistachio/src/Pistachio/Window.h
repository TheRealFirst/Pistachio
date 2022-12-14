#pragma once

#include "papch.h"

#include "Pistachio/Core.h"
#include "Pistachio/Events/Event.h"

namespace Pistachio
{
    struct WindowProbs
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProbs(const std::string& title = "Pistachio Engine", unsigned int width = 3840, unsigned int height = 2160)
            : Title(title), Width(width), Height(height)
        {
            
        }
    };

    // Interface representing a desktop system based Window
    class PISTACHIO_API Window
    {
    public:
        using  EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window(){}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        // Window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;

        static Window* Create(const WindowProbs& probs = WindowProbs());
    };
}
