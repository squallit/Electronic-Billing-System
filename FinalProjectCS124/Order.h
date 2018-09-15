#ifndef ORDER_H
#define ORDER_H

#include "Product.h"


struct Order
{
	Product item;
	int quantity;
	double total;

	Order()
	{
		Product item;
		quantity = 0;
		total = item.getPrice() * quantity;
	}

	Order(Product f_item, int f_quantity)
	{
		item = f_item;
		quantity = f_quantity;
		total = item.getPrice() * quantity;
	}
};

#endif