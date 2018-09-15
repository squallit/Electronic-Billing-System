#ifndef ProductList_hpp
#define ProductList_hpp

#include "BinaryTree.h"
#include "Product.h"
#include <string>
#include <iostream>

class ProductList : public BinaryTree<Product>
{
public:
	void searchProduct(string name);
	Product getProduct(string name);
	void printReport();
};

void ProductList::searchProduct(string name)
{
	bool flag = false; //flag to know if search is found

					   //Dummy Product to look for
	Product tempProduct(0, name, 0.0);

	//Search for Product
	flag = searchNode(tempProduct);

	if (flag) //found
	{
		cout << endl;
		cout << left << setw(15) << "Product ID" << setw(30) << "Product Name" << setw(10) << "Price" << endl;
		cout << setfill('=') << setw(55) << "=" << setfill(' ') << endl;
		cout << tempProduct;
	}
	else //not found
	{
		cout << "\nThere is not match!\n";
	}

}

//Get a product data from its name
Product ProductList::getProduct(string name)
{
	bool flag = false; //flag to know if search is found

					   //Dummy Product to look for
	Product tempProduct(0, name, 0.0);

	//Search for Product
	flag = searchNode(tempProduct);

	//If not found still return tempProduct with productID = 0
	return tempProduct;
}

void ProductList::printReport()
{
	displayInOrder();
}


#endif /* ProductList_h */
