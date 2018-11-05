#pragma once

#include "Vector2d.h"
#include "Vector3d.h"

class ExtendedVector2d : public Vector3d
{
private:
	void Normalize();
public: 
	ExtendedVector2d();
	ExtendedVector2d(const double &x, const double &y, const double &z);
	ExtendedVector2d(const Vector2d &vector);
	Vector2d get2d();
	void set2d(const Vector2d &vector);
};