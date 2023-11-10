
#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

#define MAXSIZE 50

int main() {
    bool continueProgram = true;
    while (continueProgram) {
        printWelcome();

        int shapeChoice = printShapeMenu();

        switch (shapeChoice) {
        case 1:
            printf("Triangle selected.\n");
            int triangleSides[3] = { 0, 0, 0 };
            int* triangleSidesPtr = getTriangleSides(triangleSides);

            if (isTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2])) {
                double angleA, angleB, angleC;
                calculateTriangleAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &angleA, &angleB, &angleC);
                printf("Angles of the triangle: %.2f, %.2f, %.2f\n", angleA, angleB, angleC);
            }
            else {
                printf("The given side lengths do not form a valid triangle.\n");
            }
            break;
        case 2:
            printf_s("Rectangle selected.\n");
            int rectanglePoints[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
            int* rectanglePointsPtr = getRectanglePoints(rectanglePoints);
            analyzeRectangle(rectanglePointsPtr);
            break;
        case 0:
            continueProgram = false;
            break;
        default:
            printf("Invalid value entered.\n");
            break;
        }
    }

    return 0;
}

void printWelcome() {
    printf("\n");
    printf(" **********************\n");
    printf("**     Welcome to     **\n");
    printf("**   Polygon Checker  **\n");
    printf(" **********************\n");
}

int printShapeMenu() {
    printf("1. Triangle\n");
    printf("0. Exit\n");

    int shapeChoice;
    printf("Enter number: ");
    scanf_s("%1o", &shapeChoice);

    return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
    printf("Enter the three sides of the triangle: ");
    for (int i = 0; i < 3; i++) {
        scanf_s("%d", &triangleSides[i]);
    }
    return triangleSides;
}
