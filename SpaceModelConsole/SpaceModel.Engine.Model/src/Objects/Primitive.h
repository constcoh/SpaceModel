#pragma once
#include "BaseObject.h"

class Primitive : public BaseObject {
public:
	Primitive();
	virtual const char *GetPrimitiveName() const;
};