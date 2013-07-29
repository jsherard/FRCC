// Programmer:  Jeff Sherard
// June 11, 2013
// Ch03_Ex7 Program

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	// declare variables
	ifstream inFile;
	ofstream outFile;

	string lastName1, firstName1;
	double currentSalary1, updatedSalary1, percentPayIncrease1;
	string lastName2, firstName2;
	double currentSalary2, updatedSalary2, percentPayIncrease2;
	string lastName3, firstName3;
	double currentSalary3, updatedSalary3, percentPayIncrease3;

	//Open files
	inFile.open("Ch3Ex7Data.txt");
	outFile.open("Ch3Ex7Output.dat");

	//Set formatting
	outFile << fixed << showpoint;
	outFile << setprecision(2);

	//Read in data from Ch3Ex7Data.txt file
	inFile	>> lastName1 >> firstName1 >> currentSalary1 >> percentPayIncrease1
			>> lastName2 >> firstName2 >> currentSalary2 >> percentPayIncrease2
			>> lastName3 >> firstName3 >> currentSalary3 >> percentPayIncrease3;

	//Calculate updated salary
	updatedSalary1 = currentSalary1 * (1 + percentPayIncrease1/100.00);
	updatedSalary2 = currentSalary2 * (1 + percentPayIncrease2/100.00);
	updatedSalary3 = currentSalary3 * (1 + percentPayIncrease3/100.00);

	//Output data to Ch3Ex7Output.dat
	outFile << firstName1 << " " << lastName1 << " " << updatedSalary1 << endl
			<< firstName2 << " " << lastName2 << " " << updatedSalary2 << endl
			<< firstName3 << " " << lastName3 << " " << updatedSalary3 << endl;

	//Close files
	inFile.close();
	outFile.close();

	return 0;
}