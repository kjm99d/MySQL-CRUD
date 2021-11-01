#pragma once(lib, "mysqlcppconn8-static.lib")

#include <stdlib.h>
#include <iostream>

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>

using namespace std;

int main(void)
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;

	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "1@jungmin");
	con->setSchema("test_db");
	
	pstmt = con->prepareStatement("SELECT * FROM tester;");
	result = pstmt->executeQuery();

	while (result->next())
	{

		sql::SQLString stra = result->getString("des");
		cout << stra.c_str() << endl;;
	
	}

	

	delete con;

	cout << endl;

	return EXIT_SUCCESS;
}