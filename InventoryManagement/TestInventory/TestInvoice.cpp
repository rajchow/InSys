#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\InventoryManagement\Invoice.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestInventory
{
	/// Pointer to TableInterface class to be used for interacting with the Invoice table
	Table invoice;

	/// Unit test class for testing Invoice class
	TEST_CLASS(TestInvoice)
	{
	public:
		
		/// \brief sets up each test method
		///
		/// - Initializes invoice variable to Invoice class
		/// - Clears the invoice.txt table and inputs data to test
		TEST_METHOD_INITIALIZE(SetUp)
		{
			invoice = new Invoice();

			ofstream ofstr;
			ofstr.open("textfiles\\invoice.txt", ios_base::trunc); // clear Invoice table
			
			// Data for testing
			ofstr << "1|2012-09-01\n";
			ofstr << "2|2012-09-08\n";
			ofstr << "3|2012-09-15\n";
			ofstr << "4|2012-09-15\n";
		
			ofstr.close();
		}

		TEST_METHOD_CLEANUP(TearDown)
		{
			delete invoice;
		}

		/// \brief tests if the Invoice class can search a table by invoice_id
		TEST_METHOD(TestInvoiceSearchByInvoiceID)
		{
			// Log test name
			Logger::WriteMessage("TestInvoiceSearchByInvoiceID");

			// String to store value returned by Invoice::search
			string returned = invoice->search("invoice_id", "2");
			
			// Logs returned values
			Logger::WriteMessage(returned.c_str());

			// Asserts what is expected with what is actually returned
			Assert::AreEqual("2|2012-09-08\n", returned.c_str());
		}

		/// \brief tests if the Invoice class can search a table by date
		TEST_METHOD(TestInvoiceSearchByDate)
		{
			Logger::WriteMessage("TestInvoiceSearchByDate");

			string returned = invoice->search("date", "2012-09-08");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("2|2012-09-08\n", returned.c_str());
		}

		/// \brief tests if the Invoice class can search and return multiple invoices with same date
		TEST_METHOD(TestInvoiceSearchReturnsMultipleDates)
		{
			Logger::WriteMessage("TestInvoiceSearchReturnsMultipleDates");

			string returned = invoice->search("date", "2012-09-15"); //two occurences in file

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("3|2012-09-15\n4|2012-09-15\n", returned.c_str());
		}

		/// \brief tests if the Invoice class doesn't find a value it throws an exception
		TEST_METHOD(TestInvoiceSearchDoesNotExist)
		{
			Logger::WriteMessage("TestInvoiceSearchValueDoesNotExist");
			
			// tests if exception is thrown by making sure 
			try {
			string returned = invoice->search("invoice_id", "99999");
			Assert::Fail(); // fail test if no exception is thrown
			}
			catch (exception e) { //continue if exception was thrown
			}
		}
		
		/// \brief tests if the Invoice class can add a row to the Invoice table
		TEST_METHOD(TestInvoiceAdd)
		{
			// vector of strings to store values to add to row
			vector<string> addVector;
			addVector.push_back("2012-09-22");
			
			Logger::WriteMessage("TestInvoiceAdd");

			invoice->add(addVector);

			string returned = invoice->search("date", "2012-09-22");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("5|2012-09-22\n", returned.c_str()); // invoice_id should increment
		}

		/// \brief tests if the Invoice class can modify a row in the Invoice table
		TEST_METHOD(TestInvoiceModify)
		{
			
			Logger::WriteMessage("TestInvoiceModify");

			invoice->modifyRow("invoice_id", "4", "date", "2012-09-22");

			string returned = invoice->search("date", "2012-09-22");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("4|2012-09-22\n", returned.c_str());
			
		}

		/// \brief test if the Invoice class can modifiy multiple rows that have the same value
		TEST_METHOD(TestInvoiceModifyMultiple)
		{
			
			Logger::WriteMessage("TestInvoiceModifyMulptiple");

			invoice->modifyRow("date", "2012-09-15", "date", "2012-09-22"); // two occurences in file

			string returned = invoice->search("date", "2012-09-22");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("3|2012-09-22\n4|2012-09-22\n", returned.c_str());
		}
	};
}