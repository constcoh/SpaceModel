#pragma once

#include "Matrix4d.h"

class Transform3dFactory
{
public:
	static Matrix4d Shift(
		const double &dx,
		const double &dy,
		const double &dz);

	static Matrix4d RotateX(const double &angle);
	static Matrix4d RotateY(const double &angle);
	static Matrix4d RotateZ(const double &angle);

	static Matrix4d Scale(
		const double &sx,
		const double &sy,
		const double &sz);
};