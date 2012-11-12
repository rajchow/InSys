#include "InvoiceItem.h"

void InvoiceItem::add(vector<string> addVector) throw (AlreadyExistsException) {
ifstream infstream; // ifstream to be used to read invoiceItem.txt
	ofstream outfstream; // ofstream to be used to write to invoiceItem.txt

	int invoice_item_id = 0; // int used to store the highest invoice__item_id so far
	int delimPos; // int used to store the position of the first delimiter

	string currentRow; // string that stores the current row on the invoice table
	string invoice_item_idTemp; // string used to store the current highest invoice_item_id so far
	string product_id = addVector[0]; // product_id to be added to file
	string quantity = addVector[1]; // quantity to be added to file

	infstream.open(fileName);

	if(infstream.is_open())
	{
		// while loop continues as long as there is another line in the text file
		// finds the highest invoice_id in the file and stores it in invoice_item_id
		while(infstream.good())
		{
			getline(infstream, currentRow); // store next line of textfile in currentRow

			// Searches for the position of the delimiter
			delimPos = currentRow.find('|');
			
			// stores the current invoice_item_id into invoice_item_idTemp
			invoice_item_idTemp = currentRow.substr(0, delimPos);

			// Assigns current invoice item id to last invoice item id if current is higher
			if(atoi(invoice_item_idTemp.c_str()) > invoice_item_id)
			{
				invoice_item_id = atoi(invoice_item_idTemp.c_str());
			}
		}
	}

	infstream.close();

	// increments invoice_id so it is higher than last invoice_id in the file
	invoice_item_id++;

	outfstream.open(fileName, ios_base::app);

	// writes to invoiceItem.txt the new row data as defined by invoice_item_id, product_id, and quantity
	// with delimiters between each input and a line break at the end
	outfstream << invoice_item_id << "|" + product_id + "|" + quantity + "\n";

	outfstream.close();
}

string InvoiceItem::search(string columnName, string valueToFind) throw(DoesNotExistException) { 

	ifstream infstream; // ifstream to be used to read invoiceItem.txt

	string returnString = ""; // string used to store the value to be returned
	string currentRow; // string used to store the current row

	//strings to store the invoice_item_id, product_id, and quantity in the current row
	string invoice_item_id, product_id, quantity; 

	// delimiters used to store positions of the delimiters '|' in the current row
	int delimPos1, delimPos2;

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

			delimPos1 = currentRow.find('|'); // finds position of first delimiter
			delimPos2 = currentRow.find('|', delimPos1 + 1); // position of second delimiter
			
			invoice_item_id = currentRow.substr(0, delimPos1); //store first string as invoice_item_id
			product_id = currentRow.substr(delimPos1 + 1, delimPos2-delimPos1-1); //store second string as product_id
			quantity = currentRow.substr(delimPos2 + 1); //store third string as quantity

			// if searching by invoice_item_id
			if(columnName == "invoice_item_id" && 
				invoice_item_id == valueToFind) {
				returnString = currentRow + "\n"; //since invoice_item_id is unique returns current row
				break;
			}
			// if searching by product_id
			else if(columnName == "product_id" &&
				product_id == valueToFind)	{	
				returnString += currentRow + "\n"; //adds any row that contains same product_id
			}
			// if searching by product_id
			else if(columnName == "quantity" &&
				quantity == valueToFind)	{	
				returnString += currentRow + "\n"; //adds any row that contains same quantity
			}
		}
	}
	
	infstream.close();

	// throws DoesNotExistException if nothing was found
	if(returnString == "")
		throw DoesNotExistException(valueToFind + " does not exist in column: " + columnName); 

	return returnString;
}
	
void InvoiceItem::modifyRow(string valueToFind, string columnNameToModify, string valueOfModify) {
	
	ifstream infstream; // ifstream to be used to read invoiceItem.txt
	ofstream outfstream; // ofstream to be used to write to invoiceItem.txt	
	vector<string> fileVector; // string vector to store each line of the invoice.txt file

	string currentRow; // string to store the current row in the table
	string invoice_item_id; //string to store invoice_item_id of currrent row
	string product_id; //string to store product_id of current row
	string quantity; //string to store quantity of current row

	int delimPos1, delimPos2; // position of delimiters in current row


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

			delimPos1 = currentRow.find('|'); // position of first delimiter '|'
			delimPos2 = currentRow.find('|', delimPos1 + 1); // position of second delimiter '|'

			// stores substring before '|' in invoice_item_id
			invoice_item_id = currentRow.substr(0, delimPos1);
			// store second substring between first and second delimiters into product_id
			product_id = currentRow.substr(delimPos1 + 1, delimPos2 - delimPos1 - 1); 
			// store third substring after second delimiter into quantity
			quantity = currentRow.substr(delimPos2 + 1);

			// if the invoice_item_id of the currentRow matches valueToFind, modify the row
			// and push_back the modified string into fileVector
			// otherwise push_back the same string into fileVector
			if (invoice_item_id == valueToFind)
			{
				if (columnNameToModify == "product_id") // modify product_id
					fileVector.push_back(invoice_item_id + "|" + valueOfModify + "|" + quantity + "\n");
				else if (columnNameToModify == "quantity") // modify quantity
					fileVector.push_back(invoice_item_id + "|" + product_id + "|" + valueOfModify + "\n");
			}
			else
				fileVector.push_back(invoice_item_id + "|" + product_id + "|" +  quantity + "\n");
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

void InvoiceItem::deleteRow(string valueToFind) {}

InvoiceItem::InvoiceItem() { fileName = "textfiles\\invoiceItem.txt"; }

InvoiceItem::~InvoiceItem() {};