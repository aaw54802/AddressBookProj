// AddressBookProj.cpp : This file contains branches for AddressType and test for it

/*#include <iostream>
#include "AddressType.h"
using namespace std;
int main()
{
	cout << "Testing default constructor ... " << endl;
	AddressType defAddress;
	defAddress.print();
	cout << endl;
	cout << "Testing constructor with parameters ... " << endl;
	AddressType address("123 South Street", "Newport News", "VA", 23664);
	address.print();
	cout << endl;

	cout << "Testing invalid state (Virginia)... " << endl;
	address.setState("Virginia");
	address.print();
	cout << endl;

	cout << "Testing invalid zipcode (55555555)..." << endl;
	address.setZipcode(55555555);
	address.print();
	cout << endl;

	cout << "Testing valid address ..." << endl;
	address.setAddress("44 East Main Street");
	address.setCity("Hampton");
	address.setState("VA");
	address.setZipcode(23669);
	address.print();
	cout << endl;
}*/

#include <iostream>
#include "dateType.h"

using namespace std;
// Program to verify that the modified dateType class is working correctly
int main()
{
	cout << "Testing default constructor ... ";
	dateType defDate;
	defDate.print();
	cout << endl;

	cout << "Testing constructor with parameters ... ";
	dateType date(2, 29, 2016);
	date.print();
	cout << endl;

	cout << "Setting date with invalid year (1000) ... ";
	date.setDate(2, 29, 1000);
	date.print();
	cout << endl;

	cout << "Setting date with invalid month (13) ... ";
	date.setDate(13, 29, 2016);
	date.print();
	cout << endl;

	cout << "Setting date with invalid day (4, 31) ... ";
	date.setDate(4, 31, 2016);
	date.print();
	cout << endl;

	cout << "Setting invalid date: Feb 29, 2015 ... ";
	date.setDate(2, 29, 2015);
	date.print();
	cout << endl;

	cout << "Setting valid date: Feb 28, 2015 ... ";
	date.setDate(2, 28, 2015);
	date.print();
	cout << endl;

	cout << "Setting valid date (August 15, 2016) ... ";
	date.setDate(8, 15, 2016);
	date.print();
	cout << endl;
}

