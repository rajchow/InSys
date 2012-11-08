#ifndef CATEGORY_H
#define CATEGORY_H

#include "TableInterface.h"

class Category : public TableInterface
{
private:
	/// output and input streams for reading and writing the category.txt file
	ofstream categoryOutFile;
	ifstream categoryInFile;
	

public:
	void add(vector<string> addVector);

	string search(string columnName, string valueToFind);

	void deleteRow(string columnName, string valueToFind);
};

#endif