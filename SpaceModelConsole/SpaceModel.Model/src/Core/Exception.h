#pragma once

#include <string>

class Exception {
private:
	const char* description;
	const char* variable;
public:
	Exception(const char* variable, const char* description = NULL);
	std::string getMessage();
};