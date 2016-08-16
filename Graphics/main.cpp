#define GLM_FORCE_PURE
#include "gl_core_4_4.h"
#include <glfw3.h>
#include <iostream>
#include "Gizmos.h"
#include <glm\glm.hpp>
#include <glm\ext.hpp>
using glm::vec3;
using glm::vec4;
using glm::mat4;

int main()
{
	//float r = 1;
	float r = 0.1f;
	float g = 0.1f;
	float b = 0.1f;
	vec3 Sun = vec3(0, 2, 0);
	if (glfwInit() == false)
		return -1;
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);
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
	mat4 view = glm::lookAt(vec3(15, 5, 10), vec3(0), vec3(0, 1, 0));
	mat4 projection = glm::perspective(glm::pi<float>() * 0.25f,
		16 / 9.f, 0.1f, 1000.f);

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	while (glfwWindowShouldClose(window) == false &&
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glClearColor(r, g, b, 1);
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//r -= .25f;
		//g += .25f;
		////b += .5f;
		//if (r <= 0.0f)
		//{
		//	r = 1.0f;
		//	g = 0.0f;
		//	b = 0.0f;
		//}
		// our game logic and update code goes here!
		// so does our render code!
		while (glfwWindowShouldClose(window) == false &&
			glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			Gizmos::clear();
			Gizmos::addTransform(glm::mat4(1));
			vec4 white(1);
			vec4 black(0, 0, 0, 1);
			for (int i = 0; i < 21; ++i) {
				Gizmos::addLine(vec3(-10 + i, 0, 10),
					vec3(-10 + i, 0, -10),
					i == 10 ? white : black);
				Gizmos::addLine(vec3(10, 0, -10 + i),
					vec3(-10, 0, -10 + i),
					i == 10 ? white : black);
			}
			Gizmos::addSphere(Sun, 3, 50, 50, vec4(0.5f, 0.25f, 0.0f, 1));
			
			Gizmos::draw(projection * view);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}