#include "stdafx.h"
#include "CppUnitTest.h"
#include "Matrices\Matrix3d.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpaceModelTests
{
	TEST_CLASS(Matrix3dTests)
	{
	public:

		TEST_METHOD(Model_Matrix3d_Inverse)
		{
			// TODO: Your test code here
			Matrix3d M(1, 2, 3, 4, 5, 6, 7, 8, 8);
			Matrix3d Back = M.Inverse();
			Matrix3d One = M * Back;
			double eps = 0.0000000001;
			Assert::AreEqual(1, One.a11, eps);
			Assert::AreEqual(0, One.a12, eps);
			Assert::AreEqual(0, One.a13, eps);
			Assert::AreEqual(0, One.a21, eps);
			Assert::AreEqual(1, One.a22, eps);
			Assert::AreEqual(0, One.a23, eps);
			Assert::AreEqual(0, One.a31, eps);
			Assert::AreEqual(0, One.a32, eps);
			Assert::AreEqual(1, One.a33, eps);
		}
	};
}