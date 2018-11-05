#include "JsonLoader.h"

ComplexObject* JsonLoader::Load(const char *filename)
{
	Document document;
	ifstream input(filename, std::ios::ate | std::ios::binary);

	// Get file length:
	int fileLength = 0;
	input.seekg(0, std::ios::end);
	fileLength = input.tellg();

	// Load file into buffer:
	char * buffer = new char[fileLength + 1];
	buffer[fileLength] = 0;
	input.seekg(0, std::ios::beg);
	input.read(buffer, fileLength);
	input.close();

	// Parse file:
	auto parseDocumentResult = document.Parse(buffer).HasParseError();
	assert(parseDocumentResult == false);

	auto complexObject = JsonLoader::LoadObject(document);
	delete[] buffer;
	return complexObject;
}

ComplexObject* JsonLoader::LoadObject(Document &document)
{
	assert(document.IsObject());
	return JsonLoader::LoadComplexObject(document.GetObject());
}

#pragma region Complex object reader

ComplexObject* JsonLoader::LoadComplexObject(RapidJsonObject &object)
{
	assert(object.HasMember("childObjects"));
	assert(object.HasMember("primitives"));
	assert(object.HasMember("transformMatrix"));


	assert(object["childObjects"].IsArray());
	assert(object["primitives"].IsArray());
	assert(object["transformMatrix"].IsArray());

	ComplexObject *pComplexObject = new ComplexObject();
	RapidJsonArray childs = object["childObjects"].GetArray();
	for (SizeType i = 0; i < childs.Size(); ++i) {
		pComplexObject->AddChild(JsonLoader::LoadComplexObject(childs[i].GetObject()));
	}

	RapidJsonArray primitives = object["primitives"].GetArray();
	for (SizeType i = 0; i < primitives.Size(); ++i) {
		pComplexObject->AddPrimitive(JsonLoader::LoadPrimitive(primitives[i].GetObject()));
	}

	pComplexObject->transformMatrix = JsonLoader::LoadMatrix4d(object["transformMatrix"].GetArray());
	return pComplexObject;
}

#pragma endregion


#pragma region Primitives readers

Primitive* JsonLoader::LoadPrimitive(RapidJsonObject &object)
{
	assert(object.HasMember("name"));
	auto name = object["name"].GetString();
	if (std::strcmp(name, "ColorPoint") == 0) {
		return JsonLoader::LoadColorPoint(object);
	}
	if (std::strcmp(name, "SpacePoint") == 0) {
		return JsonLoader::LoadSpacePoint(object);
	}
	if (std::strcmp(name, "TemperaturePoint") == 0) {
		return JsonLoader::LoadTemperaturePoint(object);
	}
}

ColorPoint* JsonLoader::LoadColorPoint(RapidJsonObject &object)
{
	assert(object.HasMember("position"));
	assert(object.HasMember("velocity"));
	assert(object.HasMember("radius"));
	assert(object.HasMember("mass"));
	assert(object.HasMember("color"));

	assert(object["position"].IsArray());
	assert(object["velocity"].IsArray());
	assert(object["radius"].IsDouble());
	assert(object["mass"].IsDouble());
	assert(object["color"].IsArray());

	return new ColorPoint(
		JsonLoader::LoadVector3d(object["position"].GetArray()),
		JsonLoader::LoadVector3d(object["velocity"].GetArray()),
		object["radius"].GetDouble(),
		object["mass"].GetDouble(),
		JsonLoader::LoadColor(object["color"].GetArray()));
}

SpacePoint* JsonLoader::LoadSpacePoint(RapidJsonObject &object)
{
	assert(object.HasMember("position"));
	assert(object.HasMember("velocity"));
	assert(object.HasMember("radius"));
	assert(object.HasMember("mass"));

	assert(object["position"].IsArray());
	assert(object["velocity"].IsArray());
	assert(object["radius"].IsDouble());
	assert(object["mass"].IsDouble());

	return new SpacePoint(
		JsonLoader::LoadVector3d(object["position"].GetArray()),
		JsonLoader::LoadVector3d(object["velocity"].GetArray()),
		object["radius"].GetDouble(),
		object["mass"].GetDouble());
}

TemperaturePoint* JsonLoader::LoadTemperaturePoint(RapidJsonObject &object)
{
	assert(object.HasMember("position"));
	assert(object.HasMember("velocity"));
	assert(object.HasMember("radius"));
	assert(object.HasMember("mass"));
	assert(object.HasMember("temperature"));

	assert(object["position"].IsArray());
	assert(object["velocity"].IsArray());
	assert(object["radius"].IsDouble());
	assert(object["mass"].IsDouble());
	assert(object["temperature"].IsDouble());

	return new TemperaturePoint(
		JsonLoader::LoadVector3d(object["position"].GetArray()),
		JsonLoader::LoadVector3d(object["velocity"].GetArray()),
		object["radius"].GetDouble(),
		object["mass"].GetDouble(),
		object["temperature"].GetDouble());
}

#pragma endregion

#pragma region Matrix 4d reader

Matrix4d JsonLoader::LoadMatrix4d(RapidJsonArray &array)
{
	assert(array.Size() >= 16);
	return Matrix4d(
		array[0].GetDouble(), array[1].GetDouble(), array[2].GetDouble(), array[3].GetDouble(),
		array[4].GetDouble(), array[5].GetDouble(), array[6].GetDouble(), array[7].GetDouble(),
		array[8].GetDouble(), array[9].GetDouble(), array[10].GetDouble(), array[11].GetDouble(),
		array[12].GetDouble(), array[13].GetDouble(), array[14].GetDouble(), array[15].GetDouble());
}

#pragma endregion

#pragma region Vector 3d reader

Vector3d JsonLoader::LoadVector3d(RapidJsonArray &array)
{
	assert(array.Size() >= 3);
	return Vector3d(array[0].GetDouble(), array[1].GetDouble(), array[2].GetDouble());
}

#pragma endregion

#pragma region Color reader

Color JsonLoader::LoadColor(RapidJsonArray &array)
{
	assert(array.Size() >= 3);
	return Color(array[0].GetInt(), array[1].GetInt(), array[2].GetInt());
}

#pragma endregion