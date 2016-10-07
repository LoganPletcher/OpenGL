#include "Flycamera.h"

bool FlyCamera::update(float deltaTime)
{
	GLFWwindow* window = glfwGetCurrentContext();
	mat4 transform = getWorldTransform();
	if (glfwGetKey(window, 'W') == GLFW_PRESS)
		setPosition(vec4(0, 0, 0, .1));
	if (glfwGetKey(window, 'S') == GLFW_PRESS)
		setPosition(vec4(0, 0, 0, -.1));
	if (glfwGetKey(window, 'Q') == GLFW_PRESS)
		setPosition(vec4(0, .01, 0, 0));
	if (glfwGetKey(window, 'E') == GLFW_PRESS)
		setPosition(vec4(0, -.1, 0, 0));
	if (glfwGetKey(window, 'A') == GLFW_PRESS)
		setPosition(vec4(.1, 0, -.1, 0));
	if (glfwGetKey(window, 'D') == GLFW_PRESS)
		setPosition(vec4(-.1, 0, .1, 0));

	static bool sbMouseButtonDown = false;
	if (glfwGetMouseButton(window, 1) == GLFW_PRESS)
	{
		static double prevMouseX = 0, prevMouseY = 0;
		if (sbMouseButtonDown == false) {
			sbMouseButtonDown = true;
			glfwGetCursorPos(window, &prevMouseX, &prevMouseY);
		}
		double mouseX = 0, mouseY = 0;
		glfwGetCursorPos(window, &mouseX, &mouseY);
		
		double deltaX = mouseX - prevMouseX;
		double deltaY = mouseY - prevMouseY;

		prevMouseX = mouseX;
		prevMouseY = mouseY;

		mat4 Tmat;
		if (deltaX != 0)
		{
			//mat4 world = getWorldTransform();
			
		}
	}

	viewTransform = glm::inverse(worldTransform);
	projectionViewTransform = projectionTransform * viewTransform;
	return true;
}

void FlyCamera::setSpeed(float s)
{
	speed = s;
}