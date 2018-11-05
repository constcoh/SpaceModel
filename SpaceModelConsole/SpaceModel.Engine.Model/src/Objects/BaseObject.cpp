#include "BaseObject.h"

int BaseObject::_createdObjectsCount = 0;

BaseObject::BaseObject()
{
	this->_id = _createdObjectsCount++;
}

int BaseObject::getId() const
{
	return this->_id;
}

int BaseObject::getCreatedObjectsCount()
{
	return _createdObjectsCount;
}