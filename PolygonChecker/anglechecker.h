#pragma once

#include <stdbool.h>
#include "rectangleSolver.h"

/* Out should be an array that is at least three doubles long */
bool GetTriAngles(int side1, int side2, int side3, double *out);

double angleFromThreePoints(COORDINATEPOINT, COORDINATEPOINT, COORDINATEPOINT);