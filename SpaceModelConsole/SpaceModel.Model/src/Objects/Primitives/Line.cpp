#include "Line.h"
#include "Point.h"

Line::Line() 
	: Primitive()
{
}

Line::Line(const Vector3d &v1, const Vector3d &v2) 
	: Primitive(), v1(v1), v2(v2)
{
}

double Line::getLength() {
	return (this->v1 - this->v2).length();
}