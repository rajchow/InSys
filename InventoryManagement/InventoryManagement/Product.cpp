#include "Product.h"

string Product :: add(vector<string> addVector) throw(AlreadyExistsException)
{
	// list to retrieve all rows in the file, sort by product_id, then write back to the file
	list<string> prodList;

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

				// adds current row to the list
				prodList.push_back(rowReceive);

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

		// adds new product to list
		prodList.push_back(productID + "|" + categoryID + "|" + productDescription + "|" + productName + "|" + productPrice);

		// sort the list
		prodList.sort();

		// opens product.txt for output
		productOutFile.open(productTextFile, ios_base::trunc);

		// iterator for prodList
		list<string>::iterator it;

		// output all strings in prodList to the file
		for(it = prodList.begin(); it != prodList.end(); ++it)
		{
			productOutFile<<*it<<endl;
		}

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

	// bool to tell whether a match was found or not
	bool resultFound = false;

	// string to be used to return the results of a search
	string returnString;

	// string to contain the contents of a row received from the file
	string rowReceive;

	// ints to store the position of the first, second, third, and fourth delimiters
	int delimiter;
	int delimiter2;
	int delimiter3;
	int delimiter4;

	// strings to contain the data from the current row retrieved from the file
	string productID;
	string categoryID;
	string productDescription;
	string productName;
	string productPrice;

	try{
		// opens category.txt
		productInFile.open(productTextFile);

		// ensures that categoryInFile is open
		if(productInFile.is_open())
		{
			// initially clears all text from returnString
			returnString.clear();

			// while loop continues as long as there is another line in the text file
			while(productInFile.good())
			{
				// retrieves the next line in categoryInFile and assigns it to the string rowReceive
				getline(productInFile, rowReceive);

				// finds the first delimiter position and assigns it to int delimiter
				delimiter = rowReceive.find('|');
			
				// finds the second delimiter position and assigns it to int delimiter2
				delimiter2 = rowReceive.find('|', delimiter+1);
			
				// finds the third delimiter position and assigns it to int delimiter3
				delimiter3 = rowReceive.find('|', delimiter2+1);
			
				// finds the fourth delimiter position and assigns it to int delimiter4
				delimiter4 = rowReceive.find('|', delimiter3+1);

				// retrieves the product_ID from the row data and assigns it to productID
				productID = rowReceive.substr(0,delimiter);

				// retrieves the category_ID from the row data and assigns it to categoryID
				categoryID = rowReceive.substr(delimiter+1, delimiter2-2);

				// retrieves the product description from the row data and assigns it to productDescription
				productDescription = rowReceive.substr(delimiter2+1, delimiter3-2);

				// retrieves the product name from the row data and assigns it to productName
				productName = rowReceive.substr(delimiter3+1, delimiter4-2);

				// retrieves the price from the row data and assigns it to productPrice
				productPrice = rowReceive.substr(delimiter4+1);

				// checks if columnName (argument) is "product_id" and if product_id data of current row matches 
				// valueToFind (argument)
				if(columnName == "product_id" && 
					atoi(productID.c_str()) == atoi(valueToFind.c_str()))
				{
					// concatenates the row that matched the search arguments to the string returnString 
					// along with a line break at the end
					returnString += rowReceive + "\n";

					resultFound = true;
				}
				
				// checks if columnName (argument) is "category_id" and if category_id data of current row matches 
				// valueToFind (argument)
				else if(columnName == "category_id" && 
					atoi(categoryID.c_str()) == atoi(valueToFind.c_str()))
				{
					// concatenates the row that matched the search arguments to the string returnString 
					// along with a line break at the end
					returnString += rowReceive + "\n";

					resultFound = true;
				}
				
				// checks if columnName (argument) is "productDescription" and if product description data of current row matches 
				// valueToFind (argument)
				else if(columnName == "productDescription" && 
					atoi(productDescription.c_str()) == atoi(valueToFind.c_str()))
				{
					// concatenates the row that matched the search arguments to the string returnString 
					// along with a line break at the end
					returnString += rowReceive + "\n";

					resultFound = true;
				}
				
				// checks if columnName (argument) is "productName" and if product name data of current row matches 
				// valueToFind (argument)
				else if(columnName == "productName" && 
					atoi(productName.c_str()) == atoi(valueToFind.c_str()))
				{
					// concatenates the row that matched the search arguments to the string returnString 
					// along with a line break at the end
					returnString += rowReceive + "\n";

					resultFound = true;
				}
				
				// checks if columnName (argument) is "productPrice" and if product price data of current row matches 
				// valueToFind (argument)
				else if(columnName == "productPrice" && 
					atoi(productPrice.c_str()) == atoi(valueToFind.c_str()))
				{
					// concatenates the row that matched the search arguments to the string returnString 
					// along with a line break at the end
					returnString += rowReceive + "\n";

					resultFound = true;
				}
			}
		}
		// closes product.txt
		productInFile.close();

		if(!resultFound)
			throw DoesNotExistException("Product Does Not Exist");

		// \return returnString is returned as a result of the search function
		return returnString;
	} catch(DoesNotExistException e)
	{
		return e.what();
	}
}

void Product :: deleteRow(string valueToFind)
{
	// assigns the value for the name of the textfile to be used
	productTextFile = "textFiles/product.txt";
}

void Product :: modifyRow(string valueToFind, string columnNameToModify, string valueOfModify)
{
	// assigns the value for the name of the textfile to be used
	productTextFile = "textFiles/product.txt";
}