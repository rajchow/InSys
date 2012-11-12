#ifndef INVOICEITEM_H
#define INVOICEITEM_H

#include "TableInterface.h"

/// \brief Class for interacting with the InvoiceItem table
///
/// InvoiceItem will interact with a flat file representing the InvoiceItem table in the database
/// Responsibilities of the InvoiceItem class include:
/// - Add a row to the InvoiceItem table
/// - Search for a row in the InvoiceItem table
/// - Modify a row in the InvoiceItem table
/// - Connect and disconnect from the database
class InvoiceItem : public TableInterface {
private:

	/// \brief file name of text file for InvoiceItem table
	string fileName;

	/// \brief deleteRow will do nothing for InvoiceItem class
	///
	/// Invoice Items should not be deleted from the database
	/// because all filed invoices will be kept
	void deleteRow(string valueToFind);

public:

	/// \brief default constructor for InvoiceItem
	///
	/// \post fileName initialized
	InvoiceItem();

	/// \brief Add function to insert data into the invoice item text file
	/// 
	/// \param[in] addVector is a vector of strings for the data to be entered
	///            for InvoiceItem. This will be values for 
	///            product_id and quantity in that order
	/// \throw nothing will be thrown because primary key is automatically incremented, thus no duplication
	void add(vector<string> addVector) throw (AlreadyExistsException);

	string search(string columnName, string valueToFind) throw(DoesNotExistException);

	/// \brief Modify function to change the data in a given row
	///
	/// Modification will be done by finding a matching value by searching for valueToFind
	/// in the primary key (invoice_item_id) column of the table. Only product_id and quantity
	/// can by modified.
	/// \pre Row exists. This will be checked by the main program beforehand
	/// \param[in] valueToFind identifies the value to be searched for in the primary key
	/// \param[in] columnNameToModify identifies the column to change data for
	/// \prama[in] valueOfModify provides the new data for the desired column
	void modifyRow(string valueToFind, string columnNameToModify, string valueOfModify);

	/// \brief Destructor for InvoiceItem
	~InvoiceItem();
};


#endif