#include "Transform3dFactory.h"
#include <math.h>

Matrix4d Transform3dFactory::Shift(
	const double &dx,
	const double &dy,
	const double &dz)
{
	return Matrix4d(
		1.0, 0.0, 0.0, dx,
		0.0, 1.0, 0.0, dy,
		0.0, 0.0, 1.0, dz,
		0.0, 0.0, 0.0, 1.0);
}

Matrix4d Transform3dFactory::RotateX(const double &angle)
{
	double sinA = sin(angle), cosA = cos(angle);
	return Matrix4d(
		1.0, 0.0, 0.0, 0.0,
		0.0, cosA, -sinA, 0.0,
		0.0, sinA, cosA, 0.0,
		0.0, 0.0, 0.0, 1.0);
}


Matrix4d Transform3dFactory::RotateY(const double &angle)
{
	double sinA = sin(angle), cosA = cos(angle);
	return Matrix4d(
		cosA, 0.0, sinA, 0.0,
		0.0, 1.0, 0.0, 0.0,
		-sinA, 0.0, cosA, 0.0,
		0.0, 0.0, 0.0, 1.0);
}

Matrix4d Transform3dFactory::RotateZ(const double &angle)
{
	double sinA = sin(angle), cosA = cos(angle);
	return Matrix4d(
		cosA, -sinA, 0.0, 0.0,
		sinA, cosA, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0);
}

Matrix4d Transform3dFactory::Scale(
	const double &sx,
	const double &sy,
	const double &sz)
{
	return Matrix4d(
		sx, 0.0, 0.0, 0.0,
		0.0, sy, 0.0, 0.0,
		0.0, 0.0, sz, 0.0,
		0.0, 0.0, 0.0, 1.0);
}
