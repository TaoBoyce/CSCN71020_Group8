#include "anglechecker.h"
#include <stdio.h>

// Why is this neccesary??
#define _USE_MATH_DEFINES
#include <math.h>

const double RAD2DEG = 180 / M_PI;

bool GetTriAngles(int side1, int side2, int side3, double *out) {
	if (out == 0) {
		fprintf(stderr, "Invalid Pointer.");
		return false;
	}
	if (side1 < 0 && side2 < 0 && side3 < 0) {
		fprintf(stderr, "Invalid Side length.");
		return false;
	}

	double side1d = (double) side1;
	double side2d = (double) side2;
	double side3d = (double) side3;

	double area = sqrt((side1d + side2d + side3d) * (-side1d + side2d + side3d) * (side1d - side2d + side3d) * (side1d + side2d - side3d)) / 4;

	out[0] = RAD2DEG * asin((2 * area) / (side1d * side2d));
	out[1] = RAD2DEG * asin((2 * area) / (side2d * side3d));
	out[2] = RAD2DEG * asin((2*area) / (side3d*side1d));

	if (out[0] != out[0]) {
		return false;
	}

	return true;
}

double angleFromThreePoints(COORDINATEPOINT point1, COORDINATEPOINT point2, COORDINATEPOINT point3) {
	
	//getting the angle of the vertex at point 1

	double side12 = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
	double side13 = sqrt(pow(point1.x - point3.x, 2) + pow(point1.y - point3.y, 2));
	double side23 = sqrt(pow(point2.x - point3.x, 2) + pow(point2.y - point3.y, 2));


	double angleRadians = acos((pow(side12, 2) + pow(side13, 2) - pow(side23, 2)) / (2 * side12 * side13));

	//converting radians to degrees
	
	double angleDegree = angleRadians * RAD2DEG;

	return angleDegree;
}