<<<<<<< HEAD
#include "Invoice.h"

// function to add a row to the table
void Invoice::add(vector<string> addVector) {

	
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

	outfstream.close();
}

string Invoice::search(string columnName, string valueToFind) throw(exception) {

	ifstream infstream; // ifstream to be used to read invoice.txt

	string returnString; // string used to store the value to be returned
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

void Invoice::modifyRow(string columnNameToFind, string valueToFind, string columnNameToModify, string valueOfModify) {

	ifstream infstream; // ifstream to be used to read invoice.txt
	ofstream outfstream; // ofstream to be used to write to invoice.txt	
	vector<string> fileVector; // string vector to store each line of the invoice.txt file

	string currentRow; // string to store the current row in the table
	string date; //string to store date of line to be modified
	string invoice_id; //string to store invoice_id of line to be modified
	int delimPos; // position in the line of delimiter

	infstream.open(fileName);
	
	// store invoice.txt to fileVector
	while (!infstream.eof()) {
		getline(infstream, currentRow);
		currentRow += "\n";
		fileVector.push_back(currentRow);
	}

	fileVector.pop_back(); // removes extra line break

	vector<string>::iterator it = fileVector.begin(); // iterator for fileVector
	string toFind = ""; // used to find a line in the fileVector
	string searchResult; // string to store search results

	try {
	searchResult = search(columnNameToFind, valueToFind); // stores the result of the search
	}
	catch (exception e) { throw e; }

	// finds the position of the line to be found and replaces the value with valueOfModify
	// if search returns multiple results, break up the result line by line
	// and modify each corresponding line in the fileVector
	while (toFind != searchResult) {
		delimPos = searchResult.find('\n');
		toFind = searchResult.substr(0, delimPos) + "\n"; // take the first line of search result
		
		if (toFind != searchResult) // remove the first line of search result if they aren't equal
			searchResult = searchResult.substr(delimPos + 1); 

		it = find(it, fileVector.end(), toFind); // position of toFind in fileVector
	
		// change the date with the valueOfModify
		delimPos = (*it).find('|');
		invoice_id = (*it).substr(0, delimPos);
		date = (*it).substr(delimPos + 1);
		*it = invoice_id + "|" + valueOfModify + "\n";
		
		it++; // increment iterator to the next line in fileVector
	}

	infstream.close();
	
	// clears invoice.txt so fileVector can be written on it
	outfstream.open(fileName, ios_base::trunc);

	// copy fileVector to invoice.txt
	for(int i = 0; i < (int) fileVector.size(); i++)
		outfstream << fileVector[i];
	
	outfstream.close();
}

void Invoice::deleteRow(string columnName, string valueToFind){}

Invoice::Invoice() { fileName = "textfiles\\invoice.txt"; }

Invoice::~Invoice(){}

=======
#include "Invoice.h"

// function to add a row to the table
void Invoice::add(vector<string> addVector) {

	
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

	outfstream.close();
}

string Invoice::search(string columnName, string valueToFind) throw(exception) {

	ifstream infstream; // ifstream to be used to read invoice.txt

	string returnString; // string used to store the value to be returned
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

void Invoice::modifyRow(string columnNameToFind, string valueToFind, string columnNameToModify, string valueOfModify) {

	ifstream infstream; // ifstream to be used to read invoice.txt
	ofstream outfstream; // ofstream to be used to write to invoice.txt	
	vector<string> fileVector; // string vector to store each line of the invoice.txt file

	string currentRow; // string to store the current row in the table
	string date; //string to store date of line to be modified
	string invoice_id; //string to store invoice_id of line to be modified
	int delimPos; // position in the line of delimiter

	infstream.open(fileName);
	
	// store invoice.txt to fileVector
	while (!infstream.eof()) {
		getline(infstream, currentRow);
		currentRow += "\n";
		fileVector.push_back(currentRow);
	}

	fileVector.pop_back(); // removes extra line break

	vector<string>::iterator it = fileVector.begin(); // iterator for fileVector
	string toFind = ""; // used to find a line in the fileVector
	string searchResult; // string to store search results

	try {
	searchResult = search(columnNameToFind, valueToFind); // stores the result of the search
	}
	catch (exception e) { throw e; }

	// finds the position of the line to be found and replaces the value with valueOfModify
	// if search returns multiple results, break up the result line by line
	// and modify each corresponding line in the fileVector
	while (toFind != searchResult) {
		delimPos = searchResult.find('\n');
		toFind = searchResult.substr(0, delimPos) + "\n"; // take the first line of search result
		
		if (toFind != searchResult) // remove the first line of search result if they aren't equal
			searchResult = searchResult.substr(delimPos + 1); 

		it = find(it, fileVector.end(), toFind); // position of toFind in fileVector
	
		// change the date with the valueOfModify
		delimPos = (*it).find('|');
		invoice_id = (*it).substr(0, delimPos);
		date = (*it).substr(delimPos + 1);
		*it = invoice_id + "|" + valueOfModify + "\n";
		
		it++; // increment iterator to the next line in fileVector
	}

	infstream.close();
	
	// clears invoice.txt so fileVector can be written on it
	outfstream.open(fileName, ios_base::trunc);

	// copy fileVector to invoice.txt
	for(int i = 0; i < (int) fileVector.size(); i++)
		outfstream << fileVector[i];
	
	outfstream.close();
}

void Invoice::deleteRow(string columnName, string valueToFind){}

Invoice::Invoice() { fileName = "textfiles\\invoice.txt"; }

Invoice::~Invoice(){}

>>>>>>> 9604ebfd074af0d2d18460c657fa0e1e78ddb94e
