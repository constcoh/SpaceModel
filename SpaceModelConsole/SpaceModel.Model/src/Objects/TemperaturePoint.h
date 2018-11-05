#pragma once

#include "SpacePoint.h"

class TemperaturePoint : public SpacePoint
{
public:
	double temperature;
	TemperaturePoint();
	TemperaturePoint(
		const Point &position,
		const Vector3d &velocity,
		const double &radius,
		const double &mass,
		const double &temperature);
};