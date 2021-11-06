#include <stdio.h>
#include <stdbool.h>

#include "rectangleSolver.h"

bool analyzeRectangle(int rectanglePoints[][2]) { //took out for loop as checking for matching points once is enough
    if (!findMatchingPoints(rectanglePoints[X][X], rectanglePoints[X][Y], rectanglePoints)) {
        printf_s("Not a rectangle.\n");
        return false;
    }
        
    sortPoints(rectanglePoints);
    printRectangle(rectanglePoints);
    return true;
}

// Returns true if there are 4 matches (+2 self match).
bool findMatchingPoints(int x, int y, int rectanglePoints[][2]) {
    int matches = 0;
    for (int i = 0; i < 4; i++) {
        if (x == rectanglePoints[i][X])
            matches++;

        if (y == rectanglePoints[i][Y])
            matches++;
    }

    return matches == 4 ? true : false;
}

void sortPoints(int rectanglePoints[][2]) {
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