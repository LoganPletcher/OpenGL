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

void Camera::setPosition(vec3 position)
{
	worldTransform[3].xyz = position;
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