#pragma once

#include "JsonLoader.h"
#include "JsonSaver.h"

#include "Objects\ColorPoint.h"
#include "Objects\TemperaturePoint.h"
#include "Objects\SpacePoint.h"

int mainSaverTest(){
	SpacePoint *spacePoint = new SpacePoint(Point(1, 2, 3), Point(4, 5, 6), 7, 8);
	TemperaturePoint *temperaturePoint = new TemperaturePoint(Point(1, 2, 3), Point(4, 5, 6), 7, 8, 9);
	ColorPoint *colorPoint = new ColorPoint(Point(1, 2, 3), Point(4, 5, 6), 7, 8, Color(9, 10, 11));
	ComplexObject *complexObject = new ComplexObject();
	complexObject->AddPrimitive(spacePoint);
	complexObject->AddPrimitive(temperaturePoint);
	for (int i = 0; i < 100000;++i) {
		complexObject->AddPrimitive(colorPoint);
	}

	JsonSaver::Save("test041118.json", *complexObject);
	return 0;
}

ComplexObject* mainLoaderTest()
{
	auto obj = JsonLoader::Load("test041118.json");
	return 0;
}