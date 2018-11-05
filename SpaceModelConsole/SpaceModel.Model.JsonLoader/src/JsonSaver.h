#pragma once

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "Objects\ColorPoint.h"
#include "Objects\TemperaturePoint.h"
#include "Objects\SpacePoint.h"
#include "Core\Color.h"

#include "Objects\All.h"

using namespace rapidjson;
using namespace std;

class JsonSaver {
public:
	static bool Save(
		const char *filename,
		const ComplexObject &rootObject);
private:
	// Complex object writer:
	static void Save(
		Writer<StringBuffer> &writer,
		const ComplexObject &rootObject);

	// Primitives resolver:
	static void Save(
		Writer<StringBuffer> &writer,
		const Primitive *primitive);

	// Primitives writers:
	static void Save(
		Writer<StringBuffer> &writer,
		const ColorPoint *primitive);
	static void Save(
		Writer<StringBuffer> &writer,
		const TemperaturePoint *primitive);
	static void Save(
		Writer<StringBuffer> &writer,
		const SpacePoint *primitive);

	// Matrix writer:
	static void Save(
		Writer<StringBuffer> &writer,
		const char *matrixName,
		const Matrix4d &matrix);

	// Vector3d writer:
	static void Save(
		Writer<StringBuffer> &writer,
		const char *vectorName,
		const Vector3d &vector3d);

	// Color writer:
	static void Save(
		Writer<StringBuffer> &writer,
		const char *colorName,
		const Color &color);
};