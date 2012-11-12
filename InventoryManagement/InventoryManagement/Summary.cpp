#include "Summary.h"

// Add function to insert data into the summary text file
// 
// parameter[in]: addVector is a vector of strings for the data to be entered
//            the first element is product_id
//            the second element is total_quantity
// throw: AlreadyExistsException if product_id already exists
// postcondition: Summary is sorted by product_id
void Summary::add(vector<string> addVector) throw(AlreadyExistsException) {
	ifstream infstream; // ifstream to be used to read summary.txt
	ofstream outfstream; // ofstream to be used to write to summary.txt

	int delimPos; // int used to store the position of the first delimiter

	string product_id = addVector[0]; // product_id to be added to file
	string total_quantity = addVector[1]; // total_quantity to be added to file
    string currentRow; // string that stores the current row on the summary table
	string productID; // string to store the product_id in the current row

	vector<string> fileVector; // vector of strings to be used for storing the text file and sorting
	
	// open the summary.txt file
	infstream.open(fileName);

	if(infstream.is_open())
	{
		// while loop continues as long as there is another line in the text file
		// finds the highest product_id in the file and stores it in product_id
		while(infstream.good())
		{
			getline(infstream, currentRow); // store next line of textfile in currentRow

			// adds currentRow to the vector if it is not empty
			// which can occur if there are no more valid entries in the table
			if(!currentRow.empty())
				fileVector.push_back(currentRow);

			// Searches for the position of the delimiter
			delimPos = currentRow.find('|');
			
			// stores the current product_id into productID
			productID = currentRow.substr(0, delimPos);

			// Throw AlreadyExistsException if product id already exists
			if(product_id == productID)
			{
				throw AlreadyExistsException("product_id already exists");
			}
		}
	}

	infstream.close();

	fileVector.push_back(product_id + "|" + total_quantity); // adds new row to vector

	sort(fileVector.begin(), fileVector.end()); // sorts the fileVector

	// opens and clears summary.txt for output
	outfstream.open(fileName, ios_base::trunc);

	// copy fileVector to summary.txt
	for(int i = 0; i < (int) fileVector.size(); i++)
		outfstream << fileVector[i] << "\n";

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
string Summary::search(string columnName, string valueToFind) throw(DoesNotExistException) { 
	
	ifstream infstream; // ifstream to be used to read summary.txt

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
			getline(infstream, currentRow); // store next line of textfile in currentRow

			// break when an empty string is assigned to currentRow
			// which occurss if there are no more valid entries in the table
			if (currentRow.empty())
				break;

			delimPos = currentRow.find('|'); // finds position of delimiter
			
			product_id = currentRow.substr(0, delimPos); // stores first string as product_id
			total_quantity = currentRow.substr(delimPos+1); // stores second string as total_quantity

			// if searching by product_id
			if(columnName == "product_id" && 
				product_id == valueToFind) {
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

// deleteRow function to find a specific row of data and remove it from the file
//
// Deletion will by done by finding the a matching value by searching for valueToFind
// in the primary key column of the table 
// precondition: Row exists. This will be checked by the main program beforehand
// parameter[in]: valueToFind identifies the value to be searched for in the primary key column (product_id)
void Summary::deleteRow(string valueToFind) {

	ifstream infstream; // ifstream to be used to read summary.txt
	ofstream outfstream; // ofstream to be used to write to summary.txt	
	vector<string> fileVector; // string vector to store each line of the summary.txt file

	string currentRow; // string to store the current row in the table
	string total_quantity; //string to store total_quantity of line to be modified
	string product_id; //string to store product_id of line to be modified
	int delimPos; // position in the line of delimiter

	infstream.open(fileName);

	if(infstream.is_open())
	{
		// while loop continues as long as there is another line in the text file
		// transfers summary.txt to fileVector with the desired row removed
		while(infstream.good())
		{
			getline(infstream, currentRow); // store next line of textfile in currentRow
			
			// break when an empty string is assigned to currentRow
			// which occurss if there are no more valid entries in the table
			if (currentRow.empty())
				break;

			delimPos = currentRow.find('|'); // position of first delimiter '|'

			product_id = currentRow.substr(0,delimPos); // stores substring before '|' in product_id
			total_quantity = currentRow.substr(delimPos + 1); // store substring after '|' in total_quantity

			if (product_id != valueToFind)
				fileVector.push_back(product_id + "|" + total_quantity + "\n");
		}
	}

	infstream.close();

	// clears summary.txt so fileVector can be written on it
	outfstream.open(fileName, ios_base::trunc);

	// copy fileVector to summary.txt
	for(int i = 0; i < (int) fileVector.size(); i++)
		outfstream << fileVector[i];
	
	outfstream.close();
}

// Modify function to change the data in a given row
//
// Modification will be done by searching by the primary key of the table (product_id)
// preconditon: Row exists. This will be checked by the main program beforehand
// param[in]: valueToFind identifies the value to be searched in the primary key column
// param[in]: columnNameToModify identifies the column to change data for
// prama[in]: valueOfModify provides the new data for the desired column
// postcondition: Summary table is sorted by product_id
void Summary::modifyRow(string valueToFind, string columnNameToModify, string valueOfModify) {
	

	ifstream infstream; // ifstream to be used to read summary.txt
	ofstream outfstream; // ofstream to be used to write to summary.txt	
	vector<string> fileVector; // string vector to store each line of the summary.txt file

	string currentRow; // string to store the current row in the table
	string total_quantity; //string to store total_quantity of line to be modified
	string product_id; //string to store product_id of line to be modified
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

			product_id = currentRow.substr(0,delimPos); // stores substring before '|' in product_id
			total_quantity = currentRow.substr(delimPos + 1); // store substring after '|' in total_quantity

			// if the product_id of the currentRow matches valueToFind, modify total_quantity
			// and push_back the modified string into fileVector
			// otherwise push_back the same string into fileVector
			if (product_id == valueToFind)
				fileVector.push_back(product_id + "|" + valueOfModify + "\n");
			else
				fileVector.push_back(product_id + "|" + total_quantity + "\n");
		}
	}

	infstream.close();

	sort(fileVector.begin(), fileVector.end()); // sorts the fileVector

	// clears summary.txt so fileVector can be written on it
	outfstream.open(fileName, ios_base::trunc);

	// copy fileVector to summary.txt
	for(int i = 0; i < (int) fileVector.size(); i++)
		outfstream << fileVector[i];
	
	outfstream.close();
}

Summary::Summary() { fileName = "textfiles\\summary.txt"; }

Summary::~Summary() {};