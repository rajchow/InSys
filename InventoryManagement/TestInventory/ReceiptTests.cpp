#include "stdafx.h"
#include "CppUnitTest.h"

#include "../InventoryManagement/Receipt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestInventory
{
	/// Pointer to TableInterface class to be used for interacting with the Receipt table
	Table receipt;

	/// Unit test class for testing Receipt class
	TEST_CLASS(ReceiptTests)
	{
	public:

		/// \brief sets up each test method
		///
		/// - Initializes receipt variable to Receipt class
		/// - Clears the receipt.txt table and inputs data to test
		TEST_METHOD_INITIALIZE(SetUp)
		{
			receipt = new Receipt();

			ofstream ofstr;
			ofstr.open("textfiles\\receipt.txt", ios_base::trunc); // clear receipt table

			// Data for testing
			ofstr << "001|2012-11-12\n";
			ofstr << "002|2013-01-11\n";
			ofstr << "003|2013-12-10\n";
			ofstr << "004|2013-12-01\n";

			ofstr.close();
		}

		/// \brief clean up after every test method
		TEST_METHOD_CLEANUP(TearDown)
		{
			delete receipt;
		}

		/// \brief tests if the receipt class can search a table by receipt_id
		TEST_METHOD(TestReceiptSearchByReceiptID)
		{
			// Log test name
			Logger::WriteMessage("TestReceiptSearchByReceiptID");

			// String to store value returned by Receipt::search
			string returned = receipt->search("receipt_id", "002");

			// Logs returned values
			Logger::WriteMessage(returned.c_str());

			// Asserts what is expected with what is actually returned
			Assert::AreEqual("002|2013-01-11\n", returned.c_str());
		}

		/// \brief tests if the Receipt class can search a table by date
		TEST_METHOD(TestReceiptSearchByDate)
		{
			Logger::WriteMessage("TestReceiptSearchByDate");

			string returned = receipt->search("date", "2013-01-11");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("002|2013-01-11\n", returned.c_str());
		}


		/// \brief tests if the Receipt class doesn't find a value it throws an exception
		TEST_METHOD(TestReceiptSearchValueDoesNotExist)
		{
			Logger::WriteMessage("TestReceiptSearchValueDoesNotExist");

			// tests if DoesNotExistException is thrown
			try {
				string returned = receipt->search("receipt_id", "005");
				Assert::Fail(); // fail test if no exception is thrown
			}
			catch (exception DoesNotExistException) {} // continue if DoesNotExistException was thrown
			catch (...) { Assert::Fail();} // Fail if something else is thrown
		}

		/// \brief tests if the receipt class can add a row to the Invoice table
		TEST_METHOD(TestReceiptAdd)
		{
			// vector of strings to store values to add to row
			vector<string> addVector;
			addVector.push_back("2012-11-22");

			Logger::WriteMessage("TestReceiptAdd");

			receipt->add(addVector);

			string returned = receipt->search("date", "2012-11-22");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("5|2012-11-22\n", returned.c_str()); // receipt_id should increment
		}

		/// \brief tests if the Receipt class can modify a row in the Receipt table
		TEST_METHOD(TestReceiptModify)
		{

			Logger::WriteMessage("TestReceiptModify");

			receipt->modifyRow("004", "date", "2013-12-01"); // change date

			string returned = receipt->search("date", "2013-12-01");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("004|2013-12-01\n", returned.c_str());

		}

	};
}