#include "pch.h"
#include "CppUnitTest.h"
#include <cstdio>
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

			Assert::IsTrue(round(out[0]) == 36 && round(out[1]) == 89 && round(out[2]) == 55 && valid);
		}
		TEST_METHOD(GetTriAngles2) {
			// Tests Obtuse Triangle
			double out[3];

			bool valid = GetTriAngles(20, 4, 17, out);

			// For Debug
			char str[100];
			sprintf_s(str, "%lf, %lf, %lf", out[0], out[1], out[2]);
			Logger::WriteMessage(str);

			Assert::IsTrue(round(out[0]) == 34 && round(out[1]) == 34 && round(out[2]) == 16 && valid);
		}
		TEST_METHOD(GetTriAngles3) {
			// Tests Right Triangle
			double out[3];

			bool valid = GetTriAngles(5, 5, 5, out);

			Assert::IsTrue(round(out[0]) == 60 && round(out[1]) == 60 && round(out[2]) == 60 && valid);
		}

		TEST_METHOD(GetTriAngles4) {
			// Test if angles are correct
			double out[3];

			bool valid = GetTriAngles(5, 12, 13, out);

			// Truncates to account for negligble floating point precision errors
			Assert::IsTrue(round(out[0]) == 90 && round(out[1]) == 23 && round(out[2]) == 67 && valid);
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
}