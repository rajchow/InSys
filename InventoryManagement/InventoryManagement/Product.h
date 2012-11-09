#ifndef PRODUCT_H
#define PRODUCT_H

#include "TableInterface.h"

class Product : public TableInterface
{
private:
	/// output and input streams for reading and writing the category.txt file
	ofstream categoryOutFile;
	ifstream categoryInFile;

	/// variable to contain the filename to be used for the category data
	string categoryTextFile;
	

public:
	void add(vector<string> addVector);

	string search(string columnName, string valueToFind);

	void deleteRow(string columnName, string valueToFind) throw(exception);

	void modifyRow(string columnNameToFind, string valueToFind, string columnNameToModify, string valueOfModify);
};

#endif