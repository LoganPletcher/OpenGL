#define GLM_FORCE_PURE
#define GLM_SWIZZLE

#include "gl_core_4_4.h"
#include <glfw3.h>
#include <iostream>
#include "Gizmos.h"
#include <glm\ext.hpp>

using glm::vec3;
using glm::vec4;
using glm::mat4;

int main()
{
	GLFWwindow* window;
	mat4 view;
	mat4 projection;
	if (glfwInit() == false)
		return -1;
	window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);
	if (window == nullptr)
	{
		glfwTerminate();
		return -2;
	}
	glfwMakeContextCurrent(window);
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}
	Gizmos::create();
	//view = glm::lookAt(vec3(20, 60, 20), vec3(0), vec3(0, 1, 0));
	projection = glm::ortho(glm::pi<float>() * 0.15f,
		16 / 9.f, 0.1f, 1000.f);
	Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
	system("pause");
	return 0;
}