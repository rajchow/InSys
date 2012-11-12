#ifndef TABLEINTERFACE_H
#define TABLEINTERFACE_H

/* Standard C++ headers */
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>

#include "AlreadyExistsException.h"
#include "DoesNotExistException.h"

using namespace std;

/// \brief Class for interacting with the tables in the database
///
/// TableInterface will interact with each table in the database
/// Responsibilities of the TableInterface class include:
/// - Add a row to a table of the database
/// - Search for a row in a table of the database
/// - Delete a row in a table of the database
/// - Modify a row in a table of the database
/// - Connect and disconnect from the database
class TableInterface
{
public:
	/// \brief Add function to insert data into the category text file
	/// 
	/// \param[in] addVector is a vector of strings for the data to be entered
	/// \return returns a string to notify the user whether the add was successful or not
	/// \throw AlreadyExistsException when trying to add a primary key that already exists
	virtual void add(vector<string> addVector) throw(AlreadyExistsException) = 0;

	/// \brief Search function to find a specific row of data and return it as a string
	///
	/// \param[in] columnName identifies the name of the column to be searched
	/// \param[in] valueToFind identifies the value to be searched for in the column
	/// \return a string which contains a concatenation of all values in the row found in the database table
	///         if multiple values exist, return all rows with that value, where
	///         each row is separated by a new line
	/// \throw DoesNotExistException when trying to find a row that doesn't exist
	virtual string search(string columnName, string valueToFind) throw(DoesNotExistException) = 0;

	/// \brief DeleteRow function to find a specific row of data and remove it from the file
	///
	/// Deletion will by done by finding the a matching value by searching for valueToFind
	/// in the primary key column of the table 
	/// \pre Row exists. This will be checked by the main program beforehand
	/// \param[in] valueToFind identifies the value to be searched for in the primary key column
	virtual void deleteRow(string valueToFind) = 0;

	/// \brief Modify function to change the data in a given row
	///
	/// Modification will be done by finding a matching value by searching for valueToFind
	/// in the primary key column of the table
	/// \pre Row exists. This will be checked by the main program beforehand
	/// \param[in] valueToFind identifies the value to be searched for in the primary key
	/// \param[in] columnNameToModify identifies the column to change data for
	/// \prama[in] valueOfModify provides the new data for the desired column
	virtual void modifyRow(string valueToFind, string columnNameToModify, string valueOfModify) = 0;

	/// Virtual destructor for TableInterface
	virtual ~TableInterface() {};
};

typedef TableInterface * Table;
#endif