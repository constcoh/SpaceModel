#pragma once

#include <string>

class Exception {
private:
	std::string message;
public:
	Exception(const std::string &conditionDescription);
	Exception(const char* variable, const char* description = NULL);
	std::string getMessage();
};