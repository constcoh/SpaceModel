#pragma once

#include "Vectors\Vector2d.h"

class Matrix2d {
public:
	double a11, a12;
	double a21, a22;

	const static Matrix2d Zero;
	const static Matrix2d Identity;

	Matrix2d();
	Matrix2d(
		const double a11, const double a12,
		const double a21, const double a22);

	const Matrix2d& operator=(const Matrix2d &matrix);
	const Matrix2d& operator*=(const Matrix2d &matrix);
	Matrix2d operator*(const Matrix2d &matrix) const;
	Vector2d operator*(const Vector2d &vector) const;

	// vector = M * vector
	void ApplyMultToVector(Vector2d &vector) const;

	double Det() const;

	Matrix2d Inverse() const;
	void SelfInverse();

	Matrix2d Transpose() const;
	void SelfTranspose();
};
