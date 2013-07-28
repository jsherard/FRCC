// Programmer:  Jeff Sherard
// Junly 27, 2013
// Ch09_Ex02 Program

#include <iostream>
#include<fstream>
#include <iomanip>
#include <string>

using namespace std;

// Constant

const int NUM_STUDENTS = 10;

// Structs
struct studentType
{
	string studentFName;
	string studentLName;
	int testScore;
	char grade;
};

// Functon Prototypes
void inputData();
void assignGrade();
void highestGrade();
void outputData();

int main()
{
	// Declare Variables and Arrays
	studentType classStudents[NUM_STUDENTS];
	
	// Input
	inputData();

	// Calculate
	assignGrade();

	highestGrade();

	//Output
	outputData();

	cout << endl;

	system ("pause");

	return 0;
}

void inputData()
{
	ifstream infile;
	string inputFile;

	cout << "Enter the input file name: ";
	cin >> inputFile;
	cout << endl;

	infile.open(inputFile.c_str());

	if (!infile)
	{
		cout << "Cannot open the input file." << endl;
	}

	infile.close();
	infile.clear();
}

void assignGrade()
{

}

void highestGrade()
{

}

void outputData()
{
	ofstream outfile;
	string outputFile;

	cout << "Enter the output file name: ";
	cin >> outputFile;
	cout << endl;

	outfile.open(outputFile.c_str());

	outfile.close();

	cout << left << setw(25) << "Student Name" << setw(12) << "Test Score" << setw(10) << "Grade" << endl;

	cout << "Please see the results in Ch9_Ex2Out.txt";
}