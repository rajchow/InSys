#ifndef CATEGORY_H
#define CATEGORY_H

#include "TableInterface.h"

class Category : public TableInterface
{
private:
	/// output and input streams for reading and writing the category.txt file
	ofstream categoryOutFile;
	ifstream categoryInFile;

	/// variable to contain the filename to be used for the category data
	string categoryTextFile;
	

public:
	string add(vector<string> addVector) throw(AlreadyExistsException);

	string search(string columnName, string valueToFind) throw(DoesNotExistException);

	void deleteRow(string valueToFind);

	void modifyRow(string valueToFind, string columnNameToModify, string valueOfModify);
};

#endif