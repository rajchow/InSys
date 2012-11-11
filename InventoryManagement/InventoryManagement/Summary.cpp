#include "Summary.h"

void Summary::add(vector<string> addVector) throw(AlreadyExistsException) {
	ifstream infstream; // ifstream to be used to read invoice.txt
	ofstream outfstream; // ofstream to be used to write to invoice.txt

	int delimPos; // int used to store the position of the first delimiter

	string currentRow; // string that stores the current row on the invoice table
	string product_id = addVector[0]; // product_id to be added to file
	string total_quantity = addVector[1]; // total_quantity to be added to file
	
	try { 
		// search throws DoesNotExistException if product_id does not exist
		currentRow = search("product_id", product_id); 
	}
	catch (DoesNotExistException e) { //If product_id does not exist, add it

	outfstream.open(fileName, ios_base::app);

	// writes to invoice.txt the new row data as defined by invoice_id, and date 
	// with delimiters between each input and a line break at the end
	outfstream << product_id << "|" + total_quantity + "\n";

	outfstream.close();

	return;
	} // end catch

	// throw AlreadyExistsException if search returns a result
	throw AlreadyExistsException("product_id already exists");
}

string Summary::search(string columnName, string valueToFind) throw(DoesNotExistException) { 
	
	ifstream infstream; // ifstream to be used to read invoice.txt

	string returnString; // string used to store the value to be returned
	string currentRow; // string used to store the current row
	string product_id, total_quantity; //strings to store the product_id and total_quantity in current row

	// delimiter used to store positions of the delimiters '|' in the current row
	int delimPos;

	infstream.open(fileName);

	if(infstream.is_open())
	{

		// while loop continues as long as there is another line in the text file
		while(infstream.good())
		{
			getline(infstream, currentRow);

			// break when an empty string is assigned to currentRow
			// which occurss if there are no more valid entries in the table
			if (currentRow.empty())
				break;

			delimPos = currentRow.find('|'); // finds position of delimiter
			
			product_id = currentRow.substr(0, delimPos); // stores first string as product_id
			total_quantity = currentRow.substr(delimPos+1); // stores second string as total_quantity

			// if searching by product_id
			if(columnName == "product_id" && 
				atoi(product_id.c_str()) == atoi(valueToFind.c_str())) {
				returnString = currentRow + "\n"; //since product_id is unique, returns current row
				break;
			}
			// if searching by total_quantity
			else if(columnName == "total_quantity" &&
				total_quantity == valueToFind)	{	
				returnString += currentRow + "\n"; //adds any row that contains same total_quantity
			}
		}
	}
	
	infstream.close();

	// throws DoesNotExistException if nothing was found
	if(returnString == "")
		throw DoesNotExistException(valueToFind + " does not exist in column: " + columnName); 

	return returnString;
}

void Summary::deleteRow(string valueToFind) {}

void Summary::modifyRow(string valueToFind, string columnNameToModify, string valueOfModify) {}

Summary::Summary() { fileName = "textfiles\\summary.txt"; }

Summary::~Summary() {};