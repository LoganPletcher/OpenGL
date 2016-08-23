#ifndef _OPENGL_STAR_SYSTEM_H_
#define _OPENGL_STAR_SYSTEM_H_
#include "Program.h"

class OpenGL_Star_System : public Program
{
public:
	virtual int Start();
	virtual bool Update();
	virtual void Draw();
	virtual void Quit();
	
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
}

#endif !_OPENGL_STAR_SYSTEM_H_