#include "Product.h"

string Product :: add(vector<string> addVector) throw(AlreadyExistsException)
{
	// assigns the value for the name of the textfile to be used
	productTextFile = "textFiles/product.txt";

	// string to contain the contents of a row received from the file
	string rowReceive;

	// assign to char delim the | character as the desired delimiter
	char delim = '|';

	// string prodID to be used when searching through products for already existing product_id
	string prodID;

	// strings to contain the contents of the vector argument
	string productID = addVector[0];
	string categoryID = addVector[1];
	string productDescription = addVector[2];
	string productName = addVector[3];
	string productPrice = addVector[4];
	try
	{
		// open the product.txt file
		productInFile.open(productTextFile);

		// ensure that the file is opened
		if(productInFile.is_open())
		{

			// while loop continues as long as there is another line in the text file
			while(productInFile.good())
			{
				// retrieves the next line in categoryInFile and assigns it to the string rowReceive
				getline(productInFile, rowReceive);

				// retrieves the category_ID as a substring of the entire row and sets it to the string categoryID
				prodID = rowReceive.substr(0,rowReceive.find(delim));

				// Checks if the product_id of the current row is equal to the productID to be added to the file
				if(prodID == productID)
				{
					throw AlreadyExistsException("Product ID already exists");
				}
			}
		}

		// close product.txt file
		productInFile.close();

		// opens product.txt for output
		productOutFile.open(productTextFile, ios_base::app);

		// appends to the file the new product data
		productOutFile<<productID + "|" + categoryID + "|" + productDescription + "|" + productName + "|" + productPrice + "\n";

		// closes product.txt
		productOutFile.close();

		// returns a string notifying the user of a successful add
		return "Product Added Successfully";

	} catch(AlreadyExistsException e)
	{
		return e.what();
	}
}

string Product :: search(string columnName, string valueToFind) throw(DoesNotExistException)
{
	// assigns the value for the name of the textfile to be used
	productTextFile = "textFiles/product.txt";
	return NULL;
}

void Product :: deleteRow(string columnName, string valueToFind)
{
	// assigns the value for the name of the textfile to be used
	productTextFile = "textFiles/product.txt";
}

void Product :: modifyRow(string valueToFind, string columnNameToModify, string valueOfModify)
{
	// assigns the value for the name of the textfile to be used
	productTextFile = "textFiles/product.txt";
}