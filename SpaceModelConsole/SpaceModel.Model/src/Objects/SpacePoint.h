#pragma once

#include "Vectors\Vector3d.h"
#include "Objects\Primitives\Point.h"

class SpacePoint : public Point
{
public:
	Vector3d  velocity;
	double radius, mass;
	SpacePoint();
	SpacePoint(
		const Point &position, 
		const Vector3d &velocity, 
		const double &radius, 
		const double &mass);
};