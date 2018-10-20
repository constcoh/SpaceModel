#include "Core.h"
#include "Vector2d.h"
#include <math.h>

const Vector2d Vector2d::Zero(0, 0);
const Vector2d Vector2d::OrtX(1, 0);
const Vector2d Vector2d::OrtY(0, 1);

Vector2d::Vector2d() :x(0.0), y(0.0)
{
}

Vector2d::Vector2d(double x, double y) :x(x), y(y)
{
}

bool Vector2d::operator==(const Vector2d& vector) const
{
	return CompareWithPercision(x, vector.x) && CompareWithPercision(y, vector.y);
}

bool Vector2d::operator!=(const Vector2d& vector) const
{
	return !CompareWithPercision(x, vector.x) || !CompareWithPercision(y, vector.y);
}

const Vector2d& Vector2d::operator=(const Vector2d& vector)
{
	x = vector.x; y = vector.y;
	return *this;
}


const Vector2d& Vector2d::operator+=(const Vector2d& vector)
{
	x += vector.x; y += vector.y;
	return *this;
}

const Vector2d& Vector2d::operator-=(const Vector2d& vector)
{
	x -= vector.x; y -= vector.y;
	return *this;
}

const Vector2d& Vector2d::operator*=(const double arg)
{
	x *= arg; y *= arg;
	return *this;
}

const Vector2d& Vector2d::operator/=(const double arg)
{
	x /= arg; y /= arg;
	return *this;
}

Vector2d Vector2d::operator-() const
{
	return Vector2d(-x,-y);
}

Vector2d Vector2d::operator+(const Vector2d& vector) const
{
	return Vector2d(x + vector.x, y + vector.y);
}

Vector2d Vector2d::operator-(const Vector2d& vector) const
{
	return Vector2d(x - vector.x, y - vector.y);
}

Vector2d Vector2d::operator*(const double arg) const
{
	return Vector2d(x * arg, y * arg);
}

double Vector2d::scalarMult(const Vector2d& vector) const
{
	return x*vector.x + y*vector.y;
}

double Vector2d::length() const
{
	return sqrt(x*x + y*y);
}

double Vector2d::length2() const
{
	return x*x + y*y;
}