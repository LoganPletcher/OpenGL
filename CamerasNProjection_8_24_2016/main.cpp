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
	//GLFWwindow* window;
	//mat4 view;
	//mat4 projection;
	//if (glfwInit() == false)
	//	return -1;
	//window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);
	//if (window == nullptr)
	//{
	//	glfwTerminate();
	//	return -2;
	//}
	//glfwMakeContextCurrent(window);
	//if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	//{
	//	glfwDestroyWindow(window);
	//	glfwTerminate();
	//	return -3;
	//}
	//Gizmos::create();
	////view = glm::lookAt(vec3(20, 60, 20), vec3(0), vec3(0, 1, 0));
	//projection = glm::ortho(glm::pi<float>() * 0.15f,
	//	16 / 9.f, 0.1f, 1000.f);
	//Gizmos::destroy();
	//glfwDestroyWindow(window);
	//glfwTerminate();
	//system("pause");
	//return 0;

	GLFWwindow* window;
	mat4 view;
	mat4 projection;
	double DCPosX, DCPosY;
	float FCPosX;
	float currentTime = glfwGetTime();
	float previousTime = currentTime;
	float deltaTime = 0;
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
	view = glm::lookAt(vec3(30, 30, 30), vec3(0), vec3(0, 1, 0));
	//projection = glm::perspective(glm::pi<float>() * 0.15f,
	//	16 / 9.f, 0.1f, 1000.f);
	projection = glm::ortho(-32.f, 32.f, -18.f, 18.f, 0.f, 100.f);
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);
	glClearColor(0.25f, 0.25f, 0.25f, 1);
	while (glfwWindowShouldClose(window) == false &&
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Gizmos::clear();
		Gizmos::addTransform(glm::mat4(1));
		vec4 white(1);
		vec4 black(0, 0, 0, 1);
		currentTime = glfwGetTime();
		deltaTime = (currentTime - previousTime);
		previousTime = currentTime;
		glfwGetCursorPos(window, &DCPosX, &DCPosY);
		FCPosX = std::abs(DCPosX - 640);
		if (DCPosX - 640 > 0)
			view = glm::rotate(view, 3.f * deltaTime, vec3(0,1,0));
		else if (DCPosX - 640 < 0)
			view = glm::rotate(view, -3.f * deltaTime, vec3(0, 1, 0));
		glfwSetCursorPos(window, 1280 - (1280 / 2), 720 - (720 / 2));
		for (int i = 0; i < 21; ++i) {
			Gizmos::addLine(vec3(-10 + i, 0, 10),
				vec3(-10 + i, 0, -10),
				i == 10 ? white : black);
			Gizmos::addLine(vec3(10, 0, -10 + i),
				vec3(-10, 0, -10 + i),
				i == 10 ? white : black);
		}
		Gizmos::addSphere(vec3(0,0,0), 5, 50, 50, black);
		Gizmos::draw(projection * view);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glEnable(GL_DEPTH_TEST);
	Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}