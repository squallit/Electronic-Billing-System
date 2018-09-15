#ifndef CustomerList_hpp
#define CustomerList_hpp

#include "BinaryTree.h"
#include "Customer.h"
#include <string>
#include <iostream>

class CustomerList : public BinaryTree<Customer>
{
public:
	void searchCustomer(string name);
	bool findCustomer(string name);
	void printReport();
};

void CustomerList::searchCustomer(string name)
{
	bool flag = false; //flag to know if search is found

	//Dummy customer to look for
	Customer tempCustomer(name, " ", " ", " ");

	//Search for Customer
	flag = searchNode(tempCustomer);

	if (flag) //found
	{
		cout << endl;
		cout << left << setw(20) << "Customer Name" << setw(30) << "Address" << setw(30) << "Email" << setw(10) << "Phone Number" << endl;
		cout << setfill('=') << setw(92) << "=" << setfill(' ') << endl;
		cout << tempCustomer;
	}
	else //not found
	{
		cout << "\nThere is not match!\n";
	}

}

bool CustomerList::findCustomer(string name)
{
	bool flag = false; //flag to know if search is found

	//Dummy customer to look for
	Customer tempCustomer(name, " ", " ", " ");

	//Search for Customer
	flag = searchNode(tempCustomer);

	return flag;
}


void CustomerList::printReport()
{
	displayInOrder();
}


#endif /* CustomerList_h */
