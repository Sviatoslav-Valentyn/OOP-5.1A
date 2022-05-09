#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP 5.1A/Bill.h"
#include "../OOP 5.1A/Bill.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Bill testBill(2, 3.0);
			double cost = testBill.Cost();
			Assert::AreEqual(6.0, cost);
		}
	};
}
