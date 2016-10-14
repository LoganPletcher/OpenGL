#include "Flycamera.h"

bool FlyCamera::update(float deltaTime)
{
	GLFWwindow* window = glfwGetCurrentContext();
	mat4 transform = getWorldTransform();
	if (glfwGetKey(window, 'W') == GLFW_PRESS)
		setPosition(vec4(-.2, -.2, -.2, 0));
	if (glfwGetKey(window, 'S') == GLFW_PRESS)
		setPosition(vec4(.2, .2, .2, 0));
	if (glfwGetKey(window, 'Q') == GLFW_PRESS)
		setPosition(vec4(0, .2, 0, 0));
	if (glfwGetKey(window, 'E') == GLFW_PRESS)
		setPosition(vec4(0, -.2, 0, 0));
	if (glfwGetKey(window, 'A') == GLFW_PRESS)
		setPosition(vec4(.2, 0, -.2, 0));
	if (glfwGetKey(window, 'D') == GLFW_PRESS)
		setPosition(vec4(-.2, 0, .2, 0));

	if (glfwGetKey(window, 'P') == GLFW_PRESS)
		changeYRotation(0.0174533);
	if (glfwGetKey(window, 'O') == GLFW_PRESS)
		changeYRotation(-0.0174533);
	if (glfwGetKey(window, 'I') == GLFW_PRESS)
		changeXRotation(0.0174533);
	if (glfwGetKey(window, 'U') == GLFW_PRESS)
		changeXRotation(-0.0174533);

	viewTransform = glm::inverse(worldTransform);
	projectionViewTransform = projectionTransform * viewTransform;
	return true;
}

void FlyCamera::setSpeed(float s)
{
	speed = s;
}