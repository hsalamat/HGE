#pragma once
//step2
#include "HGE/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace HGE {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

}