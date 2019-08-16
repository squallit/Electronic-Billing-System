/*
Basic Electronics Billing System
*/

//this is main
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "BinaryTree.h"
#include "Order.h"
#include "Customer.h"
#include "CustomerList.h"
#include "Product.h"
#include "ProductList.h"
#include "Invoice.h"
#include "InvoiceList.h"

/*******************
Function Prototypes
********************/
int DisplayMenu();
void initializeData(CustomerList&, ProductList&, InvoiceList&);

//===========================================
//Add a new customer
Customer addCustomer();
//Find a customer
void findCustomer(CustomerList&);
//Print all customers
void printCustomers(CustomerList&);
//============================================


//===========================================
//Add a new product
Product addProduct();
//Find a customer
void findProduct(ProductList&);
//Print all customers
void printProducts(ProductList&);
//============================================


//===========================================
//Add a new invoice
Invoice addInvoice(CustomerList&, ProductList&);
//Find a Invoice
void findInvoice(InvoiceList&, CustomerList&, ProductList&);
//============================================

int main()
{
	CustomerList customers;
	ProductList products;
	InvoiceList invoices;


	//Initialize sample data
	initializeData(customers, products, invoices);


	//Menu for user's choice
	//Repeat until user choose to quit
	while (true)
	{
		//Display Menu and Get User's Option
		int userOption = DisplayMenu();


		if (userOption == 1)
		{
			//Create a new customer
			Invoice newInvoice = addInvoice(customers, products);

			//Insert new Customer into binary tree
			invoices.insertNode(newInvoice);

			cout << endl << "New Invoice Added!" << endl;
		}
		else if (userOption == 2)
		{
			
			//Find a customer
			findInvoice(invoices, customers, products);
		}
		else if (userOption == 3)
		{
			//Create a new customer
			Customer newCustomer = addCustomer();

			//Insert new Customer into binary tree
			customers.insertNode(newCustomer);

			cout << endl << "New Customer Added!" << endl;
		}
		else if (userOption == 4)
		{
			//Find a customer
			findCustomer(customers);
		}
		else if (userOption == 5)
		{
			//Print all customers
			printCustomers(customers);
		}
		else if (userOption == 6)
		{
			//Create a new product
			Product newProduct = addProduct();

			//Insert new Product into binary tree
			products.insertNode(newProduct);

			cout << endl << "New Product Added!" << endl;
		}
		else if (userOption == 7)
		{
			//Find a Product
			findProduct(products);
		}
		else if (userOption == 8)
		{
			//Print all Products
			printProducts(products);
		}
		else
		{
			//Exit the program
			cout << "Thank you for using the program!!! Bye!!!\n";
			return 0;
		}
	}

}

int DisplayMenu()
{
	int option; // this variable will save user's choice
	//Displaying Options for the menu
	cout << endl << endl;
	cout << "==================================" << endl;
	cout << "   LUU ELECTRONICS BILING SYSTEM  " << endl;
	cout << "==================================" << endl << endl;
	cout << "1) CREATE A NEW INVOICE" << endl;
	cout << "2) FIND AN INVOICE" << endl;
	cout << "==================================" << endl;
	cout << "3) ADD A NEW CUSTOMER" << endl;
	cout << "4) FIND A CUSTOMER" << endl;
	cout << "5) PRINT ALL CUSTOMERS" << endl;
	cout << "==================================" << endl;
	cout << "6) ADD A NEW PRODUCT" << endl;
	cout << "7) FIND AN PRODUCT" << endl;
	cout << "8) PRINT ALL PRODUCT" << endl;
	cout << "==================================" << endl;
	cout << "9) EXIT PROGRAM" << endl << endl;
	cout << "Enter your choice : ";
	cin >> option;

	while (cin.fail() == true || option < 1 || option > 9)
	{
		//Error message
		cin.clear();
		cout << "Invalid Choice! Please re-enter your choice: ";
		cin.ignore(256, '\n');
		cin >> option;

	}   //condition of do-while loop

	return option;
}



//Initialize Sample Data
void initializeData(CustomerList& customers, ProductList& products, InvoiceList& invoices)
{
	//Initialize Sample Customer Data
	customers.insertNode(Customer("John Robinson", "San Jose, CA", "robinson.john@gmail.com", "408-444-9820"));
	customers.insertNode(Customer("Mary Smith", "San Francisco, CA", "smith.mary@hotmail.com", "510-123-4567"));
	customers.insertNode(Customer("Son Luu", "San Jose, CA", "paul.luu@gmail.com", "408-000-4181"));
	customers.insertNode(Customer("Elton Lee", "Chicago, IL", "lee.elton@yahoo.com", "345-235-8482"));
	customers.insertNode(Customer("Paris Garcia", "New York, NY", "paris.garcia@company.com", "123-324-3567"));

	//Initialize Sample Product Data
	products.insertNode(Product(1, "iPad Air", 500.00));
	products.insertNode(Product(2, "iPad Mini", 400.00));
	products.insertNode(Product(3, "Samsung S7", 599.00));
	products.insertNode(Product(4, "iPhone 7", 699.00));
	products.insertNode(Product(5, "iPhone 7 Plus", 799.00));
	products.insertNode(Product(6, "LG G3", 250.00));
	products.insertNode(Product(7, "Samsung Note 7", 850.00));
	products.insertNode(Product(8, "Bose Speaker", 199.00));
	products.insertNode(Product(9, "JBL Speaker", 149.00));
	products.insertNode(Product(10, "Sony Headphone", 500.00));

	//Initialize Sample Invoice Data
	
	//create a vector array of struct Order
	//Order is a struct with attributes: 
	//Product item;
	//int quantity;
	//double total;

	//First invoice
	vector<Order> orders_1;
	orders_1.push_back(Order(products.getProduct("iPad Air"), 2));
	orders_1.push_back(Order(products.getProduct("LG G3"), 1));
	orders_1.push_back(Order(products.getProduct("Sony Headphone"), 1));
	invoices.insertNode(Invoice(1, "Son Luu", orders_1));

	//Second Invoice
	vector<Order> orders_2;
	orders_2.push_back(Order(products.getProduct("Samsung Note 7"), 1));
	orders_2.push_back(Order(products.getProduct("JBL Speaker"), 2));
	orders_2.push_back(Order(products.getProduct("iPad Mini"), 3));
	invoices.insertNode(Invoice(2, "Elton Lee", orders_2));

	//Third Invoice
	vector<Order> orders_3;
	orders_3.push_back(Order(products.getProduct("iPhone 7 Plus"), 2));
	orders_3.push_back(Order(products.getProduct("Samsung S7"), 1));
	orders_3.push_back(Order(products.getProduct("Bose Speaker"), 3));
	invoices.insertNode(Invoice(3, "John Robinson", orders_3));
}




//Add a new customer
Customer addCustomer()
{
	string name, address, email, phone;

	cout << "Enter customer name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter customer address: ";
	getline(cin, address);
	cout << "Enter customer email: ";
	getline(cin, email);
	cout << "Enter customer phone number: ";
	getline(cin, phone);

	return Customer(name, address, email, phone);
}


//Find a customer
void findCustomer(CustomerList& customers)
{
	string name;

	cout << "Enter customer's name to search for: ";
	cin.ignore();
	getline(cin, name);

	//Search for a customer using binary tree
	customers.searchCustomer(name);
}

//Print all customers
void printCustomers(CustomerList& customers)
{
	cout << endl;
	cout << left << setw(20) << "Customer Name" << setw(30) << "Address" << setw(30) << "Email" << setw(10) << "Phone Number" << endl;
	cout << setfill('=') << setw(92) << "=" << setfill(' ') << endl;
	customers.printReport();
}


//Add a new product
Product addProduct()
{
	int id;
	string name;
	double price;

	cout << "Enter product id: ";
	cin.ignore();
	cin >> id;
	cout << "Enter product name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter product price: ";
	cin >> price;

	return Product(id, name, price);
}
//Find a customer
void findProduct(ProductList& products)
{
	string name;

	cout << "Enter product name to search for: ";
	cin.ignore();
	getline(cin, name);

	//Search for a customer using binary tree
	products.searchProduct(name);
}


//Print all customers
void printProducts(ProductList& products)
{
	cout << endl;
	cout << left << setw(15) << "Product ID" << setw(30) << "Product Name" << setw(10) << "Price" << endl;
	cout << setfill('=') << setw(55) << "=" << setfill(' ') << endl;
	products.printReport();
}


//Add a new invoice
Invoice addInvoice(CustomerList& customers, ProductList& products)
{
	//Vector array to add orders together
	vector<Order> orders;
	int invoiceID;
	string customerName;
	string productName;
	int quantity;
	char productFlag = 'y';
	char customerFlag = 'y';

	cout << "\nAdding orders to invoice...\n\n";
	cout << "Enter invoice ID: ";
	cin >> invoiceID;
	cin.ignore(256, '\n');

	
	//Search and add customer 
	//Customer must be in customer list
	//display customer names for reference
	cout << endl << "======= Customer Reference Table ==========" << endl;
	printCustomers(customers);
	do
	{
		

		cout << "\nEnter exact customer name: ";
		getline(cin, customerName);

		bool customerFound = customers.findCustomer(customerName);


		if (!customerFound)
		{
			cout << "\nCustomer not found! Please try again.\n";
		}
		else //customerFound
		{
			cout << "\nCustomer found! Adding orders for " << customerName << "...\n";
			customerFlag = 'n';
		}

	} while (customerFlag == 'y');


	
	//Search and add item 
	//Item product must be available in the product list
	//Display products for user reference
	cout << endl << "======= Products Reference Table ==========" << endl;
	printProducts(products);
	do
	{
		cout << "\nEnter exact product name to be added to invoice: ";
		getline(cin, productName);

		Product newProduct = products.getProduct(productName);
		if (newProduct.getSku() == 0)
		{
			cout << "\nProduct not found! Please try again.\n";
		}
		else
		{
			cout << "Enter quantity: ";
			cin >> quantity;

			//Add order to cart
			orders.push_back(Order(newProduct, quantity));

			cout << "\nNew order added!\n";
			cout << "\nContinue to add another order? (y or n): ";
			cin >> productFlag;
			cin.ignore();
		}

		
	} while (productFlag == 'y');

	
	return Invoice(invoiceID, customerName, orders);
}


//Find a Invoice
void findInvoice(InvoiceList& invoices, CustomerList& customers, ProductList& products)
{
	int invoiceID;
	cout << "Enter invoice ID to search for: ";
	cin.ignore();
	cin >> invoiceID;


	//Dummy Invoice to look for
	Invoice tempInvoice;
	tempInvoice.setInvoiceID(invoiceID);

	//Search for a invoice using invoice ID
	bool flag = invoices.searchInvoice(tempInvoice);

	if (flag)
	{
		cout << endl << endl;
		cout << "========================================= INVOICE " << invoiceID << " ======================================" << endl;
		cout << "Invoice ID: " << tempInvoice.getInvoiceID() << endl;
		
		//Print customer information associted with the customer name on the invoice
		cout << "\n\nCUSTOMER INFORMATION: " << endl;
		customers.searchCustomer(tempInvoice.getCustomerName());
		cout << endl;

		//Print order information
		cout << "\n\ORDER INFORMATION: " << endl << endl;
		cout << left << setw(15) << "Product ID"
			<< left << setw(30) << "Product Name"
			<< left << setw(15) << "Price"
			<< left << setw(15) << "Quantity"
			<< left << setw(15) << "Total" << endl;
		cout << setfill('=') << setw(90) << "=" << setfill(' ') << endl;
		//Print orders information associated with the invoice
		vector<Order> orderList = tempInvoice.getOrderList();
		for (int i = 0; i < orderList.size(); i++)
		{
			
			
			cout << left << setw(15) << orderList[i].item.getSku()
				<< left << setw(30) << orderList[i].item.getName()
				<< left << setw(15) << orderList[i].item.getPrice()
				<< left << setw(15) << orderList[i].quantity
				<< left << setw(15) << orderList[i].total << endl;
			
		}


		//Total amount
		cout << endl << fixed << setprecision(2) << "INVOICE TOTAL: $" << tempInvoice.getInvoiceTotal() << endl << endl;
		cout << "=================================== END OF INVOICE " << invoiceID << " ======================================" << endl;
		
	}
}
