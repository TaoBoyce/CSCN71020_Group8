#pragma once
#include <stdbool.h>
#define RECT_COORD_WIDTH 2
#define RECT_COORD_COUNT 4

void printWelcome();
int printShapeMenu();
int* getTriangleSides(int* triangleSides);

//tao - fall23
bool getFourPoints(int rectanglePoints[RECT_COORD_WIDTH][RECT_COORD_COUNT]);