#include "papch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Pistachio
{
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
    {
        PA_CORE_ASSERT(windowHandle, "Window handle is null!")
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        PA_CORE_ASSERT(status, "Failed to initialize Glad!")

#ifdef PA_ENABLE_ASSERTS
int versionMajor;
        int versionMinor;
        glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
        glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

        PA_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Pistachio requires at least OpenGL version 4.5!");
#endif
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}
