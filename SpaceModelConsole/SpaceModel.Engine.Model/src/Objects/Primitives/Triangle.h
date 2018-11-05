#pragma once

#include "..\Primitive.h"
#include "Vectors\Vector3d.h"

class Triangle : public Primitive {
public:
	Vector3d v1;
	Vector3d v2;
	Vector3d v3;
	Triangle();
	Triangle(const Vector3d &v1, const Vector3d &v2, const Vector3d &v3);
};