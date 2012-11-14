#include "SalesSummary.h"
#include "DoesNotExistException.h"
#include "AlreadyExistsException.h"

void SalesSummary :: add(vector<string> addVector)throw (AlreadyExistsException)
{
	string rowReceive;

	// initialization of the delimiter
	int delimiter;

	char delim = '|';

	// assigns string the vector values
	string receiptID = addVector[0];
	string salesID = addVector[1];

	// opens salesSummary.txt
	ssInFile.open(salesSummaryTextFile);
	if(ssInFile.is_open())
	{

		while(ssInFile.good())
		{
			// assigns the string to the next line in the file salesSummary.txt
			getline(ssInFile, rowReceive);

			//finds delimitor
			delimiter = rowReceive.find(delim);
						
		}
	}

	// closes the file
	ssInFile.close();
	
	// opens file and appends it to the last line
	ssOutFile.open(salesSummaryTextFile, ios_base::app);

	// writes to salesSummary.txt with delimiters
	ssOutFile<<"" + receiptID + delim + salesID + "\n";

	// closes salesSummary.txt
	ssOutFile.close();

}

string SalesSummary :: search(string columnName, string valueToFind) throw (DoesNotExistException)
{
	bool resultFound = false;
	string returnString;
	string rowReceive;
	string receiptID, salesID;

	// initialization of delimiters
	int delimiter;
	int delimiter2;
	char delim = '|';

	try{
	// opens salesSummary.txt
	ssInFile.open(salesSummaryTextFile);

	if(ssInFile.is_open())
	{
		// clears the contents in the string
		returnString.clear();

		while(ssInFile.good())
		{
			// assigns the string with the next line in the file
			getline(ssInFile, rowReceive);

			// assigns the first delimiter position
			delimiter = rowReceive.find('|');

			// assigns the second delimiter position
			delimiter2 = rowReceive.find('|', delimiter+1);

			// assigns string receipt with data in the row
			receiptID = rowReceive.substr(0, delimiter);

			// assigns string sales ID with data in the row
			salesID = rowReceive.substr(delimiter+1);
			// checks if value to find is equal to the salesID 
		
			if(columnName == "salesID" && 
				salesID == valueToFind)				
				returnString += rowReceive + "\n";
				resultFound = true;
			// checks if value to find is equal to the receiptID
			 if(columnName == "receiptID" &&
				receiptID == valueToFind)
				returnString += rowReceive + "\n";
				resultFound = true;
		}
	}
	// closes the file
	ssInFile.close();

	// ensures if the return value is less than the minimun value
	if(!resultFound)
		throw DoesNotExistException("Summary does not exist");
	return returnString;

	} catch (DoesNotExistException e)

	{
	return e.what();
	}
}

void SalesSummary :: modifyRow( string valueToFind, string columnNameToModify, string valueOfModify){}

void SalesSummary :: deleteRow( string valueToFind) {}

// Initializes sales summary text file
SalesSummary::SalesSummary() { salesSummaryTextFile = "textFiles/salesSummary.txt"; }

SalesSummary::~SalesSummary(){}