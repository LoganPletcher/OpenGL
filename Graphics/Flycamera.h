#ifndef _FLYCAMERA_H_
#define _FLYCAMERA_H_

#include "Camera.h"

class FlyCamera : public Camera
{
public:
	bool update(float deltaTime) override;
	void setSpeed(float speed);

private:
	float speed;
	vec3 up;
};

#endif