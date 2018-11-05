#include "Core\Condition.h"
#include "ExtendedVector3d.h"

#pragma region Private mathods

void ExtendedVector3d::Normalize()
{
	Condition::IsFalse(this->w == 0, "z is not 0");
	x /= w;
	y /= w;
	z /= w;
}

#pragma endregion

#pragma region  Public Methods

ExtendedVector3d::ExtendedVector3d() : Vector4d(0.0, 0.0, 0.0, 1.0)
{
}

ExtendedVector3d::ExtendedVector3d(const double &x, const double &y, const double &z, const double &w) 
	: Vector4d(x, y, z, w)
{
}

ExtendedVector3d::ExtendedVector3d(const Vector3d &vector) : Vector4d(vector.x, vector.y, vector.z, 1.0)
{
}

Vector3d ExtendedVector3d::get3d()
{
	Condition::IsFalse(this->w == 0, "w is not 0");
	return Vector3d(x / w, y / w, z / w);
}

void ExtendedVector3d::set3d(const Vector3d &vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
	this->w = 1;
}

#pragma endregion

