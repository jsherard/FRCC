// Programmer:  Jeff Sherard
// Junly 27, 2013
// Ch09_Ex02 Program

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Constant - to set class size

const int NUM_STUDENTS = 20;

// Structs - create student info (to store in an array)
struct studentType
{
	string studentFName;
	string studentLName;
	int testScore;
	char grade;	
};

// Functon Prototypes  **CURRENTLY SET FOR VOID - May pass data later**
void inputData(ifstream& infile, studentType list[], int listSize);
void assignGrade(studentType list[], int listSize);
int highestScore(studentType list[], int listSize);
void outputData(ofstream& outfile, studentType list[], int listSize, int temp);

int main()
{
	// Open Input/Output File - Ch9_Ex2Data.txt (studentFName studentLlName score) + Ch9_ExOut.txt
	ifstream infile;
	ofstream outfile;
	string inputFile = "Ch9_Ex2Data.txt";
	string outputFile = "Ch9_Ex2out.txt";

	// Declare Variables and Arrays
	int temp;
	studentType classStudents[NUM_STUDENTS];

	infile.open(inputFile.c_str());

	// if data file doesn't exist error out
	if (!infile)
	{
		cout << "Cannot open the input file." << endl;
	}
	
	// Input
	inputData(infile, classStudents, NUM_STUDENTS);

	infile.close();
	infile.clear();

	// Calculate
	assignGrade(classStudents, NUM_STUDENTS);
	temp = highestScore(classStudents, NUM_STUDENTS);

	// put data in output file
	outfile.open(outputFile.c_str());

	//Output
	outputData(outfile, classStudents, NUM_STUDENTS, temp);

	// close output file
	outfile.close();

	cout << endl;

	system ("pause");

	return 0;
}

void inputData(ifstream& indata, studentType list[], int listSize)
{
	int index;

	// put studentType data into classStudents array
	for (index = 0; index < listSize; index++)
	{
		indata  >> list[index].studentFName
				>> list[index].studentLName
				>> list[index].testScore;
		list[index].grade = ' ';
	}
}

void assignGrade(studentType list[], int listSize)
{
// Grading scale
/*	90 - 100 = A
	80 - 89 = B
	70 - 79 = C
	60 - 69 = D
	0 - 59 = F
*/
	int index;

	for (index = 0; index < listSize; index++)
		if (list[index].testScore >= 90)
			list[index].grade = 'A';
		else if (list[index].testScore >= 80)
			list[index].grade = 'B';
		else if (list[index].testScore >= 70)
			list[index].grade = 'C';
		else if (list[index].testScore >= 60)
			list[index].grade = 'D';
		else list[index].grade = 'F';
}

int highestScore(studentType list[], int listSize)
{
	int index;
	int smallestIndex;
	int location;
	int temp;
	int tempArray[NUM_STUDENTS];

	// put test scores in a temporary array to sort
	for (index = 0; index < listSize; index++)
		tempArray[index] = list[index].testScore;


	// do an array selection sort to find the highest score
	for (index = 0; index < listSize - 1; index++)
	{
		smallestIndex = index;

		for (location = index + 1; location < listSize; location++)
			if (tempArray[location] < tempArray[smallestIndex])
				smallestIndex = location;

		temp = tempArray[smallestIndex];
		tempArray[smallestIndex] = tempArray[index];
		tempArray[index] = temp;
	}

	temp = tempArray[19];

	return temp;
}

void outputData(ofstream& outfile, studentType list[], int listSize, int temp)
{
	//Print to file Names Scores Grades
	outfile << "Student Name" <<setw(21) << "Test Score" << setw(7) << "Grade" << endl;

	for (int index = 0; index < NUM_STUDENTS; index++)
	{
		string tempName = list[index].studentLName + ", " + list[index].studentFName;
		outfile << left << setw(29) << tempName;
		outfile << setw(8) << list[index].testScore << setw(15) << list[index].grade << endl;
	}

	outfile << endl;
	outfile << "Highest Test Score: " << temp << endl;
	outfile << "Students having the highest test score:" << endl;

	// Print to file student names of those with the highest test score
	for (int index = 0; index < NUM_STUDENTS; index++)
		if (list[index].testScore == temp)
			outfile << list[index].studentLName << ",  " << list[index].studentFName << endl;

	cout << "Please see the results in Ch9_Ex2Out.txt";
}