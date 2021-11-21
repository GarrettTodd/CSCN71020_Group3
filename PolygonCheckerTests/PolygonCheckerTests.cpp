#include "pch.h"
#include "CppUnitTest.h"

#include <stdbool.h>

#define MAX_POINTS 4
#define A 0
#define B 1
#define C 2
#define D 3

extern "C"
{
	char* analyzeTriangle(double side1, double side2, double side3, bool*);
	bool largestSide(double, double, double);
	bool lengthChecker(double, double, double);
	void findingAngles(double, double, double, double*);

	typedef struct point
	{
		int x;
		int y;
	} Point;

	int getValidInput(char[]);
	void getPoints(Point[]);
	bool analyzePoints(Point[]);
	void reorderPoints(Point[]);
	bool checkOrthogonality(Point, Point, Point);
	void sortPoints(Point[]);
	void swap(Point[], int, int);
	double distanceBetween(Point, Point);
	double getPerimeter(Point[]);
	double getArea(Point[]);

}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
	TEST_CLASS(TriangleTests)
	{
	public:

		//analyzeTriangle
		TEST_METHOD(analyzeTriangle_Invalid)
		{
			//testing analyzeTriangle with invalid sides: 1 2 3
			// expected outcome of function: "Not a triangle"

			double triangleSides[3] = { 1, 2, 3 };
			char* Expected = "Not a triangle";
			bool isTriangle;
			char* Result = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2], &isTriangle);

			Assert::AreEqual(Expected, Result);


		}

		TEST_METHOD(analyzeTriangle_Zero)
		{
			// testing analyzeTriangle with an input of zero 
			// expected outcome of function: "Not a triangle"

			double triangleSides[3] = { 5, 0, 7 };
			char* Expected = "Not a triangle";
			bool isTriangle;
			char* Result = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2], &isTriangle);

			Assert::AreEqual(Expected, Result);

		}

		TEST_METHOD(analyzeTriangle_Negative)
		{
			// testing analyzeTriangle with an input of a negative number 
			// expected outcome of function: "Not a triangle"

			double triangleSides[3] = { -1, 1, 1 };
			char* Expected = "Not a triangle";
			bool isTriangle;
			char* Result = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2], &isTriangle);

			Assert::AreEqual(Expected, Result);

		}

		TEST_METHOD(analyzeTriangle_Scalene)
		{
			// testing analyzeTriangle with an inputs: of 5, 7, 10 
			// expected outcome of function: "Scalene triangle"

			double triangleSides[3] = { 5, 10, 7 };
			char* Expected = "Scalene triangle";
			bool isTriangle;
			char* Result = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2], &isTriangle);

			Assert::AreEqual(Expected, Result);

		}

		TEST_METHOD(analyzeTriangle_Equilateral)
		{
			// testing analyzeTriangle with an inputs: of 7, 7, 7 
			// expected outcome of function: "Equilateral triangle"

			double triangleSides[3] = { 7, 7, 7 };
			char* Expected = "Equilateral triangle";
			bool isTriangle;
			char* Result = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2], &isTriangle);

			Assert::AreEqual(Expected, Result);

		}

		TEST_METHOD(analyzeTriangle_Isosceles)
		{
			// testing analyzeTriangle with an inputs: of 6, 8, 6 
			// expected outcome of function: "Isosceles triangle"

			double triangleSides[3] = { 6, 8, 6 };
			char* Expected = "Isosceles triangle";
			bool isTriangle;
			char* Result = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2], &isTriangle);

			Assert::AreEqual(Expected, Result);

		}

		TEST_METHOD(analyzeTriangle_isTriangle_True)
		{
			// testing analyzeTriangle to create a equailatoral triangle where isTriangle is true 
			// expected outcome of function: isTriangle should be true

			double triangleSides[3] = { 7, 7, 7 };
			bool Expected = true;
			bool isTriangle;
			analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2], &isTriangle);

			Assert::AreEqual(Expected, isTriangle);

		}

		TEST_METHOD(analyzeTriangle_isTriangle_False)
		{
			// testing analyzeTriangle to create a invaild triangle where isTriangle is false 
			// expected outcome of function: isTriangle should be false

			double triangleSides[3] = { 1, 2, 3 };
			bool Expected = false;
			bool isTriangle = true;
			analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2], &isTriangle);

			Assert::AreEqual(Expected, isTriangle);

		}

		//findingAngles 

		TEST_METHOD(findingAngles_Scalene_angle1)
		{
			// testing findingAngles to create a the first angle of a scalene
			// expected outcome of function:40.535797641604667 

			double triangleSides[3] = { 7, 5, 10 };
			double Expected = 40.535797641604667;

			double angle;
			findingAngles(triangleSides[0], triangleSides[1], triangleSides[2], &angle);
			Assert::AreEqual(Expected, angle);




		}

		TEST_METHOD(findingAngles_Scalene_angle2)
		{
			// testing findingAngles to create a the second angle of a scalene
			// expected outcome of function:111.80373566125496 

			double triangleSides[3] = { 7, 5, 10 };
			double Expected = 111.80373566125496;


			double angle;
			findingAngles(triangleSides[2], triangleSides[0], triangleSides[1], &angle);
			Assert::AreEqual(Expected, angle);




		}


		TEST_METHOD(findingAngles_Scalene_angle3)
		{
			// testing findingAngles to create a the Third angle of a scalene
			// expected outcome of function:27.660446849299753

			double triangleSides[3] = { 7, 5, 10 };
			double Expected = 27.660446849299753;



			double angle;
			findingAngles(triangleSides[1], triangleSides[2], triangleSides[0], &angle);
			Assert::AreEqual(Expected, angle);




		}

		TEST_METHOD(findingAngles_Equilatoral_angle1)
		{
			// testing findingAngles to create a the first angle of a Equilatoral
			// expected outcome of function:59.999993384053134

			double triangleSides[3] = { 7, 7, 7 };
			double Expected = 59.999993384053134;

			double angle;
			findingAngles(triangleSides[0], triangleSides[1], triangleSides[2], &angle);
			Assert::AreEqual(Expected, angle);




		}

		TEST_METHOD(findingAngles_Equilatoral_angle2)
		{
			// testing findingAngles to create a the second angle of a Equilatoral
			// expected outcome of function:59.999993384053134 

			double triangleSides[3] = { 7, 7, 7 };
			double Expected = 59.999993384053134;

			double angle;
			findingAngles(triangleSides[2], triangleSides[0], triangleSides[1], &angle);
			Assert::AreEqual(Expected, angle);




		}

		TEST_METHOD(findingAngles_Equilatoral_angle3)
		{
			// testing findingAngles to create a the third angle of a Equilatoral
			// expected outcome of function:59.999993384053134 

			double triangleSides[3] = { 7, 7, 7 };
			double Expected = 59.999993384053134;

			double angle;
			findingAngles(triangleSides[1], triangleSides[2], triangleSides[0], &angle);
			Assert::AreEqual(Expected, angle);




		}


		TEST_METHOD(findingAngles_Isosceles_angle1)
		{
			// testing findingAngles to create a the first angle of a Isosceles
			// expected outcome of function:48.189679790548134

			double triangleSides[3] = { 6, 6, 8 };
			double Expected = 48.189679790548134;

			double angle;
			findingAngles(triangleSides[0], triangleSides[1], triangleSides[2], &angle);
			Assert::AreEqual(Expected, angle);




		}


		TEST_METHOD(findingAngles_Isosceles_angle2)
		{
			// testing findingAngles to create a the second angle of a Isosceles
			// expected outcome of function:83.620620571063128

			double triangleSides[3] = { 6, 6, 8 };
			double Expected = 83.620620571063128;

			double angle;
			findingAngles(triangleSides[2], triangleSides[0], triangleSides[1], &angle);
			Assert::AreEqual(Expected, angle);




		}

		TEST_METHOD(findingAngles_Isosceles_angle3)
		{
			// testing findingAngles to create a the third angle of a Isosceles
			// expected outcome of function:48.189679790548134

			double triangleSides[3] = { 6, 6, 8 };
			double Expected = 48.189679790548134;

			double angle;
			findingAngles(triangleSides[1], triangleSides[2], triangleSides[0], &angle);
			Assert::AreEqual(Expected, angle);

			
		}

		//Testing largestSide

		TEST_METHOD(largestSide_invalid)
		{
			// testing LargestSide() to with invaild side lengths
			// expected outcome of function:False

			double triangleSides[3] = { 8, 7, 1 };
			bool NotEqual = true;
			bool result;
			result = largestSide(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreNotEqual(NotEqual, result);

			
			


		}

		TEST_METHOD(largestSide_Scalene)
		{
			// testing LargestSide() with 8,9,4 that form a scalene triangle 
			// to verify the sum of the smaller sides are larger than the largest side
			// expected outcome of function:True

			double triangleSides[3] = { 8, 9, 4 };
			bool Expected = true;
			bool result;
			result = largestSide(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual(Expected , result);





		}
		TEST_METHOD(largestSide_Equilatoral)
		{
			// testing LargestSide() with 7,7,7 that form a Equilatoral triangle 
			// to verify the sum of the smaller sides are larger than the largest side
			// expected outcome of function:True

			double triangleSides[3] = { 7, 7, 7};
			bool NotExpected = false;
			bool result;
			result = largestSide(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreNotEqual(NotExpected, result);





		}

		TEST_METHOD(largestSide_Isosceles)
		{
			// testing LargestSide() with 6,6,8 that form a isosceles triangle 
			// to verify the sum of the smaller sides are larger than the largest side
			// expected outcome of function:True

			double triangleSides[3] = { 6, 6, 8 };
			bool NotExpected = false;
			bool result;
			result = largestSide(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreNotEqual(NotExpected, result);





		}

	};

	TEST_CLASS(RectangleTests)
	{
	public:

		TEST_METHOD(distanceBetween_TwoDiffPoints)
		{
			Point a; 
			a.x = 6;
			a.y = 10;
			Point b;
			b.x = 12;
			b.y = 4;

			double expected = 8.485;
			double result = distanceBetween(a,b);

			Assert::AreEqual(expected, result, 3);
		}
		TEST_METHOD(distanceBetween_SamePoints)
		{
			Point a;
			a.x = 7;
			a.y = -4;
			Point b;
			b.x = 7;
			b.y = -4;

			double expected = 0.0;
			double result = distanceBetween(a, b);

			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(distanceBetween_NegativeOnlyPoints)
		{
			Point a;
			a.x = -7;
			a.y = -15;
			Point b;
			b.x = -23;
			b.y = -4;

			double expected = 19.416488;
			double result = distanceBetween(a, b);

			Assert::AreEqual(expected, result, 3);
		}
		TEST_METHOD(distanceBetween_NegativeAndPositivePoints)
		{
			Point a;
			a.x = 14;
			a.y = -31;
			Point b;
			b.x = -9;
			b.y = 17;

			double expected = 53.225934;
			double result = distanceBetween(a, b);

			Assert::AreEqual(expected, result, 3);
		}
		TEST_METHOD(getPerimeter_NonRectangle)
		{
			Point points[4];
			points[0].x = 6;
			points[0].y = 10;
			points[1].x = 12;
			points[1].y = 4;
			points[2].x = 2;
			points[2].y = -6;
			points[3].x = -2;
			points[3].y = 5;

			double expected = 43.766;
			double result = getPerimeter(points);

			Assert::AreEqual(expected, result, 3);
		}
		TEST_METHOD(getPerimeter_DiagonalLineRectangle)
		{
			Point points[4];
			points[0].x = 6;
			points[0].y = 10;
			points[1].x = 12;
			points[1].y = 4;
			points[2].x = 4;
			points[2].y = -4;
			points[3].x = -2;
			points[3].y = 2;

			double expected = 39.598;
			double result = getPerimeter(points);

			Assert::AreEqual(expected, result, 3);
		}
		TEST_METHOD(getPerimeter_HorizontalandVerticalLineRectangle_66)
		{
			Point points[4];
			points[0].x = 3;
			points[0].y = 15;
			points[1].x = -7;
			points[1].y = 15;
			points[2].x = -7;
			points[2].y = -8;
			points[3].x = 3;
			points[3].y = -8;

			double expected = 66.000;
			double result = getPerimeter(points);

			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(getPerimeter_PointsEnteredAreSame_0)
		{
			Point points[4];
			points[0].x = 4;
			points[0].y = 9;
			points[1].x = 4;
			points[1].y = 9;
			points[2].x = 4;
			points[2].y = 9;
			points[3].x = 4;
			points[3].y = 9;

			double expected = 0.0;
			double result = getPerimeter(points);

			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(getArea_DiagonalLineRectangle_96)
		{
			Point points[3];
			points[0].x = 6;
			points[0].y = 10;
			points[1].x = -2;
			points[1].y = 2;
			points[2].x = 4;
			points[2].y = -4;
	
			double expected = 96.000;
			double result = getArea(points);

			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(getArea_HorizontalandVerticalLineRectangle_230)
		{	
			//assume points have been sorted as the sorting takes place before this function is called in program
			Point points[3];
			points[0].x = 3;
			points[0].y = 15;
			points[1].x = -7;
			points[1].y = 15;
			points[2].x = -7;
			points[2].y = -8;

			double expected = 230.000;
			double result = getArea(points);

			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(checkOrthogonality_DiagonalLineRectangle)
		{
			Point points[3];
			points[0].x = 6;
			points[0].y = 10;
			points[1].x = -2;
			points[1].y = 2;
			points[2].x = 4;
			points[2].y = -4;

			Assert::IsTrue(checkOrthogonality(points[0], points[1], points[2]));
		}
		TEST_METHOD(checkOrthogonality_VerticalAndHorizontalLineRectangle)
		{
			Point points[3];
			points[0].x = 3;
			points[0].y = 15;
			points[1].x = -7;
			points[1].y = 15;
			points[2].x = -7;
			points[2].y = -8;

			Assert::IsTrue(checkOrthogonality(points[0], points[1], points[2]));
		}
		TEST_METHOD(checkOrthogonality_AcuteAngle)
		{
			Point points[3];
			points[0].x = 3;
			points[0].y = 15;
			points[1].x = -7;
			points[1].y = 15;
			points[2].x = -2;
			points[2].y = -8;

			Assert::IsFalse(checkOrthogonality(points[0], points[1], points[2]));
		}
		TEST_METHOD(checkOrthogonality_ObtuseAngle)
		{
			Point points[3];
			points[0].x = 3;
			points[0].y = 15;
			points[1].x = -7;
			points[1].y = 15;
			points[2].x = -18;
			points[2].y = -8;

			Assert::IsFalse(checkOrthogonality(points[0], points[1], points[2]));
		}
		TEST_METHOD(checkOrthogonality_StraightAngle)
		{
			Point points[3];
			points[0].x = 3;
			points[0].y = 15;
			points[1].x = -7;
			points[1].y = 15;
			points[2].x = -11;
			points[2].y = -15;

			Assert::IsFalse(checkOrthogonality(points[0], points[1], points[2]));
		}
		TEST_METHOD(analyzePoints_DiagonalLineRectangle)
		{
			Point points[4];
			points[0].x = 6;
			points[0].y = 10;
			points[1].x = 12;
			points[1].y = 4;
			points[2].x = 4;
			points[2].y = -4;
			points[3].x = -2;
			points[3].y = 2;

			Assert::IsTrue(analyzePoints(points));
		}
		TEST_METHOD(analyzePoints_VerticalAndHorizontalLineRectangle)
		{
			Point points[4];
			points[0].x = 3;
			points[0].y = 15;
			points[1].x = -7;
			points[1].y = 15;
			points[2].x = -7;
			points[2].y = -8;
			points[3].x = 3;
			points[3].y = -8;

			Assert::IsTrue(analyzePoints(points));
		}
		TEST_METHOD(analyzePoints_NonRectangle)
		{
			Point points[4];
			points[0].x = 2;
			points[0].y = 9;
			points[1].x = 0;
			points[1].y = 12;
			points[2].x = -7;
			points[2].y = 2;
			points[3].x = 4;
			points[3].y = -2;

			Assert::IsFalse(analyzePoints(points));
		}
		TEST_METHOD(analyzePoints_DiagonalLineRectangle_PointsNotInOrder)
		{
			Point points[4];
			points[0].x = 6;
			points[0].y = 10;
			points[1].x = 4;
			points[1].y = -4;
			points[2].x = -2;
			points[2].y = 2;
			points[3].x = 12;
			points[3].y = 4;

			Assert::IsTrue(analyzePoints(points));
		}
		TEST_METHOD(analyzePoints_VerticalAndHorizontalLineRectangle_PointsNotInOrder)
		{
			Point points[4];
			points[0].x = 3;
			points[0].y = 15;
			points[1].x = -7;
			points[1].y = -8;
			points[2].x = 3;
			points[2].y = -8;
			points[3].x = -7;
			points[3].y = 15;

			Assert::IsTrue(analyzePoints(points));
		}
		TEST_METHOD(analyzePoints_AllSamePoints)
		{
			Point points[4];
			points[0].x = 17;
			points[0].y = -15;
			points[1].x = 17;
			points[1].y = -15;
			points[2].x = 17;
			points[2].y = -15;
			points[3].x = 17;
			points[3].y = -15;

			Assert::IsFalse(analyzePoints(points));
		}
	};

	TEST_CLASS(MiscellaneousTests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};
}

