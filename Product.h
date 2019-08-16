#ifndef Product_H
#define Product_H


#include <string>
#include <iomanip>

using namespace std;


class Product
{
private:
	int productID;
	string  productName;
	double productPrice;
	
public:


	Product()
	{
		productID = 0;
		productName = "";
		productPrice = 0.0;
	}

	Product(int f_productID, string f_productName, double f_price)
	{
		productID = f_productID;
		productName = f_productName;
		productPrice = f_price;
	}

	bool operator<(Product);
	bool operator>(Product);
	bool operator==(Product);
	friend ostream& operator<<(ostream&, Product);

	int getSku() { return productID; }
	string getName() { return productName; }
	double getPrice() { return productPrice; }

};


bool Product::operator<(Product right)
{
	if (productName < right.productName)
		return true;
	else
		return false;
}

bool Product::operator>(Product right)
{
	if (productName > right.productName)
		return true;
	else
		return false;
}

bool Product::operator==(Product right)
{
	if (productName == right.productName)
		return true;
	else
		return false;
}


ostream& operator<<(ostream& out, Product right)
{
	out << left << setw(15) << right.productID << setw(30) << right.productName << fixed << setprecision(2) << "$ " << right.productPrice;
	return out;
}



#endif
