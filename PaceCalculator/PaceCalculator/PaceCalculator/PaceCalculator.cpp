// Programmer:  Jeff Sherard
// Date: 07/05/13
// Race Calculator

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void paceCalculator(double distanceMiles, double timeMinutes);
void distanceCalculator(double minutesMiles, double timeMinutes);
void timeCalculator(double distanceMiles, double minutesMiles);

int main()
{
	// define variables
	double distanceMiles;
	double timeMinutes;
	double minutesMiles;
	double paceTime;

	char inputLetter;

	// Introduction
	cout << "Program to calculate your running time, distance or pace."
		<< endl
		<< endl;

		cout << "To stop the program enter #."
		<< endl
		<< endl;

	// get input
	// Given 2 of 3 variables - calculate pace, distance or time
	cout << "Do you want to calculate Pace, Distance or Time? (P, D, T) = ";
	cin >> inputLetter;

	while (inputLetter != '#')
	{

	if (inputLetter == 'P' || inputLetter == 'p' ||inputLetter == 'D' ||inputLetter == 'd' || inputLetter == 'T' || inputLetter == 'P')

	switch (inputLetter)
	{
	//	Choose paceCalculator
	case ('P'):
	case ('p'):
		cout << "Input distance in miles: ";
		cin >> distanceMiles;
		cout << "Input time in minutes: ";
		cin >> timeMinutes;
		cout << endl;

		paceCalculator(distanceMiles,timeMinutes);

		break;

	//	Choose distanceCalculator
	case ('D'):
	case ('d'):
		cout << "Input pace in minutes/miles: ";
		cin >> minutesMiles;
		cout << "Input time in minutes: ";
		cin >> timeMinutes;
		cout << endl;

		distanceCalculator(minutesMiles, timeMinutes);

		break;

	//	Choose timeCalculator
	case ('T'):
	case ('t'):
		cout << "Input distance in miles: ";
		cin >> distanceMiles;
		cout << "Input pace in min/miles: ";
		cin >> paceTime;
		cout << endl;

		timeCalculator(distanceMiles, paceTime);

		break;
	}

	else
	cout << endl;
	cout << "To stop the program enter #." << endl << endl;
	cout << "Do you want to calculate Pace, Distance or Time? (P, D, T) = " << endl;
	cin >> inputLetter;

	system("pause");

	} // end while

	return 0;
}

void paceCalculator(double distanceMiles, double timeMinutes)
{
	double paceTime;

	// calculate
	paceTime = timeMinutes / distanceMiles;

	// output results
	cout << "Pace = " << paceTime << " min/mile" << endl << endl;
	cout << "===================================================" << endl << endl;
}

void distanceCalculator(double minutesMiles, double timeMinutes)
{
	double distanceTraveled;

	// calculate
	distanceTraveled = minutesMiles / timeMinutes;

	// output results
	cout << "Distance = " << distanceTraveled << " miles" << endl << endl;
	cout << "===================================================" << endl << endl;
}

void timeCalculator(double distanceMiles, double paceTime)
{
	double timeSpent;

	// calculate
	timeSpent = distanceMiles * paceTime;

	// output results
	cout << "Time = " << timeSpent << " minutes" << endl << endl;
	cout << "===================================================" << endl << endl;
}