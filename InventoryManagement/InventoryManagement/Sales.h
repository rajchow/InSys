#ifndef SALES_H
#define SALES_H

#include "TableInterface.h"

class Sales : public TableInterface
{
private:
	/// \brief output stream for writing to the Sales file
	ofstream salesOutFile;

	/// \brief output stream for writing to the Sales file
	ifstream salesInFile;

	/// \brief file name of Sales text file
	string salesTextFile;

public:
	/// \brief default constructor for Sales

	Sales();

	void add(vector<string> addVector) throw(AlreadyExistsException);

	string search(string columnName, string valueToFind) throw(DoesNotExistException);

	void deleteRow(string valueToFind);

	void modifyRow(string valueToFind, string columnNameToModify, string valueOfModify);

	/// \brief Destructor for Sales
	~Sales();
};

#endif