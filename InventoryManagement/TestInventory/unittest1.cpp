#include "stdafx.h"
#include "CppUnitTest.h"
#include "../InventoryManagement/TableInterface.h"
#include "../InventoryManagement/Category.h"
#include "../InventoryManagement/Category.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestInventory
{		
	/// Pointer to TableInterface to be used for interacting with the Category table
	Table cat;

	/// Unit test class for testing Category class
	TEST_CLASS(UnitTest1)
	{

	public:
		
		/// \brief Setup before each test method
		///
		/// - Sets cat to point to a Category table class
		/// - Clears the Category table in the database and then adds data for testing
		TEST_CLASS_INITIALIZE(setup)
		{
			cat = new Category();
			
			ofstream ofstr;
			ofstr.open("category.txt", ios_base::trunc); // clear Category table
			
			// Data for testing
			ofstr << "1|sweet and tangy produce|fruits\n";
			ofstr << "2|ready for your enjoyment|hot foods\n";
			ofstr << "3|underwater delicacies|seafood\n";
		
			ofstr.close();
		}

		/// \brief Clean up function after test methods are run
		TEST_CLASS_CLEANUP(teardown)
		{
			delete cat;
		}
		
		/// \brief Test class to test if Category can search by ID
		TEST_METHOD(TestCategorySearchByCategoryID)
		{
			// String to store value returned by Category::search
			string categoryReturned;

			categoryReturned = cat->search("category_id", "2");

			// Logs test name and returned values
			const char *p;
			p = categoryReturned.c_str();
			Logger::WriteMessage("TestCategorySearchByCategoryID");
			Logger::WriteMessage(p);

			// Asserts what is expected with what is actually returned
			Assert::AreEqual("2|ready for your enjoyment|hot foods\n", categoryReturned.c_str());
		}

		/// \brief Test class to test if Category can search by description
		TEST_METHOD(TestCategorySearchByDescription)
		{
			string categoryReturned;

			categoryReturned = cat->search("description", "underwater delicacies");

			const char *p;
			p = categoryReturned.c_str();
			Logger::WriteMessage("TestCategorySearchByDescription");
			Logger::WriteMessage(p);

			Assert::AreEqual("3|underwater delicacies|seafood\n", categoryReturned.c_str());

		}

		/// \brief Test class to test if Category can search by name
		TEST_METHOD(TestCategorySearchByName)
		{
			string categoryReturned;

			categoryReturned = cat->search("name", "seafood");

			const char *p;
			p = categoryReturned.c_str();
			Logger::WriteMessage("TestCategorySearchByName");
			Logger::WriteMessage(p);

			Assert::AreEqual("3|underwater delicacies|seafood\n", categoryReturned.c_str());

		}

		TEST_METHOD(TestCategoryAdd)
		{
			string categoryReturned;
			string categoryExpected = "4|testDescription|testName\n";

			vector<string> catVector;
			catVector.push_back("testDescription");
			catVector.push_back("testName");

			cat->add(catVector);

			categoryReturned = cat->search("category_id", "4");
			
			const char *p;
			p = categoryReturned.c_str();
			Logger::WriteMessage("TestCategoryAdd");
			Logger::WriteMessage(p);
			
			Assert::AreEqual(categoryExpected, categoryReturned);
		}

		TEST_METHOD(TestCategoryDelete)
		{
			string returnedString;
			string expectedString = "Category Does Not Exist";

			cat->deleteRow("catergory_id","1");

			returnedString = cat->search("category_id", "1");
			
			const char *p;
			p = returnedString.c_str();
			Logger::WriteMessage("TestCategoryDelete");
			Logger::WriteMessage(p);

			Assert::AreEqual(expectedString,returnedString);
		}

	};
}