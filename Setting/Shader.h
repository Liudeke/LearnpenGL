#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
class Shader
{
public:
	unsigned int ID;
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();
	void use();
	
	void setBool(const std::string &name, bool value) const;
	
	// ------------------------------------------------------------------------
	void setInt(const std::string &name, int value) const;
	
	// ------------------------------------------------------------------------
	void setFloat(const std::string &name, float value) const;
	
private:
	void checkCompileErrors(unsigned int shader, std::string type);
};

