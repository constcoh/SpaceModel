#include "Matrix3d.h"
#include "Core\Condition.h"

#define det22(a11,a12,a21,a22) ((a11)*(a22)-(a12)*(a21))

Matrix3d::Matrix3d() :
	a11(0.0), a12(0.0), a13(0.0),
	a21(0.0), a22(0.0), a23(0.0),
	a31(0.0), a32(0.0), a33(0.0)
{
}

Matrix3d::Matrix3d(
	const double a11, const double a12, const double a13,
	const double a21, const double a22, const double a23,
	const double a31, const double a32, const double a33):
	a11(a11), a12(a12), a13(a13),
	a21(a21), a22(a22), a23(a23),
	a31(a31), a32(a32), a33(a33)
{
}

const Matrix3d& Matrix3d::operator=(const Matrix3d &matrix)
{
	a11 = matrix.a11; a12 = matrix.a12; a13 = matrix.a13;
	a21 = matrix.a21; a22 = matrix.a22; a23 = matrix.a23;
	a31 = matrix.a31; a32 = matrix.a32; a33 = matrix.a33;
	return *this;
}

const Matrix3d& Matrix3d::operator*=(const Matrix3d &m)
{
	double new11 = a11*m.a11 + a12*m.a21 + a13*m.a31, new12 = a11*m.a12 + a12*m.a22 + a13*m.a32, new13 = a11*m.a13 + a12*m.a23 + a13*m.a33;

	double new21 = a21*m.a11 + a22*m.a21 + a23*m.a31, new22 = a21*m.a12 + a22*m.a22 + a23*m.a32, new23 = a21*m.a13 + a22*m.a23 + a23*m.a33;

	double new31 = a31*m.a11 + a32*m.a21 + a33*m.a31, new32 = a31*m.a12 + a32*m.a22 + a33*m.a32, new33 = a31*m.a13 + a32*m.a23 + a33*m.a33;

	a11 = new11; a12 = new12; a13 = new13;
	a21 = new21; a22 = new22; a23 = new23;
	a31 = new31; a32 = new32; a33 = new33;

	return *this;
}

Matrix3d Matrix3d::operator*(const Matrix3d &m) const
{
	return Matrix3d(
		a11*m.a11 + a12*m.a21 + a13*m.a31, a11*m.a12 + a12*m.a22 + a13*m.a32, a11*m.a13 + a12*m.a23 + a13*m.a33,

		a21*m.a11 + a22*m.a21 + a23*m.a31, a21*m.a12 + a22*m.a22 + a23*m.a32, a21*m.a13 + a22*m.a23 + a23*m.a33,
		
		a31*m.a11 + a32*m.a21 + a33*m.a31, a31*m.a12 + a32*m.a22 + a33*m.a32, a31*m.a13 + a32*m.a23 + a33*m.a33);
}

Vector3d Matrix3d::operator*(const Vector3d &vector) const
{
	return Vector3d(
		a11*vector.x + a12*vector.y + a13*vector.z,
		a21*vector.x + a22*vector.y + a23*vector.z,
		a31*vector.x + a32*vector.y + a33*vector.z);
}

ExtendedVector2d Matrix3d::operator*(const ExtendedVector2d &vector) const
{
	return ExtendedVector2d(
		a11*vector.x + a12*vector.y + a13*vector.z,
		a21*vector.x + a22*vector.y + a23*vector.z,
		a31*vector.x + a32*vector.y + a33*vector.z);
}

// vector = M * vector
void Matrix3d::ApplyMultToVector(Vector3d &vector) const
{
	double newX = a11*vector.x + a12*vector.y + a13*vector.z;
	double newY = a21*vector.x + a22*vector.y + a23*vector.z;
	double newZ = a31*vector.x + a32*vector.y + a33*vector.z;
	vector.x = newX;
	vector.y = newY;
	vector.z = newZ;
}

// vector = M * vector
void Matrix3d::ApplyMultToVector(ExtendedVector2d &vector) const
{
	double newX = a11*vector.x + a12*vector.y + a13*vector.z;
	double newY = a21*vector.x + a22*vector.y + a23*vector.z;
	double newZ = a31*vector.x + a32*vector.y + a33*vector.z;
	vector.x = newX;
	vector.y = newY;
	vector.z = newZ;
}

double Matrix3d::Det() const
{
	return a11*a22*a33 + a12*a23*a31 + a13*a21*a32
		- a13*a22*a31 - a11*a23*a32 - a12*a21*a33;
}

Matrix3d Matrix3d::Inverse() const
{
	double det = this->Det();
	Condition::IsTrue(det != 0, "det is not equals to 0.");

	double A11 = det22(a22, a23, a32, a33), A12 = -det22(a21, a23, a31, a33), A13 = det22(a21, a22, a31, a32);

	double A21 = -det22(a12, a13, a32, a33), A22 = det22(a11, a13, a31, a33), A23 = -det22(a11, a12, a31, a32);

	double A31 = det22(a12, a13, a22, a23), A32 = -det22(a11, a13, a21, a23), A33 = det22(a11, a12, a21, a22);

	return Matrix3d(
		A11 / det, A21 / det, A31 / det,
		A12 / det, A22 / det, A32 / det,
		A13 / det, A23 / det, A33 / det);
}

void Matrix3d::SelfInverse()
{
	*this = this->Inverse();
}


Matrix3d Matrix3d::Transpose() const
{
	return Matrix3d(
		a11, a21, a31,
		a12, a22, a32,
		a13, a23, a33);
}

void Matrix3d::SelfTranspose()
{
	double tmp1 = a12; a12 = a21; a21 = tmp1;

	double tmp2 = a13; a13 = a31; a31 = tmp2;
	double tmp3 = a23; a23 = a32; a32 = tmp3;
}

const Matrix3d Matrix3d::Zero = Matrix3d(
	0.0, 0.0, 0.0,
	0.0, 0.0, 0.0,
	0.0, 0.0, 0.0);

const Matrix3d Matrix3d::Identity = Matrix3d(
	1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0);
