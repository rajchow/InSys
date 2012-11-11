#ifndef PRODUCT_H
#define PRODUCT_H

#include "TableInterface.h"

class Product : public TableInterface
{
private:
	/// output and input streams for reading and writing the category.txt file
	ofstream productOutFile;
	ifstream productInFile;

	/// variable to contain the filename to be used for the category data
	string productTextFile;
	

public:
	void add(vector<string> addVector) throw(AlreadyExistsException);

	string search(string columnName, string valueToFind) throw(DoesNotExistException);

	void deleteRow(string valueToFind);

	void modifyRow(string valueToFind, string columnNameToModify, string valueOfModify);
};

#endif