
#pragma region Primitive objects access methods

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

#pragma endregion

