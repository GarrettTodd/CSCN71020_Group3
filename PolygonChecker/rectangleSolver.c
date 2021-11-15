#include "rectangleSolver.h"

int getValidInput(char prompt[])
{
	int input, temp;
	while (1)
	{
		printf("%s", prompt);
		temp = scanf_s("%d", &input);

		// Checks if scanf didn't match any input and if the input contained any unwanted trailing characters.
		if (temp != 1 || getchar() != 10)
		{
			while (getchar() != '\n'); // Cleans stdin.
			printf("Invalid value entered, try again.\n");
		}
		else
			return input;
	}
}

void getPoints(Point points[])
{
	for (int i = 0; i < MAX_POINTS; i++)
	{
		printf("Enter point [%d]\n", i + 1);
		// Gets the input from user and assigns it to a point.
		points[i].x = getValidInput("X: ");
		points[i].y = getValidInput("Y: ");
	}
}

bool analyzePoints(Point points[])
{
	bool Orthogonal[3] = { false }; // Creates a new bool array to hold the return value of each checkOrthogonality.
	// Checks 3 points at a time and returns true if they form a 90 degree angle or are perpendicular.
	Orthogonal[0] = checkOrthogonality(points[A], points[B], points[C]) &&
		checkOrthogonality(points[B], points[C], points[D]) &&
		checkOrthogonality(points[C], points[D], points[A]);
	reorderPoints(points); // Changes the order of the points so that we can check every combination.

	Orthogonal[1] = checkOrthogonality(points[A], points[B], points[C]) &&
		checkOrthogonality(points[B], points[C], points[D]) &&
		checkOrthogonality(points[C], points[D], points[A]);
	reorderPoints(points);

	Orthogonal[2] = checkOrthogonality(points[A], points[B], points[C]) &&
		checkOrthogonality(points[B], points[C], points[D]) &&
		checkOrthogonality(points[C], points[D], points[A]);
	reorderPoints(points);
	sortPoints(points); // Sorts the points so that they are correctly arranged and to prevent any diagonal checks later.

	return Orthogonal[0] || Orthogonal[1] || Orthogonal[2] ? true : false; // Returns true if at least 1 check returned true.
}

void reorderPoints(Point points[])
{
	// Point 'D' is used as a constant and stays in the same position.
	Point tempPoint = points[A];
	points[A] = points[B];
	points[B] = points[C];
	points[C] = tempPoint;
}

bool checkOrthogonality(Point a, Point b, Point c)
{
	int angle = (b.x - a.x) * (b.x - c.x) +
		(b.y - a.y) * (b.y - c.y);
	return angle == 0 ? true : false; // Returns true if the angle is equal to 0, which indicates that
									  // point 'B' forms a 90 degree angle between 'A' and 'C'.
}

void sortPoints(Point points[])
{
	for (int i = 0; i < MAX_POINTS; i++)
		for (int j = i; j < MAX_POINTS; j++)
			if ((points[i].x > points[j].x))
				swap(points, i, j); // Sorts the points using the x coordinate.

	for (int i = 0; i < MAX_POINTS; i++)
		for (int j = i; j < MAX_POINTS; j++)
			if ((points[i].y > points[j].y) && (points[i].x == points[j].x))
				swap(points, i, j); // Sorts the points using the y coordinate with respect to the x coordinate.

	swap(points, C, D); // Swaps the last 2 points to prevent the points from connecting diagonally.
}

void swap(Point points[], int i, int j)
{
	Point tempPoint = points[i];
	points[i] = points[j];
	points[j] = tempPoint;
}

double distanceBetween(Point a, Point b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double getPerimeter(Point points[])
{
	return distanceBetween(points[A], points[B]) +
		distanceBetween(points[B], points[C]) +
		distanceBetween(points[C], points[D]) +
		distanceBetween(points[D], points[A]);
}

double getArea(Point points[])
{
	return distanceBetween(points[A], points[B]) *
		distanceBetween(points[B], points[C]);
}