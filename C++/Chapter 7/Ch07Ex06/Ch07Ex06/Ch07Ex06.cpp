// Programmer:  Jeff Sherard
// Date: 07/17/13
// Assignment: Chapter 7, Exercise 6

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Function Prototypes
int doubleNumber(int x);
int reverseNumber(int x);
int raiseNumber(int x);
int sumNumber(int x);
int raiseFirstToSecondNumber(int x);
int raiseFirstTwoToLastNumber(int x);
int primeNumber(int x);
int lessThanTen (int x);
void printFunction(int x, int y);

int main()
{
	// Initialize variables
	int iRandom;
	int menuSelection;
	int primeYesNo;

	// Initialize random seed
	srand (time(NULL));
	
	// Generate random number
	iRandom = rand() % 100;
	/* TEST CASE iRandom = 28;  // PLACEHOLDER FOR RANDOM NUMBER = 28 *REMOVE**/
	cout  << "The two digit number is: " << iRandom << endl;

	do
	{

	// Menu Selection
	cout << "1: Enter 1 to double the number." << endl;
	cout << "2: Enter 2 to reverse the digits of the number." << endl; 
	cout << "3: Enter 3 to raise the number to the power of 2, 3, or 4." << endl; 
	cout << "4: Enter 4 to sum the digits of the number." << endl; 
	cout << "5: Enter 5 to raise the first digit to the power of the second digit." << endl; 
	cout << "6: Enter 6 to raise the first two digits to the power of the last digit." << endl; 
	cout << "9: Enter 9 to terminate the program." << endl;

	cin >> menuSelection;

	switch (menuSelection)
	{
	case 1:
		iRandom = doubleNumber(iRandom);
		primeYesNo = primeNumber(iRandom);
		printFunction (iRandom, primeYesNo);
		iRandom = lessThanTen (iRandom);
		break;
	case 2:
		iRandom = reverseNumber(iRandom);
		primeYesNo = primeNumber(iRandom);
		printFunction (iRandom, primeYesNo);
		iRandom = lessThanTen (iRandom);
		break;
	case 3:
		iRandom = raiseNumber(iRandom);
		primeYesNo = primeNumber(iRandom);
		printFunction (iRandom, primeYesNo);
		iRandom = lessThanTen (iRandom);
		break;
	case 4:
		iRandom = sumNumber(iRandom);
		primeYesNo = primeNumber(iRandom);
		printFunction (iRandom, primeYesNo);
		iRandom = lessThanTen (iRandom);
		break;
	case 5:
		iRandom = raiseFirstToSecondNumber(iRandom);
		primeYesNo = primeNumber(iRandom);
		printFunction (iRandom, primeYesNo);
		iRandom = lessThanTen (iRandom);
		break;
	case 6:
		iRandom = raiseFirstTwoToLastNumber(iRandom);
		primeYesNo = primeNumber(iRandom);
		printFunction (iRandom, primeYesNo);
		iRandom = lessThanTen (iRandom);
		break;
	default:
		break;

	system ("pause");

	}

	}
	while (menuSelection !=9);

	cout << endl;

	system ("pause");

	return 0;
}

int doubleNumber(int iRandom)
{
	iRandom = iRandom * 2;

	return iRandom;
}

int reverseNumber(int iRandom)
{
	// declare variables
	int ones = 0, tens = 0, huns = 0, thous = 0;
	
	// break into individual digits

	if (iRandom <10)
	{
		return iRandom;
	}

	if (iRandom < 100)
	{
		ones = iRandom%10;
		iRandom = iRandom/10;
		tens = iRandom%10;

		iRandom = ones*10 + tens*1;

		return iRandom;
	}

	if (iRandom <1000)
	{
		ones = iRandom%10;
		iRandom = iRandom/10;
		tens = iRandom%10;
		iRandom = iRandom/10;
		thous = iRandom%10;

		iRandom = ones*100 + tens*10 + thous*1;

		return iRandom;
	}
}

int raiseNumber(int iRandom)
{
	// declare variables
	double raiseTo;

	// additional input for raising iRandom to 2, 3, or 4
	cout << endl << "Enter power (2, 3, 4): ";
	cin >> raiseTo;
		
	iRandom = pow(iRandom, raiseTo);

	return iRandom;
}

int sumNumber(int iRandom)
{
	// declare variables

	int ones, tens, huns, thous;
	
	// break into individual digits
	ones = iRandom%10;
	iRandom = iRandom/10; // divide iRandom by 10 to get to tens
	tens = iRandom%10;
	iRandom = iRandom/10; // divide iRandom by 10 to get to hun
	huns = iRandom%10;
	iRandom = iRandom/10; // divide iRandom by 10 to get to thou
	thous = iRandom%10;

	iRandom = ones + tens + huns + thous;

	return iRandom;
}

int raiseFirstToSecondNumber(int iRandom)
{

	// declare variables
	double ones, tens;
	
	// break into individual digits
	ones = iRandom%10;
	iRandom = iRandom/10; // divide iRandom by 10 to get to tens
	tens = iRandom%10;

	iRandom = pow(tens, ones);

	return iRandom;
}

int raiseFirstTwoToLastNumber(int iRandom)
{
	if (iRandom <100 || iRandom > 999)
	{
		cout << endl;
		cout << "To perform this operation, it must be a three digit number." << endl;

		return iRandom;
	}

	double ones, tens, huns;
	
	// break into individual digits
	ones = iRandom%10;
	iRandom = iRandom/10; // divide iRandom by 10 to get to tens
	tens = iRandom%10;
	iRandom = iRandom/10; // divide iRandom by 10 to geth thous
	huns = iRandom%10;

	iRandom = pow(ones + tens*10, huns);

	return iRandom;
}

int primeNumber(int iRandom)
{
	int primeYesNo;
	int count = 0;

	for (int i = 2; i < iRandom; i++) // Loop to see if number is divisable
	{
		if (iRandom%i == 0)
		{
			count++;
			
			break;
		}
	}

	if (count == 0) // see if check variable has changed (if no = prime number, if yes = not prime)
	{
		primeYesNo = 0;

		return primeYesNo;
	}
	else
	{
		primeYesNo = 1;

		return primeYesNo;
	}
}

void printFunction(int iRandom, int primeYesNo)
{
		if (primeYesNo == 0)
		{
			cout << endl;
			cout << iRandom << " is prime." << endl << endl;
		}
		else
		{
			cout << endl;
			cout << iRandom << " is not prime." << endl << endl;
		}
}

int lessThanTen (int iRandom)
{
	if (iRandom < 10)
	{
		cout << iRandom << " is less than 10, so adding 10 to it." << endl;
		iRandom = iRandom + 10;

		return iRandom;
	}

	return iRandom;
}