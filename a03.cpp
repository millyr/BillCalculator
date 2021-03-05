#include <iostream>
#include <cmath>
using namespace std;

/******************************************************************************
** Program Name : Verizon Bill Calculator
** File Name    : a03.cpp
** Author		: Milly R. Dorante-Morales
** Date			: 11/30/2020
** Assignment	: 03
** Description	: Calculates customers bill according to phone plan and amount
**				  gigabytes used.
** Sources		: None.
*/

/******************************************************************************
** Function Name	: introduction
** Parameters		: None.
** Description		: Displays Verizon's phone plans and overage charges/
******************************************************************************/

void introduction() {
	cout << "S: 2GB $35/mo*" << endl;
	cout << "M: 4GB $50/mo*" << endl;
	cout << "L: 8GB $70/mo*" << endl;
	cout << "U: Unlimited $75/mo\n" << endl;
	cout << "*Overage charges $15 per GB\n" << endl;
}

/******************************************************************************
** Function Name	: main
** Parameters		: None.
** Description		: Calls introduction function, has a while loop thats check
**					  whether the char plan is a valid input corresponding 
**					  to phone plans, then calculates bill according to GB
**					  usage, and if the total cost is more than $75, an upgrade
**					  to the unlimited plan is recommended.
******************************************************************************/

int main() {
	char plan;
	double gigs = 0;
	double totalCost = 0;
	double planCost = 0;
	double overageCost = 0;
	bool validPlan = false;

	introduction();

	while (validPlan == false) {
		cout << "Which plan are you on? (S,M,L,U): ";
		cin >> plan;

		plan = tolower(plan);
		if (plan == 's' || plan == 'm' || plan == 'l' || plan == 'u') {
			validPlan = true;
		}
		else {
			cout << "Invalid Plan!" << endl;
		}
	}
	cout << "\nHow many GBs did you use?: ";
	cin >> gigs;
	gigs = ceil(gigs);
	switch (plan)
	{
	case 's':if (gigs <= 2) {
			overageCost = 0;
			planCost = 35.00;
			totalCost = 35.00;
			}
		else {
			planCost = 35.00;
			overageCost = ((double)gigs - 2.00) * 15.00;
			totalCost = planCost + overageCost;
		}
			break;
	case 'm':if (gigs <= 4) {
			overageCost = 0;
			planCost = 50.00;
			totalCost = 50.00;
		}
		else {
			planCost = 50.00;
			overageCost = ((double)gigs - 4.00) * 15.00;
			totalCost = planCost + overageCost;
		}
			break;
	case 'l':if (gigs <= 8) {
			overageCost = 0;
			planCost = 70.00;
			totalCost = 70.00;
		}
		else {
			planCost = 70.00;
			overageCost = ((double)gigs - 8.00) * 15.00;
			totalCost = planCost + overageCost;
		}
			break;
	case 'u':
		overageCost = 0;
		planCost = 75.00;
		totalCost = 75.00;
		break;
	}
	if (overageCost == 0) {
		cout << "Plan Charges: $" << planCost << endl;
		cout << "Total Charges: $" << totalCost << endl;
		if (totalCost >= 75.0) {
			cout << "Upgrade to Unlimited and save $" << totalCost - 75.00;
		}
	}
	else {
		cout << "Plan Charges: $" << planCost << endl;
		cout << "Overage Charges: $" << overageCost << endl;
		cout << "Total Charges: $" << totalCost << endl;
		if (totalCost >= 75.00) {
			cout << "Upgrade to Unlimited and save $" << totalCost - 75.00;
		}
	} 
}
