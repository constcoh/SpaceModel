#include "Exception.h"
#include "Extensions\StringExtensions.h"

Exception::Exception(const char* variable, const char* description)
{
	this->description = description;
	this->variable = variable;
}

std::string Exception::getMessage()
{
	std::string description = StringExtensions::safeGet(this->description);
	std::string variable = StringExtensions::safeGet(this->variable);

	return "Exception: " + variable + " : " + description;
}