#ifndef CATEGORY_H
#define CATEGORY_H

#include "TableInterface.h"

/// \brief Class for interacting with the Invoice table
///
/// Category will interact with a flat file representing the Category table in the database
/// Responsibilities of the Category class include:
/// - Add a row to the Category table
/// - Delete a row to the Category table
/// - Search for a row in the Category table
/// - Modify a row in the Category table
class Category : public TableInterface
{
private:
	/// \brief output stream for writing to the Category file
	ofstream categoryOutFile;

	/// \brief input stream for reading to the Category file
	ifstream categoryInFile;

	/// \brief file name of text file for Category table
	string categoryTextFile;
	

public:
	/// \brief default constructor for Category
	///
	/// \post categoryTextFile initialized
	Category();

	void add(vector<string> addVector) throw(AlreadyExistsException);

	string search(string columnName, string valueToFind) throw(DoesNotExistException);

	void deleteRow(string valueToFind);

	void modifyRow(string valueToFind, string columnNameToModify, string valueOfModify);
	
	/// \brief Destructor for Product
	~Category();
};

#endif