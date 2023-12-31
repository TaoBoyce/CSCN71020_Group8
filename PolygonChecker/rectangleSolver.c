#include <stdio.h>
#include "rectangleSolver.h"
#include "anglechecker.h"

#define HALFPOINTS 2


RECTANGLECORNERS rectangleMaker(COORDINATEPOINT point1, COORDINATEPOINT point2, COORDINATEPOINT point3, COORDINATEPOINT point4) {
	//make a rectangle to output
	RECTANGLECORNERS outputRectangle;

	//sort the points into upper and lower point arrays, so we can sort it into left and right later

	COORDINATEPOINT topHalf[HALFPOINTS];
	COORDINATEPOINT bottomHalf[HALFPOINTS];

	if (point1.y > point2.y) {
		if (point3.y > point4.y) {
			if (point1.y > point3.y) {
				if (point2.y > point4.y) {
					if (point2.y > point3.y) {
						//1+2 top 3+4 bot
						topHalf[0] = point1;
						topHalf[1] = point2;
						bottomHalf[0] = point3;
						bottomHalf[1] = point4;
					}
					else {
						//1+3 top 2+4 bot
						topHalf[0] = point1;
						topHalf[1] = point3;
						bottomHalf[0] = point2;
						bottomHalf[1] = point4;
					}
				}
				else {
					//1+3 top 4+2 bot
					topHalf[0] = point1;
					topHalf[1] = point3;
					bottomHalf[0] = point4;
					bottomHalf[1] = point2;
				}
			}
			else {
				if (point2.y > point4.y) {
					//1+3 top 2+4 bot
					topHalf[0] = point1;
					topHalf[1] = point3;
					bottomHalf[0] = point2;
					bottomHalf[1] = point4;
				}
				else {
					if (point1.y > point4.y) {
						//3+1 top 2+4 bot
						topHalf[0] = point3;
						topHalf[1] = point1;
						bottomHalf[0] = point2;
						bottomHalf[1] = point4;
					}
					else {
						//3+4 top 1+2 bot
						topHalf[0] = point3;
						topHalf[1] = point4;
						bottomHalf[0] = point1;
						bottomHalf[1] = point2;
					}
				}
			}
		}
		else {
			if (point1.y > point4.y) {
				if (point2.y > point3.y) {
					if (point4.y > point2.y) {
						//1+4 top 2+3 bot
						topHalf[0] = point1;
						topHalf[1] = point4;
						bottomHalf[0] = point2;
						bottomHalf[1] = point3;
					}
					else {
						//1+2 top 4+3 bot
						topHalf[0] = point1;
						topHalf[1] = point2;
						bottomHalf[0] = point4;
						bottomHalf[1] = point3;
					}
				}
				else {
					//1+4 top 2+3 bot
					topHalf[0] = point1;
					topHalf[1] = point4;
					bottomHalf[0] = point2;
					bottomHalf[1] = point4;
				}
			}
			else {
				if (point2.y > point3.y) {
					//4+1 top 2+3 bot
					topHalf[0] = point4;
					topHalf[1] = point1;
					bottomHalf[0] = point2;
					bottomHalf[1] = point3;
				}
				else {
					if (point1.y > point3.y) {
						//4+1 top 3+2 bot
						topHalf[0] = point4;
						topHalf[1] = point1;
						bottomHalf[0] = point3;
						bottomHalf[1] = point2;
					}
					else {
						//4+3 top 1+2 bot
						topHalf[0] = point4;
						topHalf[1] = point3;
						bottomHalf[0] = point1;
						bottomHalf[1] = point2;
					}
				}
			}
		}
	}
	else {
		if (point3.y > point4.y) {
			if (point2.y > point3.y) {
				if (point1.y > point4.y) {
					if (point1.y > point3.y) {
						//2+1 top 3+4 bot
						topHalf[0] = point2;
						topHalf[1] = point1;
						bottomHalf[0] = point3;
						bottomHalf[1] = point4;
					}
					else {
						//2+3 top 1+4 bot
						topHalf[0] = point2;
						topHalf[1] = point3;
						bottomHalf[0] = point1;
						bottomHalf[1] = point4;
					}
				}
				else {
					//2+3 top 4+1 bot
					topHalf[0] = point2;
					topHalf[1] = point3;
					bottomHalf[0] = point4;
					bottomHalf[1] = point1;
				}
			}
			else {
				if (point1.y > point4.y) {
					//3+2 top 1+4 bot
					topHalf[0] = point3;
					topHalf[1] = point2;
					bottomHalf[0] = point1;
					bottomHalf[1] = point4;
				}
				else {
					if (point2.y > point4.y) {
						//3+2 top 4+1 bot
						topHalf[0] = point3;
						topHalf[1] = point2;
						bottomHalf[0] = point4;
						bottomHalf[1] = point1;
					}
					else {
						//3+4 top 2+1 bot
						topHalf[0] = point3;
						topHalf[1] = point4;
						bottomHalf[0] = point2;
						bottomHalf[1] = point1;
					}
				}
			}
		}
		else {
			if (point2.y > point4.y) {
				if (point1.y > point3.y) {
					if (point4.y > point1.y) {
						//2+4 top 1+3 bot
						topHalf[0] = point2;
						topHalf[1] = point4;
						bottomHalf[0] = point1;
						bottomHalf[1] = point3;
					}
					else {
						//2+1 top 4+3 bot
						topHalf[0] = point2;
						topHalf[1] = point1;
						bottomHalf[0] = point4;
						bottomHalf[1] = point3;
					}
				}
				else {
					//2+4 top 3+1 bot
					topHalf[0] = point2;
					topHalf[1] = point4;
					bottomHalf[0] = point3;
					bottomHalf[1] = point1;
				}
			}
			else {
				if (point1.y > point3.y) {
					//4+1 top 1+3 bot
					topHalf[0] = point4;
					topHalf[1] = point1;
					bottomHalf[0] = point1;
					bottomHalf[1] = point3;
				}
				else {
					if (point2.y > point3.y) {
						//4+2 top 3+1 bot
						topHalf[0] = point4;
						topHalf[1] = point2;
						bottomHalf[0] = point3;
						bottomHalf[1] = point1;
					}
					else {
						//4+3 top 2+1 bot
						topHalf[0] = point4;
						topHalf[1] = point3;
						bottomHalf[0] = point2;
						bottomHalf[1] = point1;
					}
				}
			}
		}
	}

	//divide the top and bottom between left and right
	if (topHalf[0].x > topHalf[1].x) {
		outputRectangle.topRight = topHalf[0];
		outputRectangle.topLeft = topHalf[1];
	}
	else if (topHalf[0].x < topHalf[1].x) {
		outputRectangle.topRight = topHalf[1];
		outputRectangle.topLeft = topHalf[0];
	}

	else {
		if (topHalf[0].y > topHalf[1].y) {
			if (bottomHalf[0].x > topHalf[0].x || bottomHalf[1].x > topHalf[0].x) {
				outputRectangle.topRight = topHalf[0];
				outputRectangle.topLeft = topHalf[1];
			}
			else if (bottomHalf[0].x <= topHalf[0].x || bottomHalf[1].x <= topHalf[0].x) {
				outputRectangle.topLeft = topHalf[0];
				outputRectangle.topRight = topHalf[1];
			}
		}
		else {
			if (bottomHalf[0].x > topHalf[1].x || bottomHalf[1].x > topHalf[1].x) {
				outputRectangle.topRight = topHalf[1];
				outputRectangle.topLeft = topHalf[0];
			}
			else if (bottomHalf[0].x <= topHalf[1].x || bottomHalf[1].x <= topHalf[1].x) {
				outputRectangle.topLeft = topHalf[1];
				outputRectangle.topRight = topHalf[0];
			}
		}
	}

	if (bottomHalf[0].x > bottomHalf[1].x) {
		outputRectangle.bottomRight = bottomHalf[0];
		outputRectangle.bottomLeft = bottomHalf[1];
	}
	else if (bottomHalf[0].x < bottomHalf[1].x) {
		outputRectangle.bottomRight = bottomHalf[1];
		outputRectangle.bottomLeft = bottomHalf[0];
	}

	else {
		if (bottomHalf[0].y < bottomHalf[1].y) {
			if (topHalf[0].x > bottomHalf[0].x || topHalf[1].x > bottomHalf[0].x) {
				outputRectangle.bottomRight = bottomHalf[0];
				outputRectangle.bottomLeft = bottomHalf[1];
			}
			else if (topHalf[0].x <= bottomHalf[0].x || topHalf[1].x <= bottomHalf[0].x) {
				outputRectangle.bottomLeft = bottomHalf[0];
				outputRectangle.bottomRight = bottomHalf[1];
			}
		}
		else {
			if (topHalf[0].x > bottomHalf[1].x || topHalf[1].x > bottomHalf[1].x) {
				outputRectangle.bottomRight = bottomHalf[1];
				outputRectangle.bottomLeft = bottomHalf[0];
			}
			else if (topHalf[0].x <= bottomHalf[1].x || topHalf[1].x <= bottomHalf[1].x) {
				outputRectangle.bottomLeft = bottomHalf[1];
				outputRectangle.bottomRight = bottomHalf[0];
			}
		}
	}
	return outputRectangle;
	
}


float rectanglePerimeter(RECTANGLECORNERS rectangle) {
	float leftSide = rectangle.topLeft.y - rectangle.bottomLeft.y;
	float topSide = rectangle.topRight.x - rectangle.topLeft.x;
	float rightSide = rectangle.topRight.y - rectangle.bottomRight.y;
	float bottomSide = rectangle.bottomRight.x - rectangle.bottomLeft.x;

	float perimeter = leftSide + topSide + rightSide + bottomSide;

	return perimeter;
}

float rectangleArea(RECTANGLECORNERS rectangle) {
	float height = rectangle.topLeft.y - rectangle.bottomLeft.y;
	float width = rectangle.topRight.x - rectangle.topLeft.x;

	float area = height * width;

	return area;
}

bool rectangleChecker(RECTANGLECORNERS rectangle) {

	//check all 4 angles to make sure they're square
	if (compareD(angleFromThreePoints(rectangle.topLeft, rectangle.topRight, rectangle.bottomLeft), 90.0) &&
		compareD(angleFromThreePoints(rectangle.topRight, rectangle.topLeft, rectangle.bottomRight), 90.0) &&
		compareD(angleFromThreePoints(rectangle.bottomRight, rectangle.topRight, rectangle.bottomLeft), 90.0) &&
		compareD(angleFromThreePoints(rectangle.bottomLeft, rectangle.bottomRight, rectangle.topLeft), 90.0)) {
		return true;
	}
	else {
		return false;
	}

}

COORDINATEPOINT coordinatePointMaker(float x, float y) {
	COORDINATEPOINT newPoint;
	newPoint.x = x;
	newPoint.y = y;

	return newPoint;
}