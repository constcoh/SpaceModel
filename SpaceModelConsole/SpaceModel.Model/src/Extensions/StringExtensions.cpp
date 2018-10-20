#include "StringExtensions.h"

std::string StringExtensions::safeGet(const char *arg)
{
	if (arg == NULL) {
		return std::string();
	}

	return std::string(arg);
}
