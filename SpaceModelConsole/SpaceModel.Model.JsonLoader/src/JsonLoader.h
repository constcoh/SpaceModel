#pragma once

#include <fstream>
#include <iostream>
#include "rapidjson\reader.h"
#include "rapidjson\document.h"

#include "Objects\All.h"
#include "Objects\ColorPoint.h"
#include "Objects\TemperaturePoint.h"
#include "Objects\SpacePoint.h"
#include "Core\Color.h"

using namespace rapidjson;
using namespace std;

typedef GenericObject<false, GenericValue<UTF8<>>> RapidJsonObject;
typedef GenericArray<false, GenericValue<UTF8<>>> RapidJsonArray;

class JsonLoader {
public :
	static ComplexObject* Load(const char *filename);
private:
	static ComplexObject* LoadObject(Document &document);

	// Complex object reader:
	static ComplexObject* LoadComplexObject(RapidJsonObject &object);

	// Primitives readers:
	static Primitive* LoadPrimitive(RapidJsonObject &object);
	static ColorPoint* LoadColorPoint(RapidJsonObject &object);
	static SpacePoint* LoadSpacePoint(RapidJsonObject &object);
	static TemperaturePoint* LoadTemperaturePoint(RapidJsonObject &object);

	// Matrix 4d reader:
	static Matrix4d LoadMatrix4d(RapidJsonArray &array);

	// Vector 3d reader:
	static Vector3d LoadVector3d(RapidJsonArray &array);

	// Color reader:
	static Color LoadColor(RapidJsonArray &array);
};