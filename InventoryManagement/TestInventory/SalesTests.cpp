#include "stdafx.h"
#include "CppUnitTest.h"
#include "../InventoryManagement/Sales.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestInventory
{		
	Table sale;

	TEST_CLASS(salesTests)
	{

	public:

		TEST_METHOD_INITIALIZE(setup)
		{
			Logger::WriteMessage("TEST_CLASS setup");

			sale = new Sales();

			ofstream ofstr;
			ofstr.open("textFiles/sales.txt", ios_base::trunc); // clear Category table

			// Data for testing
			ofstr << "1|10|5|1\n";
			ofstr << "2|5|2|2\n";
			ofstr << "3|80|20|3\n";
			ofstr << "4|2|2|4\n";

			ofstr.close();
		}

		TEST_METHOD_CLEANUP(teardown)
		{
			Logger::WriteMessage("TEST_CLASS cleanup");

			delete sale;
		}

		TEST_METHOD(TestSalesSearchBySalesID)
		{
			Logger::WriteMessage("TestSalesSearchBySalesID");

			string salesReturned;

			salesReturned = sale->search("sales_id", "1");

			const char *p;
			p = salesReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("1|10|5|1\n", salesReturned.c_str());
		}

		TEST_METHOD(TestSalesSearchByQuantitySold)
		{
			Logger::WriteMessage("TestSalesSearchByQuantitySold");

			string salesReturned;

			salesReturned = sale->search("quantity_sold", "10");

			const char *p;
			p = salesReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("1|10|5|1\n", salesReturned.c_str());

		}

		TEST_METHOD(TestSalesSearchByDiscount)
		{
			Logger::WriteMessage("TestSalesSearchByDiscount");

			string salesReturned;

			salesReturned = sale->search("discount", "2");

			const char *p;
			p = salesReturned.c_str();
			Logger::WriteMessage(p);
			
			Assert::AreEqual("2|5|2|2\n", salesReturned.c_str());

		}
		TEST_METHOD(TestSalesSearchByProductID)
		{
			Logger::WriteMessage("TestSalesSearchByProductID");

			string salesReturned;

			salesReturned = sale->search("productID", "2");

			const char *p;
			p = salesReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("2|5|2|2\n" "4|2|2|4\n", salesReturned.c_str());

		}

		TEST_METHOD(TestSalesAdd)
		{
			Logger::WriteMessage("TestSalesAdd");

			string salesReturned;

			string salesExpected = "5|2|5|80\n";

			vector<string> saleVector;
			saleVector.push_back("2");
			saleVector.push_back("80");
			saleVector.push_back("5");
			sale->add(saleVector);

			salesReturned = sale->search("sales_id", "5");

			const char *p;
			p = salesReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual(salesExpected, salesReturned);
		}
		TEST_METHOD(TestSalesModify)
		{
			Logger::WriteMessage("TestSalesModify");

			string returnedString;

			string expectedString = "1|10|6|1\n";

			sale->modifyRow("1","productID","6");

			returnedString = sale->search("sales_id", "1");

			const char *p;
			p = returnedString.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual(expectedString,returnedString);
		}

		TEST_METHOD(TestSalesDelete)
		{
			Logger::WriteMessage("TestSalesDelete");

			string returnedString;

			string expectedString = "Sales Does Not Exist";

			sale->deleteRow("3");

			try{
				// call the category search function to ensure that the category was successfully deleted
				returnedString = sale->search("sales_id", "3");
				Assert::Fail(L"No exception for input",LINE_INFO());
			} catch(DoesNotExistException e) {
				
			} catch(...)
			{
				Assert::Fail(L"Wrong Exception Caught", LINE_INFO());
			}
					
		}
		
	};
}