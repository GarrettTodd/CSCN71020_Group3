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
		case 1:
			printf("Rectangle selected.\n");
			Point points[4] = { 0 };
			getPoints(points);
			bool isRectangle = analyzePoints(points);
			printf("\nPerimeter: %.3lf\n", getPerimeter(points));
			if (isRectangle)
				printf("Area: %.3lf\n", getArea(points));
			else
				printf("The points doesn't form a rectangle.\n\n");
			break;
		case 2:
			printf_s("Triangle selected.\n");
			double triangleSides[3] = { 0, 0, 0 };
			double* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			bool isTriangle;
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &isTriangle);
			printf_s("\n%s\n", result);
			if (isTriangle == true)
			{
				double angle[3];
				findingAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &angle[0]);
				findingAngles(triangleSidesPtr[2], triangleSidesPtr[0], triangleSidesPtr[1], &angle[1]);
				findingAngles(triangleSidesPtr[1], triangleSidesPtr[2], triangleSidesPtr[0], &angle[2]);
				printf_s("The angles of your triangle are: %.3f, %.3f, %.3f\n", angle[0], angle[1], angle[2]);
			} printf("\n");

			break;
		case 3:
			printf("Exiting...\n");
			continueProgram = false;
			break;
		default:
			printf("Invalid value entered.\n");
			break;
		}
	}
}

double* getTriangleSides(double* triangleSides)
{
	for (int i = 0; i < 3; i++)
	{
		printf("Enter side [%d]\n", i + 1);
		triangleSides[i] = getValidInput("> ");
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
	printf("1. Rectangle\n");
	printf("2. Triangle\n");
	printf("3. Exit\n\n");

	int choice = getValidInput("> ");

	return choice;
}