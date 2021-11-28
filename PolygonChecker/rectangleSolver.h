#pragma once

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_POINTS 4
#define A 0
#define B 1
#define C 2
#define D 3

typedef struct point
{
	double x;
	double y;
} Point;

double getValidInput(char[]);
void getPoints(Point[]);
bool analyzePoints(Point[]);
void reorderPoints(Point[]);
bool checkOrthogonality(Point, Point, Point);
void sortPoints(Point[]);
void swap(Point[], int, int);
double distanceBetween(Point, Point);
double getPerimeter(Point[]);
double getArea(Point[]);