#include "stdafx.h"
#include "CppUnitTest.h"
#include "../InventoryManagement/Returns.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestInventory
{		
	/// Pointer to TableInterface to be used for interacting with the Returns table
	Table ret;

	/// Unit test class for testing Returns class
	TEST_CLASS(returnTests)
	{

	public:
		
		/// \brief Setup before the Test class
		///
		/// - Sets ret to point to a Returns table class
		/// - Clears the Returns table in the database and then adds data for testing
		TEST_METHOD_INITIALIZE(setup)
		{
			Logger::WriteMessage("TEST_CLASS setup");

			ret = new Returns();
			
			ofstream ofstr;
			ofstr.open("textFiles/returns.txt", ios_base::trunc); // clear Returns table
			
			// Data for testing
			ofstr << "1|1|10|2012/11/09\n";
			ofstr << "2|7|5|2012/11/08\n";
			ofstr << "3|12|1|2012/10/29\n";
		
			ofstr.close();
		}

		/// \brief Clean up function after test class is run
		TEST_METHOD_CLEANUP(teardown)
		{
			Logger::WriteMessage("TEST_CLASS cleanup");

			delete ret;
		}
		
		/// \brief Test if Returns can search by ID
		TEST_METHOD(TestReturnsSearchByReturnsID)
		{
			Logger::WriteMessage("TestReturnsSearchByReturnsID");

			// String to store value returned by Returns::search
			string returnsReturned;

			returnsReturned = ret->search("returns_id", "2");

			// Logs test name and returned values
			const char *p;
			p = returnsReturned.c_str();
			Logger::WriteMessage(p);

			// Asserts what is expected with what is actually returned
			Assert::AreEqual("2|7|5|2012/11/08\n", returnsReturned.c_str());
		}

		/// \brief Test if Returns can search by sales_id
		TEST_METHOD(TestReturnsSearchBySalesID)
		{
			Logger::WriteMessage("TestReturnsSearchBySalesID");

			string returnsReturned;

			returnsReturned = ret->search("sales_id", "7");

			const char *p;
			p = returnsReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("2|7|5|2012/11/08\n", returnsReturned.c_str());

		}

		/// \brief Test if Returns can search by quantity_returned
		TEST_METHOD(TestReturnsSearchByQuantityReturned)
		{
			Logger::WriteMessage("TestReturnsSearchByQuantityReturned");

			string returnsReturned;

			returnsReturned = ret->search("quantity_returned", "10");

			const char *p;
			p = returnsReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("1|1|10|2012/11/09\n", returnsReturned.c_str());

		}


				/// \brief Test if Returns can search by date_returned
		TEST_METHOD(TestReturnsSearchByDateReturned)
		{
			Logger::WriteMessage("TestReturnsSearchByDateReturned");

			string returnsReturned;

			returnsReturned = ret->search("date_returned", "2012/10/29");

			const char *p;
			p = returnsReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("3|12|1|2012/10/29\n", returnsReturned.c_str());

		}
		/// \brief Test if returns can add a new data entry into returns.txt
		TEST_METHOD(TestReturnsAdd)
		{
			// identifies in the test log which test method is currently active
			Logger::WriteMessage("TestReturnsAdd");

			// string for the search return string
			string returnsReturned;

			// string containing the expected information to be received from the search
			string returnsExpected = "4|3|500|2011/05/06\n";

			// vector to contain the information for the required columns for a new entry
			vector<string> retVector;
			// insertion of the test data into the vector to be passed as the argument for the add function
			retVector.push_back("3");
			retVector.push_back("500");
			retVector.push_back("2011/05/06");

			// calling the returns add function
			ret->add(retVector);

			// calling the returns seach function to ensure that the add function was successful
			returnsReturned = ret->search("returns_id", "4");
			
			// convert the returned string to a const char to output in the test log
			const char *p;
			p = returnsReturned.c_str();
			Logger::WriteMessage(p);
			
			// assert that the return string matches the expected return string
			// in this case the expected return is "4|testDescription|testName\n"
			Assert::AreEqual(returnsExpected, returnsReturned);
		}

		/// \brief Test if returns can delete a row of data from returns.txt
		TEST_METHOD(TestReturnsDelete)
		{
			// identifies in the test log which test method is currently active
			Logger::WriteMessage("TestReturnsDelete");
			
			// string for the search return string
			string returnedString;
			
			// string containing the expected information to be received from the search
			string expectedString = "Return Does Not Exist";

			// call the returns delete function
			ret->deleteRow("1");

			// call the returns search function to ensure that the returns was successfully deleted
			returnedString = ret->search("returns_id", "1");

			// convert the returned string to a const char to output in the test log
			const char *p;
			p = returnedString.c_str();
			Logger::WriteMessage(p);

			// assert that the returned string matches the expected string
			// in this case the expectation is "Returns Does Not Exist"
			Assert::AreEqual(expectedString,returnedString);
		}

		/// \brief Test if returns can modify the a row of data in returns.txt
		TEST_METHOD(TestReturnsModify)
		{
			// identifies in the test log which test method is currently active
			Logger::WriteMessage("TestReturnsModify");
			
			// string for the search return string
			string returnedString;
			
			// string containing the expected information to be received from the search
			string expectedString = "1|9|7|2010/05/05\n";

			// 3 calls to modify each column
			ret->modifyRow("1","sales_id","9");
			ret->modifyRow("1","quantity_returned","7");
			ret->modifyRow("1","date_returned","2010/05/05");

			// call the returns search function to ensure that the returns was successfully modified
			returnedString = ret->search("returns_id", "1");

			// convert the returned string to a const char to output in the test log
			const char *p;
			p = returnedString.c_str();
			Logger::WriteMessage(p);

			// assert that the returned string matches the expected string
			// in this case the expectation is "1|90|700|2012/02/07\n"
			Assert::AreEqual(expectedString,returnedString);
		}

	};
}