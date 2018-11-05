#include "SpacePoint.h"

SpacePoint::SpacePoint()
	:Point(Vector3d::Zero),
	velocity(Vector3d::Zero),
	radius(0),
	mass(0)
{}

SpacePoint::SpacePoint(
	const Point &position,
	const Vector3d &velocity,
	const double &radius,
	const double &mass)
	:Point(position),
	velocity(velocity),
	radius(radius),
	mass(mass)
{}