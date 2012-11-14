#include "Product.h"

void Product :: add(vector<string> addVector) throw(AlreadyExistsException)
{
	// list to retrieve all rows in the file, sort by product_id, then write back to the file
	list<string> prodList;

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

			// adds current row to the list if it is not empty
			if(rowReceive.size() != 0)
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
}

string Product :: search(string columnName, string valueToFind) throw(DoesNotExistException)
{

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
			categoryID = rowReceive.substr(delimiter+1, delimiter2-delimiter-1);

			// retrieves the product description from the row data and assigns it to productDescription
			productDescription = rowReceive.substr(delimiter2+1, delimiter3-delimiter2-1);

			// retrieves the product name from the row data and assigns it to productName
			productName = rowReceive.substr(delimiter3+1, delimiter4-delimiter3-1);

			// retrieves the price from the row data and assigns it to productPrice
			productPrice = rowReceive.substr(delimiter4+1);

			// checks if columnName (argument) is "product_id" and if product_id data of current row matches 
			// valueToFind (argument)
			if(columnName == "product_id" && 
				atoi(productID.c_str()) == atoi(valueToFind.c_str()))
			{
				// concatenates the row that matched the search arguments to the string returnString 
				// along with a line break at the end
				returnString += rowReceive + "\r\n";

				resultFound = true;
			}
				
			// checks if columnName (argument) is "category_id" and if category_id data of current row matches 
			// valueToFind (argument)
			else if(columnName == "category_id" && 
				atoi(categoryID.c_str()) == atoi(valueToFind.c_str()))
			{
				// concatenates the row that matched the search arguments to the string returnString 
				// along with a line break at the end
				returnString += rowReceive + "\r\n";

				resultFound = true;
			}
				
			// checks if columnName (argument) is "description" and if product description data of current row matches 
			// valueToFind (argument)
			else if(columnName == "description" && 
				atoi(productDescription.c_str()) == atoi(valueToFind.c_str()))
			{
				// concatenates the row that matched the search arguments to the string returnString 
				// along with a line break at the end
				returnString += rowReceive + "\r\n";

				resultFound = true;
			}
				
			// checks if columnName (argument) is "name" and if product name data of current row matches 
			// valueToFind (argument)
			else if(columnName == "name" && 
				productName == valueToFind)
			{
				// concatenates the row that matched the search arguments to the string returnString 
				// along with a line break at the end
				returnString += rowReceive + "\r\n";

				resultFound = true;
			}
				
			// checks if columnName (argument) is "price" and if product price data of current row matches 
			// valueToFind (argument)
			else if(columnName == "price" && 
				atof(productPrice.c_str()) == atof(valueToFind.c_str()))
			{
				// concatenates the row that matched the search arguments to the string returnString 
				// along with a line break at the end
				returnString += rowReceive + "\r\n";

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
}

void Product :: deleteRow(string valueToFind)
{
	// string to contain the contents of a row received from the file
	string rowReceive;

	// string to contain the category_ID from a received row of data
	string productID;

	// ints to store the position of the first delimiter
	int delimiter;

	// vector to store all rows of the file except the one to be deleted then to be rewritten to the file
	vector<string> prodFileVect;

	// assign to char delim the | character as the desired delimiter
	char delim = '|';

	// opens category.txt
	productInFile.open(productTextFile);

	// ensures that categoryInFile is open
	if(productInFile.is_open())
	{
		// while loop continues as long as there is another line in the text file
		while(productInFile.good())
		{
			// retrieves the next line in categoryInFile and assigns it to the string rowReceive
			getline(productInFile, rowReceive);

			// finds the first delimiter position and assigns it to int delimiter
			delimiter = rowReceive.find('|');

			// retrieves the category_ID from the row data and assigns it to categoryID
			productID = rowReceive.substr(0,delimiter);

			// checks that if the valueToFind (argument) does not match the current row
			//		the row is written to the vector (if it does match the row is skipped - deleted)
			if(atoi(productID.c_str()) != atoi(valueToFind.c_str()))
			{
				prodFileVect.push_back(rowReceive);
			}
		}
	}
	
	// closes category.txt
	productInFile.close();
	
	// opens category.txt and eliminates all contents and prepares to write values from the vector to category.txt
	productOutFile.open(productTextFile, ios_base::trunc);
	
	// iterates through catFileVect and places each string from the vector into category.txt
	for(int i = 0; i < (int) prodFileVect.size(); i++)
	{
		if(prodFileVect[i].size() > 0)
			// writes string from vector into category.txt
			productOutFile<<prodFileVect[i]<<endl;
	}
	
	// closes category.txt
	productOutFile.close();
}

void Product :: modifyRow(string valueToFind, string columnNameToModify, string valueOfModify)
{
	// string to contain the row data received from the file
	string rowReceive;
	
	// string to contain the category_ID from a received row of data
	string productID;
	
	//strings used to store the description and name values in a row
	string categoryID, description, name, price;

	// vector to store all rows of the file then to be rewritten to the file with the required modifications
	vector<string> prodFileVect;

	// ints to store the position of the first and second delimiters
	int delimiter;
	int delimiter2;
	int delimiter3;
	int delimiter4;

	// assign to char delim the | character as the desired delimiter
	char delim = '|';

	// opens category.txt
	productInFile.open(productTextFile);

	// ensures that categoryInFile is open
	if(productInFile.is_open())
	{
		// while loop continues as long as there is another line in the text file
		while(productInFile.good())
		{
			// retrieves the next line in categoryInFile and assigns it to the string rowReceive
			getline(productInFile, rowReceive);

			// finds the first delimiter position and assigns it to int delimiter
			delimiter = rowReceive.find('|');
			
			// finds the second delimiter position and assigns it to int delimiter2
			delimiter2 = rowReceive.find('|', delimiter+1);
			
			// finds the second delimiter position and assigns it to int delimiter3
			delimiter3 = rowReceive.find('|', delimiter2+1);
			
			// finds the second delimiter position and assigns it to int delimiter4
			delimiter4 = rowReceive.find('|', delimiter3+1);

			// retrieves the product_ID from the row data and assigns it to productID
			productID = rowReceive.substr(0,delimiter);

			// retrieves the category_id from the row data and assigns it to string categoryID
			categoryID = rowReceive.substr(delimiter+1, delimiter2-delimiter-1);

			// retrieves the description from the row data and assigns it to string description
			description = rowReceive.substr(delimiter2+1, delimiter3-delimiter2-1);

			// retrieves the name from the row data and assigns it to string name
			name = rowReceive.substr(delimiter3+1, delimiter4-delimiter3-1);

			// retrieves the price from the row data and assigns it to string price
			price = rowReceive.substr(delimiter4+1);

			// if - the valueToFind (argument) does not match the current row product_id value then the row is written to the vector
			// 
			// else - if the valueToFind (argument) do match the current row the row is modified with the desired changes
			if(atoi(productID.c_str()) != atoi(valueToFind.c_str()))
			{
				prodFileVect.push_back(rowReceive);
			} else {
				// checks if the desired column to change is categoryID and inputs the row with the new category_id into the vector
				if(columnNameToModify == "categoryID")
					prodFileVect.push_back(productID + delim + valueOfModify + delim + description + delim + name + delim + price);
				// checks if the desired column to change is description and inputs the row with the new description into the vector
				else if(columnNameToModify == "description")
					prodFileVect.push_back(productID + delim + categoryID + delim + valueOfModify + delim + name + delim + price);
				// checks if the desired column to change is name and inputs the row with the new name into the vector
				else if(columnNameToModify == "name")
					prodFileVect.push_back(productID + delim + categoryID + delim + description + delim + valueOfModify + delim + price);
				// checks if the desired column to change is price and inputs the row with the new price into the vector
				else if(columnNameToModify == "price")
					prodFileVect.push_back(productID + delim + categoryID + delim + description + delim + name + delim + valueOfModify);
			}
		}
	}
	
	// closes category.txt
	productInFile.close();
	
	// opens category.txt and eliminates all contents and prepares to write values from the vector to category.txt
	productOutFile.open(productTextFile, ios_base::trunc);
	
	// iterates through catFileVect and places each string from the vector into category.txt
	for(int i = 0; i < (int) prodFileVect.size(); i++)
	{
		if(prodFileVect[i].size() > 0)
			// writes string from vector into category.txt
			productOutFile<<prodFileVect[i]<<endl;
	}
	
	// closes category.txt
	productOutFile.close();
}

// Initializes productTextFile
Product::Product() { productTextFile = "textFiles/product.txt"; }

Product::~Product(){}