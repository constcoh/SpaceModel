#pragma once

#include "Vectors\Vector3d.h"
#include "Matrices\Matrix4d.h"
#include "Matrices\Transform3dFactory.h"

class Camera {
private:
	// General Camera properties:
	Vector3d front;
	Vector3d position;
	Vector3d up;

	// View matrix parameters:
	double maxDistance;
	double minDistance;
	double horizontalAngle;
	double verticalAngle;
	double height;
	double width;
	double* zBuffer;  
	////Color 
public:
	Camera(
		const Vector3d& front,
		const Vector3d& position,
		const Vector3d& up,
		const double maxDistance,
		const double minDistance,
		const double horizontalAngle,
		const double verticalAngle,
		const double height,
		const double width);

	~Camera();

	void Move(const Vector3d x);
	void RotateUp(const double &angle);
	void RotateLeft(const double &angle);
};