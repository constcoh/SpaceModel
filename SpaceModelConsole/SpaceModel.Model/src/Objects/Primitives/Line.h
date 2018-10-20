#pragma once

#include "..\Primitive.h"
#include "Vectors\Vector3d.h"

class Line : public Primitive {
public:
	Line();
	Line(const Vector3d &v1, const Vector3d &v2);
	Vector3d v1;
	Vector3d v2;
	double getLength();
};