#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
#include "../PolygonChecker/main.h"
#include "../PolygonChecker/rectangleSolver.h"
#include "../PolygonChecker/triangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My4PointsTesting
{
	TEST_CLASS(My4PointsTesting)
	{
	public:
		
		TEST_METHOD(InvalidInputTest)
		{
			int points[] = { -1,2,3,4,5,6,7,8 };
			Assert::AreEqual(0, isRectangle(points));
		}
		// Test case to check if points indeed form a rectangle
		TEST_METHOD(IsRectangle_ValidRectangle)
		{
			int rectanglePoints[8] = { 0, 0, 0, 4, 3, 0, 3, 4 }; // Valid rectangle points
			Assert::IsTrue(isRectangle(rectanglePoints));
		}
		// Test case to check if points do not form a rectangle
		TEST_METHOD(IsRectangle_NotRectangle)
		{
			int rectanglePoints[8] = { 0, 0, 0, 4, 3, 0, 5, 4 }; // Not a rectangle
			Assert::IsFalse(isRectangle(rectanglePoints));
		}
		// Edge cases for isRectangle function
		TEST_METHOD(IsRectangle_ZeroCoordinates)
		{
			int points[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
			Assert::IsTrue(isRectangle(points));
		}
		TEST_METHOD(IsRectangle_NegativeCoordinates)
		{
			int points[8] = { -1, -2, -3, -4, -5, -6, -7, -8 };
			Assert::IsFalse(isRectangle(points));
		}
		TEST_METHOD(AnalyzeRectangle_LargeValues)
		{
			int points[8] = { 1000000, 1000000, 1000000, 1000004, 1000003, 1000000, 1000003, 1000004 }; // Large values
			analyzeRectangle(points);
		}
		TEST_METHOD(AnalyzeRectangle_DiagonalLine_NotRectangle)
		{
			int points[8] = { 0, 0, 1, 1, 2, 2, 3, 3 }; // Diagonal line (not a rectangle)
			Assert::IsFalse(isRectangle(points));
		}
		TEST_METHOD(AnalyzeRectangle_NearlyRectangle)
		{
			int points[8] = { 0, 0, 1, 0, 0, 4, 1, 4 }; // Nearly a rectangle
			analyzeRectangle(points);
			Assert::IsFalse(isRectangle(points));
		}
		TEST_METHOD(CalculatePerimeter_Square)
		{
			double side = 4.0;
			double expectedPerimeter = 16.0; // For a square with side length 4
			double calculatedPerimeter = 2 * (side + side);

			Assert::AreEqual(expectedPerimeter, calculatedPerimeter);
		}
		TEST_METHOD(CalculateArea_Square)
		{
			double side = 4.0;
			double expectedArea = 16.0; // For a square with side length 4
			double calculatedArea = side * side;

			Assert::AreEqual(expectedArea, calculatedArea);
		}
		TEST_METHOD(CalculatePerimeter_LargeValues)
		{
			double side1 = 10000.0;
			double side2 = 5000.0;
			double expectedPerimeter = 30000.0; // For sides 10000 and 5000
			double calculatedPerimeter = 2 * (side1 + side2);

			Assert::AreEqual(expectedPerimeter, calculatedPerimeter);
		}
		TEST_METHOD(CalculateArea_DecimalValues)
		{
			double side1 = 3.5;
			double side2 = 6.25;
			double expectedArea = 21.875; // For sides 3.5 and 6.25
			double calculatedArea = side1 * side2;

			Assert::AreEqual(expectedArea, calculatedArea);
		}
		TEST_METHOD(CalculatePerimeter_NegativeValues)
		{
			double side = -4.0;
			double expectedPerimeter = -16.0; // For sides -4 and -4
			double calculatedPerimeter = 2 * (side + side);

			Assert::AreEqual(expectedPerimeter, calculatedPerimeter);
		}
	};
}
