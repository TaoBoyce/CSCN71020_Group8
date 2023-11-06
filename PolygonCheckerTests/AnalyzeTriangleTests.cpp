#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
	char* analyzeTriangle(int side1, int side2, int side3);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnalyzeTriangleTests
{
	TEST_CLASS(AnalyzeTriangleTests)
	{
	public:

		TEST_METHOD(AnalyzeTriangle1)
		{
			//functionality: equilateral
			char* expected = "Equilateral triangle";
			char* actual = analyzeTriangle(5, 5, 5);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle2)
		{
			//functionality: icosceles
			char* expected = "Isosceles triangle";
			char* actual = analyzeTriangle(5, 5, 3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle3)
		{
			//functionality: scalene
			char* expected = "Scalene triangle";
			char* actual = analyzeTriangle(5, 4, 3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle4)
		{
			//functionality: not triangle
			char* expected = "Not a triangle";
			char* actual = analyzeTriangle(5, 0, 3);
			Assert::AreEqual(expected, actual);
		}
	};
}