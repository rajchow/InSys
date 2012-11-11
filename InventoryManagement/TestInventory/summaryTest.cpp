#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\InventoryManagement\Summary.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestInventory
{
	/// \brief Pointer to TableInterface used to interact with the Summary table
	Table summary;

	/// \brief Unit test class for testing Summary
	TEST_CLASS(summaryTests)
	{
	public:
		
		/// \brief sets up each test method
		///
		/// - Initializes summary class
		/// - Clears the summary.txt table and inputs data to test
		TEST_METHOD_INITIALIZE(SetUp)
		{
			summary = new Summary();

			ofstream ofstr;
			ofstr.open("textfiles\\summary.txt", ios_base::trunc); // clear Summary table
			
			// Set up summary data for testing
			ofstr << "1425|20\n";
			ofstr << "2543|0\n";
			ofstr << "1002|50\n";
			ofstr << "1003|0\n";
		
			ofstr.close();

			ofstr.open("textfiles\\product.txt", ios_base::trunc); // clear Product table

			// Set up product data for testing
			
			ofstr << "1425|1|24 pack 355mL cans of Budget Brand Cola|BBCola24|5.98\n";
			ofstr << "2543|1|6 pack 710mL bottle Budget Brand Root Beer|BBRootBeer6Bottle|3.49\n";
			ofstr << "1002|2|250g bag Budget Brand Regular Tortilla Chips|BBRegTortillaChip|2.24\n";
			ofstr << "1003|2|250g bag Budget Brand Ketchup Potato Chips|BBKetPotatoChip|2.24\n";

			ofstr.close();
		}

		/// \brief clean up after every test method
		TEST_METHOD_CLEANUP(TearDown)
		{
			delete summary;
		}

		/// \brief tests if the Summary class can search a table by product_id
		TEST_METHOD(TestSummarySearchByProductID)
		{
			// Log test name
			Logger::WriteMessage("TestSummarySearchByProductID");

			// String to store value returned by Summary::search
			string returned = summary->search("product_id", "1002");
			
			// Logs returned values
			Logger::WriteMessage(returned.c_str());

			// Asserts what is expected with what is actually returned
			Assert::AreEqual("1002|50\n", returned.c_str());
		}

		/// \brief tests if the Summary class can search rows with same valuesand return multiple results
		TEST_METHOD(TestSummarySearchReturnsMultipleResults)
		{
			// Log test name
			Logger::WriteMessage("TestSummarySearchReturnsMultipleResults");

			// String to store value returned by Summary::search
			string returned = summary->search("total_quantity", "0");
			
			// Logs returned values
			Logger::WriteMessage(returned.c_str());

			// Asserts what is expected with what is actually returned
			Assert::AreEqual("2543|0\n1003|0\n", returned.c_str());
		}

		/// \brief tests if the Summary class doesn't find a value it throws an exception
		TEST_METHOD(TestSummarySearchValueDoesNotExist)
		{
			Logger::WriteMessage("TestSummarySearchValueDoesNotExist");
			
			// tests if exception is thrown by making sure 
			try {
				string returned = summary->search("product_id", "99999");
				Assert::Fail(); // fail test if no exception is thrown
			}
			catch (DoesNotExistException e) { // continue if DoesNotExistException was thrown
				Logger::WriteMessage(e.what());
			} 
			catch (...) { // Fail if something else is thrown
				Logger::WriteMessage("Other exception");
				Assert::Fail(); 
			} 
		}

		/// \brief tests if the Summary class can add a row to the Summary table
		TEST_METHOD(TestSummaryAdd)
		{
			// vector of strings to store values to add to row
			vector<string> addVector;
			addVector.push_back("00000"); //product_id
			addVector.push_back("1"); //total_quantity
			
			Logger::WriteMessage("TestSummaryAdd");

			summary->add(addVector);

			string returned = summary->search("product_id", "00000");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("00000|1\n", returned.c_str());
		}

		//// \brief tests if the Summary class throws AlreadyExistsException
		TEST_METHOD(TestSummaryAddProductAlreadyExists)
		{
			Logger::WriteMessage("TestSummaryAddProductAlreadyExists");

			// vector of strings to store values to add to row
			vector<string> addVector;
			addVector.push_back("1002"); //product_id already exists
			addVector.push_back("1"); //total_quantity
			
			// tests if exception is thrown
			try {
				summary->add(addVector);
				Assert::Fail(); // fail test if no exception is thrown
			}
			catch (AlreadyExistsException e) { // continue if DoesNotExistException was thrown
				Logger::WriteMessage(e.what());
			} 
			catch (...) { Assert::Fail();} // Fail if something else is thrown
		}
	};
}