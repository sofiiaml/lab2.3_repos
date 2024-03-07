#include "pch.h"
#include "CppUnitTest.h"
#include "../2.3/FuzzyNumber.h"
#include "../2.3/FuzzyNumber.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest23
{
	TEST_CLASS(UnitTest23)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			FuzzyNumber a(2, 5, 7);
			FuzzyNumber b(1, 3, 2);
			FuzzyNumber c= a+b;
			Assert::AreEqual(c.getX(), -5.0);
			Assert::AreEqual(c.getL(), 3.0);
			Assert::AreEqual(c.getR(), 12.0);
		}
	};
}