#include "Camera.h"

void Camera::setPerspective(float fieldOfView, float aspectRatio, float Near, float Far)
{
	projectionTransform = glm::perspective(fieldOfView,
		aspectRatio, Near, Far);
	projectionViewTransform = projectionTransform * viewTransform;
}

void Camera::setLookAt(vec3 from, vec3 to, vec3 up)
{
	viewTransform = glm::lookAt(from, to, up);
	worldTransform = glm::inverse(viewTransform);
	projectionViewTransform = projectionTransform * viewTransform;
}

void Camera::setPosition(vec4 difference)
{
	//float newX = viewTransform[0].x * cos(radians) + viewTransform[0].z * sin(radians);
	//float newZ = viewTransform[0].x * -sin(radians) + viewTransform[0].z * cos(radians);
	//viewTransform[0].xyz = vec3(newX, viewTransform[0].y, newZ);
	worldTransform[3] += difference;
}

void Camera::changeRotation(float rad)
{
	worldTransform[0].x = worldTransform[0].x * cos(rad);
	worldTransform[0].z = worldTransform[0].z * sin(rad);
	worldTransform[2].x = worldTransform[2].x * -sin(rad);
	worldTransform[2].z = worldTransform[2].z * cos(rad);
}

mat4 Camera::getWorldTransform()
{
	return worldTransform;
}

mat4 Camera::getView()
{
	return viewTransform;
}

mat4 Camera::getProjection()
{
	return projectionTransform;
}

mat4 Camera::getProjectionView()
{
	return projectionViewTransform;
}

void Camera::updateProjectionViewTransform()
{
	projectionViewTransform = projectionTransform * viewTransform;
}