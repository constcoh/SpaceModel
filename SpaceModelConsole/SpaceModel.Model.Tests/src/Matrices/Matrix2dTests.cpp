#include "stdafx.h"
#include "CppUnitTest.h"
#include "Matrices\Matrix2d.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpaceModelTests
{
	TEST_CLASS(Matrix2dTests)
	{
	public:

		TEST_METHOD(Model_Matrix2d_Inverse)
		{
			// TODO: Your test code here
			Matrix2d M(1, 2, 3, 4);
			Matrix2d Back = M.Inverse();
			Matrix2d One = M * Back;
			double eps = 0.0000000001;
			Assert::AreEqual(1, One.a11, eps);
			Assert::AreEqual(0, One.a12, eps);
			Assert::AreEqual(0, One.a21, eps);
			Assert::AreEqual(1, One.a22, eps);
		}
	};
}