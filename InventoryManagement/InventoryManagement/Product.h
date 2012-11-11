#ifndef PRODUCT_H
#define PRODUCT_H

#include "TableInterface.h"

/// \brief Class for interacting with the Invoice table
///
/// Product will interact with a flat file representing the Product table in the database
/// Responsibilities of the Product class include:
/// - Add a row to the Product table
/// - Delete a row to the Product table
/// - Search for a row in the Product table
/// - Modify a row in the Product table
class Product : public TableInterface
{
private:
	/// \brief output stream for writing to the Product file
	ofstream productOutFile;

	/// \brief input stream for reading to the Product file
	ifstream productInFile;

	/// \brief file name of text file for Product table
	string productTextFile;
	

public:
	/// \brief default constructor for Product
	///
	/// \post productTextFile initialized
	Product();

	void add(vector<string> addVector) throw(AlreadyExistsException);

	string search(string columnName, string valueToFind) throw(DoesNotExistException);

	void deleteRow(string valueToFind);

	void modifyRow(string valueToFind, string columnNameToModify, string valueOfModify);

	/// \brief Destructor for Product
	~Product();
};

#endif