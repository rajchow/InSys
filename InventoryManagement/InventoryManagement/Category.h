#ifndef CATEGORY_H
#define CATEGORY_H

#include "TableInterface.h"

class Category : public TableInterface
{
public:
	void add(vector<string> addVector);

	string search(string columnName, string valueToFind);
};

#endif