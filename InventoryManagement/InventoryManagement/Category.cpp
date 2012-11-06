#include "Category.h"

void Category :: add(vector<string> addVector)
{
	delim = '|';

	string descript = addVector[0];
	string name = addVector[1];
	
	categoryInFile.open("category.txt", ios_base::in);

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

	categoryInFile.open("category.txt", ios_base::in);

	if(categoryInFile.is_open())
	{
		returnString.clear();
		while(categoryInFile.good())
		{
			getline(categoryInFile, rowReceive);
			delimiter = rowReceive.find('|');
			categoryID = rowReceive.substr(0,delimiter);
			categoryIDTemp = atoi(categoryID.c_str());
			if(categoryIDTemp == atoi(valueToFind.c_str()))
			{
				returnString += rowReceive + "\n";
			}
		}
	}
		categoryInFile.close();
	

	return returnString;
}