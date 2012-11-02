/* Standard C++ headers */
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>

/* MySQL Connector/C++ specific headers */
#include <driver.h>
#include <connection.h>
#include <statement.h>
#include <prepared_statement.h>
#include <resultset.h>
#include <metadata.h>
#include <resultset_metadata.h>
#include <exception.h>
#include <warning.h>
	
#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "root"
#define DATABASE "test"

#define NUMOFFSET 100
#define COLNAME 200

using namespace std;
using namespace sql;

int main() {

	Driver *driver;
	Connection *con;
	Statement *stmt;
	ResultSet *res;

	string inputText;

	try {
		driver = get_driver_instance();
		
		/* create a database connection using the Driver */
		con = driver -> connect("tcp://127.0.0.1:3306", "root", "root");

		/* select appropriate database schema */
		con -> setSchema("insys");

		stmt = con->createStatement();

		res = stmt -> executeQuery("SELECT * FROM category");

		cout<<res->rowsCount()<<endl;
		
		cout<<"Type 'done' to exit"<<endl;

		while(inputText.compare("done"))
		{
			cin >> inputText;
		}

		/* Clean up */
		delete res;
		delete stmt;
		con -> close();
		delete con;

	} catch (SQLException &e) {
		return EXIT_FAILURE;
	} catch (std::runtime_error &e) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
} // main()