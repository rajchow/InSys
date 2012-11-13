#include "Invoice.h"

// Add function to insert data into the invoice text file
// 
// parameter: addVector is a vector of strings for the data to be entered
//            for Invoice, this will be a single value the date
//            since invoice_id is automatically incremented
// throws: nothing will be thrown because primary key is automatically incremented, thus no duplication
void Invoice::add(vector<string> addVector) throw(AlreadyExistsException) {

	ifstream infstream; // ifstream to be used to read invoice.txt
	ofstream outfstream; // ofstream to be used to write to invoice.txt

	int invoice_id = 0; // int used to store the highest invoice_id so far
	int delimPos; // int used to store the position of the first delimiter

	string currentRow; // string that stores the current row on the invoice table
	string invoice_idTemp; // string used to store the current highest invoice_id so far
	string date = addVector[0]; // date to be added to file

	infstream.open(fileName);

	if(infstream.is_open())
	{
		// while loop continues as long as there is another line in the text file
		// finds the highest invoice_id in the file and stores it in invoice_id
		while(infstream.good())
		{
			getline(infstream, currentRow); // store next line of textfile in currentRow

			// Searches for the position of the delimiter
			delimPos = currentRow.find('|');
			
			// stores the current invoice_id into invoice_idTemp
			invoice_idTemp = currentRow.substr(0, delimPos);

			// Assigns current invoice id to last invoice id if current is higher
			if(atoi(invoice_idTemp.c_str()) > invoice_id)
			{
				invoice_id = atoi(invoice_idTemp.c_str());
			}
		}
	}

	infstream.close();

	// increments invoice_id so it is higher than last invoice_id in the file
	invoice_id++;

	outfstream.open(fileName, ios_base::app);

	// writes to invoice.txt the new row data as defined by invoice_id, and date 
	// with delimiters between each input and a line break at the end
	outfstream << invoice_id << "|" + date + "\n";

	outfstream.close();
}

// Search function to find a specific row of data and return it as a string
//
// param[in]: columnName identifies the name of the column to be searched
// param[in]: valueToFind identifies the value to be searched for in the column
// return: a string which contains a concatenation of all values in the row found in the database table
//         if multiple values exist, return all rows with that value, where
//         each row is separated by a new line
// throw: DoesNotExistException when trying to find a row that doesn't exist
string Invoice::search(string columnName, string valueToFind) throw(DoesNotExistException) {

	ifstream infstream; // ifstream to be used to read invoice.txt

	string returnString = ""; // string used to store the value to be returned
	string currentRow; // string used to store the current row
	string invoice_id, date; //strings to store the invoice_id and date in the current row

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
			
			invoice_id = currentRow.substr(0, delimPos); // stores first string as invoice_id
			date = currentRow.substr(delimPos+1); // stores second string as date

			// if searching by invoice_id
			if(columnName == "invoice_id" && 
				invoice_id == valueToFind) {
				returnString = currentRow + "\n"; //since invoice_id is unique returns current row
				break;
			}
			// if searching by date
			else if(columnName == "date" &&
				date == valueToFind)	{	
				returnString += currentRow + "\n"; //adds any row that contains same date
			}
		}
	}
	
	infstream.close();

	// throws DoesNotExistException if nothing was found
	if(returnString == "")
		throw DoesNotExistException(valueToFind + " does not exist in column: " + columnName); 

	return returnString;
}

// Modify function to change the data in a given row
//
// Modification will be done by searching by the primary key of the table (invoice_id)
// Only date will be modified
// preconditon: Row exists. This will be checked by the main program beforehand.
// param[in]: valueToFind identifies the value to be searched in the primary key column
// param[in]: columnNameToModify identifies the column to change data for
// param[in]: valueOfModify provides the new data for the desired column
void Invoice::modifyRow(string valueToFind, string columnNameToModify, string valueOfModify) {

	ifstream infstream; // ifstream to be used to read invoice.txt
	ofstream outfstream; // ofstream to be used to write to invoice.txt	
	vector<string> fileVector; // string vector to store each line of the invoice.txt file

	string currentRow; // string to store the current row in the table
	string date; //string to store date of current row in the tabled
	string invoice_id; //string to store invoice_id of current row in the table
	int delimPos; // position in the line of delimiter

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

			delimPos = currentRow.find('|'); // position of first delimiter '|'

			invoice_id = currentRow.substr(0,delimPos); // stores substring before '|' in invoice_id
			date = currentRow.substr(delimPos + 1); // store substring after '|' in date

			// if the invoice_id of the currentRow matches valueToFind, modify date
			// and push_back the modified string into fileVector
			// otherwise push_back the same string into fileVector
			if (invoice_id == valueToFind)
				fileVector.push_back(invoice_id + "|" + valueOfModify + "\n");
			else
				fileVector.push_back(invoice_id + "|" + date + "\n");
		}
	}

	infstream.close();
	
	// clears invoice.txt so fileVector can be written on it
	outfstream.open(fileName, ios_base::trunc);

	// copy fileVector to invoice.txt
	for(int i = 0; i < (int) fileVector.size(); i++)
		outfstream << fileVector[i];
	
	outfstream.close();
}

// Invoices will not be allowed to be deleted
void Invoice::deleteRow(string valueToFind){}

// Initializes fileName
Invoice::Invoice() { fileName = "textfiles\\invoice.txt"; }

// Destructor
Invoice::~Invoice(){}
