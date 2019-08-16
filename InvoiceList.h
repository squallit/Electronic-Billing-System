#ifndef InvoiceList_hpp
#define InvoiceList_hpp

#include "BinaryTree.h"
#include "Invoice.h"
#include <string>
#include <iostream>

class InvoiceList : public BinaryTree<Invoice>
{
public:
	bool searchInvoice(Invoice& searchedInvoice);
	void printReport();
};

bool InvoiceList::searchInvoice(Invoice& searchedInvoice)
{

	//Search for Invoice
	bool	flag = searchNode(searchedInvoice);

	return flag;

}

void InvoiceList::printReport()
{
	displayInOrder();
}


#endif /* InvoiceList_h */
