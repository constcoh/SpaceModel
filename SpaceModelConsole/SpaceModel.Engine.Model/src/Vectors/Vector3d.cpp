#include "Core.h"
#include "Vector3d.h"
#include <math.h>

const Vector3d Vector3d::Zero(0, 0, 0);
const Vector3d Vector3d::OrtX(1, 0, 0);
const Vector3d Vector3d::OrtY(0, 1, 0);
const Vector3d Vector3d::OrtZ(0, 0, 1);

Vector3d::Vector3d() :x(0.0), y(0.0), z(0.0)
{
}

Vector3d::Vector3d(double x, double y, double z) :x(x), y(y), z(z)
{
}

bool Vector3d::operator==(const Vector3d& vector) const
{
	return
		CompareWithPercision(x, vector.x) &&
		CompareWithPercision(y, vector.y) &&
		CompareWithPercision(z, vector.z);
}

bool Vector3d::operator!=(const Vector3d& vector) const
{
	return
		!CompareWithPercision(x, vector.x) ||
		!CompareWithPercision(y, vector.y) ||
		!CompareWithPercision(z, vector.z);
}

const Vector3d& Vector3d::operator=(const Vector3d& vector)
{
	x = vector.x; y = vector.y; z = vector.z;
	return *this;
}


const Vector3d& Vector3d::operator+=(const Vector3d& vector)
{
	x += vector.x; y += vector.y; z += vector.z;
	return *this;
}

const Vector3d& Vector3d::operator-=(const Vector3d& vector)
{
	x -= vector.x; y -= vector.y; z -= vector.z;
	return *this;
}

const Vector3d& Vector3d::operator*=(const double arg)
{
	x *= arg; y *= arg; z *= arg;
	return *this;
}

const Vector3d& Vector3d::operator/=(const double arg)
{
	x /= arg; y /= arg; z /= arg;
	return *this;
}

Vector3d Vector3d::operator-() const
{
	return Vector3d(-x,-y,-z);
}

Vector3d Vector3d::operator+(const Vector3d& vector) const
{
	return Vector3d(x + vector.x, y + vector.y, z + vector.z);
}

Vector3d Vector3d::operator-(const Vector3d& vector) const
{
	return Vector3d(x - vector.x, y - vector.y, z - vector.z);
}

Vector3d Vector3d::operator*(const double arg) const
{
	return Vector3d(x * arg, y * arg, z * arg);
}

double Vector3d::scalarMult(const Vector3d& vector) const
{
	return x*vector.x + y*vector.y + z*vector.z;
}

double Vector3d::length() const
{
	return sqrt(x*x + y*y + z*z);
}

double Vector3d::length2() const
{
	return x*x + y*y + z*z;
}
