// Programmer:  Jeff Sherard
// Date: 07/20/13
// Assignment: Chapter 8, Exercise 14

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Constants
const int NO_OF_EMPLOYEES = 10;
const double OVER_TIME = 1.5;
const double WORK_WEEK = 40;

// Arrays
string *names_Array;
double *hours_Array;
double *rates_Array;
double *weekly_Array;

// Function Prototypes
void readData(ifstream&, string[], double[], double[], string&, double&, double&);
void weeklyPay(double[], double[], double&, double&);
double avgWeeklyPay(double[], double&);
void outputFunction(double&);


int main()
{
	// Initialize variables & arrays
	string names;
	string namesAvg;
	double hours;
	double rates;
	double weekly;

	// Declare file stream variables
	ifstream inData;
	inData.open("ch8_Ex14Data.txt");

	// Define Arrays
	names_Array = new string[NO_OF_EMPLOYEES];
	hours_Array = new double[NO_OF_EMPLOYEES];
	rates_Array = new double[NO_OF_EMPLOYEES];
	weekly_Array = new double[NO_OF_EMPLOYEES];

	//input data
	readData(inData, names_Array, hours_Array, rates_Array, names, hours, rates);

	inData.close();

	// calculations
	weeklyPay(hours_Array, rates_Array, hours, rates);
	avgWeeklyPay(weekly_Array, weekly);

	//output
	outputFunction(weekly);

	system ("pause");
	return 0;
}

void readData(ifstream& inData, string names_Array[], double hours_Array[], double rates_Array[], string& names, double& hours, double& rates)
{
	int i = 0;
	string line;

	while(getline(inData, line))
	{
		inData >> names >> hours >> rates;

		names_Array[i] = names;
		hours_Array[i] = hours;
		rates_Array[i] = rates;

		i++;
	}
}

void weeklyPay(double hours_Array[], double rates_Array[], double& hours, double& rates)
{
	double weekly = 0;

	for (int i = 0; i < NO_OF_EMPLOYEES; i++)

	{
		//calculation for regular pay
		weekly_Array[i] = weekly;

		if ( hours_Array[i] <= 40)
			weekly_Array[i] = hours_Array[i] * rates_Array[i];
		else
			weekly_Array[i] = ((hours_Array[i] - WORK_WEEK)*OVER_TIME + WORK_WEEK) * rates_Array[i];
	}
}

double avgWeeklyPay(double weekly_Array[], double& weekly)
{
	weekly = 0;

	// find average weekly pay rate
	for (int i = 0; i < NO_OF_EMPLOYEES; i++)
		weekly = weekly + weekly_Array[i];

	weekly = weekly / NO_OF_EMPLOYEES;

	return weekly;
}

void outputFunction(double& weekly)
{	
	cout << fixed << showpoint << setprecision(2);
	
	cout << left << setw(10) << "Name" << right << setw(10) << "Hrs Worked"
		 << setw(10) << "Pay Rate" << setw(10) << "Salary" << endl;

	for (int i = 0; i < NO_OF_EMPLOYEES; i++)
			cout << left << setw(10) << names_Array[i] << right << setw(10) << hours_Array[i]
				 << setw(10) << rates_Array[i] << setw(10) << weekly_Array[i] << endl;
	
	cout << endl;

	cout << "Average Salary: $" << weekly << endl;

	cout << endl;
	
	cout << "Employees whose salaries are greater than or equal to the average salary" << endl;

	for (int i = 0; i < NO_OF_EMPLOYEES; i++)
	{
		if (weekly_Array[i] > weekly)
			cout << names_Array[i] << endl;
	}

	cout << endl;
}