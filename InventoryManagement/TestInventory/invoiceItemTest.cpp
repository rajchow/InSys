#include "stdafx.h"
#include "CppUnitTest.h"

#include "../InventoryManagement/InvoiceItem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestInventory
{
	/// Pointer to TableInterface class to be used for interacting with the InvoiceItem table
	Table invoiceItem;

	/// \brief unit test class for testing InvoiceItem class
	TEST_CLASS(invoiceItemTest)
	{
	public:

		/// \brief sets up each test method
		///
		/// - Initializes invoiceItem variable to InvoiceItem class
		/// - Clears the invoiceItem.txt table and inputs data to test
		TEST_METHOD_INITIALIZE(SetUp)
		{
			invoiceItem = new InvoiceItem();

			ofstream ofstr;
			ofstr.open("textfiles\\invoiceItem.txt", ios_base::trunc); // clear InvoiceItem table
			
			// Data for testing
			ofstr << "101|00000|33\n";
			ofstr << "102|1002|25\n";
			ofstr << "103|2720|1\n";
			ofstr << "104|00011|33\n";
		
			ofstr.close();
		}

		/// \brief clean up after every test method
		TEST_METHOD_CLEANUP(TearDown)
		{
			delete invoiceItem;
		}
		
		/// \brief tests if the InvoiceItem class can search a table by invoice_item_id
		TEST_METHOD(TestInvoiceItemSearchByInvoiceItemID)
		{
			// Log test name
			Logger::WriteMessage("TestInvoiceItemSearchByInvoiceItemID");

			// String to store value returned by Invoice::search
			string returned = invoiceItem->search("invoice_item_id", "102");
			
			// Logs returned values
			Logger::WriteMessage(returned.c_str());

			// Asserts what is expected with what is actually returned
			Assert::AreEqual("102|1002|25\n", returned.c_str());
		}

		/// \brief tests if the InvoiceItem class can search a table by product_id
		TEST_METHOD(TestInvoiceItemSearchByProductID)
		{
			Logger::WriteMessage("TestInvoiceItemSearchByProductID");

			string returned = invoiceItem->search("product_id", "2720");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("103|2720|1\n", returned.c_str());
		}

		/// \brief tests if the InvoiceItem class can return multiple rows with same value in a column
		TEST_METHOD(TestInvoiceItemSearchReturnsMultiple)
		{
			Logger::WriteMessage("TestInvoiceItemSearchReturnsMultiple");

			string returned = invoiceItem->search("quantity", "33"); // multiples exist

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("101|00000|33\n104|00011|33\n", returned.c_str());
		}

		/// \brief tests if the InvoiceItem class doesn't find a value it throws an exception
		TEST_METHOD(TestInvoiceItemSearchValueDoesNotExist)
		{
			Logger::WriteMessage("TestInvoiceSearchValueDoesNotExist");
			
			// tests if DoesNotExistException is thrown
			try {
				string returned = invoiceItem->search("product_id", "12345");
				Assert::Fail(); // fail test if no exception is thrown
			}
			catch (exception DoesNotExistException) {} // continue if DoesNotExistException was thrown
			catch (...) { Assert::Fail();} // Fail if something else is thrown
		}

		/// \brief tests if the InvoiceItem class can add a row to the table
		TEST_METHOD(TestInvoiceItemAdd)
		{
			Logger::WriteMessage("TestInvoiceItemAdd");

			// vector of strings to store values to add to row
			vector<string> addVector;
			addVector.push_back("5555");
			addVector.push_back("9");

			invoiceItem->add(addVector);

			string returned = invoiceItem->search("product_id", "5555");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("105|5555|9\n", returned.c_str()); // auto increment
		}

		/// \brief tests if the InvoiceItem class can modify a product_id in the InvoiceItem table
		TEST_METHOD(TestInvoiceItemModifyProductID)
		{
			Logger::WriteMessage("TestInvoiceItemModifyProductID");

			invoiceItem->modifyRow("103", "product_id", "1620"); //change 103's product id to 1620

			string returned = invoiceItem->search("quantity", "1");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("103|1620|1\n", returned.c_str());
		}

		/// \brief tests if the InvoiceItem class can modify a quantity in the InvoiceItem table
		TEST_METHOD(TestInvoiceItemModifyQuantity)
		{
			Logger::WriteMessage("TestInvoiceItemModifyQuantity");

			try { // allow to be able to test invoiceItem in isolation
			invoiceItem->modifyRow("102", "quantity", "9001"); // change 102's quantity to 9001
			}
			catch (DoesNotExistException e) { // catches Summary's failed search and allows it
			}

			string returned = invoiceItem->search("invoice_item_id", "102");

			Logger::WriteMessage(returned.c_str());

			Assert::AreEqual("102|1002|9001\n", returned.c_str());
		}
	};
}