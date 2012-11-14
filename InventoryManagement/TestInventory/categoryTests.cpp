#include "stdafx.h"
#include "CppUnitTest.h"

#include "../InventoryManagement/Category.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestInventory
{		
	/// Pointer to TableInterface to be used for interacting with the Category table
	Table cat;

	/// Unit test class for testing Category class
	TEST_CLASS(categoryTests)
	{

	public:
		
		/// \brief Setup before the Test class
		///
		/// - Sets cat to point to a Category table class
		/// - Clears the Category table in the database and then adds data for testing
		TEST_METHOD_INITIALIZE(setup)
		{
			Logger::WriteMessage("TEST_CLASS setup");

			cat = new Category();
			
			ofstream ofstr;
			ofstr.open("textFiles/category.txt", ios_base::trunc); // clear Category table
			
			// Data for testing
			ofstr << "1|sweet and tangy produce|fruits\n";
			ofstr << "2|ready for your enjoyment|hot foods\n";
			ofstr << "3|underwater delicacies|seafood\n";
		
			ofstr.close();
		}

		/// \brief Clean up function after test class is run
		TEST_METHOD_CLEANUP(teardown)
		{
			Logger::WriteMessage("TEST_CLASS cleanup\n");

			delete cat;
		}
		
		/// \brief Test if Category can search by ID
		TEST_METHOD(TestCategorySearchByCategoryID)
		{
			Logger::WriteMessage("TestCategorySearchByCategoryID");

			// String to store value returned by Category::search
			string categoryReturned;

			categoryReturned = cat->search("category_id", "2");

			// Logs test name and returned values
			const char *p;
			p = categoryReturned.c_str();
			Logger::WriteMessage(p);

			// Asserts what is expected with what is actually returned
			Assert::AreEqual("2|ready for your enjoyment|hot foods", categoryReturned.c_str());
		}

		/// \brief Test if Category can search by description
		TEST_METHOD(TestCategorySearchByDescription)
		{
			Logger::WriteMessage("TestCategorySearchByDescription");

			string categoryReturned;

			categoryReturned = cat->search("description", "underwater delicacies");

			const char *p;
			p = categoryReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("3|underwater delicacies|seafood\r\n", categoryReturned.c_str());

		}

		/// \brief Test if Category can search by name
		TEST_METHOD(TestCategorySearchByName)
		{
			Logger::WriteMessage("TestCategorySearchByName");

			string categoryReturned;

			categoryReturned = cat->search("name", "seafood");

			const char *p;
			p = categoryReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("3|underwater delicacies|seafood\r\n", categoryReturned.c_str());

		}

		/// \brief Test response to a search for a Category that does not exist
		TEST_METHOD(TestCategorySearchDoesNotExist)
		{
			Logger::WriteMessage("TestCategorySearchDoesNotExist");
			

			string categoryReturned;
			try{
				categoryReturned = cat->search("name", "electronics");
				Assert::Fail(L"No exception for input",LINE_INFO());
			} catch(DoesNotExistException e) {
				// Correct exception caught
			} catch(...)
			{
				Assert::Fail(L"Wrong Exception Caught", LINE_INFO());
			}
		}

		/// \brief Test if category can add a new data entry into category.txt
		TEST_METHOD(TestCategoryAdd)
		{
			// identifies in the test log which test method is currently active
			Logger::WriteMessage("TestCategoryAdd");

			// string for the search return string
			string categoryReturned;

			// string containing the expected information to be received from the search
			string categoryExpected = "4|testDescription|testName";

			// vector to contain the information for the required columns for a new entry
			vector<string> catVector;
			// insertion of the test data into the vector to be passed as the argument for the add function
			catVector.push_back("testDescription");
			catVector.push_back("testName");

			// calling the category add function
			cat->add(catVector);

			// calling the category seach function to ensure that the add function was successful
			categoryReturned = cat->search("category_id", "4");
			
			// convert the returned string to a const char to output in the test log
			const char *p;
			p = categoryReturned.c_str();
			Logger::WriteMessage(p);
			
			// assert that the return string matches the expected return string
			// in this case the expected return is "4|testDescription|testName\n"
			Assert::AreEqual(categoryExpected, categoryReturned);
		}

		/// \brief Test if category can delete a row of data from category.txt
		TEST_METHOD(TestCategoryDelete)
		{
			// identifies in the test log which test method is currently active
			Logger::WriteMessage("TestCategoryDelete");
			
			// string for the search return string
			string returnedString;

			// call the category delete function
			cat->deleteRow("1");

			try{
				// call the category search function to ensure that the category was successfully deleted
				returnedString = cat->search("category_id", "1");
				Assert::Fail(L"No exception for input",LINE_INFO());
			} catch(DoesNotExistException e) {
				// Correct exception caught
			} catch(...)
			{
				Assert::Fail(L"Wrong Exception Caught", LINE_INFO());
			}
		}

		/// \brief Test if category can modify the a row of data in category.txt
		TEST_METHOD(TestCategoryModify)
		{
			// identifies in the test log which test method is currently active
			Logger::WriteMessage("TestCategoryModify");
			
			// string for the search return string
			string returnedString;
			
			// string containing the expected information to be received from the search
			string expectedString = "1|Description Modified|Name Modified";

			// call the category modify function to modify the description
			cat->modifyRow("1","description","Description Modified");
			// call the category modify function to modify the name
			cat->modifyRow("1","name","Name Modified");

			// call the category search function to ensure that the category was successfully modified
			returnedString = cat->search("category_id", "1");

			// convert the returned string to a const char to output in the test log
			const char *p;
			p = returnedString.c_str();
			Logger::WriteMessage(p);

			// assert that the returned string matches the expected string
			// in this case the expectation is "1|Description Modified|Name Modified\n"
			Assert::AreEqual(expectedString,returnedString);
		}
		
	};
}