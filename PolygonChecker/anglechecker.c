#include "anglechecker.h"
#include <stdio.h>

// Why is this neccesary??
#define _USE_MATH_DEFINES
#include <math.h>

const double Rad2Deg = 180 / M_PI;

bool GetTriAngles(int side1, int side2, int side3, double *out) {
	if (out == 0) {
		fprintf(stderr, "Invalid Pointer.");
		return false;
	}
	if (side1 < 0 && side2 < 0 && side3 < 0) {
		fprintf(stderr, "Invalid Side length.");
		return false;
	}

	double side1d = (double)side1;
	double side2d = (double)side2;
	double side3d = (double)side3;

	out[0] = Rad2Deg * acos(((side2d * side2d) + (side3d * side3d) - (side1d * side1d)) / (2 * side2d * side3d));
	out[1] = Rad2Deg * acos(((side1d * side1d) + (side3d * side3d) - (side2d * side2d)) / (2 * side2d * side3d));
	out[2] = Rad2Deg * acos(((side1d * side1d) + (side2d * side2d) - (side3d * side3d)) / (2 * side2d * side3d));

	return true;
}