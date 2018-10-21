#include "Matrix2d.h"
#include "Core\Condition.h"

Matrix2d::Matrix2d():
	a11(0.0), a12(0.0),
	a21(0.0), a22(0.0)
{
}

Matrix2d::Matrix2d(
	const double a11, const double a12,
	const double a21, const double a22) :
	a11(a11), a12(a12),
	a21(a21), a22(a22)
{
}

const Matrix2d& Matrix2d::operator=(const Matrix2d &matrix)
{
	this->a11 = matrix.a11;
	this->a12 = matrix.a12;
	this->a21 = matrix.a21;
	this->a22 = matrix.a22;
	return *this;
}

const Matrix2d& Matrix2d::operator*=(const Matrix2d &matrix)
{
	double new11 = a11*matrix.a11 + a12*matrix.a21, new12 = a11*matrix.a12 + a12*matrix.a22;
	double new21 = a21*matrix.a11 + a22*matrix.a21, new22 = a21*matrix.a12 + a22*matrix.a22;
	a11 = new11; a12 = new12;
	a21 = new21; a22 = new22;
	return *this;
}

Matrix2d Matrix2d::operator*(const Matrix2d &matrix) const
{
	return Matrix2d(
		a11*matrix.a11 + a12*matrix.a21, a11*matrix.a12 + a12*matrix.a22,
		a21*matrix.a11 + a22*matrix.a21, a21*matrix.a12 + a22*matrix.a22);
}

Vector2d Matrix2d::operator*(const Vector2d &vector) const
{
	return Vector2d(
		a11*vector.x + a12*vector.y,
		a21*vector.x + a22*vector.y);
}

// vector = M * vector
void Matrix2d::ApplyMultToVector(Vector2d &vector) const
{
	double newX = a11*vector.x + a12*vector.y;
	double newY = a21*vector.x + a22*vector.y;
	vector.x = newX;
	vector.y = newY;
}

double Matrix2d::Det() const
{
	return a11*a22 - a12*a21;
}

Matrix2d Matrix2d::Inverse() const
{
	double det = this->Det();
	Condition::IsTrue(det != 0, "det is not equals to 0.");
	return Matrix2d(
		a22 / det, -a12 / det,
		-a21 / det, a11 / det);
}

void Matrix2d::SelfInverse()
{
	*this = this->Inverse();
}

Matrix2d Matrix2d::Transpose() const
{
	return Matrix2d(
		a11, a21,
		a12, a22);
}

void Matrix2d::SelfTranspose()
{
	double tmp = a12; a12 = a21; a21 = tmp;
}

const Matrix2d Matrix2d::Zero = Matrix2d(
	0.0, 0.0, 
	0.0, 0.0);

const Matrix2d Matrix2d::Identity = Matrix2d(
	1.0, 0.0,
	0.0, 1.0);
