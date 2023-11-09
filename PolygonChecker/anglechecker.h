#pragma once

#include <stdbool.h>

/* Out should be an array that is at least three doubles long
 * First element = opposite, Second element = adjacent, Third element = hypotenuse */
bool GetTriAngles(int side1, int side2, int side3, double *out);