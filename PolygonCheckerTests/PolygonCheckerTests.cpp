#include "pch.h"
#include "CppUnitTest.h"

#include <stdbool.h>
#include <math.h>
#include <float.h>

extern "C"
{

	char* analyzeTriangle(double side1, double side2, double side3, bool*);
	bool largestSide(double, double, double);
	bool lengthChecker(double, double, double);
	void findingAngles(double, double, double, double*);

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

		TEST_METHOD(TestMethod1)
		{
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

