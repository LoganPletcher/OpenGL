#include "OPENGL_STAR_SYSTEM.h"
#include <iostream>

int OpenGL_Star_System::Start()
{
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
	view = glm::lookAt(vec3(20, 60, 20), vec3(0), vec3(0, 1, 0));
	projection = glm::perspective(glm::pi<float>() * 0.15f,
		16 / 9.f, 0.1f, 1000.f);
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);
	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);
	return 0;
}

bool OpenGL_Star_System::Update()
{
	while (glfwWindowShouldClose(window) == false &&
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Gizmos::clear();
		Gizmos::addTransform(glm::mat4(1));
		Sun = Sun * glm::rotate((1.0f*(3.14f / 180.0f)), vec3(0, 1, 0));
		Planet = Sun * glm::translate(vec3(5, 0, 0));
		Moon = Planet * glm::rotate((1.0f*(3.14f / 180.0f)), vec3(0, 1, 0)) * glm::translate(vec3(2, 0, 0));
		return true;
	}
	return false;
}

void OpenGL_Star_System::Draw()
{
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
	Gizmos::addSphere(vec3(Sun[3]), 3, 50, 50, vec4(1.0f, 0.62f, 0.0f, 1), &Sun);
	Gizmos::addSphere(vec3(Planet[3]), .5, 25, 25, vec4(0.0f, 1.0f, 1.0f, 1), &Planet);
	Gizmos::addSphere(vec3(Moon[3]), .2, 12, 12, vec4(0.5f, 0.5f, 0.5f, 1), &Moon);
	Gizmos::draw(projection * view);

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void OpenGL_Star_System::Quit()
{
	Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
}