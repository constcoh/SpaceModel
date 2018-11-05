#include "Core\Condition.h"
#include "ExtendedVector2d.h"

#pragma region Private mathods

void ExtendedVector2d::Normalize()
{
	Condition::IsFalse(this->z == 0, "z is not 0");
	x /= z;
	y /= z;
}

#pragma endregion

#pragma region  Public Methods

ExtendedVector2d::ExtendedVector2d(const double &x, const double &y, const double &z)
	: Vector3d(x, y, z)
{
}

ExtendedVector2d::ExtendedVector2d() : Vector3d(0.0, 0.0, 1.0)
{
}

ExtendedVector2d::ExtendedVector2d(const Vector2d &vector) : Vector3d(vector.x, vector.y, 1.0)
{
}

Vector2d ExtendedVector2d::get2d()
{
	Condition::IsFalse(this->z == 0, "z is not 0");
	return Vector2d(x / z, y / z);
}

void ExtendedVector2d::set2d(const Vector2d &vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = 1;
}

#pragma endregion

