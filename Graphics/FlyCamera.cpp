#include "Flycamera.h"

bool FlyCamera::update(float deltaTime)
{
	GLFWwindow* window = glfwGetCurrentContext();
	mat4 transform = getWorldTransform();
	if (glfwGetKey(window, 'W') == GLFW_PRESS)
		setPosition(vec4(0, 0, 0, -1));
	if (glfwGetKey(window, 'S') == GLFW_PRESS)
		setPosition(vec4(0, 0, 0, 1));
	if (glfwGetKey(window, 'Q') == GLFW_PRESS)
		setPosition(vec4(0, -1, 0, 0));
	if (glfwGetKey(window, 'E') == GLFW_PRESS)
		setPosition(vec4(0, 1, 0, 0));
	if (glfwGetKey(window, 'A') == GLFW_PRESS)
		setPosition(vec4(1, 0, 0, 0));
	if (glfwGetKey(window, 'D') == GLFW_PRESS)
		setPosition(vec4(-1, 0, 0, 0));
	return true;
}

void FlyCamera::setSpeed(float s)
{
	speed = s;
}