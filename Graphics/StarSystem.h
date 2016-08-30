#ifndef _STARSYSTEM_H_
#define _STARSYSTEM_H_

#define GLM_FORCE_PURE
#define GLM_SWIZZLE

#include "gl_core_4_4.h"
#include <glfw3.h>
#include <iostream>
#include "Gizmos.h"
#include <glm\ext.hpp>

#include "Program.h"

using glm::vec3;
using glm::vec4;
using glm::mat4;

class StarSystem : public Program
{
public:
	bool startup() override;
	bool update() override;
	void draw() override;
	void shutdown() override;
	
private:
	float r;
	float g;
	float b;
	mat4 Sun;
	mat4 Planet;
	mat4 Moon;
	GLFWwindow* window;
	mat4 view;
	mat4 projection;
	double DCPosX, DCPosY;
	float FCPosX;
	float currentTime = glfwGetTime();
	float previousTime = currentTime;
	float deltaTime = 0;
};

#endif