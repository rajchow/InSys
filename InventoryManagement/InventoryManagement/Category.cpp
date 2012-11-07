#include "Category.h"

void Category :: add(vector<string> addVector)
{
	// assign to char delim the | character as the desired delimiter
	delim = '|';

	// place the contents of the vector argument into strings descript and name
	string descript = addVector[0];
	string name = addVector[1];
	
	// open the file "category.txt"
	categoryInFile.open("category.txt");

	// ensure that the file is opened
	if(categoryInFile.is_open())
	{
		// assigns an initial value (0) to catID
		catID = 0;

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
	categoryOutFile.open("category.txt", ios_base::app);

	// writes to category.txt the new row data as defined by categoryID, descript, 
	// and name, with delimiters between each input and a line break at the end
	categoryOutFile<<"" + categoryID + delim + descript + delim + name + "\n";

	// closes category.txt
	categoryOutFile.close();

}

string Category :: search(string columnName, string valueToFind)
{
	// assign to char delim the | character as the desired delimiter
	delim = '|';

	// opens category.txt
	categoryInFile.open("category.txt");

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
			description = rowReceive.substr(delimiter+1, delimiter2-2);

			// retrieves the name from the row data and assigns it to string name
			name = rowReceive.substr(delimiter2+1);

			// checks if columnName (argument) is "category_id" and if category_id data of current row matches 
			// valueToFind (argument)
			if(columnName == "category_id" && 
				atoi(categoryID.c_str()) == atoi(valueToFind.c_str()))
				// breaks the loop if parameters are met
				break;

			// checks if columnName (argument) is "description" and if description data of current row matches
			// valueToFind (argument)
			else if(columnName == "description" &&		//*** if statements in while loops probably isn't the
				description == valueToFind)				//*** most efficient method. Maybe we need Strategy Pattern?
														//*** instead of columnName as a parameter, 
														//*** maybe a SearchStrategy object?
				// breaks the loop if parameters are met
				break;

			// checks if columnName (argument) is "name" and if name data of current row matches
			// valueToFind (argument)
			else if(columnName == "name" &&
				name == valueToFind)
				// breaks the loop if parameters are met
				break;

		}
	}
	// closes category.txt
	categoryInFile.close();

	// concatenates the row that matched the search arguments to the string returnString 
	// along with a line break at the end
	returnString += rowReceive + "\n";
	
	// checks if returnString contains less than the minimum number of characters (category_id and two delimiters)
	if(returnString.size() < 3)
	{
		// if returnString did not receive any row data it is assigned a string stating that the row does not exist
		returnString = "Category Does Not Exist";
	}

	// \return returnString is returned as a result of the search function
	return returnString;
}

void Category :: deleteRow(string columnName, string valueToFind)
{
	// vector to store all rows of the file except the one to be deleted then to be rewritten to the file
	vector<string> catFileVect;

	// assign to char delim the | character as the desired delimiter
	delim = '|';

	// opens category.txt
	categoryInFile.open("category.txt");

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
			description = rowReceive.substr(delimiter+1, delimiter2-2);

			// retrieves the name from the row data and assigns it to string name
			name = rowReceive.substr(delimiter2+1);

			// checks that if
			// columnName (argument) = category_id and the valueToFind (argument) does not match the current 
			//		row category_id value then the row is written to the vector
			// columnName (argument) = description and the valueToFind (argument) does not match the current 
			//		row description value then the row is written to the vector
			// columnName (argument) = name and the valueToFind (argument) does not match the current 
			//		row name value then the row is written to the vector
			// 
			// if the columnName (argument) and the valueToFind (argument) do match the current row
			//		the row is skipped (ie - deleted) and not written to the vector
			if((columnName == "category_id" && atoi(categoryID.c_str()) != atoi(valueToFind.c_str())) 
				|| ((columnName == "description" && description != valueToFind)) 
				|| ((columnName == "name" && name != valueToFind)))
			{
				catFileVect.push_back(rowReceive);
			}
		}
	}
	
	// closes category.txt
	categoryInFile.close();
	
	// opens category.txt and eliminates all contents and prepares to write values from the vector to category.txt
	categoryOutFile.open("category.txt", ios_base::trunc);
	
	// iterates through catFileVect and places each string from the vector into category.txt
	for(int i = 0; i < (int) catFileVect.size(); i++)
	{
		// writes string from vector into category.txt
		categoryOutFile<<catFileVect[i]<<endl;
	}
	
	// closes category.txt
	categoryOutFile.close();
}