#include "stdafx.h"
#include "CppUnitTest.h"
#include "../InventoryManagement/TableInterface.h"
#include "../InventoryManagement/Product.h"
#include "../InventoryManagement/Product.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestInventory
{
	/// Pointer to TableInterface to be used for interacting with the Category table
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
		}

		/// \brief Clean up function after test class is run
		TEST_METHOD_CLEANUP(teardown)
		{
			Logger::WriteMessage("TEST_CLASS cleanup");
		}

	};
}