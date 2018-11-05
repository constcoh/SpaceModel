#include "Matrix4d.h"
#include "Core\Condition.h"

#define det33(a11,a12,a13,a21,a22,a23,a31,a32,a33)  ((a11)*(a22)*(a33) + (a12)*(a23)*(a31) + (a13)*(a21)*(a32) - (a13)*(a22)*(a31) - (a11)*(a23)*(a32) - (a12)*(a21)*(a33))

Matrix4d::Matrix4d() :
	a11(0.0), a12(0.0), a13(0.0), a14(0.0),
	a21(0.0), a22(0.0), a23(0.0), a24(0.0),
	a31(0.0), a32(0.0), a33(0.0), a34(0.0),
	a41(0.0), a42(0.0), a43(0.0), a44(0.0)
{
}

Matrix4d::Matrix4d(
	const double a11, const double a12, const double a13, const double a14,
	const double a21, const double a22, const double a23, const double a24,
	const double a31, const double a32, const double a33, const double a34,
	const double a41, const double a42, const double a43, const double a44) :
	a11(a11), a12(a12), a13(a13), a14(a14),
	a21(a21), a22(a22), a23(a23), a24(a24),
	a31(a31), a32(a32), a33(a33), a34(a34),
	a41(a41), a42(a42), a43(a43), a44(a44)	
{
}

const Matrix4d& Matrix4d::operator=(const Matrix4d &matrix)
{
	a11 = matrix.a11; a12 = matrix.a12; a13 = matrix.a13; a14 = matrix.a14;
	a21 = matrix.a21; a22 = matrix.a22; a23 = matrix.a23; a24 = matrix.a24;
	a31 = matrix.a31; a32 = matrix.a32; a33 = matrix.a33; a34 = matrix.a34;
	a41 = matrix.a41; a42 = matrix.a42; a43 = matrix.a43; a44 = matrix.a44;
	return *this;
}

const Matrix4d& Matrix4d::operator*=(const Matrix4d &m)
{
	double new11 = a11*m.a11 + a12*m.a21 + a13*m.a31 + a14*m.a41, new12 = a11*m.a12 + a12*m.a22 + a13*m.a32 + a14*m.a42, new13 = a11*m.a13 + a12*m.a23 + a13*m.a33 + a14*m.a43, new14 = a11*m.a14 + a12*m.a24 + a13*m.a34 + a14*m.a44;

	double new21 = a21*m.a11 + a22*m.a21 + a23*m.a31 + a24*m.a41, new22 = a21*m.a12 + a22*m.a22 + a23*m.a32 + a24*m.a42, new23 = a21*m.a13 + a22*m.a23 + a23*m.a33 + a24*m.a43, new24 = a21*m.a14 + a22*m.a24 + a23*m.a34 + a24*m.a44;

	double new31 = a31*m.a11 + a32*m.a21 + a33*m.a31 + a34*m.a41, new32 = a31*m.a12 + a32*m.a22 + a33*m.a32 + a34*m.a42, new33 = a31*m.a13 + a32*m.a23 + a33*m.a33 + a34*m.a43, new34 = a31*m.a14 + a32*m.a24 + a33*m.a34 + a34*m.a44;

	double new41 = a41*m.a11 + a42*m.a21 + a43*m.a31 + a44*m.a41, new42 = a41*m.a12 + a42*m.a22 + a43*m.a32 + a44*m.a42, new43 = a41*m.a13 + a42*m.a23 + a43*m.a33 + a44*m.a43, new44 = a41*m.a14 + a42*m.a24 + a43*m.a34 + a44*m.a44;

	a11 = new11; a12 = new12; a13 = new13; a14 = new14;
	a21 = new21; a22 = new22; a23 = new23; a24 = new24;
	a31 = new31; a32 = new32; a33 = new33; a34 = new34;
	a41 = new41; a42 = new42; a43 = new43; a44 = new44;

	return *this;
}

Matrix4d Matrix4d::operator*(const Matrix4d &m) const
{
	return Matrix4d(
		a11*m.a11 + a12*m.a21 + a13*m.a31 + a14*m.a41, a11*m.a12 + a12*m.a22 + a13*m.a32 + a14*m.a42, a11*m.a13 + a12*m.a23 + a13*m.a33 + a14*m.a43, a11*m.a14 + a12*m.a24 + a13*m.a34 + a14*m.a44,

		a21*m.a11 + a22*m.a21 + a23*m.a31 + a24*m.a41, a21*m.a12 + a22*m.a22 + a23*m.a32 + a24*m.a42, a21*m.a13 + a22*m.a23 + a23*m.a33 + a24*m.a43, a21*m.a14 + a22*m.a24 + a23*m.a34 + a24*m.a44,

		a31*m.a11 + a32*m.a21 + a33*m.a31 + a34*m.a41, a31*m.a12 + a32*m.a22 + a33*m.a32 + a34*m.a42, a31*m.a13 + a32*m.a23 + a33*m.a33 + a34*m.a43, a31*m.a14 + a32*m.a24 + a33*m.a34 + a34*m.a44,

		a41*m.a11 + a42*m.a21 + a43*m.a31 + a44*m.a41, a41*m.a12 + a42*m.a22 + a43*m.a32 + a44*m.a42, a41*m.a13 + a42*m.a23 + a43*m.a33 + a44*m.a43, a41*m.a14 + a42*m.a24 + a43*m.a34 + a44*m.a44);
}

Vector4d Matrix4d::operator*(const Vector4d &vector) const
{
	return Vector4d(
		a11*vector.x + a12*vector.y + a13*vector.z + a14*vector.w,
		a21*vector.x + a22*vector.y + a23*vector.z + a24*vector.w,
		a31*vector.x + a32*vector.y + a33*vector.z + a34*vector.w,
		a41*vector.x + a42*vector.y + a43*vector.z + a44*vector.w);
}

ExtendedVector3d Matrix4d::operator*(const ExtendedVector3d &vector) const
{
	return ExtendedVector3d(
		a11*vector.x + a12*vector.y + a13*vector.z + a14*vector.w,
		a21*vector.x + a22*vector.y + a23*vector.z + a24*vector.w,
		a31*vector.x + a32*vector.y + a33*vector.z + a34*vector.w,
		a41*vector.x + a42*vector.y + a43*vector.z + a44*vector.w);
}

// vector = M * vector
void Matrix4d::ApplyMultToVector(Vector4d &vector) const
{
	double newX = a11*vector.x + a12*vector.y + a13*vector.z + a14*vector.w;
	double newY = a21*vector.x + a22*vector.y + a23*vector.z + a24*vector.w;
	double newZ = a31*vector.x + a32*vector.y + a33*vector.z + a34*vector.w;
	double newW = a41*vector.x + a42*vector.y + a43*vector.z + a44*vector.w;
	vector.x = newX;
	vector.y = newY;
	vector.z = newZ;
	vector.w = newW;
}

// vector = M * vector
void Matrix4d::ApplyMultToVector(ExtendedVector3d &vector) const
{
	double newX = a11*vector.x + a12*vector.y + a13*vector.z + a14*vector.w;
	double newY = a21*vector.x + a22*vector.y + a23*vector.z + a24*vector.w;
	double newZ = a31*vector.x + a32*vector.y + a33*vector.z + a34*vector.w;
	double newW = a41*vector.x + a42*vector.y + a43*vector.z + a44*vector.w;
	vector.x = newX;
	vector.y = newY;
	vector.z = newZ;
	vector.w = newW;
}


double Matrix4d::Det() const
{
	double A11 = det33(
		a22, a23, a24,
		a32, a33, a34,
		a42, a43, a44);

	double A12 = -det33(
		a21, a23, a24,
		a31, a33, a34,
		a41, a43, a44);

	double A13 = det33(
		a21, a22, a24,
		a31, a32, a34,
		a41, a42, a44);

	double A14 = - det33(
		a21, a22, a23,
		a31, a32, a33,
		a41, a42, a43);

	return a11*A11 + a12*A12 + a13*A13 + a14*A14;
}

Matrix4d Matrix4d::Inverse() const
{
	double det = this->Det();
	Condition::IsTrue(det != 0, "det is not equals to 0.");

	// Line 1:
	double A11 = det33(
		a22, a23, a24,
		a32, a33, a34,
		a42, a43, a44);

	double A12 = -det33(
		a21, a23, a24,
		a31, a33, a34,
		a41, a43, a44);

	double A13 = det33(
		a21, a22, a24,
		a31, a32, a34,
		a41, a42, a44);

	double A14 = -det33(
		a21, a22, a23,
		a31, a32, a33,
		a41, a42, a43);

	// Line 2:
	double A21 = -det33(
		a12, a13, a14,
		a32, a33, a34,
		a42, a43, a44);

	double A22 = det33(
		a11, a13, a14,
		a31, a33, a34,
		a41, a43, a44);

	double A23 = -det33(
		a11, a12, a14,
		a31, a32, a34,
		a41, a42, a44);

	double A24 = det33(
		a11, a12, a13,
		a31, a32, a33,
		a41, a42, a43);

	// Line 3:
	double A31 = det33(
		a12, a13, a14,
		a22, a23, a24,
		a42, a43, a44);

	double A32 = -det33(
		a11, a13, a14,
		a21, a23, a24,
		a41, a43, a44);

	double A33 = det33(
		a11, a12, a14,
		a21, a22, a24,
		a41, a42, a44);

	double A34 = -det33(
		a11, a12, a13,
		a21, a22, a23,
		a41, a42, a43);

	// Line 4:
	double A41 = -det33(
		a12, a13, a14,
		a22, a23, a24,
		a32, a33, a34);

	double A42 = det33(
		a11, a13, a14,
		a21, a23, a24,
		a31, a33, a34);

	double A43 = -det33(
		a11, a12, a14,
		a21, a22, a24,
		a31, a32, a34);

	double A44 = det33(
		a11, a12, a13,
		a21, a22, a23,
		a31, a32, a33);

	return Matrix4d(
		A11 / det, A21 / det, A31 / det, A41 / det,
		A12 / det, A22 / det, A32 / det, A42 / det,
		A13 / det, A23 / det, A33 / det, A43 / det,
		A14 / det, A24 / det, A34 / det, A44 / det);
}

void Matrix4d::SelfInverse()
{
	*this = this->Inverse();
}

Matrix4d Matrix4d::Transpose() const
{
	return Matrix4d(
		a11, a21, a31, a41,
		a12, a22, a32, a42,
		a13, a23, a33, a43,
		a14, a24, a34, a44);
}

void Matrix4d::SelfTranspose()
{
	double tmp1 = a12; a12 = a21; a21 = tmp1;

	double tmp2 = a13; a13 = a31; a31 = tmp2;
	double tmp3 = a23; a23 = a32; a32 = tmp3;

	double tmp4 = a14; a14 = a41; a41 = tmp4;
	double tmp5 = a24; a24 = a42; a42 = tmp5;
	double tmp6 = a34; a34 = a43; a43 = tmp6;
}

const Matrix4d Matrix4d::Zero = Matrix4d(
	0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0);

const Matrix4d Matrix4d::Identity = Matrix4d(
	1.0, 0.0, 0.0, 0.0,
	0.0, 1.0, 0.0, 0.0,
	0.0, 0.0, 1.0, 0.0,
	0.0, 0.0, 0.0, 1.0);
