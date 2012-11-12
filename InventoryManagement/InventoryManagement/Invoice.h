#ifndef INVOICE_H
#define INVOICE_H

#include "TableInterface.h"

/// \brief Class for interacting with the Invoice table
///
/// Invoice will interact with a flat file representing the Invoice table in the database
/// Responsibilities of the Invoice class include:
/// - Add a row to the Invoice table
/// - Search for a row in the Invoice table
/// - Modify a row in the Invoice table
/// - Connect and disconnect from the database
class Invoice : public TableInterface {

private:

	/// \brief file name of text file for Invoice table
	string fileName;

	/// \brief deleteRow will do nothing for Invoice class
	///
	/// Invoices should not be deleted from the database
	/// because all filed invoices will be kept
	void deleteRow(string valueToFind);

public:

	/// \brief default constructor for Invoice
	///
	/// \post fileName initialized
	Invoice();

	/// \brief Add function to insert data into the invoice text file
	/// 
	/// \param[in] addVector is a vector of strings for the data to be entered
	///            for Invoice, this will be a single value the date
	///            since invoice_id is automatically incremented
	/// \throw nothing will be thrown because primary key is automatically incremented, thus no duplication
	void add(vector<string> addVector) throw (AlreadyExistsException);

	string search(string columnName, string valueToFind) throw(DoesNotExistException);

	void modifyRow(string valueToFind, string columnNameToModify, string valueOfModify);

	/// \brief Destructor for Invoice
	~Invoice();

};

#endif