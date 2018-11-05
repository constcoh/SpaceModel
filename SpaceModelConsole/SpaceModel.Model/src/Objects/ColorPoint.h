#pragma once

#include "Core\Color.h"
#include "SpacePoint.h"

class ColorPoint : public SpacePoint
{
public:
	Color color;
	ColorPoint();
	ColorPoint(const Point &position,
		const Vector3d &velocity,
		const double &radius,
		const double &mass,
		const Color &color);
};