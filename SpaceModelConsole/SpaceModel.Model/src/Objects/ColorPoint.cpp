#pragma once

#include "ColorPoint.h"

ColorPoint::ColorPoint()
	:SpacePoint(),
	color()
{}

ColorPoint::ColorPoint(const Point &position,
	const Vector3d &velocity,
	const double &radius,
	const double &mass,
	const Color &color)
	: SpacePoint(
		position,
		velocity,
		radius,
		mass),
	color(color)
{
}