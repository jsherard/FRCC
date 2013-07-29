// Programmer:  Jeff Sherard
// Date: 07/02/13
// Assignment: Chapter 5 Exercise #9

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	// define variables
	int firstNum, secondNum;
	int sumEven = 0, sumOddSquares = 0;
	
	// input
	cout << "Enter two numbers." << endl;
	cout << "First number must be less than the second number you enter" << endl;
	cout << "Enter numbers: ";
	cin >> firstNum >> secondNum;
	
	if (firstNum > secondNum)
		{
			cout << "First Number must be less than second number" << endl << endl;

			cout << "Enter two numbers." << endl;
			cout << "First number must be less than the second number you enter" << endl;
			cout << "Enter numbers: ";
			cin >> firstNum >> secondNum;
		}

	cout << endl;

	// Output all odd numbers between firstNum and secondNum
	cout << "Odd integers between " << firstNum << " and " << secondNum << " are:" << endl;
	int i = firstNum;
	while (i <= secondNum) 
	{
		if (i % 2 != 0)
			{
				cout << i << " ";
			}
		i = i + 1;
	}

	// Output line break
	cout << endl;

	// Output the sum of all even numbers between firstNum and secondNum
	i = firstNum;
	while (i <= secondNum) 
	{
		if (i % 2 == 0)
			{
				sumEven = sumEven + i;
			}
		i = i + 1;
	}
	cout << "Sum of even integers between " << firstNum << " and " << secondNum << " = " << sumEven << endl;

	// Output the numbers and their squares between firstNum and secondNum
	cout << "Number" << setw(20) << "Square of Number" << endl;
	i = firstNum;
	while (i <= secondNum)
	{
		cout << setw(4) << i << setw(19) << i * i << endl;
		i= i + 1;
	}

	// Output line break
	cout << endl;

	// Output the sum of the square of the odd numbers between firstNum and secondNum
	i = firstNum;
	while (i <= secondNum) 
	{
		if (i % 2 != 0)
			{
				sumOddSquares = sumOddSquares + (i * i);
			}
		i = i + 1;
	}
	
	cout << "Sum of the squares of odd integers between " << firstNum << " and " << secondNum << " = " << sumOddSquares << endl;

	// Output all uppercase letters
	cout << "Upper case letters are: ";
	
	char letterUpper = 'A';

	while (letterUpper <= 'Z')
	{
		cout << letterUpper << " ";
		letterUpper++;
	}

	cout << endl << endl;

	system("pause");

	return 0;
}