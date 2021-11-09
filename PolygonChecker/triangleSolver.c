
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3, bool* isTriangle) {
	char* result = "";
	if (!largestSide(side1, side2, side3))
	{
		result = "Not a triangle";
		*isTriangle = false; 
		
	}
	else if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
		*isTriangle = false;
		
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
		*isTriangle = true;
	}
	else if ((side1 == side2 && side1 != side3) ||
		(side1 == side3 && side1 != side2) ||
		(side2 == side3 && side2 != side1))
	{
		result = "Isosceles triangle";
		*isTriangle = true;
	}
	else {
		result = "Scalene triangle";
		*isTriangle = true;
	}

	return result;
}

bool largestSide(int side1, int side2, int side3)
{
	int largest = side1;
	bool smallerSidesAreBigger = lengthChecker(side1, side2, side3);
	if (side2 > largest)
	{
		largest = side2;
		smallerSidesAreBigger = lengthChecker(side2, side1, side3);
	}
	if (side3 > largest)
	{
		largest = side3;
		smallerSidesAreBigger = lengthChecker(side3, side1, side2);
	}
	return smallerSidesAreBigger;
}

bool lengthChecker(int big, int smaller1, int smaller2)
{
	bool smallerSidesAreBigger = false;
	if (big < (smaller1 + smaller2))
	{
		smallerSidesAreBigger = true;
	}
	return smallerSidesAreBigger;
}

void findingAngles(float side1, float side2, float side3, float* angle)
{
	const float PI = 3.141593;
	float temporary1 = (((side1 * side1) - (side2 * side2) - (side3 * side3)) / (-2 * side2 * side3));

	*angle = acos(temporary1);
	*angle = *angle * (180 / PI);

	return;
}
