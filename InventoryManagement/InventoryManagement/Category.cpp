#include "Category.h"

void Category :: add(vector<string> addVector)
{
	delim = '|';

	string descript = addVector[0];
	string name = addVector[1];
	
	categoryInFile.open("category.txt");

	if(categoryInFile.is_open())
	{
		catID = 0;
		while(categoryInFile.good())
		{
			getline(categoryInFile, rowReceive);
			delimiter = rowReceive.find('|');
			categoryID = rowReceive.substr(0,delimiter);
			categoryIDTemp = atoi(categoryID.c_str());
			if(categoryIDTemp > catID)
			{
				catID = categoryIDTemp;
			}
		}
		categoryInFile.close();

		catID++;

		categoryID = to_string(catID);

		categoryOutFile.open("category.txt", ios_base::app);

		categoryOutFile<<"" + categoryID + delim + descript + delim + name + "\n";

		categoryOutFile.close();

	}
}

string Category :: search(string columnName, string valueToFind)
{
	delim = '|';

	categoryInFile.open("category.txt", ios_base::in);  //*** is adding ios_base::in necessary for ifstreams?

	//strings used to store the description and name values in a row
	string description, name;

	//integer used to store the position of the second and last delimeters in the row
	int delimiter2;

	if(categoryInFile.is_open())
	{
		returnString.clear();
		while(categoryInFile.good())
		{
			getline(categoryInFile, rowReceive);
			delimiter = rowReceive.find('|');
			delimiter2 = rowReceive.find('|', delimiter+1);
			categoryID = rowReceive.substr(0,delimiter);
			description = rowReceive.substr(delimiter+1, delimiter2-2);
			name = rowReceive.substr(delimiter2+1);
			categoryIDTemp = atoi(categoryID.c_str());
			if(columnName == "category_id" && 
				categoryIDTemp == atoi(valueToFind.c_str()))  //*** can't we use atoi(categoryID.cstr()) == atoi(valueToFind.c_str()) here?
				break; //*** added a break so loop doesn't keep going
			else if(columnName == "description" &&     //*** if statements in while loops probably isnt
				description == valueToFind)       //*** the most efficient method. Maybe we need Strategy Pattern?
				break;                            //***instead of columnName as a parameter, maybe a SearchStrategy object?
			else if(columnName == "name" &&
				name == valueToFind)
				break;

		}
	}
	categoryInFile.close();

	returnString += rowReceive + "\n";
	
	if(returnString.empty())
	{
		returnString = "Category Does Not Exist";
	}

	return returnString;
}

void Category :: deleteRow(string columnName, string valueToFind)
{
	delim = '|';
}