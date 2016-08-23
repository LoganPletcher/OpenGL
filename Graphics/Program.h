#ifndef PROGRAM_H
#define PROGRAM_H
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

class Program
{
public:
	virtual int Start() = 0;
	virtual bool Update() = 0;
	virtual void Draw() = 0;
	virtual void Quit() = 0;
private:
};
#endif !PROGRAM_H