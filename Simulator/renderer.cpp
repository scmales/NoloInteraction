#include "renderer.h"
#include "glad/glad.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


namespace scmales {
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void processInput(GLFWwindow* window);
	const unsigned int SCR_WIDTH = 1920;
	const unsigned int SCR_HEIGHT = 1048;

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
	void processInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
	}
	Renderer::Renderer() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
		}
	}
	void Renderer::run()
	{
		 float vertices[] = {
		 -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		  0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		 -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,

		 -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		  0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		 -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,

		 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		 -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		 -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,

		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		  0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,

		 -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		  0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		  0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		 -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		 -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,

		 -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		 -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f
		 };

		unsigned int indices[] = {  // note that we start from 0!
			0, 1, 2,  
			3, 4, 5,  
			6, 7, 8,
			9, 10 ,11,
			12, 13, 14,
			15, 16, 17,
			18, 19, 20, 
			21, 22, 23,
			24, 25, 26,
			27, 28, 29,
			30, 31, 32,
			33, 34, 35
		};
		/*glm::vec3 cubePositions[] = {
		  glm::vec3(0.0f,  0.0f,  0.0f),
		  glm::vec3(2.0f,  5.0f, -15.0f),
		  glm::vec3(-1.5f, -2.2f, -2.5f),
		  glm::vec3(-3.8f, -2.0f, -12.3f),
		  glm::vec3(2.4f, -0.4f, -3.5f),
		  glm::vec3(-1.7f,  3.0f, -7.5f),
		  glm::vec3(1.3f, -2.0f, -2.5f),
		  glm::vec3(1.5f,  2.0f, -2.5f),
		  glm::vec3(1.5f,  0.2f, -1.5f),
		  glm::vec3(-1.3f,  1.0f, -1.5f)
		};*/

		unsigned int VBO, VAO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		
		glBindVertexArray(VAO);  //可以用glBindVertexArray(0);解除绑定

		glBindBuffer(GL_ARRAY_BUFFER, VBO);  //可以用glBindBuffer(GL_ARRAY_BUFFER, 0);解除绑定
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //VAO激活时，不能解绑EBO
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		
		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
		

		//使用纹理
		unsigned int texture1, texture2;
		glGenTextures(1, &texture1);
		glBindTexture(GL_TEXTURE_2D, texture1);
		// 设置纹理参数
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// 设置纹理过滤器参数
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// 读取纹理图，产生mipmap
		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);		
		unsigned char* data = stbi_load("..\\textures\\container.jpg", &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);
		// texture 2
		glGenTextures(1, &texture2);
		glBindTexture(GL_TEXTURE_2D, texture2);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		data = stbi_load("F:\\VS_repos\\Nolo_demo_c++\\texture\\awesomeface.png", &width, &height, &nrChannels, 0);
		if (data)
		{
			//注意png图片有RBGA
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);

		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	
		// glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		m_shaders->use(); 
		m_shaders->setInt("texture1", 0);
		m_shaders->setInt("texture2", 1);

		//投影矩阵很少改变，最好在外边设置一次就可以了
		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		m_shaders->setMat4("projection", projection);

		
		while (!glfwWindowShouldClose(window))
		{
			processInput(window);
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);			
			glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

			// 激活纹理
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture1);
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, texture2);

			//启用深度缓冲区
			glEnable(GL_DEPTH_TEST);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			
			//获取设备数据
			// std::cout << m_model->lPosition.x << " " << m_model->lPosition.y << " " << m_model->lPosition.z << std::endl;
			auto bsPosition = glm::vec3(0.0f, 0.0f, 0.0f);
			auto lPosition = glm::vec3( m_model->lPosition.x, m_model->lPosition.y, -1 * m_model->lPosition.z);
			auto rPosition = glm::vec3( m_model->rPosition.x,  m_model->rPosition.y, -1 *  m_model->rPosition.z);
			auto hmdPosition = glm::vec3( m_model->hmdPosition.x,  m_model->hmdPosition.y,-1 *  m_model->hmdPosition.z);

			auto lRotation = glm::quat(m_model->lRotation.w, m_model->lRotation.x, m_model->lRotation.y, m_model->lRotation.z);
			auto rRotation = glm::quat(m_model->rRotation.w, m_model->rRotation.x, m_model->rRotation.y, m_model->rRotation.z);
			auto hmdRotation = glm::quat(m_model->hmdRotation.w, m_model->hmdRotation.x, m_model->hmdRotation.y, m_model->hmdRotation.z);
			glm::vec3 objectPositions[] = { lPosition, rPosition, hmdPosition };
			glm::quat objectRotation[] = { lRotation, rRotation, hmdRotation };

			m_shaders->use();
			glm::mat4 trans = glm::mat4(1.0f);;
			//trans = glm::rotate(trans, glm::radians(0.0f), glm::vec3(0.0, 0.0, 1.0));
			trans = glm::scale(trans, glm::vec3(0.2, 0.2, 0.2));
			m_shaders->setMat4("transform", trans);
		
			//画基站位置
			glm::mat4 model = glm::mat4(1.0f); 
			/*model = glm::translate(model, bsPosition);  
			m_shaders->setMat4("model", model);*/

			glm::mat4 view = glm::mat4(1.0f);
			view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));		// 注意，我们将矩阵向我们要进行移动场景的反方向移动。
			m_shaders->setMat4("view", view);
			
			glBindVertexArray(VAO); //绑定顶点
			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

			/*for (unsigned int i = 1;i < 11; i++)
			{
				model = glm::mat4(1.0f);
				model = glm::translate(model, cubePositions[i-1]);
				float angle = 20.0f * i;
				model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
				m_shaders->setMat4("model", model);
				glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
			}*/
			//画交互设备
			for (unsigned int i = 0;i < 3; i++)
			{
				model = glm::mat4(1.0f);
				model = glm::translate(model, objectPositions[i]);
				model = glm::mat4_cast(objectRotation[i]) * model; //mat4_cast能把四元数转化成旋转矩阵
				// model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
				m_shaders->setMat4("model", model);
				glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
			}
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glfwTerminate();
	}
}