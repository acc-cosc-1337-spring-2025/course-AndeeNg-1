//write include statements
#include<iostream>
#include "hwexpressions.h"

using std::cout; using std::cin; using std::endl;
//write namespace using statement for cout

int main()
{
	double meal_amount, tip_rate, tip_amount, tax_amount, total;
	
	cout << "Enter meal amount: ";
	cin >> meal_amount;

	tax_amount = get_sales_tax_amount(meal_amount);

	cout << "Enter tip rate (as demical): ";
	cin >> tip_rate;

	tip_amount = get_tip_amount(meal_amount, tip_rate);

	total = tip_amount + tax_amount + meal_amount;

	cout << "Meal Amount: " << meal_amount << endl;
	cout << "Sales Tax: " << tax_amount << endl;
	cout << "Tip Amount: " << tip_amount << endl;
	cout << "Total: " << total << endl;
	return 0;
}
