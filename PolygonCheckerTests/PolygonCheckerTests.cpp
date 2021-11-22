#include "pch.h"
#include "CppUnitTest.h"

#include <stdbool.h>
#include <math.h>
#include <float.h>

extern "C"
{
	#include <rectangleSolver.h>
	#include <triangleSolver.h>
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
			// expected outcome of function:40.5358

			double triangleSides[3] = { 7, 5, 10 };
			double Expected = 40.5358;
			

			double angle;
			findingAngles(triangleSides[0], triangleSides[1], triangleSides[2], &angle);

			Assert::IsTrue(fabs(angle - Expected) < 0.0001);




		}

		TEST_METHOD(findingAngles_Scalene_angle2)
		{
			// testing findingAngles to create a the second angle of a scalene
			// expected outcome of function:111.804

			double triangleSides[3] = { 7, 5, 10 };
			double Expected = 111.804;


			double angle;
			findingAngles(triangleSides[2], triangleSides[0], triangleSides[1], &angle);
			Assert::IsTrue(fabs(angle - Expected) < 0.001);




		}


		TEST_METHOD(findingAngles_Scalene_angle3)
		{
			// testing findingAngles to create a the Third angle of a scalene
			// expected outcome of function:27.66044

			double triangleSides[3] = { 7, 5, 10 };
			double Expected = 27.6604;



			double angle;
			findingAngles(triangleSides[1], triangleSides[2], triangleSides[0], &angle);
			Assert::IsTrue(fabs(angle - Expected) < 0.0001);




		}

		TEST_METHOD(findingAngles_Equilatoral_angle1)
		{
			// testing findingAngles to create a the first angle of a Equilatoral
			// expected outcome of function:60

			double triangleSides[3] = { 7, 7, 7 };
			double Expected = 60;

			double angle;
			findingAngles(triangleSides[0], triangleSides[1], triangleSides[2], &angle);
			Assert::IsTrue(fabs(angle - Expected) < 0.00001);




		}

		TEST_METHOD(findingAngles_Equilatoral_angle2)
		{
			// testing findingAngles to create a the second angle of a Equilatoral
			// expected outcome of function:60

			double triangleSides[3] = { 7, 7, 7 };
			double Expected = 60;

			double angle;
			findingAngles(triangleSides[2], triangleSides[0], triangleSides[1], &angle);
			Assert::IsTrue(fabs(angle - Expected) < 0.00001);




		}

		TEST_METHOD(findingAngles_Equilatoral_angle3)
		{
			// testing findingAngles to create a the third angle of a Equilatoral
			// expected outcome of function:60 

			double triangleSides[3] = { 7, 7, 7 };
			double Expected = 60;

			double angle;
			findingAngles(triangleSides[1], triangleSides[2], triangleSides[0], &angle);
			Assert::IsTrue(fabs(angle - Expected) < 0.00001);




		}


		TEST_METHOD(findingAngles_Isosceles_angle1)
		{
			// testing findingAngles to create a the first angle of a Isosceles
			// expected outcome of function:48.1897

			double triangleSides[3] = { 6, 6, 8 };
			double Expected = 48.1897;

			double angle;
			findingAngles(triangleSides[0], triangleSides[1], triangleSides[2], &angle);
			Assert::IsTrue(fabs(angle - Expected) < 0.0001);




		}


		TEST_METHOD(findingAngles_Isosceles_angle2)
		{
			// testing findingAngles to create a the second angle of a Isosceles
			// expected outcome of function:83.6206

			double triangleSides[3] = { 6, 6, 8 };
			double Expected = 83.6206;

			double angle;
			findingAngles(triangleSides[2], triangleSides[0], triangleSides[1], &angle);
			Assert::IsTrue(fabs(angle - Expected) < 0.0001);




		}

		TEST_METHOD(findingAngles_Isosceles_angle3)
		{
			// testing findingAngles to create a the third angle of a Isosceles
			// expected outcome of function:48.1897

			double triangleSides[3] = { 6, 6, 8 };
			double Expected = 48.1897;

			double angle;
			findingAngles(triangleSides[1], triangleSides[2], triangleSides[0], &angle);
			Assert::IsTrue(fabs(angle - Expected) < 0.0001);

			
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

		//testing lengthChecker 
		TEST_METHOD(lengthChecker_Invaild_Smaller)
		{
			// testing lengthChecker() with largest side being 9 and smaller sides being 7 and 1 
			// the sum of the smaller sides are smaller than the largest side should not create a triangle
			// expected outcome of function:false

			double triangleSides[3] = { 9, 7, 1 };
			bool Expected = false;
			bool result;
			result = lengthChecker(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual(Expected, result);





		}

		TEST_METHOD(lengthChecker_Vaild)
		{
			// testing lengthChecker() with largest side being 9 and smaller sides being 9 and 1 
			//  the sum of the smaller sides will be larger than the largest side and should create a triangle
			// expected outcome of function:True

			double triangleSides[3] = { 9, 9, 1 };
			bool Expected = true;
			bool result;
			result = lengthChecker(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual(Expected, result);





		}

		TEST_METHOD(lengthChecker_Invaild_Equal)
		{
			// testing lengthChecker() with largest side being 9 and smaller sides being 8 and 1 
			//  the sum of the smaller sides will be equal to the largest side and should not create a triangle
			// expected outcome of function:false

			double triangleSides[3] = { 9, 8, 1 };
			bool Expected = false;
			bool result;
			result = lengthChecker(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual(Expected, result);





		}


	};

	TEST_CLASS(RectangleTests)
	{
	public:

		//Testing distanceBetween()
		TEST_METHOD(distanceBetween_PositiveOnlyPoints_PositiveLength)
		{
			//testing the distanceBetween() function of 2 random positive points
			//it will return the shortest possible length between these two points which should be 8.485 
			//a 3rd parameter for AreEqual() is used to determine precision to avoid a failing test case due to precision
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

		TEST_METHOD(distanceBetween_SamePoints_ZeroLength)
		{
			//testing the distanceBetween() function of 2 points that are the same
			//it should return 0 as there is no distance between them
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

		TEST_METHOD(distanceBetween_NegativeOnlyPoints_PositiveLength)
		{
			//testing the distanceBetween() function of 2 random negative points
			//it will return the shortest possible length between these two points which should be 19.416488 
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

		TEST_METHOD(distanceBetween_NegativeAndPositivePoints_PositiveLength)
		{
			//testing the distanceBetween() function of 2 points that have both positive and negative values
			//it will return the shortest possible length between these two points which should be 53.225934 
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

		//Testing getPerimeter()
		TEST_METHOD(getPerimeter_NonRectangle_PositiveValuePerimeter)
		{
			//testing the getPerimeter() function of points that do not form a rectangle
			//It should return 43.766 as the shapes perimeter
			//A 3rd parameter is used for AreEqual() for precision to avoid a failing test case due to precision
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

		TEST_METHOD(getPerimeter_DiagonalLineRectangle_PositivePerimeterValue)
		{
			//testing the getPerimeter() function of points that do form a rectangle with only diagonal lines
			//It should return 39.598 as the shapes perimeter
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

		TEST_METHOD(getPerimeter_HorizontalandVerticalLineRectangle_PostivePerimeterValue)
		{
			//testing the getPerimeter() function of points that do form a rectangle with only vertical and horizontal lines
			//It should return 66.000 as the shapes perimeter
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

		TEST_METHOD(getPerimeter_PointsEnteredAreSame_ZeroPerimeter)
		{
			//testing the getPerimeter() function of points that are all the same
			//It should return 0.0 as the shapes perimeter as the points do not create a shape
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

		//Testing getArea()
		//only 2 cases is performed as area is calculated after shape is confirmed to be a rectangle
		TEST_METHOD(getArea_DiagonalLineRectangle_PositiveAreaValue)
		{
			//testing the getArea() function of points that create a diagonal line rectangle
			//it should return 96.000 as the shapes area
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

		TEST_METHOD(getArea_HorizontalandVerticalLineRectangle_PositiveAreaValue)
		{	
			//testing the getArea() function of points that create a vertical and horizontal line rectangle
			//it should return 230.000 as the shapes area
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

		//Testing checkOrthogonality()
		TEST_METHOD(checkOrthogonality_DiagonalLineRectangle_True)
		{
			//Testing the checkOrthogonality() function of 3 points that can create a diagonal line rectangle
			//Function returns true only if the 1st and 3rd points intersect with the 2nd point in a way that would create a 90 degree angle
			Point points[3];
			points[0].x = 6;
			points[0].y = 10;
			points[1].x = -2;
			points[1].y = 2;
			points[2].x = 4;
			points[2].y = -4;

			Assert::IsTrue(checkOrthogonality(points[0], points[1], points[2]));
		}

		TEST_METHOD(checkOrthogonality_VerticalAndHorizontalLineRectangle_True)
		{
			//Testing the checkOrthogonality() function of 3 points that can create a vertical and horizontal line rectangle
			//Function returns true only if the 1st and 3rd points intersect with the 2nd point in a way that would create a 90 degree angle
			Point points[3];
			points[0].x = 3;
			points[0].y = 15;
			points[1].x = -7;
			points[1].y = 15;
			points[2].x = -7;
			points[2].y = -8;

			Assert::IsTrue(checkOrthogonality(points[0], points[1], points[2]));
		}

		TEST_METHOD(checkOrthogonality_AcuteAngle_False)
		{
			//Testing the checkOrthogonality() function of 3 points when connected, would create an acute angle
			//Function returns false if the 1st and 3rd points intersect the 2nd point in a way that would not create a 90 degree angle
			Point points[3];
			points[0].x = 3;
			points[0].y = 15;
			points[1].x = -7;
			points[1].y = 15;
			points[2].x = -2;
			points[2].y = -8;

			Assert::IsFalse(checkOrthogonality(points[0], points[1], points[2]));
		}

		TEST_METHOD(checkOrthogonality_ObtuseAngle_False)
		{
			//Testing the checkOrthogonality() function of 3 points when connected, would create an obtuse angle
			//Function returns false if the 1st and 3rd points intersect the 2nd point in a way that would not create a 90 degree angle
			Point points[3];
			points[0].x = 3;
			points[0].y = 15;
			points[1].x = -7;
			points[1].y = 15;
			points[2].x = -18;
			points[2].y = -8;

			Assert::IsFalse(checkOrthogonality(points[0], points[1], points[2]));
		}

		TEST_METHOD(checkOrthogonality_StraightAngle_False)
		{
			//Testing the checkOrthogonality() function of 3 points when connected, would create a straight angle (straight line)
			//Function returns false if the 1st and 3rd points intersect the 2nd point in a way that would not create a 90 degree angle
			Point points[3];
			points[0].x = 3;
			points[0].y = 15;
			points[1].x = -7;
			points[1].y = 15;
			points[2].x = -11;
			points[2].y = -15;

			Assert::IsFalse(checkOrthogonality(points[0], points[1], points[2]));
		}

		TEST_METHOD(checkOrthogonality_NegativeValuePointOnly_True)
		{
			//Testing the checkOrthogonality() function of 3 points of only negative coordinates that can create a vertical and horizontal line rectangle
			//Function returns true only if the 1st and 3rd points intersect with the 2nd point in a way that would create a 90 degree angle
			Point points[3];
			points[0].x = -13;
			points[0].y = -5;
			points[1].x = -7;
			points[1].y = -5;
			points[2].x = -7;
			points[2].y = -18;

			Assert::IsTrue(checkOrthogonality(points[0], points[1], points[2]));
		}

		//Testing analyzePoints()
		TEST_METHOD(analyzePoints_DiagonalLineRectangle_True)
		{
			//testing the analyzePoints() function of points that create a diagonal line rectangle
			//checks different combinations of these points to see if any form 90 degree angles with eachother
			//returns true if when all points are connected, they each form a 90 degree angle indicating a rectangle
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

		TEST_METHOD(analyzePoints_VerticalAndHorizontalLineRectangle_True)
		{
			//testing the analyzePoints() function of points that create a vertical and horizontal line rectangle
			//returns true if when all points are connected, they each form a 90 degree angle indicating a rectangle
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

		TEST_METHOD(analyzePoints_NonRectangle_False)
		{
			//testing the analyzePoints() function of points that don't create a rectangle
			//returns false if when all points are connecting, not all of them form 90 degree angles indicating a non-rectangle
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

		TEST_METHOD(analyzePoints_DiagonalLineRectanglePointsNotInOrder_True)
		{
			//testing the analyzePoints() function of points that create a diagonal line rectangle but inputted out of order
			//creates multiple combinations of these points to see if the shape made creates 90 degree angles
			//returns true if one or more combinations show all points having 90 degree angles
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

		TEST_METHOD(analyzePoints_VerticalAndHorizontalLineRectanglePointsNotInOrder_True)
		{
			//testing the analyzePoints() function of points that create a vertical and horizontal line rectangle but inputted out of order
			//creates multiple combinations of these points to see if the shape made creates 90 degree angles
			//returns true if one or more combinations show all points having 90 degree angles
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

		TEST_METHOD(analyzePoints_AllSamePoints_False)
		{
			//testing the analyzePoints() function of points that are all the same
			//checks if the points entered are the same and returns false if they are
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

}

