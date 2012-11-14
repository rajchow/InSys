#include "stdafx.h"
#include "CppUnitTest.h"

#include "../InventoryManagement/Product.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestInventory
{
	/// Pointer to TableInterface to be used for interacting with the Product table
	Table prod;
	
	/// Unit test class for testing Product class
	TEST_CLASS(productTests)
	{
	public:
		
		/// \brief Setup before the Test class
		///
		/// - Sets cat to point to a Product table class
		/// - Clears the Product table in the database and then adds data for testing
		TEST_METHOD_INITIALIZE(setup)
		{
			Logger::WriteMessage("TEST_CLASS setup");

			prod = new Product();
			
			ofstream ofstr;
			ofstr.open("textFiles/product.txt", ios_base::trunc); // clear Category table
			
			// Data for testing
			ofstr << "1425|1|24 pack 355mL cans of Budget Brand Cola|BBCola24|5.98\n";
			ofstr << "2543|1|6 pack 710mL bottle Budget Brand Root Beer|BBRootBeer6Bottle|3.49\n";
			ofstr << "1002|2|250g bag Budget Brand Regular Tortilla Chips|BBRegTortillaChip|2.24\n";
		
			ofstr.close();
		}

		/// \brief Clean up function after test class is run
		TEST_METHOD_CLEANUP(teardown)
		{
			Logger::WriteMessage("TEST_CLASS cleanup\n");

			delete prod;
		}

		/// \brief Test that the product class can successfully search by product_id
		TEST_METHOD(TestProductSearchByProductID)
		{
			Logger::WriteMessage("TestProductSearchByProductID");

			// String to store value returned by Category::search
			string productReturned;

			productReturned = prod->search("product_id", "1425");

			// Logs test name and returned values
			const char *p;
			p = productReturned.c_str();
			Logger::WriteMessage(p);

			// Asserts what is expected with what is actually returned
			Assert::AreEqual("1425|1|24 pack 355mL cans of Budget Brand Cola|BBCola24|5.98\r\n", productReturned.c_str());
		}

		/// \brief Test that the product class can successfully search by category_id
		/// 
		/// Should be capable of returning multiple results with the same category_id
		TEST_METHOD(TestProductSearchByCategoryID)
		{
			Logger::WriteMessage("TestProductSearchByCategoryID");

			// String to store value returned by Category::search
			string productReturned;

			// string to store the expected return
			string expectedReturn = "1425|1|24 pack 355mL cans of Budget Brand Cola|BBCola24|5.98\r\n2543|1|6 pack 710mL bottle Budget Brand Root Beer|BBRootBeer6Bottle|3.49\r\n";

			productReturned = prod->search("category_id", "1");

			// Logs test name and returned values
			const char *p;
			p = productReturned.c_str();
			Logger::WriteMessage(p);

			// Asserts what is expected with what is actually returned
			Assert::AreEqual(expectedReturn.c_str(), productReturned.c_str());
		}

		/// \brief Test that the product class can successfully search by description
		TEST_METHOD(TestProductSearchByDescription)
		{
			Logger::WriteMessage("TestProductSearchByDescription");

			string productReturned;

			productReturned = prod->search("description", "6 pack 710mL bottle Budget Brand Root Beer");

			const char *p;
			p = productReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("2543|1|6 pack 710mL bottle Budget Brand Root Beer|BBRootBeer6Bottle|3.49\r\n", productReturned.c_str());
		}

		/// \brief Test that the product class can successfully search by name
		TEST_METHOD(TestProductSearchByName)
		{
			Logger::WriteMessage("TestProductSearchByName");

			string productReturned;

			productReturned = prod->search("name", "BBRootBeer6Bottle");

			const char *p;
			p = productReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("2543|1|6 pack 710mL bottle Budget Brand Root Beer|BBRootBeer6Bottle|3.49\r\n", productReturned.c_str());
		}

		/// \brief Test that the product class can successfully search by price
		TEST_METHOD(TestProductSearchByPrice)
		{
			Logger::WriteMessage("TestProductSearchByPrice");

			string productReturned;

			productReturned = prod->search("price", "3.49");

			const char *p;
			p = productReturned.c_str();
			Logger::WriteMessage(p);

			Assert::AreEqual("2543|1|6 pack 710mL bottle Budget Brand Root Beer|BBRootBeer6Bottle|3.49\r\n", productReturned.c_str());
		}

		/// \brief Test that the product::search function throws an exception when searching for a value that does not exist
		TEST_METHOD(TestProductSearchThrowsException)
		{
			// identifies in the test log which test method is currently active
			Logger::WriteMessage("TestProductSearchThrowsException");

			// string for the search return string
			string returnedString;

			try{
				// call the product search function to ensure that the product was successfully deleted
				returnedString = prod->search("product_id", "9999");

				// if exception is thrown by prod->search then this line should not run
				Assert::Fail(L"No exception for input",LINE_INFO());
			} catch(DoesNotExistException e) {
				// Correct exception caught
			} catch(...)
			{
				Assert::Fail(L"Wrong Exception Caught", LINE_INFO());
			}
		}

		/// \brief Test that product class prevents adding duplicate product_id data
		TEST_METHOD(TestProductAddAlreadyExists)
		{
			// identifies in the test log which test method is currently active
			Logger::WriteMessage("TestProductAddAlreadyExists");

			// string for the search return string
			string returnedString;

			// string containing the expected information to be received from the search
			string stringExpected = "Product ID already exists";

			// vector to contain the information for the required columns for a new entry
			vector<string> prodVector;
			// insertion of the test data into the vector to be passed as the argument for the add function
			prodVector.push_back("1425");
			prodVector.push_back("3");
			prodVector.push_back("150g bag Budget Brand Gummy Worms");
			prodVector.push_back("BBGummyWorms");
			prodVector.push_back("1.98");

			try{
				// calling the category add function
				prod->add(prodVector);
				Assert::Fail(L"No exception for input",LINE_INFO());
			} catch(AlreadyExistsException e)
			{
				// Correct exception caught
			} catch(...) 
			{
				Assert::Fail(L"Wrong Exception Caught", LINE_INFO());
			}
		}

		/// \brief Test that product class successfully adds a new product item
		TEST_METHOD(TestProductAdd)
		{
			// identifies in the test log which test method is currently active
			Logger::WriteMessage("TestProductAdd");

			// string for the search return string
			string productReturned;

			// string containing the expected information to be received from the search
			string productExpected = "1000|2|550g bag Budget Brand All Dressed Potato Chips|BBAllDressedLarge|4.98\r\n";

			// vector to contain the information for the required columns for a new entry
			vector<string> prodVector;
			// insertion of the test data into the vector to be passed as the argument for the add function
			prodVector.push_back("1000");
			prodVector.push_back("2");
			prodVector.push_back("550g bag Budget Brand All Dressed Potato Chips");
			prodVector.push_back("BBAllDressedLarge");
			prodVector.push_back("4.98");

			// calling the category add function
			prod->add(prodVector);

			// calling the category seach function to ensure that the add function was successful
			productReturned = prod->search("product_id", "1000");
			
			// convert the returned string to a const char to output in the test log
			const char *p;
			p = productReturned.c_str();
			Logger::WriteMessage(p);
			
			// assert that the return string matches the expected return string
			// in this case the expected return is "4|testDescription|testName\n"
			Assert::AreEqual(productExpected, productReturned);
		}

		/// \brief Test that the product class can successfully delete a product
		TEST_METHOD(TestProductDelete)
		{
			// identifies in the test log which test method is currently active
			Logger::WriteMessage("TestProductDelete");

			// string for the search return string
			string returnedString;

			// call the product delete function
			prod->deleteRow("1425");

			try{
				// call the product search function to ensure that the product was successfully deleted
				returnedString = prod->search("product_id", "1425");

				// if exception is thrown by prod->search then this line should not run
				Assert::Fail(L"No exception for input",LINE_INFO());
			} catch(DoesNotExistException e) {
				// Correct exception caught
			} catch(...)
			{
				Assert::Fail(L"Wrong Exception Caught", LINE_INFO());
			}
		}

		/// \brief Test that the product class can successfully modify the data for a product
		TEST_METHOD(TestProductModify)
		{
			// identifies in the test log which test method is currently active
			Logger::WriteMessage("TestProductModify");
			
			// string for the search return string
			string returnedString;
			
			// string containing the expected information to be received from the search
			string expectedString = "1425|1|Description Modified|Name Modified|1.11\r\n";

			// call the product modify function to modify the description
			prod->modifyRow("1425","description","Description Modified");
			// call the product modify function to modify the name
			prod->modifyRow("1425","name","Name Modified");
			// call the product modify function to modify the price
			prod->modifyRow("1425","price","1.11");

			// call the category search function to ensure that the product was successfully modified
			returnedString = prod->search("product_id", "1425");

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