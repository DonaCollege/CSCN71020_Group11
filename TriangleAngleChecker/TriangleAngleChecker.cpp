#include "pch.h"
#include "CppUnitTest.h"

extern "C" void calculateTriangleAngles(int side1, int side2, int side3, double* angleA, double* angleB, double* angleC);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleAngleChecker
{
	TEST_CLASS(TriangleAngleChecker)
	{
	public:
		
        TEST_METHOD(AngleCheck01)
        {
            // Define angles to store the calculated angles
            double angleA, angleB, angleC;

            // Call the function to calculate angles
            calculateTriangleAngles(6, 6, 6, &angleA, &angleB, &angleC);

            // Assert each angle separately, assuming you have a tolerance for the comparison
            Assert::AreEqual(60.03, angleA, 0.01); // 0.01 is the tolerance
            Assert::AreEqual(60.03, angleB, 0.01);
            Assert::AreEqual(60.03, angleC, 0.01);
        }

        TEST_METHOD(AngleCheck02)
        {
            double angleA, angleB, angleC;

            calculateTriangleAngles(3,2,4, &angleA, &angleB, &angleC);

            Assert::AreEqual(46.59, angleA, 0.01); 
            Assert::AreEqual(28.97, angleB, 0.01);
            Assert::AreEqual(104.53, angleC, 0.01);
        }
        TEST_METHOD(AngleCheck03)
        {
            double angleA, angleB, angleC;

            calculateTriangleAngles(5, 13, 12, &angleA, &angleB, &angleC);

            Assert::AreEqual(22.63, angleA, 0.01);
            Assert::AreEqual(90.05, angleB, 0.01);
            Assert::AreEqual(67.41, angleC, 0.01);
        }

        TEST_METHOD(AngleCheck04)
        {
            double angleA, angleB, angleC;

            calculateTriangleAngles(23, 34, 12, &angleA, &angleB, &angleC);

            Assert::AreEqual(19.13, angleA, 0.01);
            Assert::AreEqual(151.12, angleB, 0.01);
            Assert::AreEqual(9.84, angleC, 0.01);
        }

        TEST_METHOD(AngleCheck05)
        {
            double angleA, angleB, angleC;

            calculateTriangleAngles(8, 8, 1, &angleA, &angleB, &angleC);

            Assert::AreEqual(86.46, angleA, 0.01);
            Assert::AreEqual(86.46, angleB, 0.01);
            Assert::AreEqual(7.17, angleC, 0.01);
        }

        TEST_METHOD(AngleCheck06)
        {
            double angleA, angleB, angleC;

            calculateTriangleAngles(7, 8, 9, &angleA, &angleB, &angleC);

            Assert::AreEqual(48.21, angleA, 0.01);
            Assert::AreEqual(58.44, angleB, 0.01);
            Assert::AreEqual(73.44, angleC, 0.01);
        }
	};
}
