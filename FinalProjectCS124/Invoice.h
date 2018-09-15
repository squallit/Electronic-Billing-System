#ifndef Invoice_H
#define Invoice_H


#include <string>
#include <iomanip>
#include <vector>
#include "Product.h"
#include "Order.h"
using namespace std;


class Invoice
{
private:
	int invoiceID;
	string customerName;
	vector<Order> orderLists;
	double invoiceTotal;
public:


	Invoice()
	{
		invoiceID = 0;
		customerName = "";
		invoiceTotal = 0.0;
	}

	Invoice(int f_invoiceID, string f_customerName, vector<Order> f_orderLists)
	{
		invoiceID = f_invoiceID;
		customerName = f_customerName;
		orderLists = f_orderLists;


		//Get the total amount of the invoice
		invoiceTotal = 0.0;
		for (int i = 0; i < orderLists.size(); i++)
		{
			invoiceTotal += orderLists[i].total;
		}

	}

	bool operator<(Invoice);
	bool operator>(Invoice);
	bool operator==(Invoice);
	friend ostream& operator<<(ostream&, Invoice);

	int getInvoiceID() { return invoiceID; }
	void setInvoiceID(int f_invoiceID) { invoiceID = f_invoiceID; }
	string getCustomerName() { return customerName; }
	double getInvoiceTotal() { return invoiceTotal; }
	vector<Order> getOrderList() { return orderLists; }

};





bool Invoice::operator<(Invoice right)
{
	if (invoiceID < right.invoiceID)
		return true;
	else
		return false;
}

bool Invoice::operator>(Invoice right)
{
	if (invoiceID > right.invoiceID)
		return true;
	else
		return false;
}

bool Invoice::operator==(Invoice right)
{
	if (invoiceID == right.invoiceID)
		return true;
	else
		return false;
}


ostream& operator<<(ostream& out, Invoice right)
{
	out << left << setw(10) << right.invoiceID << setw(30) << right.customerName << setw(10) << right.invoiceTotal;
	return out;
}



#endif
