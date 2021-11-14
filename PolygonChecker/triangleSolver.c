
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
		// This calls largestSide function, if it returns false then the 
		// three sides do not form a triangle.
	}
	else if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
		*isTriangle = false;
		// Checking to see if any side is less than or equal to zero
		// if so these side lengths can not form a triangle
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
		*isTriangle = true;
		// If all sides are equal to eachother than it is Equilateral
	}
	else if ((side1 == side2 && side1 != side3) ||
		(side1 == side3 && side1 != side2) ||
		(side2 == side3 && side2 != side1))
	{
		result = "Isosceles triangle";
		*isTriangle = true;
		// If two sides are equal but one is not then it is Isosceles
	}
	else {
		result = "Scalene triangle";
		*isTriangle = true;
		// Lastly if no sides are equal it is Scalene
	}

	return result;
}

bool largestSide(int side1, int side2, int side3)
{
	// This function determins what side length is longest
	// and calls lengthChecker accordingly then returns the output
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
	// This function has three values passed to it, largest side and the two smaller sides
	// It then compares the largest side to the sum of the two smaller sides,
	// If the two smaller sides are less than or equal to the largest side the
	// three sides can not form a triangle and will return false, else return true
	bool smallerSidesAreBigger = false;
	if (big < (smaller1 + smaller2))
	{
		smallerSidesAreBigger = true;
	}
	return smallerSidesAreBigger;
}

void findingAngles(float side1, float side2, float side3, float* angle)
{
	// This function is called in main, it is passed the three side lengths 
	// and one of the triangles angles by reference, it calculates and
	// sets then angle then main displays it. 
	const float PI = 3.141593;
	float temporary1 = (((side1 * side1) - (side2 * side2) - (side3 * side3)) / (-2 * side2 * side3));

	*angle = acos(temporary1);
	*angle = *angle * (180 / PI);

	return;
}
