#include "stdafx.h"
#include "CppUnitTest.h"
#include "Objects\ComplexObject.h"
#include "Core\Exception.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpaceModelTests
{
	TEST_CLASS(ComplexObjectTests)
	{
	public:

		TEST_METHOD(Model_ComplexObject_AddRemove)
		{
			// TODO: Your test code here
			// Arrange:
			ComplexObject * p0 = new ComplexObject();
			ComplexObject * p1 = new ComplexObject();
			ComplexObject * p2 = new ComplexObject();

			// Act:
			p0->AddChild(p1);
			p0->AddChild(p2);
			p0->RemoveChild(p1);
			p0->RemoveChild(p2);

			// Assert:
			Assert::IsTrue(p0->getChildIteratorBegin() == p0->getChildIteratorEnd());
			delete p0;
			delete p1;
			delete p2;
			//delete p2;
		}

		TEST_METHOD(Model_ComplexObject_Add_RemoveBase)
		{
			// TODO: Your test code here
			// Arrange:
			ComplexObject * p0 = new ComplexObject();
			ComplexObject * p1 = new ComplexObject();
			ComplexObject * p2 = new ComplexObject();

			// Act:
			p0->AddChild(p1);
			p0->AddChild(p2);

			// Assert:
			delete p0;
			//delete p2;
		}

		TEST_METHOD(Model_ComplexObject_AddNull)
		{
			// TODO: Your test code here
			// Arrange:
			ComplexObject * p0 = new ComplexObject();

			try {
				// Act:
				p0->AddChild(NULL);

			}
			catch (Exception exception) {
				// Assert:
				std::string message = exception.getMessage();
			}

			delete p0;
		}
	};
}