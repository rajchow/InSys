#ifndef TABLEINTERFACE_H
#define TABLEINTERFACE_H

/* Standard C++ headers */
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <string>
#include <exception>
#include <vector>

using namespace std;

class TableInterface
{
public:
	/// \brief Add function to insert data into the table text file
	/// 
	/// \param[in] addVector is a vector of strings for the data to be entered
	virtual void add(vector<string> addVector) = 0;

	/// \brief Search function to find a specific row of data and return it as a string
	///
	/// \param[in] columnName identifies the name of the column to be searched
	/// \param[in] valueToFind identifies the value to be searched for in the column
	/// \return a string which contains a concatenation of all values in the row found in the database table
	///         if multiple values exist, return all rows with that value, where
	///         each row is separated by a new line
	/// \throw excpetion if nothing was found
	virtual string search(string columnName, string valueToFind) throw(exception) = 0;

	/// \brief DeleteRow function to find a specific row of data and remove it from the file
	///
	/// \param[in] columnName identifies the name of the column to be searched
	/// \param[in] valueToFind identifies the value to be searched for in the column
	virtual void deleteRow(string columnName, string valueToFind) = 0;

	/// \brief Modify functionn to change the data in a given row
	///
	/// \param[in] columnNameToFind identifies the column to search in
	/// \param[in] valueToFind identifies the value to be searched for in the column
	/// \param[in] columnNameToModify identifies the column to change data for
	/// \prama[in] valueOfModify provides the new data for the desired column
	virtual void modifyRow(string columnNameToFind, string valueToFind, string columnNameToModify, string valueOfModify) = 0;

	/// Virtual destructor for TableInterface
	virtual ~TableInterface() {};
};

typedef TableInterface * Table;
#endif