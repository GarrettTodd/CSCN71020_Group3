#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 2:
			printf_s("Rectangle selected.\n");
			int rectanglePoints[4][2] = { {0, 0}, {0, 0}, {0, 0}, {0, 0} };
			getRectanglePoints(rectanglePoints);
			bool isRectangle = analyzeRectangle(rectanglePoints);
			if (isRectangle) {
				printf("Perimeter: %d\n", getPerimeter(rectanglePoints));
				printf("Area: %d\n", getArea(rectanglePoints));
			}
			break;
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			bool isTriangle;
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &isTriangle);
			printf_s("%s\n", result);
			if (isTriangle)
			{
				float angle[3];
				findingAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &angle[0]);
				findingAngles(triangleSidesPtr[2], triangleSidesPtr[0], triangleSidesPtr[1], &angle[1]);
				findingAngles(triangleSidesPtr[1], triangleSidesPtr[2], triangleSidesPtr[0], &angle[2]);
				printf_s("The angles of your triangle are: %f, %f, %f\n", angle[0], angle[1], angle[2]);
			}
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n"); 
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

void getRectanglePoints(int rectanglePoints[][2]) {
	for (int i = 0; i < 4; i++) {
		printf_s("Enter point [%d]\n", i + 1);

		rectanglePoints[i][0] = getValidInput("X: ");

		rectanglePoints[i][1] = getValidInput("Y: ");
	}
}

int getValidInput(char prompt[]) {
	int input = 0, temp = 0;
	while (1) {
		printf_s("%s", prompt);
		temp = scanf_s("%d", &input);

		if (temp != 1 || getchar() != 10) {
			while (getchar() != '\n');
			printf_s("Invalid value entered, try again.\n");
		}
		else {
			return input;
			break;
		}
	}
}