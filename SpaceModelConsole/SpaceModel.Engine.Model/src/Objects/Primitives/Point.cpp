#include "Point.h"

Point::Point():Primitive(), Vector3d(0.0, 0.0, 0.0)
{
}

Point::Point(const Vector3d &vector) 
	: Primitive(), Vector3d(vector)
{
}

Point::Point(const Point &point) 
	: Primitive(), Vector3d(point)
{
}

Point::Point(const double x, const double y, const double z) 
	: Primitive(), Vector3d(x, y, z)
{
}

