#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "shaders.h"
#include "model.h"
#include "glfw/glfw3.h"
namespace scmales {
	class Renderer {
	public:
		Renderer();
		~Renderer() {}

		void setShaders(Shaders::ptr shaders) { m_shaders = shaders; }
		Shaders::ptr getShaders() { return m_shaders; }

		void setModel(Model::ptr model) { m_model = model; };
		Model::ptr getModel() { return m_model; };
		void run();
	private:
		GLFWwindow* window;
		Shaders::ptr m_shaders = nullptr;
		Model::ptr m_model = nullptr;
	};
}


#endif // !__RENDERER_H__
