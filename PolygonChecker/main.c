#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
			bool isTriangle;
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &isTriangle);
			printf_s("%s\n", result);
			if (isTriangle)
			{
				float angle[3];
				findingAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &angle[0]);
				findingAngles(triangleSidesPtr[2], triangleSidesPtr[0], triangleSidesPtr[1], &angle[1]);
				findingAngles(triangleSidesPtr[1], triangleSidesPtr[2], triangleSidesPtr[0], &angle[2]);
				printf("The angles of your triangle are: %f, %f, %f\n", angle[0], angle[1], angle[2]);
			}
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
	int TopleftcornerY = 0;
	int TopRightcornerY =0;
	int TopLeftcornerX = 0;
	int TopRightcornerX =0;
	int BottomRightcornerY=0;
	int BottomRighrcornerX=0;
	int BottomLeftcornerY=0;
	int BottomLeftcornerX=0;
	printf("\n");
	printf("Enter your First X coordinate: ");

	if (scanf("%d", &x1) != 1) // checking to see if input is an integer
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

	if (x1 == x2 && y1 == y2) // checking to make sure points aren't equal
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

	if (x1 < 0 || x2 < 0 || x3 < 0 || x4 < 0 || y1 < 0 || y2 < 0 || y3 < 0 || y4 < 0) //checking to make sure input is not negative
	{
		printf("\nInvaild!\n");

		exit(1);
	}


	if (y1 >= y2 && y1 >= y3 && y1 >= y4) //finding topleft
	{
		if (x1 <= x2 && x1 <= x3 && x1 <= x4)
		{
			TopleftcornerY = y1;
			TopLeftcornerX = x1;
			
		} 
		
	}

	else if (y2 >= y1 && y2 >= y3 && y2 >= y4) 
	{
	
		if (x2 <= x1 && x2 <= x3 && x2 <= x4)
		{
			TopleftcornerY = y2;
			TopLeftcornerX = x2;
			
		}
	}

	else if (y3 >= y1 && y3 >= y2 && y3 >= y4) 
	{
	
		if (x3 <= x1 && x3 <= x2 && x3 <= x4)
		{
			TopleftcornerY = y3;
			TopLeftcornerX = x3;
			
		}
	}

	else if (y4 >= y1 && y4 >= y2 && y4 >= y3)
	{
		if (x4 <= x1 && x4 <= x2 && x4 <= x3)
		{
			TopleftcornerY = y4;
			TopLeftcornerX = x4;
			
		}
	}

	else 
	{
	
		printf("\nInvaild!");
		exit(1);
	
	}




	if (TopleftcornerY == y1 && TopLeftcornerX < x1) //finding top right
	{
		TopRightcornerY = y1;
		TopRightcornerX = x1;
		
	}

	else if (TopleftcornerY == y2 && TopLeftcornerX < x2)
	{
		TopRightcornerY = y2;
		TopRightcornerX = x2;
		

	}

	else if (TopleftcornerY == y3 && TopLeftcornerX < x3)
	{
		TopRightcornerY = y3;
		TopRightcornerX = x3;
		

	}


	else if (TopleftcornerY == y4 && TopLeftcornerX < x4)
	{
		TopRightcornerY = y4;
		TopRightcornerX = x4;
		
	} 
	else
	{
		printf("\nInvaild!");
		exit(1);
	}


	if (TopRightcornerX == x1 && TopRightcornerY > y1) //finding bottom right
	{
		BottomRighrcornerX = x1;
		BottomRightcornerY = y1;
	}

	else if (TopRightcornerX == x2 && TopRightcornerY > y2)
	{
		BottomRighrcornerX = x2;
		BottomRightcornerY = y2;
	}

	else if (TopRightcornerX == x3 && TopRightcornerY > y3)
	{
		BottomRighrcornerX = x3;
		BottomRightcornerY = y3;
	}

	else if (TopRightcornerX == x4 && TopRightcornerY > y4)
	{
		BottomRighrcornerX = x4;
		BottomRightcornerY = y4;
	}
	else
	{
		printf("\nInvaild!");
		exit(1);
	}

	if (TopLeftcornerX == x1 && TopleftcornerY > y1) //finding bottom left
	{
		BottomLeftcornerX = x1;
		BottomLeftcornerY = y1;
	}

	else if (TopLeftcornerX == x2 && TopleftcornerY > y2)
	{
		BottomLeftcornerX = x2;
		BottomLeftcornerY = y2;
	}

	else if (TopLeftcornerX == x3 && TopleftcornerY > y3)
	{
		BottomLeftcornerX = x3;
		BottomLeftcornerY = y3;
	}

	else if (TopLeftcornerX == x4 && TopleftcornerY > y4)
	{
		BottomLeftcornerX = x4;
		BottomLeftcornerY = y4;
	} 
	else
	{
		printf("\nInvaild!");
		exit(1);
	}

	if (TopLeftcornerX != BottomLeftcornerX || TopleftcornerY != TopRightcornerY) // checking if corners align
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
	// creating rectangle
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