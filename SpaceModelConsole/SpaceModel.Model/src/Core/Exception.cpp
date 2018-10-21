#include "Exception.h"
#include "Extensions\StringExtensions.h"

Exception::Exception(const std::string &conditionDescription)
{
	this->message = "Exception, condition is incorrect: " + conditionDescription;
}

Exception::Exception(const char* variable, const char* description)
{
	std::string strDescription = StringExtensions::safeGet(description);
	std::string strVariable = StringExtensions::safeGet(variable);

	this->message = "Exception: " + strVariable + " : " + strDescription;
}

std::string Exception::getMessage()
{
	return message;
}