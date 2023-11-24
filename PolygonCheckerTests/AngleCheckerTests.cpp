#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

extern "C" {
#include "anglechecker.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AngleCheckerTests
{
	TEST_CLASS(ANGLECHECKER_TESTS) {
		TEST_METHOD(GetTriAngles1) {
			// Test Basic Functionality (Acute Triangle)
			double out[3];

			bool valid = GetTriAngles(22, 18, 13, out);

			Assert::IsTrue(round(out[0]) == 36 && round(out[1]) == 55 && round(out[2]) == 89 && valid);
		}
		TEST_METHOD(GetTriAngles2) {
			// Tests Obtuse Triangle
			double out[3];

			bool valid = GetTriAngles(20, 4, 17, out);

			Assert::IsTrue(round(out[0]) == 37 && round(out[1]) == 8 && round(out[2]) == 134 && valid);
		}
		TEST_METHOD(GetTriAngles3) {
			// Tests equilateral Triangle
			double out[3];

			bool valid = GetTriAngles(5, 5, 5, out);

			Assert::IsTrue(round(out[0]) == 60 && round(out[1]) == 60 && round(out[2]) == 60 && valid);
		}

		TEST_METHOD(GetTriAngles4) {
			// Test if angles are correct on a right triangle
			double out[3];

			bool valid = GetTriAngles(5, 12, 13, out);

			// Truncates to account for negligble floating point precision errors
			Assert::IsTrue(round(out[0]) == 90 && round(out[1]) == 67 && round(out[2]) == 23 && valid);
		}

		TEST_METHOD(GetTriAngles5) {
			// Tests ability to manage small triangles
			double out[3];

			bool valid = GetTriAngles(1, 1, 1, out);

			Assert::IsTrue(round(out[0]) == 60 && round(out[1]) == 60 && round(out[2]) == 60 && valid);
		}
		TEST_METHOD(GetTriAngles6) {
			// Tests ability to manage large triangles
			double out[3];

			bool valid = GetTriAngles(5000, 5000, 5000, out);

			Assert::IsTrue(round(out[0]) == 60 && round(out[1]) == 60 && round(out[2]) == 60 && valid);
		}
		TEST_METHOD(GetTriAngles7) {
			// Checks that negative side lengths are handled accordingly
			double out[3];
			Assert::IsFalse(GetTriAngles(-22, 5, -33, out));
		}
		TEST_METHOD(GetTriAngles8) {
			// Checks that triangle inequality is handled properly
			double out[3];
			Assert::IsFalse(GetTriAngles(5, 20, 5, out));
		}
		TEST_METHOD(GetTriAngles9) {
			// Ensures the pointer is verfiied
			Assert::IsFalse(GetTriAngles(3, 3, 3, NULL));
		}
	};

	TEST_CLASS(THREEPOINTANGLE_TESTS) {
		TEST_METHOD(acuteAngle) {
			//testing if it will calculate an acute angle accurately
			COORDINATEPOINT point1 = coordinatePointMaker(2, 2);
			COORDINATEPOINT point2 = coordinatePointMaker(6, 6);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 2);

			double actual = angleFromThreePoints(point1, point2, point3);

			Assert::AreEqual(actual, 45.0, 0.01);
		}

		TEST_METHOD(obtuseAngle) {
			//testing if it will calculate an obtuse angle accurately
			COORDINATEPOINT point1 = coordinatePointMaker(2, 2);
			COORDINATEPOINT point2 = coordinatePointMaker(-2, 6);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 2);

			double actual = angleFromThreePoints(point1, point2, point3);

			Assert::AreEqual(actual, 135.0, 0.01);
		}

		TEST_METHOD(rightAngle) {
			//testing if it will calculate an right angle accurately
			COORDINATEPOINT point1 = coordinatePointMaker(2, 2);
			COORDINATEPOINT point2 = coordinatePointMaker(2, 6);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 2);

			double actual = angleFromThreePoints(point1, point2, point3);

			Assert::AreEqual(actual, 90.0, 0.01);
		}

		TEST_METHOD(parallelAngle) {
			//testing if it will calculate an flat line angle accurately
			COORDINATEPOINT point1 = coordinatePointMaker(2, 2);
			COORDINATEPOINT point2 = coordinatePointMaker(-2, 2);
			COORDINATEPOINT point3 = coordinatePointMaker(6, 2);

			double actual = angleFromThreePoints(point1, point2, point3);

			Assert::AreEqual(actual, 180.0, 0.01);
		}
	};
}