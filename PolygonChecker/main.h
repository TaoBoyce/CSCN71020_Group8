#pragma once
#include <stdbool.h>
#define RECT_COORD_WIDTH	2
#define RECT_COORD_COUNT	4
#define ARR_X				0
#define ARR_Y				1
#define BUFF_SIZE			256

void printWelcome();
int printShapeMenu();
int* getTriangleSides(int* triangleSides);

//tao - fall23

//gets four coordinates
bool getFourPoints(int rectanglePoints[RECT_COORD_WIDTH][RECT_COORD_COUNT]);

//parses an input, and turns it into an int, 0 is valid
bool ReadInt_ZeroValid(int* output);