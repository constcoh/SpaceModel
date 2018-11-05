#pragma once

#define nameof(variable) (#variable)

class Condition {
public :
	static void IsNotNull(void * pObject);
	static void IsNotNull(void * pObject, const char * objectName);
	static void IsTrue(bool condition, const char *conditionDescription);
	static void IsFalse(bool condition, const char *conditionDescription);
};