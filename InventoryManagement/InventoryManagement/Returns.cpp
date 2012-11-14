#include "Returns.h"

void Returns :: add(vector<string> addVector)
{
	// assigns the value for the name of the textfile to be used
	returnsTextFile = "textFiles/returns.txt";

	// string to contain the contents of a row received from the file
	string rowReceive;

	// string to contain the returns_ID from a received row of data
	string returnsID;

	// ints to store the position of the first and second delimiters
	int delimiter;

	// int to store the returns_ID while checking if it is the highest returns_ID value used
	int returnsIDTemp;

	// int to store the returns_ID to be used for adding data to the returns.txt file
	int retID = 0;

	// assign to char delim the | character as the desired delimiter
	char delim = '|';

	// place the contents of the vector argument into strings descript and name
	string sales_id = addVector[0];
	string quantity_returned = addVector[1];
	string date_returned = addVector[2]; //YYYY-MM-DD

	// open the file "returns.txt"
	returnsInFile.open(returnsTextFile);

	// ensure that the file is opened
	if(returnsInFile.is_open())
	{

		// while loop continues as long as there is another line in the text file
		while(returnsInFile.good())
		{
			// retrieves the next line in returnsInFile and assigns it to the string rowReceive
			getline(returnsInFile, rowReceive);

			// Searches for the position of the delimiter
			delimiter = rowReceive.find(delim);

			// retrieves the returns_ID as a substring of the entire row and sets it to the string returnsID
			returnsID = rowReceive.substr(0,delimiter);

			// converts returnsID to an integer and assigns it to returnsIDTemp
			returnsIDTemp = atoi(returnsID.c_str());

			// Checks if the current returnsIDTemp is greater then the previously assigned returns_ID (int retID)
			if(returnsIDTemp > retID)
			{
				// if returnsIDTemp is greater than retID, retID is set to be the same as returnsIDTemp
				retID = returnsIDTemp;
			}
		}
	}

	// closes the file
	returnsInFile.close();

	// increments retID so that it is one larger than the largest existing returns_ID
	retID++;

	// converts retID to a string and assigns it to string returnsID
	returnsID = to_string(retID);

	// opens file returns.txt
	returnsOutFile.open(returnsTextFile, ios_base::app);

	// writes to returns.txt the new rows data (returnID, sales_id, quantity_returned, date returned)
	returnsOutFile<<"" + returnsID + delim + sales_id + delim + quantity_returned + delim + date_returned + "\n";

	returnsOutFile.close();
}

string Returns :: search(string columnName, string valueToFind)
{
	// assigns the value for the name of the textfile to be used
	returnsTextFile = "textFiles/returns.txt";

	// string to be used to return the results of a search
	string returnString;

	// string to contain the contents of a row received from the file
	string rowReceive;

	// string to contain the returns_ID from a received row of data
	string returnsID;

	//strings used to store the description and name values in a row
	string sales_id, quantity_returned, date_returned;

	// ints to store the position of the first and second delimiters
	int delimiter;
	int delimiter2;
	int delimiter3;

	// int to store the returns_ID to be used for adding data to the returns.txt file
	int retID = 0;

	// assign to char delim the | character as the desired delimiter
	char delim = '|';

	// opens returns.txt
	returnsInFile.open(returnsTextFile);

	// ensures that returnsInFile is open
	if(returnsInFile.is_open())
	{
		// initially clears all text from returnString
		returnString.clear();

		// while loop continues as long as there is another line in the text file
		while(returnsInFile.good())
		{
			// retrieves the next line in returnsInFile and assigns it to the string rowReceive
			getline(returnsInFile, rowReceive);

			// finds the positions of the delimeters and stores them in a variable
			delimiter = rowReceive.find(delim);
			delimiter2 = rowReceive.find(delim, delimiter+1);
			delimiter3 = rowReceive.find(delim, delimiter2+1);

			// retrieves the information from each column and puts it into a string variable
			returnsID = rowReceive.substr(0,delimiter);
			sales_id = rowReceive.substr(delimiter+1, delimiter2-delimiter-1);
			quantity_returned = rowReceive.substr(delimiter2+1, delimiter3-delimiter2-1);
			date_returned = rowReceive.substr(delimiter3+1);

			// checks if columnName (argument) is "returns_id" and if returns_id data of current row matches 
			// valueToFind (argument)
			if(columnName == "returns_id" && 
				atoi(returnsID.c_str()) == atoi(valueToFind.c_str()))
				// concatenates the row that matched the search arguments to the string returnString 
				// along with a line break at the end
				returnString += rowReceive + "\n";

			// checks if columnName (argument) is "sales_id" and if description data of current row matches
			// valueToFind (argument)
			else if(columnName == "sales_id" && 
				sales_id == valueToFind)				
				// concatenates the row that matched the search arguments to the string returnString 
				// along with a line break at the end
				returnString += rowReceive + "\n";

			// checks if columnName (argument) is "quantity_returned" and if name data of current row matches
			// valueToFind (argument)
			else if(columnName == "quantity_returned" &&
				quantity_returned == valueToFind)
				// concatenates the row that matched the search arguments to the string returnString 
				// along with a line break at the end
				returnString += rowReceive + "\n";

			// checks if columnName (argument) is "date_returned" and if name data of current row matches
			// valueToFind (argument)
			else if(columnName == "date_returned" &&
				date_returned == valueToFind)
				// concatenates the row that matched the search arguments to the string returnString 
				// along with a line break at the end
				returnString += rowReceive + "\n";

		}
	}
	// closes returns.txt
	returnsInFile.close();

	// checks if returnString contains less than the minimum number of characters (returns_id and two delimiters)
	if(returnString.size() < 1)
	{
		// if returnString did not receive any row data it is assigned a string stating that the row does not exist
		returnString = "Return Does Not Exist";
	}

	// \return returnString is returned as a result of the search function
	return returnString;
}

void Returns :: deleteRow(string valueToFind)
{
	// assigns the value for the name of the textfile to be used
	returnsTextFile = "textFiles/returns.txt";

	// string to contain the contents of a row received from the file
	string rowReceive;

	// string to contain the returns_ID from a received row of data
	string returnsID;

	//strings used to store the description and name values in a row
	string sales_id, quantity_returned, date_returned;

	// ints to store the position of the first and second delimiters
	int delimiter;
	int delimiter2;
	int delimiter3;

	// vector to store all rows of the file except the one to be deleted then to be rewritten to the file
	vector<string> retFileVect;

	// assign to char delim the | character as the desired delimiter
	char delim = '|';

	// opens returns.txt
	returnsInFile.open(returnsTextFile);

	// ensures that returnsInFile is open
	if(returnsInFile.is_open())
	{
		// while loop continues as long as there is another line in the text file
		while(returnsInFile.good())
		{
			// retrieves the next line in returnsInFile and assigns it to the string rowReceive
			getline(returnsInFile, rowReceive);

			// finds the positions of the delimeters and stores them in a variable
			delimiter = rowReceive.find(delim);
			delimiter2 = rowReceive.find(delim, delimiter+1);
			delimiter3 = rowReceive.find(delim, delimiter2+1);

			// retrieves the information from each column and puts it into a string variable
			returnsID = rowReceive.substr(0,delimiter);
			sales_id = rowReceive.substr(delimiter+1, delimiter2-delimiter-1);
			quantity_returned = rowReceive.substr(delimiter2+1, delimiter3-delimiter2-1);
			date_returned = rowReceive.substr(delimiter3+1);

			// checks the row received and writes it to the vector if it is not the row to delete
			// ie it adds all rows to our vector except the row we want to delete
			if(atoi(returnsID.c_str()) != atoi(valueToFind.c_str()))
			{
				retFileVect.push_back(rowReceive);
			}
		}
	}

	// closes returns.txt
	returnsInFile.close();

	// opens returns.txt and eliminates all contents and prepares to write values from the vector to returns.txt
	returnsOutFile.open(returnsTextFile, ios_base::trunc);

	// iterates through retFileVect and places each string from the vector into returns.txt
	for(int i = 0; i < (int) retFileVect.size(); i++)
	{
		// writes string from vector into returns.txt
		returnsOutFile<<retFileVect[i]<<endl;
	}

	// closes returns.txt
	returnsOutFile.close();
}

void Returns :: modifyRow(string valueToFind, string columnNameToModify, string valueOfModify)
{
	// assigns the value for the name of the textfile to be used
	returnsTextFile = "textFiles/returns.txt";

	// string to contain the row data received from the file
	string rowReceive;

	// string to contain the returns_ID from a received row of data
	string returnsID;

	// vector to store all rows of the file then to be rewritten to the file with the required modifications
	vector<string> retFileVect;

	//strings used to store the description and name values in a row
	string sales_id, quantity_returned, date_returned;

	// ints to store the position of the first and second delimiters
	int delimiter;
	int delimiter2;
	int delimiter3;

	// assign to char delim the | character as the desired delimiter
	char delim = '|';

	// opens returns.txt
	returnsInFile.open(returnsTextFile);

	// ensures that returnsInFile is open
	if(returnsInFile.is_open())
	{
		// while loop continues as long as there is another line in the text file
		while(returnsInFile.good())
		{
			// retrieves the next line in returnsInFile and assigns it to the string rowReceive
			getline(returnsInFile, rowReceive);

			// finds the positions of the delimeters and stores them in a variable
			delimiter = rowReceive.find(delim);
			delimiter2 = rowReceive.find(delim, delimiter+1);
			delimiter3 = rowReceive.find(delim, delimiter2+1);

			// retrieves the information from each column and puts it into a string variable
			returnsID = rowReceive.substr(0,delimiter);
			sales_id = rowReceive.substr(delimiter+1, delimiter2-delimiter-1);
			quantity_returned = rowReceive.substr(delimiter2+1, delimiter3-delimiter2-1);
			date_returned = rowReceive.substr(delimiter3+1);

			// checks the row received to make sure it is not our row to modify and writes it to our vector
			// 
			// else - if the columnName (argument) and the valueToFind (argument) do match the current row
			//		the row is modified with the desired changes
			if(atoi(returnsID.c_str()) != atoi(valueToFind.c_str()))
			{
				retFileVect.push_back(rowReceive);
			} else {
				// checks if the desired column to change is description and inputs the row with the new description into the vector
				if(columnNameToModify == "sales_id")
					retFileVect.push_back(returnsID + delim + valueOfModify + delim + quantity_returned + delim + date_returned);
				// checks if the desired column to change is name and inputs the row with the new name into the vector
				else if(columnNameToModify == "quantity_returned")
					retFileVect.push_back(returnsID + delim + sales_id + delim + valueOfModify + delim + date_returned);
				else if(columnNameToModify == "date_returned")
					retFileVect.push_back(returnsID + delim + sales_id + delim + quantity_returned + delim + valueOfModify);
			}
		}
	}

	// closes returns.txt
	returnsInFile.close();

	// opens returns.txt and eliminates all contents and prepares to write values from the vector to returns.txt
	returnsOutFile.open(returnsTextFile, ios_base::trunc);

	// iterates through retFileVect and places each string from the vector into returns.txt
	for(int i = 0; i < (int) retFileVect.size(); i++)
	{
		// writes string from vector into returns.txt
		returnsOutFile<<retFileVect[i]<<endl;
	}

	// closes returns.txt
	returnsOutFile.close();
}