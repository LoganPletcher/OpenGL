#ifndef _PROGRAM_H_
#define _PROGRAM_H_
#include "gl_core_4_4.h"
#include <glfw3.h>
#include <iostream>

class Program {
public:
	virtual bool startup() = 0;
	virtual void shutdown() = 0;
	virtual bool update() = 0;
	virtual void draw() = 0;
};
#endif