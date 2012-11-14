#include "Category.h"

void Category :: add(vector<string> addVector) throw(AlreadyExistsException)
{
	// string to contain the contents of a row received from the file
	string rowReceive;

	// string to contain the category_ID from a received row of data
	string categoryID;

	// int to store the position of the delimiter
	int delimiter;

	// int to store the category_ID while checking if it is the highest category_ID value used
	int categoryIDTemp;

	// int to store the category_ID to be used for adding data to the category.txt file
	int catID = 0;

	// assign to char delim the | character as the desired delimiter
	char delim = '|';

	// place the contents of the vector argument into strings descript and name
	string descript = addVector[0];
	string name = addVector[1];
	
	// open the file "category.txt"
	categoryInFile.open(categoryTextFile);

	// ensure that the file is opened
	if(categoryInFile.is_open())
	{

		// while loop continues as long as there is another line in the text file
		while(categoryInFile.good())
		{
			// retrieves the next line in categoryInFile and assigns it to the string rowReceive
			getline(categoryInFile, rowReceive);

			// Searches for the position of the delimiter
			delimiter = rowReceive.find(delim);

			// retrieves the category_ID as a substring of the entire row and sets it to the string categoryID
			categoryID = rowReceive.substr(0,delimiter);

			// converts categoryID to an integer and assigns it to categoryIDTemp
			categoryIDTemp = atoi(categoryID.c_str());

			// Checks if the current categoryIDTemp is greater then the previously assigned category_ID (int catID)
			if(categoryIDTemp > catID)
			{
				// if categoryIDTemp is greater than catID, catID is set to be the same as categoryIDTemp
				catID = categoryIDTemp;
			}
		}
	}

	// closes the file
	categoryInFile.close();

	// increments catID so that it is one larger than the largest existing category_ID
	catID++;

	// converts catID to a string and assigns it to string categoryID
	categoryID = to_string(catID);

	// opens file category.txt
	categoryOutFile.open(categoryTextFile, ios_base::app);

	// writes to category.txt the new row data as defined by categoryID, descript, 
	// and name, with delimiters between each input and a line break at the end
	categoryOutFile<<"" + categoryID + delim + descript + delim + name + "\n";

	// closes category.txt
	categoryOutFile.close();

}

string Category :: search(string columnName, string valueToFind) throw(DoesNotExistException)
{
	// bool to tell whether a match was found or not
	bool resultFound = false;

	// string to be used to return the results of a search
	string returnString;

	// string to contain the contents of a row received from the file
	string rowReceive;

	// string to contain the category_ID from a received row of data
	string categoryID;
	
	//strings used to store the description and name values in a row
	string description, name;

	// ints to store the position of the first and second delimiters
	int delimiter;
	int delimiter2;

	// assign to char delim the | character as the desired delimiter
	char delim = '|';

	// opens category.txt
	categoryInFile.open(categoryTextFile);

	// ensures that categoryInFile is open
	if(categoryInFile.is_open())
	{
		// initially clears all text from returnString
		returnString.clear();

		// while loop continues as long as there is another line in the text file
		while(categoryInFile.good())
		{
			// retrieves the next line in categoryInFile and assigns it to the string rowReceive
			getline(categoryInFile, rowReceive);

			// finds the first delimiter position and assigns it to int delimiter
			delimiter = rowReceive.find('|');
			
			// finds the second delimiter position and assigns it to int delimiter2
			delimiter2 = rowReceive.find('|', delimiter+1);

			// retrieves the category_ID from the row data and assigns it to categoryID
			categoryID = rowReceive.substr(0,delimiter);

			// retrieves the description from the row data and assigns it to string description
			description = rowReceive.substr(delimiter+1, delimiter2-delimiter-1);

			// retrieves the name from the row data and assigns it to string name
			name = rowReceive.substr(delimiter2+1);

			// checks if columnName (argument) is "category_id" and if category_id data of current row matches 
			// valueToFind (argument)
			if(columnName == "category_id" && 
				atoi(categoryID.c_str()) == atoi(valueToFind.c_str()))
			{
				// concatenates the row that matched the search arguments to the string returnString 
				// along with a line break at the end
				returnString += rowReceive;

				resultFound = true;
			}

			// checks if columnName (argument) is "description" and if description data of current row matches
			// valueToFind (argument)
			else if(columnName == "description" && 
				description == valueToFind)
			{
				// concatenates the row that matched the search arguments to the string returnString 
				// along with a line break at the end
				returnString += rowReceive + "\r\n";

				resultFound = true;
			}
			// checks if columnName (argument) is "name" and if name data of current row matches
			// valueToFind (argument)
			else if(columnName == "name" &&
				name == valueToFind)
			{
				// concatenates the row that matched the search arguments to the string returnString 
				// along with a line break at the end
				returnString += rowReceive + "\r\n";

				resultFound = true;
			}
		}
	}
	// closes category.txt
	categoryInFile.close();

	if(!resultFound)
		throw DoesNotExistException("Category Does Not Exist");

	// \return returnString is returned as a result of the search function
	return returnString;
}

void Category :: deleteRow(string valueToFind)
{
	// string to contain the contents of a row received from the file
	string rowReceive;

	// string to contain the category_ID from a received row of data
	string categoryID;

	// ints to store the position of the first delimiter
	int delimiter;

	// vector to store all rows of the file except the one to be deleted then to be rewritten to the file
	vector<string> catFileVect;

	// assign to char delim the | character as the desired delimiter
	char delim = '|';

	// opens category.txt
	categoryInFile.open(categoryTextFile);

	// ensures that categoryInFile is open
	if(categoryInFile.is_open())
	{
		// while loop continues as long as there is another line in the text file
		while(categoryInFile.good())
		{
			// retrieves the next line in categoryInFile and assigns it to the string rowReceive
			getline(categoryInFile, rowReceive);

			// finds the first delimiter position and assigns it to int delimiter
			delimiter = rowReceive.find('|');

			// retrieves the category_ID from the row data and assigns it to categoryID
			categoryID = rowReceive.substr(0,delimiter);

			// checks that if the valueToFind (argument) does not match the current row
			//		the row is written to the vector (if it does match the row is skipped - deleted)
			if(atoi(categoryID.c_str()) != atoi(valueToFind.c_str()))
			{
				catFileVect.push_back(rowReceive);
			}
		}
	}
	
	// closes category.txt
	categoryInFile.close();
	
	// opens category.txt and eliminates all contents and prepares to write values from the vector to category.txt
	categoryOutFile.open(categoryTextFile, ios_base::trunc);
	
	// iterates through catFileVect and places each string from the vector into category.txt
	for(int i = 0; i < (int) catFileVect.size(); i++)
	{
		if(catFileVect[i].size() > 0)
			// writes string from vector into category.txt
			categoryOutFile<<catFileVect[i]<<endl;
	}
	
	// closes category.txt
	categoryOutFile.close();
}

void Category :: modifyRow(string valueToFind, string columnNameToModify, string valueOfModify)
{
	// string to contain the row data received from the file
	string rowReceive;
	
	// string to contain the category_ID from a received row of data
	string categoryID;
	
	//strings used to store the description and name values in a row
	string description, name;

	// vector to store all rows of the file then to be rewritten to the file with the required modifications
	vector<string> catFileVect;

	// ints to store the position of the first and second delimiters
	int delimiter;
	int delimiter2;

	// assign to char delim the | character as the desired delimiter
	char delim = '|';

	// opens category.txt
	categoryInFile.open(categoryTextFile);

	// ensures that categoryInFile is open
	if(categoryInFile.is_open())
	{
		// while loop continues as long as there is another line in the text file
		while(categoryInFile.good())
		{
			// retrieves the next line in categoryInFile and assigns it to the string rowReceive
			getline(categoryInFile, rowReceive);

			// finds the first delimiter position and assigns it to int delimiter
			delimiter = rowReceive.find('|');
			
			// finds the second delimiter position and assigns it to int delimiter2
			delimiter2 = rowReceive.find('|', delimiter+1);

			// retrieves the category_ID from the row data and assigns it to categoryID
			categoryID = rowReceive.substr(0,delimiter);

			// retrieves the description from the row data and assigns it to string description
			description = rowReceive.substr(delimiter+1, delimiter2-delimiter-1);

			// retrieves the name from the row data and assigns it to string name
			name = rowReceive.substr(delimiter2+1);

			// if - the valueToFind (argument) does not match the current row category_id value then the row is written to the vector
			// 
			// else - if the valueToFind (argument) do match the current row the row is modified with the desired changes
			if(atoi(categoryID.c_str()) != atoi(valueToFind.c_str()))
			{
				catFileVect.push_back(rowReceive);
			} else {
				// checks if the desired column to change is description and inputs the row with the new description into the vector
				if(columnNameToModify == "description")
					catFileVect.push_back(categoryID + delim + valueOfModify + delim + name);
				// checks if the desired column to change is name and inputs the row with the new name into the vector
				else if(columnNameToModify == "name")
					catFileVect.push_back(categoryID + delim + description + delim + valueOfModify);
			}
		}
	}
	
	// closes category.txt
	categoryInFile.close();
	
	// opens category.txt and eliminates all contents and prepares to write values from the vector to category.txt
	categoryOutFile.open(categoryTextFile, ios_base::trunc);
	
	// iterates through catFileVect and places each string from the vector into category.txt
	for(int i = 0; i < (int) catFileVect.size(); i++)
	{
		if(catFileVect[i].size() > 0)
			// writes string from vector into category.txt
			categoryOutFile<<catFileVect[i]<<endl;
	}
	
	// closes category.txt
	categoryOutFile.close();

}

// Initializes categoryTextFile
Category::Category() { categoryTextFile = "textFiles/category.txt"; }

Category::~Category(){}