#include "Core\Condition.h"
#include "Extensions\VectorExtensions.h"

#include "ComplexObject.h"

#pragma region Constructors

ComplexObject::ComplexObject() :BaseObject(), transformMatrix(Matrix4d::Identity)
{
}

ComplexObject::ComplexObject(
	const std::vector<ComplexObject*> &childObjects,
	const std::vector<Primitive*> &primitives)
	: BaseObject(), transformMatrix(Matrix4d::Identity)
{
	this->_childObjects = childObjects;
	this->_primitives = primitives;
}

ComplexObject::ComplexObject(
	const std::vector<ComplexObject*> &childObjects,
	const std::vector<Primitive*> &primitives,
	const Matrix4d &transformMatrix)
	: BaseObject()
{
	this->_childObjects = childObjects;
	this->_primitives = primitives;
	this->transformMatrix = Matrix4d::Identity;
}

ComplexObject::ComplexObject(
	const std::vector<ComplexObject*> &childObjects)
	: BaseObject(), transformMatrix(Matrix4d::Identity)
{
	this->_childObjects = childObjects;
}

ComplexObject::ComplexObject(
	const std::vector<Primitive*> &primitives)
	: BaseObject(), transformMatrix(Matrix4d::Identity)
{
	this->_primitives = primitives;
}

#pragma endregion Constructors

#pragma region Destructor

ComplexObject::~ComplexObject()
{
	this->DeleteChilds();
	this->DeletePrimitives();
}

#pragma endregion

#pragma region Child objects access methods

void ComplexObject::AddChild(ComplexObject *childObject)
{
	Condition::IsNotNull(childObject, nameof(childObject));
	this->_childObjects.push_back(childObject);
}

bool ComplexObject::DeleteChild(ComplexObject *childObject)
{
	Condition::IsNotNull(childObject, nameof(childObject));
	int index = VectorExtensions<ComplexObject*>::getIndex(this->_childObjects, childObject);
	if (index >= 0) {
		delete childObject;
		this->_childObjects.erase(this->_childObjects.begin() + index);
		return true;
	}

	return false;
}

void ComplexObject::DeleteChilds()
{
	for (std::vector<ComplexObject*>::iterator i = this->_childObjects.begin();
		i != this->_childObjects.end();
		i++)
	{
		delete *i;
	}

	this->_childObjects.clear();
}

bool ComplexObject::RemoveChild(ComplexObject *childObject)
{
	Condition::IsNotNull(childObject, nameof(childObject));
	return VectorExtensions<ComplexObject*>::Remove(this->_childObjects, childObject);
}

void ComplexObject::RemoveChilds()
{
	this->_childObjects.clear();
}

std::vector<ComplexObject*>::iterator ComplexObject::getChildIteratorBegin()
{
	return this->_childObjects.begin();
}

std::vector<ComplexObject*>::iterator ComplexObject::getChildIteratorEnd()
{
	return this->_childObjects.end();
}

std::vector<ComplexObject*>::const_iterator ComplexObject::getChildConstIteratorBegin() const
{
	return this->_childObjects.cbegin();
}

std::vector<ComplexObject*>::const_iterator ComplexObject::getChildConstIteratorEnd() const
{
	return this->_childObjects.cend();
}

#pragma endregion

#pragma region Primitives access methods

void ComplexObject::AddPrimitive(Primitive *primitive)
{
	Condition::IsNotNull(primitive, nameof(primitive));
	this->_primitives.push_back(primitive);
}

bool ComplexObject::DeletePrimitive(Primitive *primitive)
{
	Condition::IsNotNull(primitive, nameof(primitive));
	int index = VectorExtensions<Primitive*>::getIndex(this->_primitives, primitive);
	if (index >= 0) {
		delete primitive;
		this->_primitives.erase(this->_primitives.begin() + index);
		return true;
	}

	return false;
}

void ComplexObject::DeletePrimitives()
{
	for (std::vector<Primitive*>::iterator i = this->_primitives.begin();
		i != this->_primitives.end();
		i++)
	{
		delete *i;
	}

	this->_primitives.clear();
}

bool ComplexObject::RemovePrimitive(Primitive *primitive)
{
	Condition::IsNotNull(primitive, nameof(primitive));
	return VectorExtensions<Primitive*>::Remove(this->_primitives, primitive);
}

void ComplexObject::RemovePrimitives()
{
	this->_primitives.clear();
}

std::vector<Primitive*>::iterator ComplexObject::getPrimitiveIteratorBegin()
{
	return this->_primitives.begin();
}

std::vector<Primitive*>::iterator ComplexObject::getPrimitiveIteratorEnd()
{
	return this->_primitives.end();
}

std::vector<Primitive*>::const_iterator ComplexObject::getPrimitiveConstIteratorBegin() const
{
	return this->_primitives.cbegin();
}

std::vector<Primitive*>::const_iterator ComplexObject::getPrimitiveConstIteratorEnd() const
{
	return this->_primitives.cend();
}


#pragma endregion
