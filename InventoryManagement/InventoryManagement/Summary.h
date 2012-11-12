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
/// - Connect and disconnect from the database
class Summary : public TableInterface
{
private:

	/// \brief file name of text file for Summary table
	string fileName;

public:

	/// \brief default constructor for Summary
	///
	/// \post fileName initialized
	Summary();

	/// \brief Add function to insert data into the summary text file
	/// 
	/// \param[in] addVector is a vector of strings for the data to be entered
	///            the first element is product_id
	///            the second element is total_quantity
	/// \throw AlreadyExistsException if product_id already exists
	/// \post Summary is sorted by product_id
	void add(vector<string> addVector) throw (AlreadyExistsException);

	string search(string columnName, string valueToFind) throw(DoesNotExistException);

	void deleteRow(string valueToFind);

	/// \brief Modify function to change the data in a given row
	///
	/// Modification will be done by finding a matching value by searching for valueToFind
	/// in the primary key column of the table
	/// \pre Row exists. This will be checked by the main program beforehand
	/// \param[in] valueToFind identifies the value to be searched for in the primary key
	/// \param[in] columnNameToModify identifies the column to change data for
	/// \prama[in] valueOfModify provides the new data for the desired column
	/// \post Summary table is sorted by product_id
	void modifyRow(string valueToFind, string columnNameToModify, string valueOfModify);

	/// \brief Destructor for Summary
	~Summary();
};

#endif