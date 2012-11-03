#include "Category.h"
#include <sstream>

void Category :: add(vector<string> addVector)
{
	string descript = addVector[0];
	string name = addVector[1];

	driver = get_driver_instance();
	/* create a database connection using the Driver */
	con = driver -> connect("tcp://127.0.0.1:3306", "root", "root");
	/* select appropriate database schema */
	con -> setSchema("insys");
	stmt = con->createStatement();


	stmt -> execute("INSERT INTO category (description, name) VALUES ('" + descript + "','" + name + "');");

	con->close();
}

string Category :: search(string columnName, string valueToFind)
{
	string returnString;
	int catID;

	driver = get_driver_instance();

	/* create a database connection using the Driver */
	con = driver -> connect("tcp://127.0.0.1:3306", "root", "root");

	/* select appropriate database schema */
	con -> setSchema("insys");

	stmt = con->createStatement();

	res = stmt -> executeQuery("SELECT * FROM category WHERE category_id='1'");

	catID = res->getInt("category_id");
	ostringstream convert;
	convert << catID;

	returnString = convert.str() + " " + res->getString("description") + " " + res->getString("name");

	con->close();
	return returnString;
}