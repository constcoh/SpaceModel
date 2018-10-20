#pragma once

#include <vector>

#include "BaseObject.h"
#include "Primitive.h"

class ComplexObject :public BaseObject
{
private:
	std::vector<ComplexObject*> _childObjects;
	std::vector<Primitive*> _primitives;
public:
	//// Constructors:
	ComplexObject();
	ComplexObject(
		const std::vector<ComplexObject*> &childObjects,
		const std::vector<Primitive*> &primitives);
	ComplexObject(
		const std::vector<ComplexObject*> &childObjects);
	ComplexObject(
		const std::vector<Primitive*> &primitives);

	//// Destructor:
	~ComplexObject();

	//// Child objects access methods:
	void AddChild(ComplexObject *childObject);
	bool DeleteChild(ComplexObject *childObject);
	void DeleteChilds();
	bool RemoveChild(ComplexObject *childObject);
	void RemoveChilds();
	std::vector<ComplexObject*>::iterator getChildIteratorBegin();
	std::vector<ComplexObject*>::iterator getChildIteratorEnd();

	//// Primitives access methods:
	void AddPrimitive(Primitive *primitive);
	bool DeletePrimitive(Primitive *primitive);
	void DeletePrimitives();
	bool RemovePrimitive(Primitive *primitive);
	void RemovePrimitives();
	std::vector<Primitive*>::iterator getPrimitiveIteratorBegin();
	std::vector<Primitive*>::iterator getPrimitiveIteratorEnd();
};