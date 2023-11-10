#pragma once
#ifndef TRIANGLE_SOLVER_H
#define TRIANGLE_SOLVER_H

#include <stdbool.h>


char* analyzeTriangle(int side1, int side2, int side3);
bool isTriangle(int side1, int side2, int side3);
void calculateTriangleAngles(int side1, int side2, int side3, double* angleA, double* angleB, double* angleC);

#endif // TRIANGLE_SOLVER_H 
