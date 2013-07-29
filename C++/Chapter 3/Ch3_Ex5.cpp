
#include <iostream>
#include <fstream>
#include <iomanip>
 
using namespace std; 

int main()
{
	double saleAmount = 0;
	double ticketPrice;
	int ticketsSold;

	int totalTicketsSold = 0;

	ifstream inFile;
	ofstream outFile;

	inFile.open("Ch3_Ex5Data.txt");
	outFile.open("Ch3_Ex5Out.txt");

	outFile << fixed << showpoint << setprecision(2);

	cout << "Proessing Data" << endl;

	inFile >> ticketPrice >> ticketsSold;
	
	saleAmount = saleAmount + ticketPrice * ticketsSold;
	totalTicketsSold = totalTicketsSold + ticketsSold;

	inFile >> ticketPrice >> ticketsSold;
	
	saleAmount = saleAmount + ticketPrice * ticketsSold;
	totalTicketsSold = totalTicketsSold + ticketsSold;

	inFile >> ticketPrice >> ticketsSold;
	
	saleAmount = saleAmount + ticketPrice * ticketsSold;
	totalTicketsSold = totalTicketsSold + ticketsSold;

	inFile >> ticketPrice >> ticketsSold;
	
	saleAmount = saleAmount + ticketPrice * ticketsSold;
	totalTicketsSold = totalTicketsSold + ticketsSold;

	outFile << "Number of tickets sold = " << totalTicketsSold << endl;
	outFile << "Sale amount = $" << saleAmount << endl;

	inFile.close();
	outFile.close();
	cout << "See output file: Ch3_Ex5Out.txt for the results."<< endl << endl;
	system("pause");
	return 0;
}

