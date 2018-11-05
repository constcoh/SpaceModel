#include "Color.h"

Color::Color()
	:red(0), green(0), blue(0)
{
}

Color::Color(const int red, const int green, const int blue)
	: red((unsigned char)red), green((unsigned char)green), blue((unsigned char)blue)
{
}

Color::Color(const unsigned char red, const unsigned char green, const unsigned char blue)
	: red(red), green(green), blue(blue)
{
}
