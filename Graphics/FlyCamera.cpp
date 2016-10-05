#include "Flycamera.h"

bool FlyCamera::update(float deltaTime)
{
	GLFWwindow* window = glfwGetCurrentContext();
	mat4 transform = getWorldTransform();
	if (glfwGetKey(window, 'W') == GLFW_PRESS)
		setPosition(transform[2].xyz);
	return true;
}

void FlyCamera::setSpeed(float s)
{
	speed = s;
}