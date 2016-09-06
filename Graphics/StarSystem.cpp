#include "StarSystem.h"
#include <iostream>

bool StarSystem::startup()
{
	if (glfwInit() == false)
		return false;
	window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);
	if (window == nullptr)
	{
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return false;
	}
	Gizmos::create();
	view = glm::lookAt(vec3(20, 30, 20), vec3(0), vec3(0, 1, 0));
	projection = glm::perspective(glm::pi<float>() * 0.15f,
		16 / 9.f, 0.1f, 1000.f);
	//projection = glm::ortho(-32.f, 32.f, -18.f, 18.f, 0.f, 100.f);
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);
	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);
	Sun = mat4(1);
	Planet = glm::translate(Sun, vec3(5));
	Moon = glm::translate(Planet, vec3(1.0));
	return true;
}

bool StarSystem::update()
{
	while (glfwWindowShouldClose(window) == false &&
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) 
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Gizmos::clear();
		Gizmos::addTransform(glm::mat4(1));
		Sun = Sun * glm::rotate((1.0f*(3.14f / 180.0f)), vec3(0, 1, 0));
		Planet = Sun * glm::translate(vec3(5, 0, 0));
		Moon = Planet * glm::rotate((1.0f*(3.14f / 180.0f)), vec3(0, 1, 0)) * glm::translate(Sun, vec3(1, 0, 0));
		currentTime = glfwGetTime();
		deltaTime = (currentTime - previousTime);
		previousTime = currentTime;
		glfwGetCursorPos(window, &DCPosX, &DCPosY);
		std::cout << view[0][0] << "," << view[0][1] << "," << view[0][2] << "," << view[0][3] << std::endl;
		std::cout << view[1][0] << "," << view[1][1] << "," << view[1][2] << "," << view[1][3] << std::endl;
		std::cout << view[2][0] << "," << view[2][1] << "," << view[2][2] << "," << view[2][3] << std::endl;
		std::cout << view[3][0] << "," << view[3][1] << "," << view[3][2] << "," << view[3][3] << "\n\n";
		if (DCPosX - 640 > 0)
		{
			//view = glm::rotate(view, 3.f * deltaTime, vec3(0, 1, 0));
			yAngle += deltaTime;
			//view = yRot(view, yAngle);
		}
		else if (DCPosX - 640 < 0)
		{
			//view = glm::rotate(view, -3.f * deltaTime, vec3(0, 1, 0));
			yAngle -= deltaTime;
			//view = yRot(view, yAngle);
		}
		//glfwSetCursorPos(window, 1280 - (1280 / 2), 720 - (720 / 2));
		//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		xAngle++;
		std::cout << yAngle << "\n\n";
		view = yRot(view, yAngle);
		//view = glm::rotate(view, 3.f * deltaTime, vec3(0, 1, 0));
		
		view = zRot(view, yAngle);
		view = xRot(view, yAngle);
		view[1][1] = .685994;
		view[1][2] = .727607;
		return true;
	}
	return false;
}

void StarSystem::draw()
{
	vec4 white(1);
	vec4 black(0, 0, 0, 1);
	for (int i = 0; i < 21; ++i) 
	{
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

void StarSystem::shutdown()
{
	Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
}

mat4 StarSystem::yRot(mat4 matrix, float angle)
{

	matrix[0][0] = cos(angle);
	matrix[0][2] = sin(angle);
	matrix[2][0] = -sin(angle);
	matrix[2][2] = cos(angle);

	return matrix;
}

mat4 StarSystem::xRot(mat4 matrix, float angle)
{
	matrix[1][1] = cos(angle);
	matrix[1][2] = -sin(angle);
	matrix[2][1] = sin(angle);
	matrix[2][2] = cos(angle);

	return matrix;
}

mat4 StarSystem::zRot(mat4 matrix, float angle)
{
	matrix[0][0] = cos(angle);
	matrix[0][1] = -sin(angle);
	matrix[1][0] = sin(angle);
	matrix[1][1] = cos(angle);

	return matrix;
}