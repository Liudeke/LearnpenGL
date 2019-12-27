#include <iostream>
#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
//#include <GLTools.h>
//#include <GLShaderManager.h>    // Shader Manager Class
//#include <GLBatch.h>
//#ifdef __APPLE__
//#include <glut/glut.h>          // OS X version of GLUT
//#else
//#define FREEGLUT_STATIC
//#include <gl/glut.h>            // Windows FreeGlut equivalent
//#endif
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")





////#pragma comment(lib,"glew32s.lib")
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
const char *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";
// settings
const unsigned int SCR_WIDTH = 600;
const unsigned int SCR_HEIGHT = 800;
int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(SCR_HEIGHT, SCR_WIDTH, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		//std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit()!= GLEW_OK) {
		//printf("failed");
		glfwTerminate();
		return -1;
	}
	GLfloat vVerts[18] = {
	   -0.5f, 0.0f, 0.0f,
		0.5f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f,

		//0.0f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		//0.5f, 0.0f, 0.0f,
	};
	unsigned int indices[]{
		0,1,2,
		2,1,3
	};
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	/*glViewport(0, 0, 800, 600);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);*/
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	/*glGenVertexArrays(1, &EBO);
	glBindVertexArray(EBO);*/
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vVerts), vVerts, GL_STATIC_DRAW);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	unsigned int verterShader;
	verterShader= glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(verterShader, 1, &vertexShaderSource, NULL);
	glCompileShader(verterShader);

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, verterShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//顶点shader
	/*int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	int success;
	char infolog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);*/

	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		processInput(window);
		glClearColor(0, 1, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glUseProgram(shaderProgram);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//GLint glGetUniformLocation();
	/*GL_LINES*/
	glfwTerminate();
	return 0;
}
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) ==GLFW_PRESS)//GLFW_PRESS
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
}

//GLBatch	triangleBatch;
//GLBatch squareBatch;
//GLShaderManager	shaderManager;//
//
/////////////////////////////////////////////////////////////////////////////////
//// Window has changed size, or has just been created. In either case, we need
//// to use the window dimensions to set the viewport and the projection matrix.
//void ChangeSize(int w, int h)
//{
//	glViewport(0, 0, w, h);
//}
//GLfloat vVerts[18] = { 
//	   -0.5f, 0.0f, 0.0f,
//		0.5f, 0.0f, 0.0f,
//		0.0f, 0.5f, 0.0f,
//
//		0.0f, 0.5f, 0.0f,
//		0.5f, 0.5f, 0.0f,
//		0.5f, 0.0f, 0.0f,
//};
//
//
/////////////////////////////////////////////////////////////////////////////////
//// This function does any needed initialization on the rendering context. 
//// This is the first opportunity to do any OpenGL related tasks.
//void SetupRC()
//{
//	// Blue background
//	glClearColor(0.50f, 1.0f, 1.0f, 1.0f);//设置背景颜色
//
//	shaderManager.InitializeStockShaders();//初始化着色器，使其可以编译链接自己的着色器
//
//	// Load up a triangle
//	/* vVerts[] = { -0.5f, 0.0f, 0.0f,
//		0.5f, 0.0f, 0.0f,
//		0.0f, 0.5f, 0.0f };
//*/
//	triangleBatch.Begin(GL_TRIANGLES, 6);
//	triangleBatch.CopyVertexData3f(vVerts);
//	triangleBatch.End();
//}
//
//
///////////////////////////////////////////////////////////////////////////////
//// Called to draw scene
//void RenderScene(void)//开始渲染
//{
//	// Clear the window with current clearing color
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);//清除屏幕上最后绘制的内容
//
//	GLfloat vRed[] = { 1.0f, 1.0f, 0.0f, 1.0f };
//	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
//	triangleBatch.Draw();//将几何图形 提交到着色器
//
//	// Perform the buffer swap to display back buffer
//	glutSwapBuffers();
//
//}
//
//void SpecialKeys(int key, int x, int y) {
//	GLfloat blockSize = 0.02f;
//	GLfloat stepSize = 0.025f;
//	GLfloat blockX = vVerts[0];
//	GLfloat blockY = vVerts[7];
//	vVerts[0] = 5.0f;
//	vVerts[7] = 5.0f;
//	printf("test");
//	if (key == GLUT_KEY_UP)
//		blockY += stepSize;
//	if (key == GLUT_KEY_DOWN)
//		blockY -= stepSize;
//	if (key == GLUT_KEY_LEFT)
//		blockY -= stepSize;
//	if (key == GLUT_KEY_RIGHT)
//		blockY += stepSize;
//	/*if (blockX < -1)blockX = -1;
//	if (blockX > (1 - blockSize * 2))blockX = (1 - blockSize * 2);
//
//	if (blockY < (-1 + blockSize * 2))blockY= -1 + blockSize * 2;
//	if (blockY > 1 )blockY=1;
//
//	vVerts[0] = blockX;
//	vVerts[1] = blockY-blockSize*2;
//
//	vVerts[3] = blockX+blockSize*2;
//	vVerts[4] = blockY-blockSize*2;
//
//	vVerts[6] = blockX+blockSize*2;
//	vVerts[7] = blockY;
//
//	vVerts[9] = blockX;
//	vVerts[10] = blockY;
//	squareBatch.CopyVertexData3f(vVerts);*/
//	triangleBatch.CopyVertexData3f(vVerts);
//	glutPostRedisplay();
//}
/////////////////////////////////////////////////////////////////////////////////
//// Main entry point for GLUT based programs
//int main(int argc, char* argv[])
//{
//	gltSetWorkingDirectory(argv[0]);
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
//	glutInitWindowSize(600, 800);
//	glutCreateWindow("Triangle");
//	glutReshapeFunc(ChangeSize);
//	glutDisplayFunc(RenderScene);
//	//glutSpecialFunc(SpecialKeys);
//	GLenum err = glewInit();
//	if (GLEW_OK != err) {
//		fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
//		return 1;
//	}
//
//	SetupRC();
//
//	glutMainLoop();
//	system("puase");
//	return 0;
//}
//
