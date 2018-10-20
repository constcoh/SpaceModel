#pragma once

class Vector4d
{
public:
	double x;
    double y;
	double z;
	double w;
	static const Vector4d Zero;
	static const Vector4d OrtX;
	static const Vector4d OrtY;
	static const Vector4d OrtZ;
	static const Vector4d OrtW;
public:
	Vector4d();
	Vector4d(double x, double y, double z, double w);
	bool operator==(const Vector4d& vector) const;
	bool operator!=(const Vector4d& vector) const;
	const Vector4d& operator=(const Vector4d& vector);
	const Vector4d& operator+=(const Vector4d& vector);
	const Vector4d& operator-=(const Vector4d& vector);
	const Vector4d& operator*=(const double arg);
	const Vector4d& operator/=(const double arg);
	Vector4d operator+(const Vector4d& vector) const;
	Vector4d operator-(const Vector4d& vector) const;
	Vector4d operator-() const;
	Vector4d operator*(const double arg) const;

	double scalarMult(const Vector4d& vector) const;
	double length() const;
	double length2() const;
};