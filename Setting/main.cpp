//#include <fstream>
//#include <sstream>
//#include <iostream>
//#define GLEW_STATIC
//#include<GL/glew.h>
//#include<GLFW/glfw3.h>
//#include "Shader.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include<gl/eglew.h>
//using namespace std;
//using namespace glm;
////#include <GLTools.h>
////#include <GLShaderManager.h>    // Shader Manager Class
////#include <GLBatch.h>
////#ifdef __APPLE__
////#include <glut/glut.h>          // OS X version of GLUT
////#else
////#define FREEGLUT_STATIC
////#include <gl/glut.h>            // Windows FreeGlut equivalent
////#endif
////#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
//
//
//
//
//
//////#pragma comment(lib,"glew32s.lib")
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);
//
//// settings
//const unsigned int SCR_WIDTH = 600;
//const unsigned int SCR_HEIGHT = 800;
//int main() {
//	glm::vec4 vec(1, 0, 0, 1);
//	glm::mat4 trans = glm::mat4(1);
//
//	//trans = glm::translate(trans, glm::vec3(0.5f, 0, 0));
//
//	trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0, 0, 1));
//	trans = scale(trans, vec3(0.5f, 0.5f, 0.5f));
//
//	//vec = trans * vec;
//	std::cout << vec.x << vec.y << vec.z << std::endl;
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	GLFWwindow* window = glfwCreateWindow(SCR_HEIGHT, SCR_WIDTH, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		//std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glewExperimental = true;
//	if (glewInit() != GLEW_OK) {
//		//printf("failed");
//		glfwTerminate();
//		return -1;
//	}
//	Shader shader("shader.vs", "shader.fs");
//
//	GLfloat vVerts[] = {
//	  -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//	//GLfloat vVerts[] = {
//	// 1.0f, 0.5f, 0.0f,  1.0f, 0.5f, 0.0f,  1.0f, 1.0f, // top right // 右下
//	// 1.0f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f, // bottom right// 左下
//	//0.0f,  -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, // bottom left// 顶部
//	//0.0f,  0.5f, 0.0f,  0.1f, 0.5f, 1.0f,  0.0f, 1.0f  // top left  // 顶部
//	//}; 
//	unsigned int indices[]{
//		/*0,3,6,
//		7,0,10*/
//		 0, 1, 3, // first triangle
//		1, 2, 3  // second triangle
//	};
//#pragma region MyRegion
//
//
//
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	unsigned int VAO;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	unsigned int VBO;
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vVerts), vVerts, GL_STATIC_DRAW);
//
//	unsigned int EBO;
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	/*glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);*/
//
//	unsigned int texture1, texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	int width, height, nrChannels;
//	stbi_set_flip_vertically_on_load(true);
//
//	unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//
//
//	glGenTextures(1, &texture2);
//	//glActiveTexture(GL_TEXTURE1);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//stbi_set_flip_vertically_on_load(true);
//
//	data = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//	shader.use();
//	glUniform1i(glGetUniformLocation(shader.ID, "texture1"), 0);
//	shader.setInt("texture2", 1);
//#pragma endregion
//	/*unsigned int tranformLoc = glGetUniformLocation(shader.ID, "transform");
//	glUniformMatrix4fv(tranformLoc, 1, GL_FALSE, value_ptr(trans));*/
//	//glm::mat4 transform;
//
//	while (!glfwWindowShouldClose(window))
//	{
//		// input
//		// -----
//		processInput(window);
//		glClearColor(0, 0, 0, 1);
//		glClear(GL_COLOR_BUFFER_BIT);
//		glBindVertexArray(VAO);
//
//		/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//		glActiveTexture(GL_TEXTURE0);*/
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//
//
//		//transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//
//		//transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
//		//transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//		shader.use();
//		/*unsigned int transformLoc = glGetUniformLocation(shader.ID, "transform");
//		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));*/
//
//		glm::mat4 model = glm::mat4(1.0f);
//		model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
//		glm::mat4 view = mat4(1.0f);
//		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//		glm::mat4 projection = glm::mat4(1.0f);
//		projection = glm::perspective(glm::radians(45.0f), ((float)SCR_HEIGHT / (float)SCR_WIDTH), 0.1f, 100.0f);
//
//		unsigned int transformLocmodel = glGetUniformLocation(shader.ID, "model");
//		unsigned int transformLocview = glGetUniformLocation(shader.ID, "view");
//
//		glUniformMatrix4fv(transformLocmodel, 1, GL_FALSE, glm::value_ptr(model));
//
//		glUniformMatrix4fv(transformLocview, 1, GL_FALSE, glm::value_ptr(view));
//
//		unsigned int transformLocprojection = glGetUniformLocation(shader.ID, "projection");
//		glUniformMatrix4fv(transformLocprojection, 1, GL_FALSE, glm::value_ptr(projection));
//
//
//		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
//
//		//transform = glm::mat4(1.0f); // reset it to identity matrix
//		//float xValue = cos(glfwGetTime());
//		//float YValue = sin(glfwGetTime());
//
//		//transform = glm::translate(transform, glm::vec3(xValue, YValue, 0.0f));
//		//float scaleAmount = sin(glfwGetTime());
//		//transform = glm::scale(transform, glm::vec3(scaleAmount, scaleAmount, scaleAmount));
//		//glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform)); // this time take the matrix value array's first element as its memory pointer value
//
//
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		//glDrawArrays(GL_TRIANGLES, 0, 6);
//		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//		// -------------------------------------------------------------------------------
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//
//	glfwTerminate();
//	return 0;
//}
//void processInput(GLFWwindow *window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//GLFW_PRESS
//		glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//	/*glEnable(GL_CULL_FACE);
//	glCullFace(GL_FRONT);*/
//}
//
//
//
//
