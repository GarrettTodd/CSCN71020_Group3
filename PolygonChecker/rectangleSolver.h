#pragma once

#define A 0
#define B 1
#define C 2
#define D 3
#define X 0
#define Y 1

bool analyzeRectangle(int rectanglePoints[][2]);
bool findMatchingPoints(int x, int y, int rectanglePoints[][2]);
void sortPoints(int rectanglePoints[][2]);
void printRectangle(int rectanglePoints[][2]);
int getPerimeter(int rectanglePoints[][2]);
int getArea(int rectanglePoints[][2]);