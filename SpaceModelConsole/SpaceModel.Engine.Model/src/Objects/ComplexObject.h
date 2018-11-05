#pragma once

#include <vector>

#include "BaseObject.h"
#include "Primitive.h"
#include "Matrices\Matrix4d.h"

class ComplexObject :public BaseObject
{
private:
	std::vector<ComplexObject*> _childObjects;
	std::vector<Primitive*> _primitives;
public:
	Matrix4d transformMatrix;
	//// Constructors:
	ComplexObject();
	ComplexObject(
		const std::vector<ComplexObject*> &childObjects,
		const std::vector<Primitive*> &primitives);
	ComplexObject(
		const std::vector<ComplexObject*> &childObjects,
		const std::vector<Primitive*> &primitives,
		const Matrix4d &transformMatrix);
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
	std::vector<ComplexObject*>::const_iterator getChildConstIteratorBegin() const;
	std::vector<ComplexObject*>::const_iterator getChildConstIteratorEnd() const;

	//// Primitives access methods:
	void AddPrimitive(Primitive *primitive);
	bool DeletePrimitive(Primitive *primitive);
	void DeletePrimitives();
	bool RemovePrimitive(Primitive *primitive);
	void RemovePrimitives();
	std::vector<Primitive*>::iterator getPrimitiveIteratorBegin();
	std::vector<Primitive*>::iterator getPrimitiveIteratorEnd();
	std::vector<Primitive*>::const_iterator getPrimitiveConstIteratorBegin() const;
	std::vector<Primitive*>::const_iterator getPrimitiveConstIteratorEnd() const;
};