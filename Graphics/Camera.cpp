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

void Camera::changeYRotation(float rad)
{
	rotationMat[0] = { cos(rad), 0, sin(rad), 0 };
	rotationMat[1] = { 0, 1, 0, 0 };
	rotationMat[2] = { -sin(rad), 0, cos(rad), 0 };
	rotationMat[3] = { 0, 0, 0, 1 };
	worldTransform *= rotationMat;
}

void Camera::changeXRotation(float rad)
{
	rotationMat[0] = { 1, 0, 0, 0 };
	rotationMat[1] = { 0, cos(rad), -sin(rad), 0 };
	rotationMat[2] = { 0, sin(rad), cos(rad), 0 };
	rotationMat[3] = { 0, 0, 0, 1 };
	worldTransform *= rotationMat;
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