#pragma once

#include <stdbool.h>


typedef struct CoordinatePoint {
	float x;
	float y;
} COORDINATEPOINT;

typedef struct RectangleCorners {
	COORDINATEPOINT topLeft;
	COORDINATEPOINT topRight;
	COORDINATEPOINT bottomLeft;
	COORDINATEPOINT bottomRight;
} RECTANGLECORNERS;

RECTANGLECORNERS rectangleMaker(COORDINATEPOINT, COORDINATEPOINT, COORDINATEPOINT, COORDINATEPOINT);

float rectanglePerimeter(RECTANGLECORNERS);

float rectangleArea(RECTANGLECORNERS);

bool rectangleChecker(RECTANGLECORNERS);

COORDINATEPOINT coordinatePointMaker(float, float);