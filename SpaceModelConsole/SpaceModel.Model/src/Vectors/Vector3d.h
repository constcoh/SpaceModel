#pragma once

class Vector3d
{
public:
	double x;
    double y;
	double z;
	static const Vector3d Zero;
	static const Vector3d OrtX;
	static const Vector3d OrtY;
	static const Vector3d OrtZ;
public:
	Vector3d();
	Vector3d(double x, double y, double z);
	bool operator==(const Vector3d& vector) const;
	bool operator!=(const Vector3d& vector) const;
	const Vector3d& operator=(const Vector3d& vector);
	const Vector3d& operator+=(const Vector3d& vector);
	const Vector3d& operator-=(const Vector3d& vector);
	const Vector3d& operator*=(const double arg);
	const Vector3d& operator/=(const double arg);
	Vector3d operator+(const Vector3d& vector) const;
	Vector3d operator-(const Vector3d& vector) const;
	Vector3d operator-() const;
	Vector3d operator*(const double arg) const;

	double scalarMult(const Vector3d& vector) const;
	double length() const;
	double length2() const;
};