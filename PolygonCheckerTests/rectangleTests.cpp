#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
#include "../PolygonChecker/rectangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests {


	TEST_CLASS(rectangleMakerTests) {
	public:

		TEST_METHOD(allZero) {
			//testing the range of numbers that can make a rectangle
			COORDINATEPOINT point1 = coordinatePointMaker(0, 0);
			COORDINATEPOINT point2 = coordinatePointMaker(0, 0);
			COORDINATEPOINT point3 = coordinatePointMaker(0, 0);
			COORDINATEPOINT point4 = coordinatePointMaker(0, 0);

			RECTANGLECORNERS actual = rectangleMaker(point1, point2, point3, point4);

			Assert::AreEqual(actual.bottomLeft.x, 0.0F);
			Assert::AreEqual(actual.bottomLeft.y, 0.0F);

			Assert::AreEqual(actual.bottomRight.x, 0.0F);
			Assert::AreEqual(actual.bottomRight.y, 0.0F);

			Assert::AreEqual(actual.topLeft.x, 0.0F);
			Assert::AreEqual(actual.topLeft.y, 0.0F);

			Assert::AreEqual(actual.topRight.x, 0.0F);
			Assert::AreEqual(actual.topRight.y, 0.0F);
		}

		TEST_METHOD(topTwoSameXBottomTwoRight) {
			//testing to ensure no lines cross
			COORDINATEPOINT point1 = coordinatePointMaker(5, 6);
			COORDINATEPOINT point2 = coordinatePointMaker(5, 5);
			COORDINATEPOINT point3 = coordinatePointMaker(10, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(15, 2);

			RECTANGLECORNERS actual = rectangleMaker(point1, point2, point3, point4);

			Assert::AreEqual(actual.bottomLeft.x, 10.0F);
			Assert::AreEqual(actual.bottomLeft.y, 2.0F);

			Assert::AreEqual(actual.bottomRight.x, 15.0F);
			Assert::AreEqual(actual.bottomRight.y, 2.0F);

			Assert::AreEqual(actual.topLeft.x, 5.0F);
			Assert::AreEqual(actual.topLeft.y, 5.0F);

			Assert::AreEqual(actual.topRight.x, 5.0F);
			Assert::AreEqual(actual.topRight.y, 6.0F);
		}

		TEST_METHOD(topTwoSameXBottomTwoLeft) {
			//testing to ensure no lines cross
			COORDINATEPOINT point1 = coordinatePointMaker(5, 6);
			COORDINATEPOINT point2 = coordinatePointMaker(5, 5);
			COORDINATEPOINT point3 = coordinatePointMaker(-10, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(-15, 2);

			RECTANGLECORNERS actual = rectangleMaker(point1, point2, point3, point4);

			Assert::AreEqual(actual.bottomLeft.x, -15.0F);
			Assert::AreEqual(actual.bottomLeft.y, 2.0F);

			Assert::AreEqual(actual.bottomRight.x, -10.0F);
			Assert::AreEqual(actual.bottomRight.y, 2.0F);

			Assert::AreEqual(actual.topLeft.x, 5.0F);
			Assert::AreEqual(actual.topLeft.y, 6.0F);

			Assert::AreEqual(actual.topRight.x, 5.0F);
			Assert::AreEqual(actual.topRight.y, 5.0F);
		}

		TEST_METHOD(bottomTwoSameXTopTwoRight) {
			//testing to ensure no lines cross
			COORDINATEPOINT point1 = coordinatePointMaker(15, 6);
			COORDINATEPOINT point2 = coordinatePointMaker(10, 6);
			COORDINATEPOINT point3 = coordinatePointMaker(5, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(5, 3);

			RECTANGLECORNERS actual = rectangleMaker(point1, point2, point3, point4);

			Assert::AreEqual(actual.bottomLeft.x, 5.0F);
			Assert::AreEqual(actual.bottomLeft.y, 3.0F);

			Assert::AreEqual(actual.bottomRight.x, 5.0F);
			Assert::AreEqual(actual.bottomRight.y, 2.0F);

			Assert::AreEqual(actual.topLeft.x, 10.0F);
			Assert::AreEqual(actual.topLeft.y, 6.0F);

			Assert::AreEqual(actual.topRight.x, 15.0F);
			Assert::AreEqual(actual.topRight.y, 6.0F);
		}

		TEST_METHOD(bottomTwoSameXTopTwoLeft) {
			//testing to ensure no lines cross
			COORDINATEPOINT point1 = coordinatePointMaker(-15, 6);
			COORDINATEPOINT point2 = coordinatePointMaker(-10, 6);
			COORDINATEPOINT point3 = coordinatePointMaker(5, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(5, 3);

			RECTANGLECORNERS actual = rectangleMaker(point1, point2, point3, point4);

			Assert::AreEqual(actual.bottomLeft.x, 5.0F);
			Assert::AreEqual(actual.bottomLeft.y, 2.0F);

			Assert::AreEqual(actual.bottomRight.x, 5.0F);
			Assert::AreEqual(actual.bottomRight.y, 3.0F);

			Assert::AreEqual(actual.topLeft.x, -15.0F);
			Assert::AreEqual(actual.topLeft.y, 6.0F);

			Assert::AreEqual(actual.topRight.x, -10.0F);
			Assert::AreEqual(actual.topRight.y, 6.0F);
		}
	};

	TEST_CLASS(coodinatePointMakerTests) {
	public:

		TEST_METHOD(bothPositive) {
			//testing range of numbers that can be used to make a coordinate point
			COORDINATEPOINT actual = coordinatePointMaker(5, 6);
			
			Assert::AreEqual(actual.x, 5.0F);
			Assert::AreEqual(actual.y, 6.0F);
		}

		TEST_METHOD(negativeXPositiveY) {
			//testing range of numbers that can be used to make a coordinate point
			COORDINATEPOINT actual = coordinatePointMaker(-5, 6);

			Assert::AreEqual(actual.x, -5.0F);
			Assert::AreEqual(actual.y, 6.0F);
		}

		TEST_METHOD(positiveXNegativeY) {
			//testing range of numbers that can be used to make a coordinate point
			COORDINATEPOINT actual = coordinatePointMaker(5, -6);

			Assert::AreEqual(actual.x, 5.0F);
			Assert::AreEqual(actual.y, -6.0F);
		}

		TEST_METHOD(bothNegative) {
			//testing range of numbers that can be used to make a coordinate point
			COORDINATEPOINT actual = coordinatePointMaker(-5, -6);

			Assert::AreEqual(actual.x, -5.0F);
			Assert::AreEqual(actual.y, -6.0F);
		}
	};

	TEST_CLASS(rectangleCheckerTests) {
	public:

		TEST_METHOD(verticalSquare) {
			//testing that it will properly identify a regular square
			COORDINATEPOINT point1 = coordinatePointMaker(2, 6);
			COORDINATEPOINT point2 = coordinatePointMaker(6, 6);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(2, 2);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			bool actual = rectangleChecker(square);

			Assert::IsTrue(actual);
		}

		TEST_METHOD(tiltedSquare) {
			//testing that it will still detect the rectangle if it's at an angle
			COORDINATEPOINT point1 = coordinatePointMaker(2, 4);
			COORDINATEPOINT point2 = coordinatePointMaker(4, 2);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 4);
			COORDINATEPOINT point4 = coordinatePointMaker(4, 6);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			bool actual = rectangleChecker(square);

			Assert::IsTrue(actual);
		}

		TEST_METHOD(nonSquare) {
			//testing to ensure it will properly identify non-rectangles
			COORDINATEPOINT point1 = coordinatePointMaker(50, 50);
			COORDINATEPOINT point2 = coordinatePointMaker(6, 6);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(2, 2);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			bool actual = rectangleChecker(square);

			Assert::IsFalse(actual);
		}
	};

	TEST_CLASS(rectangleAreaTests) {
	public:

		TEST_METHOD(allZeroArea) {
			//testing the range of numbers that can calculate area
			COORDINATEPOINT point1 = coordinatePointMaker(0, 0);
			COORDINATEPOINT point2 = coordinatePointMaker(0, 0);
			COORDINATEPOINT point3 = coordinatePointMaker(0, 0);
			COORDINATEPOINT point4 = coordinatePointMaker(0, 0);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			float expected = 0;
			float actual = rectangleArea(square);

			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(largeSquare) {
			//testing the range of numbers that can calculate area
			COORDINATEPOINT point1 = coordinatePointMaker(20000, 60000);
			COORDINATEPOINT point2 = coordinatePointMaker(60000, 60000);
			COORDINATEPOINT point3 = coordinatePointMaker(60000, 20000);
			COORDINATEPOINT point4 = coordinatePointMaker(20000, 20000);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			float expected = 1600000000.0;
			float actual = rectangleArea(square);

			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(regularSquare) {
			//testing that it will calculate the area of a regular square
			COORDINATEPOINT point1 = coordinatePointMaker(2, 6);
			COORDINATEPOINT point2 = coordinatePointMaker(6, 6);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(2, 2);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			float expected = 16.0;
			float actual = rectangleArea(square);

			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(wideRectangleArea) {
			//testing that it will calculate the area of rectangles of different shapes
			COORDINATEPOINT point1 = coordinatePointMaker(2, 6);
			COORDINATEPOINT point2 = coordinatePointMaker(20, 6);
			COORDINATEPOINT point3 = coordinatePointMaker(20, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(2, 2);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			float expected = 72.0;
			float actual = rectangleArea(square);

			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(tallRectangleArea) {
			//testing that it will calculate the area of rectangles of different shapes
			COORDINATEPOINT point1 = coordinatePointMaker(2, 20);
			COORDINATEPOINT point2 = coordinatePointMaker(6, 20);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(2, 2);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			float expected = 72.0;
			float actual = rectangleArea(square);

			Assert::AreEqual(actual, expected);
		}
	};

	TEST_CLASS(rectanglePerimeterTests) {
	public:

		TEST_METHOD(regularSquarePerimeter) {
			//testing that it will calculate the perimeter of a regular square
			COORDINATEPOINT point1 = coordinatePointMaker(2, 6);
			COORDINATEPOINT point2 = coordinatePointMaker(6, 6);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(2, 2);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			float expected = 16.0;
			float actual = rectanglePerimeter(square);

			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(bigSquarePerimeter) {
			//testing the range of number that can be used to get a perimeter
			COORDINATEPOINT point1 = coordinatePointMaker(2000, 6000);
			COORDINATEPOINT point2 = coordinatePointMaker(6000, 6000);
			COORDINATEPOINT point3 = coordinatePointMaker(6000, 2000);
			COORDINATEPOINT point4 = coordinatePointMaker(2000, 2000);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			float expected = 16000.0;
			float actual = rectanglePerimeter(square);

			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(allZeroPerimeter) {
			//testing the range of number that can be used to get a perimeter
			COORDINATEPOINT point1 = coordinatePointMaker(0, 0);
			COORDINATEPOINT point2 = coordinatePointMaker(0, 0);
			COORDINATEPOINT point3 = coordinatePointMaker(0, 0);
			COORDINATEPOINT point4 = coordinatePointMaker(0, 0);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			float expected = 0.0;
			float actual = rectanglePerimeter(square);

			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(tallRectanglePerimeter) {
			//testing that it will calculate the perimeter of rectangles of different shapes
			COORDINATEPOINT point1 = coordinatePointMaker(2, 20);
			COORDINATEPOINT point2 = coordinatePointMaker(6, 20);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(2, 2);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			float expected = 44.0;
			float actual = rectanglePerimeter(square);

			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(wideRectanglePerimeter) {
			//testing that it will calculate the perimeter of rectangles of different shapes
			COORDINATEPOINT point1 = coordinatePointMaker(2, 6);
			COORDINATEPOINT point2 = coordinatePointMaker(20, 6);
			COORDINATEPOINT point3 = coordinatePointMaker(20, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(2, 2);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			float expected = 44.0;
			float actual = rectanglePerimeter(square);

			Assert::AreEqual(actual, expected);
		}
	};
}