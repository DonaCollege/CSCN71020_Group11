#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int side1, int side2, int side3);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace TriangleTypechecker
{
	TEST_CLASS(TriangleTypechecker)
	{
	public:

		TEST_METHOD(NullTriangle)
		{
			char* result = analyzeTriangle(0, 0, 0);
			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(Equilateraltriangle)
		{
			char* result = analyzeTriangle(5, 5, 5);
			Assert::AreEqual("Equilateral triangle", result);
		}
		TEST_METHOD(NotaEquilateraltriangle)
		{
			char* result = analyzeTriangle(5, 1, 5);
			Assert::AreEqual("Equilateral triangle", result);
		}
		TEST_METHOD(Isoscelestriangle)
		{
			char* result = analyzeTriangle(3, 3, 7);
			Assert::AreEqual("Isosceles triangle", result);
		}
		TEST_METHOD(NotaIsoscelestriangle)
		{
			char* result = analyzeTriangle(3, 4, 7);
			Assert::AreEqual("Isosceles triangle", result);
		}
		TEST_METHOD(Scalenetriangle)
		{
			char* result = analyzeTriangle(3, 1, 7);
			Assert::AreEqual("Scalene triangle", result);
		}
		TEST_METHOD(NotaScalenetriangle)
		{
			char* result = analyzeTriangle(3, 4, 3);
			Assert::AreEqual("Scalene triangle", result);
		}
	};
}
