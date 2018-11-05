#pragma once

class Vector2d
{
public:
	double x;
    double y;
	static const Vector2d Zero;
	static const Vector2d OrtX;
	static const Vector2d OrtY;
public:
	Vector2d();
	Vector2d(double x, double y);
	bool operator==(const Vector2d& vector) const;
	bool operator!=(const Vector2d& vector) const;
	const Vector2d& operator=(const Vector2d& vector);
	const Vector2d& operator+=(const Vector2d& vector);
	const Vector2d& operator-=(const Vector2d& vector);
	const Vector2d& operator*=(const double arg);
	const Vector2d& operator/=(const double arg);
	Vector2d operator+(const Vector2d& vector) const;
	Vector2d operator-(const Vector2d& vector) const;
	Vector2d operator-() const;
	Vector2d operator*(const double arg) const;

	double scalarMult(const Vector2d& vector) const;
	double length() const;
	double length2() const;
};