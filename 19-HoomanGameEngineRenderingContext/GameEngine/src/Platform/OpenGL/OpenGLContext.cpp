//step3
#include "hgepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace HGE {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HGE_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HGE_CORE_ASSERT(status, "Failed to initialize Glad!");

		//Tells you what GPU you are using
		HGE_CORE_INFO("OpenGL Vendor: {0}",glGetString(GL_VENDOR));
		HGE_CORE_INFO("OpenGL Renderer: {0}", glGetString(GL_RENDERER));
		HGE_CORE_INFO("OpenGL Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}