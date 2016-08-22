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

void Update(mat4 *Sun, mat4 *Planet, mat4 *Moon)
{
	*Sun = glm::rotate(*Sun, 1.0f, vec3(0,1,0));
	*Planet = *Sun * glm::translate(vec3(5));
}

void Draw(mat4 Sun, mat4 Planet, mat4 Moon)
{
	Gizmos::addSphere(vec3(Sun[3][0], Sun[3][1], Sun[3][2]),3,50,50, vec4(1.0f, 0.62f, 0.0f, 1), &Sun);
	Gizmos::addSphere(vec3(Planet[3][0], Planet[3][1], Planet[3][2]), .5, 25, 25, vec4(0.0f, 0.5f, 0.5f, 1), &Planet);
	Gizmos::addSphere(vec3(Moon[3][0], Moon[3][1], Moon[3][2]), .2, 12, 12, vec4(0.5f, 0.5f, 0.5f, 1), &Moon);
}

int main()
{
	//float r = 1;
	float r = 0.1f;
	float g = 0.1f;
	float b = 0.1f;
	mat4 Sun = mat4(1);
	mat4 Planet = glm::translate(Sun, vec3(5));
	mat4 Moon = glm::translate(Planet, vec3(1.0));
	vec3 EulerAngles(0, 1, 0);
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
	mat4 view = glm::lookAt(vec3(5, 30, 10), vec3(0), vec3(0, 1, 0));
	mat4 projection = glm::perspective(glm::pi<float>() * 0.15f,
		16 / 9.f, 0.1f, 1000.f);
	mat4 model = mat4(1.0);

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
			/*if (PlanetCounter > 359)
				PlanetCounter = 0;
			else
				PlanetCounter++;
			PlanetX = cos(PlanetCounter*(3.14159 / 180))*5.0f;
			PlanetZ = sin(PlanetCounter*(3.14159 / 180))*5.0f;
			if (MoonCounter > 359)
				MoonCounter = 0;
			else
				MoonCounter++;
			MoonX = cos(MoonCounter*(3.14159 / 180)*3)*1.0f + PlanetX;
			MoonZ = sin(MoonCounter*(3.14159 / 180)*3)*1.0f + PlanetZ;*/
			//Gizmos::draw(Sun);
			//glm::translate();
			//Sun = glm::rotate(Sun, 1.0f, vec3(0, 1, 0));
			//Gizmos::addSphere(vec3(Sun[3][0], Sun[3][1], Sun[3][2]), 3, 50, 50, vec4(1.0f, 0.25f, 0.0f, 1), &Sun);
			//Gizmos::addSphere(vec3(Planet[3][0], Planet[3][1], Planet[3][2]), .5, 25, 25, vec4(0.0f, 0.5f, 0.5f, 1), &(model = glm::rotate(model, 1.0f, EulerAngles)));
			//Gizmos::addSphere(vec3(Moon[3][0], Moon[3][1], Moon[3][2]), .2, 12, 12, vec4(0.5f, 0.5f, 0.5f, 1), &(model = glm::rotate(model, .5f, EulerAngles)));
			Update(&Sun, &Planet, &Moon);
			Draw(Sun,Planet,Moon);
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