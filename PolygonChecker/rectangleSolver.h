#pragma once

#define A 0 // Point A
#define B 1 // Point B
#define C 2 // Point C
#define D 3 // Point D
#define X 0 // X coordinate
#define Y 1 // Y coordinate

bool analyzeRectangle(int rectanglePoints[][2]);
bool findMatchingPoints(int x, int y, int rectanglePoints[][2]);
void sortPoints(int rectanglePoints[][2]);
void printRectangle(int rectanglePoints[][2]);
int getPerimeter(int rectanglePoints[][2]);
int getArea(int rectanglePoints[][2]);