#include <stdio.h>
#include "rectangleSolver.h"

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
	if (topHalf[0].x >= topHalf[1].x) {
		outputRectangle.topRight = topHalf[0];
		outputRectangle.topLeft = topHalf[1];
	}
	else {
		outputRectangle.topRight = topHalf[1];
		outputRectangle.topLeft = topHalf[0];
	}

	if (bottomHalf[0].x >= bottomHalf[1].x) {
		outputRectangle.bottomRight = bottomHalf[0];
		outputRectangle.bottomLeft = bottomHalf[1];
	}
	else {
		outputRectangle.bottomRight = bottomHalf[1];
		outputRectangle.bottomLeft = bottomHalf[0];
	}


	
};