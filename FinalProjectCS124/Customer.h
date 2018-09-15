#ifndef Customer_H
#define Customer_H


#include <string>
#include <iomanip>
#include "Invoice.h"
using namespace std;


class Customer
{
private:
	string name, address, email, phone;
public:


	Customer()
	{
		name = address = email = phone = "";
	}

	Customer(string f_name, string f_address, string f_email, string f_phone)
	{
		name = f_name;
		address = f_address;
		email = f_email;
		phone = f_phone;
	}

	bool operator<(Customer);
	bool operator>(Customer);
	bool operator==(Customer);
	friend ostream& operator<<(ostream&, Customer);

	string getName() { return name; }
	void setName(string f_name) { name = f_name; }
	string getAddress() { return address; }
	string getEmail() { return email; }
	string getPhone() { return phone; }

};





bool Customer::operator<(Customer right)
{
	if (name < right.name)
		return true;
	else 
		return false;
}

bool Customer::operator>(Customer right)
{
	if (name > right.name)
		return true;
	else
		return false;
}

bool Customer::operator==(Customer right)
{
	if (name == right.name)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, Customer right)
{
	out << left << setw(20) << right.name << setw(30) << right.address << setw(30) << right.email << setw(10) << right.phone;
	return out;
}



#endif
