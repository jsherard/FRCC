// Programmer:  Jeff Sherard
// ch09_ex07

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// struct

struct footballPlayer
{
	string name;
	string position;
	int touchdowns;
	int catches;
	int passing;
	int receiving;
	int rushing;
};

void inputFunction(footballPlayer player[]);
void outputFunction(footballPlayer player[]);

int main()
{
	// initialize variables and arrays
	footballPlayer player[10];
	int switchData;

	// menu
	cout << "Enter \"1\" to input data or \"2\" to output data: ";
	cin >> switchData;
	cout << endl;

	switch (switchData)
	{
	case 1:
	//input function
		inputFunction(player);
	case 2:
	//output function
		outputFunction(player);
		break;
	default:
		cout << "Please choose \"1\" or \"2\"";
	}

	system ("pause");
		
	return 0;
}

void inputFunction(footballPlayer player[])
{
	ifstream inFile;
	inFile.open("playerData.txt");

	for (int index = 0; index < 10; index++)
	{
		inFile >> player[index].name;
		inFile >> player[index].position;
		inFile >> player[index].touchdowns;
		inFile >> player[index].catches;
		inFile >> player[index].passing;
		inFile >> player[index].receiving;
		inFile >> player[index].rushing;
	}

	inFile.close();
}

void outputFunction(footballPlayer player[])
{
	cout << left
		 << setw(11) << "Name"
		 << setw(11)  << "Position"
		 << setw(11)  << "Touchdowns"
		 << setw(11)  << "Catches"
		 << setw(11)  << "Passing"
		 << setw(11)  << "Receiving"
		 << setw(11)  << "Rushing"
		 <<endl;

	for (int index = 0; index < 10; index++)
	{
		cout << left
			 << setw(11) << player[index].name
			 << setw(11) << player[index].position
			 << setw(11) << player[index].touchdowns
			 << setw(11) << player[index].catches
			 << setw(11) << player[index].passing
			 << setw(11) << player[index].receiving
			 << setw(11) << player[index].rushing << endl;
	}

	cout << endl;
}