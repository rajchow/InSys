#include "Invoice.h"

// function to add a row to the table
void Invoice::add(vector<string> addVector) {

	// int used to store the highest invoice_id to use for automatically incrementing invoice_id
	int invoice_id = 0;
	// int used to store the position of the first delimiter
	int delimPos;

	// string that stores the current row on the invoice table
	string currentRow;
	// string used to store the current highest invoice_id so far
	string invoice_idTemp;
	// date to be added to file
	string date = addVector[0];

	infstream.open(fileName);

	if(infstream.is_open())
	{
		// while loop continues as long as there is another line in the text file
		// finds the highest invoice_id in the file and stores it in invoice_id
		while(infstream.good())
		{
			getline(infstream, currentRow);

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

	// closes category.txt
	outfstream.close();
}

string Invoice::search(string columnName, string valueToFind) throw(exception) {

	// string used to store the value to be returned
	string returnString;
	// string used to store the current row
	string currentRow;

	//strings to store the invoice_id and date in the current row
	string invoice_id, date;

	// delimiter used to store positions of the delimiters '|' in the current row
	int delimPos;

	infstream.open(fileName);

	if(infstream.is_open())
	{

		// while loop continues as long as there is another line in the text file
		while(infstream.good())
		{
			getline(infstream, currentRow);

			delimPos = currentRow.find('|'); // finds position of delimiter
			
			invoice_id = currentRow.substr(0, delimPos); // stores first string as invoice_id
			date = currentRow.substr(delimPos+1); // stores second string as date

			// if searching by invoice_id
			if(columnName == "invoice_id" && 
				atoi(invoice_id.c_str()) == atoi(valueToFind.c_str())) {
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

	// throws exception if nothing was found
	if(returnString == "")
		throw exception();

	return returnString;
}

void Invoice::deleteRow(string columnName, string valueToFind){}

Invoice::Invoice() { fileName = "TableTestFiles\\invoice.txt"; }

Invoice::~Invoice(){}

