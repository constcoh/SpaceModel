#pragma once

#include "Vector3d.h"
#include "Vector4d.h"

class ExtendedVector3d : public Vector4d
{
private:
	void Normalize();
public:
	ExtendedVector3d();
	ExtendedVector3d(const double &x, const double &y, const double &z, const double &w);
	ExtendedVector3d(const Vector3d &vector);
	Vector3d get3d();
	void set3d(const Vector3d &vector);
};