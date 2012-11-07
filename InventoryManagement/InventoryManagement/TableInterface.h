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

using namespace std;

class TableInterface
{
public:
	/// \brief Add function to insert data into the category text file
	/// 
	/// \param[in] addVector is a vector of strings for the data to be entered
	virtual void add(vector<string> addVector) = 0;

	/// \brief Search function to find a specific row of data and return it as a string
	///
	/// \param[in] columnName identifies the name of the column to be searched
	/// \param[in] valueToFind identifies the value to be searched for in the column
	/// \return a string which contains a concatenation of all values in the row found in the database table
	virtual string search(string columnName, string valueToFind) = 0;

	/// \brief DeleteRow function to find a specific row of data and remove it from the file
	///
	/// \param[in] columnName identifies the name of the column to be searched
	/// \param[in] valueToFind identifies the value to be searched for in the column
	virtual void deleteRow(string columnName, string valueToFind) = 0;

	/// Virtual destructor for TableInterface
	virtual ~TableInterface() {};
};

typedef TableInterface * Table;
#endif