#ifndef CATEGORY_H
#define CATEGORY_H

#include "TableInterface.h"

class Category : public TableInterface
{
private:
	string returnString;

	ofstream categoryOutFile;
	ifstream categoryInFile;
	
	string rowReceive;
	string categoryID;
	int delimiter;
	int categoryIDTemp;
	int catID;
	char delim;

public:
	void add(vector<string> addVector);

	string search(string columnName, string valueToFind);

	void deleteRow(string columnName, string valueToFind);
};

#endif