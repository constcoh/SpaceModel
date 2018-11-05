#include "Condition.h"
#include "Exception.h"

void Condition::IsNotNull(void *pObject)
{
	if (pObject == nullptr) {
		throw Exception(NULL,"Object pointer is NULL.");
	}
}

void Condition::IsNotNull(void *pObject, const char * objectName)
{
	if (pObject == nullptr) {
		throw Exception(objectName, "The pointer is NULL");
	}
}


void Condition::IsTrue(bool condition, const char *conditionDescription)
{
	if (condition == false) {
		throw Exception(conditionDescription);
	}
}

void Condition::IsFalse(bool condition, const char *conditionDescription)
{
	if (condition) {
		throw Exception(conditionDescription);
	}
}
