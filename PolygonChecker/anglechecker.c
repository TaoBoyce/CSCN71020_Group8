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

	return true;
}