#include "Orders.h"

// Add function to insert data into the Orders text file
// 
// parameter[in]: addVector is a vector of strings for the data to be entered
//            the first element is invoice_item_id
//            the second element is invoice_id
// \throw AlreadyExistsException when invoice_item_id already exists, since it is unique
void Orders::add(vector<string> addVector) throw (AlreadyExistsException) {
	ofstream outfstream; // ofstream to be used to write to orders.txt

	string invoice_item_id = addVector[0]; // invoice_item_id to be added to file
	string invoice_id = addVector[1]; // invoice_id to be added to file

	try {
		search("invoice_item_id", invoice_item_id);

		// if invoice_item_id already exists, throw exception
		throw AlreadyExistsException("invoice_item_id already exists");
	}
	catch (DoesNotExistException e) // if nothing was found, add new row
	{
		// append new row to the end of the orders.txt file
		outfstream.open(fileName, ios_base::app);
		outfstream << invoice_item_id + "|" + invoice_id + "\n";
		outfstream.close();
	}
}

// Search function to find a specific row of data and return it as a string
//
// param[in]: columnName identifies the name of the column to be searched
// param[in]: valueToFind identifies the value to be searched for in the column
// return: a string which contains a concatenation of all values in the row found in the database table
//         if multiple values exist, return all rows with that value, where
//         each row is separated by a new line
// throw: DoesNotExistException when trying to find a row that doesn't exist
string Orders::search(string columnName, string valueToFind) throw(DoesNotExistException) {

	ifstream infstream; // ifstream to be used to read invoice.txt

	string returnString = ""; // string used to store the value to be returned
	string currentRow; // string used to store the current row
	string invoice_item_id, invoice_id; //strings to store invoice_item_id and invoice_id in the current row

	// delimiter used to store positions of the delimiters '|' in the current row
	int delimPos;

	infstream.open(fileName);

	if(infstream.is_open())
	{

		// while loop continues as long as there is another line in the text file
		while(infstream.good())
		{
			getline(infstream, currentRow); // store next line of textfile in currentRow

			// break when an empty string is assigned to currentRow
			// which occurss if there are no more valid entries in the table
			if (currentRow.empty())
				break;

			delimPos = currentRow.find('|'); // finds position of delimiter
			
			invoice_item_id = currentRow.substr(0, delimPos); // stores first string as invoice_item_id
			invoice_id = currentRow.substr(delimPos+1); // stores second string as invoice_id

			// if searching by invoice_item_id
			if(columnName == "invoice_item_id" && 
				invoice_item_id == valueToFind) {
				returnString = currentRow + "\n"; //since invoice_item_id is unique returns current row
				break;
			}
			// if searching by date
			else if(columnName == "invoice_id" &&
				invoice_id == valueToFind)	{	
				returnString += currentRow + "\n"; //adds any row that contains same invoice_id
			}
		}
	}
	
	infstream.close();

	// throws DoesNotExistException if nothing was found
	if(returnString == "")
		throw DoesNotExistException(valueToFind + " does not exist in column: " + columnName); 

	return returnString;
}

// deleteRow will not do anything because rows will not be deleted.
// This is because both Invoice and InvoiceItem cannot be deleted
void Orders::deleteRow(string valueToFind) {}

// Orders contains two foreign primary keys of InvoiceItem and Invoice.
// Both are auto-incrimented and thus, never changed
void Orders::modifyRow(string valueToFind, string columnNameToModify, string valueOfModify) {}

// default constructor, fileName initialized
Orders::Orders() {fileName = "textfiles\\orders.txt";}
// Destructor for Orders
Orders::~Orders() {}