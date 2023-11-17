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

		TEST_METHOD(AnalyzeTriangle1A)
		{
			//functionality: equilateral
			char* expected = "Equilateral triangle";
			char* actual = analyzeTriangle(5, 5, 5);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle2A)
		{
			//functionality: icosceles
			char* expected = "Isosceles triangle";
			char* actual = analyzeTriangle(5, 5, 3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle2B)
		{
			//functionality: icosceles
			char* expected = "Isosceles triangle";
			char* actual = analyzeTriangle(3, 5, 5);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle2C)
		{
			//functionality: icosceles
			char* expected = "Isosceles triangle";
			char* actual = analyzeTriangle(5, 3, 5);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle3)
		{
			//functionality: scalene
			char* expected = "Scalene triangle";
			char* actual = analyzeTriangle(5, 4, 3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle4_1A)
		{
			//functionality: not triangle
			char* expected = "Not a triangle";
			char* actual = analyzeTriangle(5, 0, 3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle4_1B)
		{
			//functionality: not triangle
			char* expected = "Not a triangle";
			char* actual = analyzeTriangle(0, 5, 3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle4_1C)
		{
			//functionality: not triangle
			char* expected = "Not a triangle";
			char* actual = analyzeTriangle(5, 3, 0);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle4_2A)
		{
			//functionality: not triangle
			char* expected = "Not a triangle";
			char* actual = analyzeTriangle(-1, 5, 3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle4_2B)
		{
			//functionality: not triangle
			char* expected = "Not a triangle";
			char* actual = analyzeTriangle(5, -1, 3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle4_2C)
		{
			//functionality: not triangle
			char* expected = "Not a triangle";
			char* actual = analyzeTriangle(5, 3, -1);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle4_3A)
		{
			//functionality: not triangle
			char* expected = "Not a triangle";
			char* actual = analyzeTriangle(-1, -5, 3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle4_3B)
		{
			//functionality: not triangle
			char* expected = "Not a triangle";
			char* actual = analyzeTriangle(-5, 1, -3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle4_3C)
		{
			//functionality: not triangle
			char* expected = "Not a triangle";
			char* actual = analyzeTriangle(5, -3, -1);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AnalyzeTriangle4_4A)
		{
			//functionality: not triangle
			char* expected = "Not a triangle";
			char* actual = analyzeTriangle(-5, -3, -1);
			Assert::AreEqual(expected, actual);
		}


	};
}