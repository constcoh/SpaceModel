#pragma once


#include "Vectors\Vector3d.h"
#include "Vectors\ExtendedVector2d.h"

class Matrix3d {
public:
	double a11, a12, a13;
	double a21, a22, a23;
	double a31, a32, a33;

	const static Matrix3d Zero;
	const static Matrix3d Identity;

	Matrix3d();
	Matrix3d(
		const double a11, const double a12, const double a13,
		const double a21, const double a22, const double a23,
		const double a31, const double a32, const double a33);

	const Matrix3d& operator=(const Matrix3d &matrix);
	const Matrix3d& operator*=(const Matrix3d &matrix);
	Matrix3d operator*(const Matrix3d &matrix) const;
	Vector3d operator*(const Vector3d &vector) const;
	ExtendedVector2d operator*(const ExtendedVector2d &vector) const;

	// vector = M * vector
	void ApplyMultToVector(Vector3d &vector) const;
	void ApplyMultToVector(ExtendedVector2d &vector) const;

	double Det() const;

	Matrix3d Inverse() const;
	void SelfInverse();

	Matrix3d Transpose() const;
	void SelfTranspose();
};
