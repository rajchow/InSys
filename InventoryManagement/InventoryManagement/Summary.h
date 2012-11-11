#ifndef SUMMARY_H
#define SUMMARY_H

#include "TableInterface.h"

/// \brief Class for interacting with the Summary table
///
/// Summary will interact with a flat file representing the Summary table in the database
/// Responsibilities of the Summary class include:
/// - Add a row to the Summary table
/// - Search for a row in the Summary table
/// - Delete a row in the Summary table
/// - Modify a row in the Summary table
class Summary : public TableInterface
{
private:

	/// \brief file name of text file for Invoice table
	string fileName;

public:

	/// \brief default constructor for Summary
	///
	/// \post fileName initialized
	Summary();

	/// \brief Add function to insert data into the invoice text file
	/// 
	/// \param[in] addVector is a vector of strings for the data to be entered
	///            the first element is product_id
	///            the second element is total_quantity
	/// \throw AlreadyExistsException if product_id already exists
	void add(vector<string> addVector) throw (AlreadyExistsException);

	string search(string columnName, string valueToFind) throw(DoesNotExistException);

	void deleteRow(string valueToFind);

	void modifyRow(string valueToFind, string columnNameToModify, string valueOfModify);

	/// \brief Destructor for Summary
	~Summary();
};

#endif