#ifndef RETURNS_H
#define RETURNS_H

#include "TableInterface.h"

class Returns : public TableInterface
{
private:
	/// output and input streams for reading and writing the category.txt file
	ofstream returnsOutFile;
	ifstream returnsInFile;

	/// variable to contain the filename to be used for the category data
	string returnsTextFile;
	

public:
	void add(vector<string> addVector);

	string search(string columnName, string valueToFind);

	void deleteRow(string valueToFind);

	void modifyRow(string valueToFind, string columnNameToModify, string valueOfModify);
};

#endif