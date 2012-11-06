#include "stdafx.h"
#include "CppUnitTest.h"
#include "../InventoryManagement/TableInterface.h"
#include "../InventoryManagement/Category.h"
#include "../InventoryManagement/Category.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestInventory
{		
	
	Table cat;

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_CLASS_INITIALIZE(setup)
		{
			cat = new Category();
		}

		TEST_CLASS_CLEANUP(teardown)
		{
			delete cat;
		}
		
		TEST_METHOD(TestCategoryAdd)
		{
			string categoryReturned;
			string categoryExpected = "1|testDescription|testName\n";

			vector<string> catVector;
			catVector.push_back("testDescription");
			catVector.push_back("testName");

			cat->add(catVector);

			categoryReturned = cat->search("category_id", "1");
			
			const char *p;
			p = categoryReturned.c_str();
			Logger::WriteMessage(p);
			
			Assert::AreEqual(categoryExpected, categoryReturned);
		}

	};
}