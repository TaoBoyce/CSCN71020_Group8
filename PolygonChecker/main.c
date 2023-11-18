#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "anglechecker.h"
#include "rectangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			if (result != NOT_TRIANGLE) {
				//print angles
				double triangleangles[3];
				if (!GetTriAngles(triangleSides[0], triangleSides[1], triangleSides[2], triangleangles)) {
					fprintf_s(stderr, "Couldn't determine angles.\n");
				}
				else {
					printf_s("%lf degrees, %lf degrees, %lf degrees\n", triangleangles[0], triangleangles[1], triangleangles[2]);
				}
			}
			break;
		case 2:
			printf_s("Rectangle selected.\n");
			//[0][n] is X
			//[1][n] is Y
			int rectanglePoints[RECT_COORD_WIDTH][RECT_COORD_COUNT] = {0};
			bool gotPoints = getFourPoints(rectanglePoints);
			if (!gotPoints) {
				printf_s("Invalid value entered.\n");
				break;
			}
			COORDINATEPOINT coord1 = { 0 };
			coord1.x = rectanglePoints[ARR_X][0];
			coord1.y = rectanglePoints[ARR_Y][0];
			COORDINATEPOINT coord2 = { 0 };
			coord2.x = rectanglePoints[ARR_X][1];
			coord2.y = rectanglePoints[ARR_Y][1];
			COORDINATEPOINT coord3 = { 0 };
			coord3.x = rectanglePoints[ARR_X][2];
			coord3.y = rectanglePoints[ARR_Y][2];
			COORDINATEPOINT coord4 = { 0 };
			coord4.x = rectanglePoints[ARR_X][3];
			coord4.y = rectanglePoints[ARR_Y][3];
			RECTANGLECORNERS rectResult = rectangleMaker(coord1, coord2, coord3, coord4);
			if(rectangleChecker(rectResult)){
				float rectArea = rectangleArea(rectResult);
				printf_s("The area is %f\n", rectArea);
				float rectPerimeter = rectanglePerimeter(rectResult);
				printf_s("The perimeter is %f\n", rectPerimeter);
			}
			else {
				printf_s("Input is not a rectangle.\n");
			}
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	ReadInt_ZeroValid(&shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		while (!ReadInt_ZeroValid(&triangleSides[i])) {
			printf_s("Invalid input, try again.");
		}
	}
	return triangleSides;
}

bool getFourPoints(int rectanglePoints[RECT_COORD_WIDTH][RECT_COORD_COUNT]) {
	printf_s("Enter the four points of a rectangle: \n");
	//asks for each pair of coordinates
	for (int col = 0; col < RECT_COORD_COUNT; col++) {
		for (int row = 0; row < RECT_COORD_WIDTH; row++) {

			do {
				if (row % RECT_COORD_WIDTH == 0) {
					printf_s("Point %d:\nX: ", col + 1 - row / 2);
				}
				else {
					printf_s("Y: ");
				}
			} while (!ReadInt_ZeroValid(&rectanglePoints[row][col]));
			//testing
			//printf_s("Row: %d, Column: %d\n", row, col);
			//printf_s("Value: %d\n", rectanglePoints[row][col]);
		}
	}
	return true;
}

bool ReadInt_ZeroValid(int* output) {
	char buf[BUFF_SIZE];
	if (fgets(buf, BUFF_SIZE, stdin) == NULL) {
		return false;
	}
	char* endptr;
	errno = 0;
	long num = strtol(buf, &endptr, 10);
	if (buf == endptr || (*endptr != '\n' && *endptr != '\0')) {
		return false;  // failed conversion
	}
	if (errno || num < INT_MIN || num > INT_MAX) {
		return false;  // range error
	}
	if (output != NULL) {
		*output = (int)num;
	}
	return true;
}