#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int main(void)
{
	bool continueProgram = true;
	while (continueProgram)
	{
		printWelcome();
		int shapeChoice = printShapeMenu();
		switch (shapeChoice)
		{
		case 2:
			printf("Rectangle selected.\n");
			Point points[4] = { 0 };
			getPoints(points);
			bool isRectangle = analyzePoints(points);
			printf("Perimeter: %.3lf\n", getPerimeter(points));
			if (isRectangle)
				printf("Area: %.3lf\n", getArea(points));
			else
				printf("The points doesn't form a rectangle\n");
			break;
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			bool isTriangle;
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &isTriangle);
			printf_s("%s\n", result);
			if (isTriangle == true)
			{
				float angle[3];
				findingAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &angle[0]);
				findingAngles(triangleSidesPtr[2], triangleSidesPtr[0], triangleSidesPtr[1], &angle[1]);
				findingAngles(triangleSidesPtr[1], triangleSidesPtr[2], triangleSidesPtr[0], &angle[2]);
				printf_s("The angles of your triangle are: %f, %f, %f\n", angle[0], angle[1], angle[2]);
			}

			break;
		case 0:
			printf("Exiting...\n");
			continueProgram = false;
			break;
		default:
			printf("Invalid value entered.\n");
			break;
		}
	}
}

int* getTriangleSides(int* triangleSides)
{
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

void printWelcome()
{
	printf(" ********************** \n");
	printf("**     Welcome to     **\n");
	printf("**   Polygon Checker  **\n");
	printf(" ********************** \n");
}

int printShapeMenu()
{
	printf("1. Triangle\n");
	printf("2. Rectangle\n\n");
	printf("0. Exit\n");

	int choice = getValidInput("> ");

	return choice;
}