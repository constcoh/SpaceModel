#include "TemperaturePoint.h"

TemperaturePoint::TemperaturePoint()
	: SpacePoint(),
	temperature(0)
{
}

TemperaturePoint::TemperaturePoint(
	const Point &position,
	const Vector3d &velocity,
	const double &radius,
	const double &mass,
	const double &temperature)
	: SpacePoint(
		position,
		velocity,
		radius,
		mass),
	temperature(temperature)
{
}
