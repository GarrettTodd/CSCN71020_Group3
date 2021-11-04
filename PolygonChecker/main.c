#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2:
			CreateRectangle();
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
	printf_s("2. Create Rectangle\n");
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

void CreateRectangle()
{
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int TopleftcornerY;
	int TopRightcornerY;
	int TopLeftcornerX;
	int TopRightcornerX;
	int BottomRightcornerY;
	int BottomRighrcornerX;
	int BottomLeftcornerY;
	int BottomLeftcornerX;
	printf("\n");
	printf("Enter your First X coordinate: ");

	if (scanf("%d", &x1) != 1)
	{
		printf("\nInvaild!\n");

		exit(1);

	}

	printf("Enter your First Y coordinate: ");

	if (scanf("%d", &y1) != 1)
	{
		printf("\nInvaild!\n");

		exit(1);

	}


	printf("\nEnter your Second X coordinate: ");

	if (scanf("%d", &x2) != 1)
	{
		printf("\nInvaild!\n");

		exit(1);

	}


	printf("Enter your Second Y coordinate: ");

	if (scanf("%d", &y2) != 1)
	{
		printf("\nInvaild!\n");

		exit(1);

	}

	printf("\nEnter your Third X coordinate: ");

	if (scanf("%d", &x3) != 1)
	{
		printf("\nInvaild!\n");

		exit(1);

	}


	printf("Enter your Third Y coordinate: ");

	if (scanf("%d", &y3) != 1)
	{
		printf("\nInvaild!\n");

		exit(1);

	}

	printf("\nEnter your Fourth X coordinate: ");

	if (scanf("%d", &x4) != 1)
	{
		printf("\nInvaild!\n");

		exit(1);

	}

	printf("Enter your Fourth Y coordinate: ");

	if (scanf("%d", &y4) != 1)
	{
		printf("\nInvaild!\n");

		exit(1);

	}

	if (x1 == x2 && y1 == y2)
	{
		printf("\nInvaild!\n");

		exit(1);
	}

	else if (x1 == x3 && y1 == y3)
	{
		printf("\nInvaild!\n");

		exit(1);
	}

	else if (x1 == x4 && y1 == y4)
	{
		printf("\nInvaild!\n");

		exit(1);
	}

	else if (x2 == x3 && y2 == y3)
	{
		printf("\nInvaild!\n");

		exit(1);
	}

	else if (x2 == x4 && y2 == y4)
	{
		printf("\nInvaild!\n");

		exit(1);
	}

	else if (x3 == x4 && y3 == y4)
	{
		printf("\nInvaild!\n");

		exit(1);
	}

	if (x1 < 0 || x2 < 0 || x3 < 0 || x4 < 0 || y1 < 0 || y2 < 0 || y3 < 0 || y4 < 0)
	{
		printf("\nInvaild!\n");

		exit(1);
	}


	if (y1 >= y2 && y1 >= y3 && y1 >= y4)
	{
		if (x1 <= x2 && x1 <= x3 && x1 <= x4)
		{
			TopleftcornerY = y1;
			TopLeftcornerX = x1;
			
		}
	}

	if (y2 >= y1 && y2 >= y3 && y2 >= y4)
	{
		if (x2 <= x1 && x2 <= x3 && x2 <= x4)
		{
			TopleftcornerY = y2;
			TopLeftcornerX = x2;
			
		}
	}

	if (y3 >= y1 && y3 >= y2 && y3 >= y4)
	{
		if (x3 <= x1 && x3 <= x2 && x3 <= x4)
		{
			TopleftcornerY = y3;
			TopLeftcornerX = x3;
			
		}
	}

	if (y4 >= y1 && y4 >= y2 && y4 >= y3)
	{
		if (x4 <= x1 && x4 <= x2 && x4 <= x3)
		{
			TopleftcornerY = y4;
			TopLeftcornerX = x4;
			
		}
	}





	if (TopleftcornerY == y1 && TopLeftcornerX < x1)
	{
		TopRightcornerY = y1;
		TopRightcornerX = x1;
		
	}

	if (TopleftcornerY == y2 && TopLeftcornerX < x2)
	{
		TopRightcornerY = y2;
		TopRightcornerX = x2;
		

	}

	if (TopleftcornerY == y3 && TopLeftcornerX < x3)
	{
		TopRightcornerY = y3;
		TopRightcornerX = x3;
		

	}


	else if (TopleftcornerY == y4 && TopLeftcornerX < x4)
	{
		TopRightcornerY = y4;
		TopRightcornerX = x4;
		
	}


	if (TopRightcornerX == x1 && TopRightcornerY > y1)
	{
		BottomRighrcornerX = x1;
		BottomRightcornerY = y1;
	}

	if (TopRightcornerX == x2 && TopRightcornerY > y2)
	{
		BottomRighrcornerX = x2;
		BottomRightcornerY = y2;
	}

	if (TopRightcornerX == x3 && TopRightcornerY > y3)
	{
		BottomRighrcornerX = x3;
		BottomRightcornerY = y3;
	}

	if (TopRightcornerX == x4 && TopRightcornerY > y4)
	{
		BottomRighrcornerX = x4;
		BottomRightcornerY = y4;
	}

	if (TopLeftcornerX == x1 && TopleftcornerY > y1)
	{
		BottomLeftcornerX = x1;
		BottomLeftcornerY = y1;
	}

	if (TopLeftcornerX == x2 && TopleftcornerY > y2)
	{
		BottomLeftcornerX = x2;
		BottomLeftcornerY = y2;
	}

	if (TopLeftcornerX == x3 && TopleftcornerY > y3)
	{
		BottomLeftcornerX = x3;
		BottomLeftcornerY = y3;
	}

	if (TopLeftcornerX == x4 && TopleftcornerY > y4)
	{
		BottomLeftcornerX = x4;
		BottomLeftcornerY = y4;
	} 

	if (TopLeftcornerX != BottomLeftcornerX || TopleftcornerY != TopRightcornerY)
	{
		printf("\nInvaild\n");
		exit(1);
	} 

	if (TopRightcornerX != BottomRighrcornerX )
	{
		printf("\nInvaild\n");
		exit(1);
	} 

	if (BottomLeftcornerY != BottomLeftcornerY)
	{
		printf("\nInvaild\n");
		exit(1);
	}


	printf("\n\n");

	printf("A");

	int toplength = TopRightcornerX - TopLeftcornerX; 

	if (toplength < 0)
	{
		printf("\nInvaild!");
		exit(1);
	}

	for (int index = 0; index < toplength; index++)
	{
		printf("--");
	}
	printf("B\n");

	int Sidelength = TopRightcornerY - BottomRightcornerY; 

	if (Sidelength < 0)
	{
		printf("\nInvaild");
		exit(1);
	}

	for (int index = 0; index < Sidelength; index++)
	{
		if (index == 0)
		{
			
			printf("\r|");
			for (int index = 0; index < toplength; index++)
			{
				printf("  ");
			}
		}
		printf("|\n\r|");
		for (int index = 0; index < toplength; index++)
		{
			printf("  ");
		}

	}

	for (int index = 0; index < toplength; index++)
	{
		printf("\b");
	}

	printf("\rC");

	for (int index = 0; index < toplength; index++)
	{

		printf("--");
	}



	printf("D");


	





}