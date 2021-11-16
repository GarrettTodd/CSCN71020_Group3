#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>
extern "C" 
{

	char* analyzeTriangle(double side1, double side2, double side3, bool*);
	bool largestSide(double, double, double);
	bool lengthChecker(double, double, double);
	void findingAngles(double, double, double, double*);

}


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleSolverTests
{
	TEST_CLASS(TriangleSolverTests)
	{
	public:
		
		TEST_METHOD(analyzeTriangle_Invalid)
		{
			//testing analyzeTriangle with invalid sides: 1 2 3
			// expected outcome of function: "Not a triangle"

			double triangleSides[3] = { 1, 2, 3 };
			char * Expected = "Not a triangle";
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
		
	};
}
