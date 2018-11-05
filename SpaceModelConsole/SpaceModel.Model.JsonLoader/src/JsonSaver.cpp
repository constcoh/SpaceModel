#pragma once

#include "JsonSaver.h"
#include "Core\Condition.h"
#include "Core\Cast.h"
#include <fstream>
#include <iostream>

bool JsonSaver::Save(
	const char *filename,
	const ComplexObject &rootObject)
{
	StringBuffer s(0,24*1048576); // 24Mb buffer
	Writer<StringBuffer> writer(s);
	JsonSaver::Save(writer, rootObject);

	std::ofstream output(filename, std::ofstream::out | std::ofstream::binary);
	output << s.GetString();
	output.close();
	return true;
}

#pragma region Complex object writer

void JsonSaver::Save(
	Writer<StringBuffer> &writer,
	const ComplexObject &rootObject)
{
	writer.StartObject();
	writer.Key("childObjects");
	writer.StartArray();
	for (auto i = rootObject.getChildConstIteratorBegin();
		i != rootObject.getChildConstIteratorEnd();
		++i)
	{
		JsonSaver::Save(writer, **i);
	}
	writer.EndArray();

	writer.Key("primitives");
	writer.StartArray();
	for (auto i = rootObject.getPrimitiveConstIteratorBegin();
		i != rootObject.getPrimitiveConstIteratorEnd();
		++i)
	{
		JsonSaver::Save(writer, (const Primitive*)*i);
	}
	writer.EndArray();
	JsonSaver::Save(writer, "transformMatrix", rootObject.transformMatrix);
	writer.EndObject();
}

#pragma endregion

#pragma region Primitives resolver

void JsonSaver::Save(
	Writer<StringBuffer> &writer,
	const Primitive *primitive)
{
	if (Cast::IsPointerOf<ColorPoint>(primitive))
	{
		JsonSaver::Save(writer, (ColorPoint*)primitive);
		return;
	}
	if (Cast::IsPointerOf<TemperaturePoint>(primitive))
	{
		JsonSaver::Save(writer, (TemperaturePoint*)primitive);
		return;
	}
	if (Cast::IsPointerOf<SpacePoint>(primitive))
	{
		JsonSaver::Save(writer, (SpacePoint*)primitive);
		return;
	}
}

#pragma endregion 

#pragma region Primitives writers

// Color point writer:
void JsonSaver::Save(
	Writer<StringBuffer> &writer,
	const ColorPoint *primitive)
{
	writer.StartObject();
	writer.Key("name");
	writer.String("ColorPoint");
	JsonSaver::Save(writer, "position", (Vector3d)*primitive);
	JsonSaver::Save(writer, "velocity", (Vector3d)primitive->velocity);
	writer.Key("radius");
	writer.Double(primitive->radius);
	writer.Key("mass");
	writer.Double(primitive->mass);
	JsonSaver::Save(writer, "color", primitive->color);
	writer.EndObject();
}

// Temperature point writer:
void JsonSaver::Save(
	Writer<StringBuffer> &writer,
	const TemperaturePoint *primitive)
{
	writer.StartObject();
	writer.Key("name");
	writer.String("TemperaturePoint");
	JsonSaver::Save(writer, "position", (Vector3d)*primitive);
	JsonSaver::Save(writer, "velocity", primitive->velocity);
	writer.Key("radius");
	writer.Double(primitive->radius);
	writer.Key("mass");
	writer.Double(primitive->mass);
	writer.Key("temperature");
	writer.Double(primitive->temperature);
	writer.EndObject();
}

// Space point writer:
void JsonSaver::Save(
	Writer<StringBuffer> &writer,
	const SpacePoint *primitive)
{
	writer.StartObject();
	writer.Key("name");
	writer.String("SpacePoint");
	JsonSaver::Save(writer, "position", (Vector3d)*primitive);
	JsonSaver::Save(writer, "velocity", primitive->velocity);
	writer.Key("radius");
	writer.Double(primitive->radius);
	writer.Key("mass");
	writer.Double(primitive->mass);
	writer.EndObject();
}

#pragma endregion

#pragma region Matrix writer

void JsonSaver::Save(
	Writer<StringBuffer> &writer,
	const char *matrixName,
	const Matrix4d &matrix)
{
	writer.Key(matrixName);
	writer.StartArray();
	writer.Double(matrix.a11);	writer.Double(matrix.a12);	writer.Double(matrix.a13);	writer.Double(matrix.a14);
	writer.Double(matrix.a21);	writer.Double(matrix.a22);	writer.Double(matrix.a23);	writer.Double(matrix.a24);
	writer.Double(matrix.a31);	writer.Double(matrix.a32);	writer.Double(matrix.a33);	writer.Double(matrix.a34);
	writer.Double(matrix.a41);	writer.Double(matrix.a42);	writer.Double(matrix.a43);	writer.Double(matrix.a44);
	writer.EndArray();
}

#pragma endregion

#pragma region Vector3d writer

void JsonSaver::Save(
	Writer<StringBuffer> &writer,
	const char *vectorName,
	const Vector3d &vector3d)
{
	writer.Key(vectorName);
	writer.StartArray();
	writer.Double(vector3d.x);
	writer.Double(vector3d.y);
	writer.Double(vector3d.z);
	writer.EndArray();
}

#pragma endregion

#pragma region Color writer

void JsonSaver::Save(
	Writer<StringBuffer> &writer,
	const char *colorName,
	const Color &color)
{
	writer.Key(colorName);
	writer.StartArray();
	writer.Int((int)color.red);
	writer.Int((int)color.green);
	writer.Int((int)color.blue);
	writer.EndArray();
}

#pragma endregion

