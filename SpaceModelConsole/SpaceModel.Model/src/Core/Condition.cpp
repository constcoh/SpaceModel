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