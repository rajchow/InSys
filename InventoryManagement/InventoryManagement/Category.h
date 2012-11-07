#ifndef CATEGORY_H
#define CATEGORY_H

#include "TableInterface.h"

class Category : public TableInterface
{
private:
	/// string to be used to return the results of a search
	string returnString;

	/// output and input streams for reading and writing the category.txt file
	ofstream categoryOutFile;
	ifstream categoryInFile;
	
	/// string to contain the contents of a row received from the file
	string rowReceive;

	/// string to contain the category_ID from a received row of data
	string categoryID;
	
	//strings used to store the description and name values in a row
	string description, name;

	/// ints to store the position of the first and second delimiters
	int delimiter;
	int delimiter2;

	/// int to store the category_ID while checking if it is the highest category_ID value used
	int categoryIDTemp;

	/// int to store the category_ID to be used for adding data to the category.txt file
	int catID;

	/// char to define the character to be identified as the delimiter
	char delim;

public:
	void add(vector<string> addVector);

	string search(string columnName, string valueToFind);

	void deleteRow(string columnName, string valueToFind);
};

#endif