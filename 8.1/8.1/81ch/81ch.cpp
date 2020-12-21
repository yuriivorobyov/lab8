#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\Desktop\Політех\АТП\8 тема\8.1\8.1\8.1\8.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My81ch
{
	TEST_CLASS(My81ch)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int z;
			char* str = "ievnk==vre";
			z = Count( str);
			Assert::AreEqual(z, 2);
		}
	};
}

