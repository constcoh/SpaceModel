#include "stdafx.h"
#include "CppUnitTest.h"
#include "Vectors\Vector2d.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpaceModelTests
{		
	TEST_CLASS(Vector2dTests)
	{
	public:
		
		TEST_METHOD(Model_Vector2d_MinusMult)
		{
			// TODO: Your test code here
			Vector2d vec1(1, 2);
			Vector2d vec2(2, 4);
			Vector2d vec3 = -(vec1 - vec2) * 3;
			Assert::AreEqual(3, vec3.x, 0.001);
			Assert::AreEqual(6, vec3.y, 0.001);
		}

		TEST_METHOD(Model_Vector2d_Summa)
		{
			// TODO: Your test code here
			Vector2d vec1(1, 2);
			Vector2d vec2(2, 4);
			Vector2d vec3 = vec1 + vec2;
			Assert::AreEqual(3, vec3.x, 0.001);
			Assert::AreEqual(6, vec3.y, 0.001);
		}
	};
}