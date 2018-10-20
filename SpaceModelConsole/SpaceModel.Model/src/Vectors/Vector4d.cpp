#include "Core.h"
#include "Vector4d.h"
#include <math.h>

const Vector4d Vector4d::Zero(0, 0, 0, 0);
const Vector4d Vector4d::OrtX(1, 0, 0, 0);
const Vector4d Vector4d::OrtY(0, 1, 0, 0);
const Vector4d Vector4d::OrtZ(0, 0, 1, 0);
const Vector4d Vector4d::OrtW(0, 0, 0, 1);

Vector4d::Vector4d() :x(0.0), y(0.0), z(0.0), w(0.0)
{
}

Vector4d::Vector4d(double x, double y, double z, double w) :x(x), y(y), z(z), w(w)
{
}

bool Vector4d::operator==(const Vector4d& vector) const
{
	return
		CompareWithPercision(x, vector.x) &&
		CompareWithPercision(y, vector.y) &&
		CompareWithPercision(z, vector.z) &&
		CompareWithPercision(w, vector.w);
}

bool Vector4d::operator!=(const Vector4d& vector) const
{
	return
		!CompareWithPercision(x, vector.x) ||
		!CompareWithPercision(y, vector.y) ||
		!CompareWithPercision(z, vector.z) ||
		!CompareWithPercision(w, vector.w);
}

const Vector4d& Vector4d::operator=(const Vector4d& vector)
{
	x = vector.x; y = vector.y; z = vector.z; w = vector.w;
	return *this;
}


const Vector4d& Vector4d::operator+=(const Vector4d& vector)
{
	x += vector.x; y += vector.y; z += vector.z; w += vector.w;
	return *this;
}

const Vector4d& Vector4d::operator-=(const Vector4d& vector)
{
	x -= vector.x; y -= vector.y; z -= vector.z; w -= vector.w;
	return *this;
}

const Vector4d& Vector4d::operator*=(const double arg)
{
	x *= arg; y *= arg; z *= arg; w *= arg;
	return *this;
}

const Vector4d& Vector4d::operator/=(const double arg)
{
	x /= arg; y /= arg; z /= arg; w/=arg;
	return *this;
}

Vector4d Vector4d::operator-() const
{
	return Vector4d(-x,-y,-z,-w);
}

Vector4d Vector4d::operator+(const Vector4d& vector) const
{
	return Vector4d(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
}

Vector4d Vector4d::operator-(const Vector4d& vector) const
{
	return Vector4d(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
}

Vector4d Vector4d::operator*(const double arg) const
{
	return Vector4d(x * arg, y * arg, z * arg, w * arg);
}

double Vector4d::scalarMult(const Vector4d& vector) const
{
	return x*vector.x + y*vector.y + z*vector.z + w*vector.w;
}

double Vector4d::length() const
{
	return sqrt(x*x + y*y + z*z + w*w);
}

double Vector4d::length2() const
{
	return x*x + y*y + z*z + w*w;
}
