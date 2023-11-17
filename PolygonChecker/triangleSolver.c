#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = NOT_TRIANGLE;
	}
	else if (side1 + side2 < side3 ||
		side1 + side3 < side2 ||
		side2 + side3 < side1) {
		result = NOT_TRIANGLE;
	}
	else if (side1 == side2 && side1 == side3) {
		result = EQUILATERAL_TRIANGLE;
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2) ||
		(side2 == side3 && side1 != side2))
	{
		result = ISOSCELES_TRIANGLE;
	}
	else {
		result = SCALENE_TRIANGLE;
	}
	return result;
}