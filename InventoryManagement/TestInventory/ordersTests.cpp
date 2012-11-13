#include "stdafx.h"
#include "CppUnitTest.h"

#include "../InventoryManagement/Orders.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestInventory

{
	/// \brief Pointer to TableInterface used to interact with the Orders table
	Table orders;

	/// \brief unit test class for testing Orders class
	TEST_CLASS(ordersTests)
	{
	public:
		
		/// \brief sets up each test method
		///
		/// - Initializes orders class
		/// - Clears the orders.txt table and inputs data to test
		TEST_METHOD_INITIALIZE(SetUp)
		{
			orders = new Orders();

			ofstream ofstr;
			ofstr.open("textfiles\\orders.txt", ios_base::trunc); // clear Orders table
			
			// Set up orders data for testing
			ofstr << "101|1\n";
			ofstr << "102|1\n";
			ofstr << "103|2\n";
			ofstr << "104|2\n";
			ofstr << "105|3\n";

			ofstr.close();
		}

		/// \brief clean up after every test method
		TEST_METHOD_CLEANUP(TearDown)
		{
			delete orders;
		}

		/// \brief tests if the Orders class can search a table by Invoice_id
		TEST_METHOD(TestOrdersSearchByInvoiceID)
		{
			// Log test name
			Logger::WriteMessage("TestOrdersSearchByInvoiceID");

			// String to store value returned by Orders::search
			string returned = orders->search("invoice_id", "3"); // test invoice_id
			
			// Logs returned values
			Logger::WriteMessage(returned.c_str());

			// Asserts what is expected with what is actually returned
			Assert::AreEqual("105|3\n", returned.c_str());
		}

		/// \brief tests if the Orders class can search a table by invoice_item_id
		TEST_METHOD(TestOrdersSearchByInvoiceItemID)
		{
			
			Logger::WriteMessage("TestOrdersSearchByInvoiceItemID");

			// test search by invoice_item_id, store in returned
			string returned = orders->search("invoice_item_id", "103");
			
			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("103|2\n", returned.c_str());
		}

		/// \brief tests if the Orders class can search for multiple values and return multiple rows
		TEST_METHOD(TestOrdersSearchCanReturnMultiple)
		{
			Logger::WriteMessage("TestOrdersSearchCanReturnMultiple");

			// multiple invoice_id's of value 2
			string returned = orders->search("invoice_id", "2");
			
			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("103|2\n104|2\n", returned.c_str());
		}

		/// \brief tests if the Orders class doesn't find a value it throws an exception
		TEST_METHOD(TestOrdersSearchValueDoesNotExist)
		{
			Logger::WriteMessage("TestOrdersSearchValueDoesNotExist");
			
			// tests if DoesNotExistException is thrown 
			try {
				string returned = orders->search("invoice_item_id", "99999");
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

		/// \brief tests if the Orders class can add a row to the Orders table
		TEST_METHOD(TestOrdersAdd)
		{
			// vector of strings to store values to add to row
			vector<string> addVector;
			addVector.push_back("106"); //invoice_item_id
			addVector.push_back("3"); //invoice_id
			
			Logger::WriteMessage("TestOrdersAdd");

			orders->add(addVector);

			string returned = orders->search("invoice_item_id", "106");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("106|3\n", returned.c_str());
		}

		/// \brief test if Orders will throw AlreadyExistsException if invoice_item_id already exists
		TEST_METHOD(TestOrdersAddInvoiceItemIDExists)
		{
			Logger::WriteMessage("TestOrdersAddInvoiceItemIDExists");

			// vector of strings to store value to add to row
			vector<string> addVector;
			addVector.push_back("103"); //existing invoice_item_id
			addVector.push_back("33"); //invoice_id

			// tests if AlreadyExistsException is thrown 
			try {
				orders->add(addVector); // try to add existing invoice_item_id
				Assert::Fail(); // fail test if no exception is thrown
			}
			catch (AlreadyExistsException e) { // continue if DoesNotExistException was thrown
				Logger::WriteMessage(e.what());
			} 
			catch (...) { // Fail if something else is thrown
				Logger::WriteMessage("Other exception");
				Assert::Fail(); 
			} 
		}
	};
}