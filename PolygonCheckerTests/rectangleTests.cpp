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

		TEST_METHOD(bottomTwoSameXTopTwoRight) {
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
			COORDINATEPOINT actual = coordinatePointMaker(5, 6);
			
			Assert::AreEqual(actual.x, 5.0F);
			Assert::AreEqual(actual.y, 6.0F);
		}

		TEST_METHOD(negativeXPositiveY) {
			COORDINATEPOINT actual = coordinatePointMaker(-5, 6);

			Assert::AreEqual(actual.x, -5.0F);
			Assert::AreEqual(actual.y, 6.0F);
		}

		TEST_METHOD(positiveXNegativeY) {
			COORDINATEPOINT actual = coordinatePointMaker(5, -6);

			Assert::AreEqual(actual.x, 5.0F);
			Assert::AreEqual(actual.y, -6.0F);
		}

		TEST_METHOD(bothNegative) {
			COORDINATEPOINT actual = coordinatePointMaker(-5, -6);

			Assert::AreEqual(actual.x, -5.0F);
			Assert::AreEqual(actual.y, -6.0F);
		}
	};

	TEST_CLASS(rectangleCheckerTests) {
	public:

		TEST_METHOD(verticalSquare) {
			COORDINATEPOINT point1 = coordinatePointMaker(2, 6);
			COORDINATEPOINT point2 = coordinatePointMaker(6, 6);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 2);
			COORDINATEPOINT point4 = coordinatePointMaker(2, 2);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			bool actual = rectangleChecker(square);

			Assert::IsTrue(actual);
		}

		TEST_METHOD(tiltedSquare) {
			COORDINATEPOINT point1 = coordinatePointMaker(2, 4);
			COORDINATEPOINT point2 = coordinatePointMaker(4, 2);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 4);
			COORDINATEPOINT point4 = coordinatePointMaker(4, 6);

			RECTANGLECORNERS square = rectangleMaker(point1, point2, point3, point4);

			bool actual = rectangleChecker(square);

			Assert::IsTrue(actual);
		}

		TEST_METHOD(nonSquare) {
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

		TEST_METHOD(rectangleAllPositive) {

		}
	};

	TEST_CLASS(rectanglePerimeterTests) {
	public:

		TEST_METHOD(rectangleAllPositive) {

		}
	};
}