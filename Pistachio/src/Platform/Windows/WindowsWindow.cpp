#include "papch.h"
#include "WindowsWindow.h"

#include "Pistachio/Log.h"

namespace Pistachio
{
    static bool s_GLFWInitialized = false;

    Window* Window::Create(const WindowProbs& probs)
    {
        return new WindowsWindow(probs);
    }

    WindowsWindow::WindowsWindow(const WindowProbs& probs)
    {
        Init(probs);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::Init(const WindowProbs& probs)
    {
        m_Data.Title = probs.Title;
        m_Data.Width = probs.Width;
        m_Data.Height = probs.Height;

        PA_CORE_INFO("Creating window {0} ({1}, {2})", probs.Title, probs.Width, probs.Height);

        if(!s_GLFWInitialized)
        {
            //TODO: glfwTerminate on system shutdown
            int success = glfwInit();
            PA_CORE_ASSERT(success, "Could not initialize GLFW!");

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)probs.Width, (int)probs.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }
}
