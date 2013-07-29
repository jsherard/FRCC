// Programmer:  Jeff Sherard
// June 17, 2013
// Ch03_Ex05 Program

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	// Declare Variables
	int boxTicketQty;
	int sidelineTicketQty;
	int premiumTicketQty;
	int generalAdmissionTicketQty;
	int ticketsSold;
	double boxTicketPrice;
	double sidelineTicketPrice;
	double premiumTicketPrice;
	double generalAdmissionTicketPrice;
	double totalSaleAmount;

	ifstream inData;
	ofstream outData;
	
	// Message
	cout << "Processing Data" << endl;

	// Open the files
	inData.open ("Ch3_Ex5Data.txt");
	outData.open ("Ch3_Ex5Out.txt");

	// Input data

	inData	>> boxTicketPrice
			>> boxTicketQty
			>> sidelineTicketPrice
			>> sidelineTicketQty
			>> premiumTicketPrice
			>> premiumTicketQty
			>> generalAdmissionTicketPrice
			>> generalAdmissionTicketQty;

	// Calculate
	totalSaleAmount = (boxTicketQty * boxTicketPrice) +
	(sidelineTicketQty * sidelineTicketPrice) +
	(premiumTicketQty * premiumTicketPrice) +
	(generalAdmissionTicketQty * generalAdmissionTicketPrice);

	ticketsSold = boxTicketQty + sidelineTicketQty + premiumTicketQty + generalAdmissionTicketQty;

	// Format output
	outData << fixed << showpoint;
	outData << setprecision(2);

	// Output data
	outData << "Number of tickets sold = " << ticketsSold << endl
			<< "Sale amount = $" << totalSaleAmount;

	// Close the files
	inData.close ();
	outData.close ();

	//Output
	cout << "See output file: Ch3_Ex05Out.txt for the results." << endl << endl;

	system ("pause");

	return 0;
}