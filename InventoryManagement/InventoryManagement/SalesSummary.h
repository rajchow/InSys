#ifndef SALESSUMMARY_H
#define SALESSUMMARY_H

#include "TableInterface.h"

class SalesSummary : public TableInterface
{
private:
	/// output and input streams for reading and writing the sales summary.txt file
	ofstream ssOutFile;
	ifstream ssInFile;

	string salesSummaryTextFile;

public:
	SalesSummary();

	void add(vector<string> addVector) throw(AlreadyExistsException);

	string search(string columnName, string valueToFind) throw(DoesNotExistException);

	void deleteRow(string valueToFind);

	void modifyRow(string valueToFind, string columnNameToModify, string valueOfModify);

	/// \brief Destructor for Sales Summary
	~SalesSummary();
};

#endif