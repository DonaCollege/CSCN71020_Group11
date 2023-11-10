#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define _USE_MATH_DEFINE
#define M_PI 3.14
#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) ||
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}


bool isTriangle(int side1, int side2, int side3) {
	return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
}

void calculateTriangleAngles(int side1, int side2, int side3, double* angleA, double* angleB, double* angleC) {
	*angleA = acos((side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3));
	*angleB = acos((side1 * side1 + side3 * side3 - side2 * side2) / (2.0 * side1 * side3));
	*angleC = acos((side1 * side1 + side2 * side2 - side3 * side3) / (2.0 * side1 * side2));

	// Convert angles from radians to degrees
	*angleA = (*angleA) * (180.0 / M_PI);
	*angleB = (*angleB) * (180.0 / M_PI);
	*angleC = (*angleC) * (180.0 / M_PI);
}
