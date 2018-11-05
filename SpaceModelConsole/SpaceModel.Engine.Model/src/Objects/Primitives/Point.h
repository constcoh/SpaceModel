#pragma once

#include "Vectors\Vector3d.h"
#include "..\Primitive.h"

class Point : public Primitive, public Vector3d
{
public:
	Point();
	Point(const Point &point);
	Point(const Vector3d &vector);
	Point(const double x, const double y, const double z);
};