#pragma once


#include "Vectors\Vector4d.h"
#include "Vectors\ExtendedVector3d.h"

class Matrix4d {
public:
	double a11, a12, a13, a14;
	double a21, a22, a23, a24;
	double a31, a32, a33, a34;
	double a41, a42, a43, a44;

	const static Matrix4d Zero;
	const static Matrix4d Identity;

	Matrix4d();
	Matrix4d(
		const double a11, const double a12, const double a13, const double a14,
		const double a21, const double a22, const double a23, const double a24,
		const double a31, const double a32, const double a33, const double a34,
		const double a41, const double a42, const double a43, const double a44);

	const Matrix4d& operator=(const Matrix4d &matrix);
	const Matrix4d& operator*=(const Matrix4d &matrix);
	Matrix4d operator*(const Matrix4d &matrix) const;
	Vector4d operator*(const Vector4d &vector) const;
	Vector3d operator*(const Vector3d &vector) const;
	ExtendedVector3d operator*(const ExtendedVector3d &vector) const;

	// vector = M * vector
	void ApplyMultToVector(Vector3d &vector) const;
	void ApplyMultToVector(Vector4d &vector) const;
	void ApplyMultToVector(ExtendedVector3d &vector) const;

	double Det() const;

	Matrix4d Inverse() const;
	void SelfInverse();

	Matrix4d Transpose() const;
	void SelfTranspose();
};
