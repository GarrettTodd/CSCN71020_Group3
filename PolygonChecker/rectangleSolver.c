#include <stdio.h>
#include <stdbool.h>

#include "rectangleSolver.h"

//compares each point with the other points to make sure they create a rectangle
//x-and-y coordinates to form a rectangle must match up in a particular way to create the shape
bool analyzeRectangle(int rectanglePoints[][2]) { 
    for (int i = 0; i < 4; i++)
    {   //if matches is not 4, then a rectangle can not be formed
        if (!findMatchingPoints(rectanglePoints[i][X], rectanglePoints[i][Y], rectanglePoints)) {
            printf_s("Not a rectangle.\n");
            return false;
        }
    }
        
    sortPoints(rectanglePoints);
    printRectangle(rectanglePoints);
    return true;
}

// Returns true if there are 4 matches (+2 self match).
bool findMatchingPoints(int x, int y, int rectanglePoints[][2]) {
    int matches = 0;
    for (int i = 0; i < 4; i++) {
        // Checks the X coordinate of the point if it matches with the rectangle X coordinates.
        if (x == rectanglePoints[i][X])
            matches++;

        // Checks the Y coordinate of the point if it matches with the rectangle Y coordinates.
        if (y == rectanglePoints[i][Y])
            matches++;
    }

    return matches == 4 ? true : false;
}

void sortPoints(int rectanglePoints[][2]) {
    // Sort the X coordinates of the point.
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            if (rectanglePoints[i][X] > rectanglePoints[j][X]) {
                int tempX = rectanglePoints[i][X];
                int tempY = rectanglePoints[i][Y];

                rectanglePoints[i][X] = rectanglePoints[j][X];
                rectanglePoints[i][Y] = rectanglePoints[j][Y];

                rectanglePoints[j][X] = tempX;
                rectanglePoints[j][Y] = tempY;
            }
        }
    }

    // Sort the Y coordinates of the point with respect to the X coordinate.
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            if ((rectanglePoints[i][0] == rectanglePoints[j][0]) && (rectanglePoints[i][1] > rectanglePoints[j][1])) {
                int tempX = rectanglePoints[i][0];
                int tempY = rectanglePoints[i][1];

                rectanglePoints[i][0] = rectanglePoints[j][0];
                rectanglePoints[i][1] = rectanglePoints[j][1];

                rectanglePoints[j][0] = tempX;
                rectanglePoints[j][1] = tempY;
            }
        }
    }
}

/*
    A --- B
    |     |
    |     |
    C --- D

    Width = B - A
    Height = C - A
*/
void printRectangle(int rectanglePoints[][2]) {
    int width = rectanglePoints[B][Y] - rectanglePoints[A][Y];
    int height = rectanglePoints[C][X] - rectanglePoints[A][X];

    for (int w = 0; w < width; w++) {
        printf_s("#");
    } printf_s("\n");

    if (height > 2) {
        for (int h = 2; h < height; h++) {
            printf_s("#");
            for (int s = 0; s < width - 2; ++s) {
                printf_s(" ");
            }
            printf_s("#\n");
        }
    }

    for (int w = 0; w < width; w++) {
        printf_s("#");
    } printf_s("\n");
}

int getPerimeter(int rectanglePoints[][2]) {
    int width = rectanglePoints[B][Y] - rectanglePoints[A][Y];
    int height = rectanglePoints[C][X] - rectanglePoints[A][X];

    return 2 * (width + height);
}

int getArea(int rectanglePoints[][2]) {
    int width = rectanglePoints[B][Y] - rectanglePoints[A][Y];
    int height = rectanglePoints[C][X] - rectanglePoints[A][X];

    return width * height;
}