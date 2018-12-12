#include "camera.h"

Camera::Camera(
	const Vector3d& front,
	const Vector3d& position,
	const Vector3d& up,
	const double maxDistance,
	const double minDistance,
	const double horizontalAngle,
	const double verticalAngle,
	const double height,
	const double width)
	:front(front),
	position(position),
	up(up),
	maxDistance(maxDistance),
	minDistance(minDistance),
	horizontalAngle(horizontalAngle),
	verticalAngle(verticalAngle),
	height(height),
	width(width)
{
	this->zBuffer = new double*[height];
	for(int i=>0; i<)
}