#pragma once

class Color {
public:
	unsigned char green, blue, red;
	Color();
	Color(const int red, const int green, const int blue);
	Color(const unsigned char red, const unsigned char green, const unsigned char blue);
};