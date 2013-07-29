// Programmer:  Jeff Sherard
// Data: 07/05/13
// Assignment: Page 447 - programming exercise #24

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// functions return nothing back to main()
void input();
void calculate(double, double, double);
void output(double, double);

// main function calls out to input()
// main function acts as a driver
int main()
{
	input();

	system("pause");
	
	return 0;
}

// recieve all input
void input ()
{
	double priceItemYearNow;
	double priceItemYearOne;
	double priceItemYearTwo;

	cout << " Enter the current price of the item: ";
	cin >> priceItemYearNow;
	cout << endl << endl;
	cout << "Enter the price of the item one year ago: ";
	cin >> priceItemYearOne;
	cout << endl << endl;
	cout << "Enter the price of the item two years ago: ";
	cin >> priceItemYearTwo;
	cout << endl << endl;
	
	calculate (priceItemYearNow, priceItemYearOne, priceItemYearTwo);
}

// pass input to calculate function to do all calculations
void calculate (double priceItemYearNow, double priceItemYearOne, double priceItemYearTwo)
{
	double inflationRateNow;
	double inflationRateOne;

	// calculate inflation rates
	inflationRateNow = (priceItemYearNow - priceItemYearOne) / (priceItemYearOne);
	inflationRateOne = (priceItemYearOne - priceItemYearTwo) / (priceItemYearTwo);
	
	output (inflationRateNow, inflationRateOne);

}

// pass inflation rates to output function
void output (double inflationRateNow, double inflationRateOne)
{

	// define string variables
	string increaseInflation = "Inflation is increasing.";
	string decreaseInflation = "Inflation is decreasing.";
	string neutralInflation = "Inflation has not changed.";
	
	// output calculated inflation rates
	cout << setprecision(2) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
	cout << "Current year inflation: " << inflationRateNow <<endl;
	cout << "Inflation one year ago: " << inflationRateOne << endl;

	// decide if inflation rate is increasing, decreasing or staying the same
	if ((inflationRateOne - inflationRateNow) == 0)
		cout << neutralInflation << endl << endl;
	else if
		((inflationRateOne - inflationRateNow) > 0)
		cout << decreaseInflation << endl << endl;
	else
		cout << increaseInflation << endl << endl;
}