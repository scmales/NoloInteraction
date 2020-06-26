#ifndef __SHADERS_H__
#define __SHADERS_H__

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

using namespace std;

namespace scmales {

	class Shaders
	{
	public:

		typedef shared_ptr<Shaders> ptr;

		//程序ID
		unsigned int ID;

		//构造函数
		Shaders(const GLchar* vertexPath, const GLchar* fragmentPath, const GLchar* geometryPath = nullptr);
		//激活程序
		void use();
		//uniform工具函数
		void setBool(const std::string& name, bool value) const;
		void setInt(const std::string& name, int value) const;
		void setFloat(const std::string& name, float value) const;
		void setVec2(const std::string& name, const glm::vec2& value) const;
		void setVec2(const std::string& name, float x, float y) const;
		void setVec3(const std::string& name, const glm::vec3& value) const;
		void setVec3(const std::string& name, float x, float y, float z) const;
		void setVec4(const std::string& name, const glm::vec4& value) const;
		void setVec4(const std::string& name, float x, float y, float z, float w);
		void setMat2(const std::string& name, const glm::mat2& mat) const;
		void setMat3(const std::string& name, const glm::mat3& mat) const;
		void setMat4(const std::string& name, const glm::mat4& mat) const;
		void checkCompileErrors(GLuint shader, std::string type);
	};
}
#endif