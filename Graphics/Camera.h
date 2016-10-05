#ifndef _CAMERA_H_
#define _CAMERA_H_

#define GLM_FORCE_PURE
#define GLM_SWIZZLE

#include "gl_core_4_4.h"
#include <glfw3.h>
#include <iostream>
#include "Gizmos.h"
#include <glm\ext.hpp>

using glm::vec3;
using glm::vec4;
using glm::mat4;

class Camera
{
public:
	virtual bool update(float deltatime) = 0;
	void setPerspective(float fieldOfView, float aspectRatio, float Near, float Far);
	void setLookAt(vec3 from, vec3 to, vec3 up);
	void setPosition(vec4 difference);
	mat4 getWorldTransform();
	mat4 getView();
	mat4 getProjection();
	mat4 getProjectionView();
	void updateProjectionViewTransform();
private:
	mat4 worldTransform;
	mat4 viewTransform;
	mat4 projectionTransform;
	mat4 projectionViewTransform;

};

#endif