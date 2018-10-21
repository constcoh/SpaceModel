#include "stdafx.h"
#include "CppUnitTest.h"
#include "Matrices\Matrix4d.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpaceModelTests
{
	TEST_CLASS(Matrix4dTests)
	{
	public:

		TEST_METHOD(Model_Matrix4d_Inverse)
		{
			// TODO: Your test code here
			Matrix4d M(
				1, 2, 3, 4,
				4, 3, 5, 6,
				7, 6, 4, 3,
				9, 8, 6, 9);
			Matrix4d Back = M.Inverse();
			Matrix4d One = M * Back;
			double eps = 0.0000000001;
			Assert::AreEqual(1, One.a11, eps);
			Assert::AreEqual(0, One.a12, eps);
			Assert::AreEqual(0, One.a13, eps);
			Assert::AreEqual(0, One.a14, eps);
			Assert::AreEqual(0, One.a21, eps);
			Assert::AreEqual(1, One.a22, eps);
			Assert::AreEqual(0, One.a23, eps);
			Assert::AreEqual(0, One.a24, eps);
			Assert::AreEqual(0, One.a31, eps);
			Assert::AreEqual(0, One.a32, eps);
			Assert::AreEqual(1, One.a33, eps);
			Assert::AreEqual(0, One.a34, eps);
			Assert::AreEqual(0, One.a41, eps);
			Assert::AreEqual(0, One.a42, eps);
			Assert::AreEqual(0, One.a43, eps);
			Assert::AreEqual(1, One.a44, eps);
		}
	};
}