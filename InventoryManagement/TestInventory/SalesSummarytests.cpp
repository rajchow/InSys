#include "stdafx.h"
#include "CppUnitTest.h"
#include "../InventoryManagement/SalesSummary.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestInventory
{		
	/// Pointer to TableInterface 
	Table ss;

	/// Unit test class for testing Sales Summary class
	TEST_CLASS(SalesSummarytests)
	{

	public:

		/// \brief Setup before the Test class
		TEST_METHOD_INITIALIZE(setup)
		{
			Logger::WriteMessage("TEST_CLASS setup");

			ss = new SalesSummary();

			ofstream ofstr;
			ofstr.open("textFiles/SalesSummary.txt", ios_base::trunc); // clear Category table

			// Data for testing
			ofstr << "1|001\n";
			ofstr << "2|002\n";
			ofstr << "3|003\n";

			ofstr.close();
		}

		/// \brief Clean up function after test class is run
		TEST_METHOD_CLEANUP(teardown)
		{
			Logger::WriteMessage("TEST_CLASS cleanup");

			delete ss;
		}

		TEST_METHOD(TestSalesSummarySearchByReceiptID)
		{
			Logger::WriteMessage("TestSalesSummarySearchByReceiptID");

			string ssReturned;

			ssReturned = ss->search("receiptID", "2");

			const char *p;
			p = ssReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("2|002\n", ssReturned.c_str());
		}

		TEST_METHOD(TestSalesSummarySearchBySalesID)
		{
			Logger::WriteMessage("TestSalesSummarySearchBySalesID");

			string ssReturned;

			ssReturned = ss->search("salesID", "003");

			const char *p;
			p = ssReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("3|003\n", ssReturned.c_str());

		}
		TEST_METHOD(TestSalesSummaryAdd)
		{
			Logger::WriteMessage("TestSalesSummaryAdd");

			string ssReturned;

			string ssExpected = "4|004\n";

			vector<string> ssVector;
			
			ssVector.push_back("4");
			ssVector.push_back("004");

			ss->add(ssVector);

			ssReturned = ss->search("receiptID", "4");

			const char *p;
			p = ssReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual(ssExpected, ssReturned);
		}
};
}