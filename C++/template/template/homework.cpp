// Programmer:  Jeff Sherard
// Program to find the average test scores and output the average
// test score and all the test scores that are less than
// the average test score.

// 85 62 94 56 71

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

int test[5];
int sum = 0;
double average;
int index;

cout << fixed << showpoint << setprecision(2);

cout << "Enter five test scores: ";

for (index = 0; index < 5; index++)
{
	cin >> test[index];
	sum = sum + test[index];
}

average =  sum / 5.0;

cout << "The average test score is: " << average << endl;

for (index = 0; index < 5; index++)
	if (test[index] < average)
		cout << test[index] << " is less than the average test score." << endl;

cout << endl;

system ("pause");
		
return 0;
}