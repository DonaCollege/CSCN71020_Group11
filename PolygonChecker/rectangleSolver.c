#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
#include "rectangleSolver.h"
#include "triangleSolver.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int* getRectanglePoints(int* rectanglePoints) {
    printf_s("Enter the four points of the rectangle (x, y for each point): ");
    for (int i = 0; i < 8; i++) {
        scanf_s("%d", &rectanglePoints[i]);
    }
    return rectanglePoints;
}

int isRectangle(int* points) {
    for (int i = 0; i < 8; i++) {
        if (points[i] < 0) {
            return 0;
        }
    }

return 1; 
}


double distance(int x1, int y1, int x2, int y2) {
    // Helper function to calculate the distance between two points
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void analyzeRectangle(int* rectanglePoints) {
    if (isRectangle(rectanglePoints)) {
        // Calculate the side lengths and perimeter
        double side1 = distance(rectanglePoints[0], rectanglePoints[1], rectanglePoints[2], rectanglePoints[3]);
        double side2 = distance(rectanglePoints[2], rectanglePoints[3], rectanglePoints[4], rectanglePoints[5]);
        double perimeter = 2 * (side1 + side2);

        // Calculate and print the area
        double area = side1 * side2;

        printf_s("Perimeter: %.2lf\n", perimeter);
        printf_s("Area: %.2lf\n", area);
    }
    else {
        printf_s("The given points do not form a rectangle.\n");
    }
}
