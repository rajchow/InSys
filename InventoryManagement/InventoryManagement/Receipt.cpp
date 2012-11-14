#include "Receipt.h"
#include "DoesNotExistException.h"
#include "AlreadyExistsException.h"
// Add function to insert data into the receipt text file
void Receipt::add(vector<string> addVector) throw(AlreadyExistsException) {

	ifstream inputfile; // ifstream to be used to read receipt.txt
	ofstream outputfile; // ofstream to be used to write to receipt.txt

	int receipt_id = 0; // int used to store the highest receipt_id so far
	int delimiter; // int used to store the position of the first delimiter

	string rowReceived; // string that stores the current row on the receipt table
	string receipt_idTemp; // string used to store the current highest receipt_id so far
	string date = addVector[0]; // date to be added to file

	inputfile.open(fileName);

	if(inputfile.is_open())
	{
		// while loop continues as long as there is another line in the text file
		// finds the highest receipt_id in the file and stores it in receipt_id
		while(inputfile.good())
		{
			getline(inputfile, rowReceived); // store next line of textfile in currentRow

			// Searches for the position of the delimiter
			delimiter = rowReceived.find('|');

			// stores the current receipt_id into receipt_idTemp
			receipt_idTemp = rowReceived.substr(0, delimiter);

			// Assigns current receipt id to last receipt id if current is higher
			if(atoi(receipt_idTemp.c_str()) > receipt_id)
			{
				receipt_id = atoi(receipt_idTemp.c_str());
			}
		}
	}

	inputfile.close();
	receipt_id++;

	outputfile.open(fileName, ios_base::app);

	// writes to receipt.txt the new row data as defined by receipt_id, and date 
	// with delimiters between each input and a line break at the end
	outputfile << receipt_id << "|" + date + "\n";

	outputfile.close();
}

// Search function to find a specific row of data and return it as a string

string Receipt::search(string columnName, string valueToFind) throw(DoesNotExistException) {

	ifstream inputfile; // ifstream to be used to read receipt.txt

	string returnString = ""; // string used to store the value to be returned
	string rowReceived; // string used to store the current row
	string receipt_id, date; //strings to store the receipt_id and date in the current row

	// delimiter used to store positions of the delimiters '|' in the current row
	int delimiter;

	inputfile.open(fileName);

	if(inputfile.is_open())
	{

		// while loop continues as long as there is another line in the text file
		while(inputfile.good())
		{
			getline(inputfile, rowReceived); // store next line of textfile in currentRow

			// break when an empty string is assigned to currentRow
			// which occurss if there are no more valid entries in the table
			if (rowReceived.empty())
				break;

			delimiter = rowReceived.find('|'); // finds position of delimiter

			receipt_id = rowReceived.substr(0, delimiter); // stores first string as receipt_id
			date = rowReceived.substr(delimiter+1); // stores second string as date

			// if searching by receipt_id
			if(columnName == "receipt_id" && 
				receipt_id == valueToFind) {
				returnString = rowReceived + "\n"; //since receipt_id is unique returns current row
				break;
			}
			// if searching by date
			else if(columnName == "date" &&
				date == valueToFind)	{	
				returnString += rowReceived + "\n"; //adds any row that contains same date
			}
		}
	}

	inputfile.close();

	// throws DoesNotExistException if nothing was found
	if(returnString == "")
		throw DoesNotExistException(valueToFind + " does not exist in column: " + columnName); 

	return returnString;
}

// Modify function to change the data in a given row

void Receipt::modifyRow(string valueToFind, string columnNameToModify, string valueOfModify) {

	ifstream inputfile; // ifstream to be used to read receipt.txt
	ofstream outputfile; // ofstream to be used to write to receipt.txt	
	vector<string> newVec; // string vector to store each line of the receipt.txt file

	string rowReceived; // string to store the current row in the table
	string date; //string to store date of current row in the tabled
	string receipt_id; //string to store receipt_id of current row in the table
	int delimiter; // position in the line of delimiter

	inputfile.open(fileName);

	if(inputfile.is_open())
	{
		// while loop continues as long as there is another line in the text file
		while(inputfile.good())
		{
			getline(inputfile, rowReceived); // store next line of textfile in currentRow

			// break when an empty string is assigned to currentRow
			// which occurss if there are no more valid entries in the table
			if (rowReceived.empty())
				break;

			delimiter = rowReceived.find('|'); // position of first delimiter '|'

			receipt_id = rowReceived.substr(0,delimiter); // stores substring before '|' in receipt_id
			date = rowReceived.substr(delimiter + 1); // store substring after '|' in date

			// if the invoice_id of the currentRow matches valueToFind, modify date
			// and push_back the modified string into fileVector
			// otherwise push_back the same string into fileVector
			if (receipt_id == valueToFind)
				newVec.push_back(receipt_id + "|" + valueOfModify + "\n");
			else
				newVec.push_back(receipt_id + "|" + date + "\n");
		}
	}

	inputfile.close();

	// clears receipt.txt so fileVector can be written on it
	outputfile.open(fileName, ios_base::trunc);

	// copy fileVector to receipt.txt
	for(int i = 0; i < (int) newVec.size(); i++)
		outputfile << newVec[i];

	outputfile.close();
}

// Invoices will not be allowed to be deleted
void Receipt::deleteRow(string valueToFind){}

// Initializes fileName
Receipt::Receipt() { fileName = "textfiles\\receipt.txt"; }

// Destructor
Receipt::~Receipt(){}