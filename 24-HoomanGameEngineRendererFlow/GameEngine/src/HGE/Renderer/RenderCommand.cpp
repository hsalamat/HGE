#include "hgepch.h"
#include "RenderCommand.h"
//step6
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace HGE {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}