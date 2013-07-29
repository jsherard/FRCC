// Programmer:  Jeff Sherard
// June 22, 2013
// Ch04_Ex14 Program

#include <iostream>

using namespace std;

int main()
{
	// Declare Variables
	double paperHeight, paperWidth, leftMargin,rightMargin, topMargin, bottomMargin, pointSize;
	double printHeight, printWidth;
	int linePage, charLine;
	char lineSpacing;

	const double POINTS = 72;

	// Input
	cout << "Enter the length of the paper: ";
	cin >> paperHeight;
	cout << endl;

	cout << "Enter the width of the paper: ";
	cin >> paperWidth;
	cout << endl;

	cout << "Enter the left margin of the paper: ";
	cin >> leftMargin;
	cout << endl;

	cout << "Enter the right margin of the paper: ";
	cin >> rightMargin;
	cout << endl;

	cout << "Enter the top margin of the paper: ";
	cin >> topMargin;
	cout << endl;

	cout << "Enter the bottom margin of the paper: ";
	cin >> bottomMargin;
	cout << endl;

	cout << "Enter the point size of a character: ";
	cin >> pointSize;
	cout << endl;

	cout << "Enter line spacing, s or S (single spaced), d or D (double spaced): ";
	cin >> lineSpacing;
	cout << endl;

	// Calculate
	
	printWidth = paperWidth - leftMargin - rightMargin;
	printHeight = paperHeight - topMargin - bottomMargin;
	charLine = (printWidth * POINTS) / pointSize;

	switch (lineSpacing)
	{
	case 'd':
			linePage = (printHeight * POINTS) / (pointSize * 2);
			break;
	case 's':
			linePage = (printHeight * POINTS) / (pointSize);
			break;
	case 'D':
			linePage = (printHeight * POINTS) / (pointSize * 2);
			break;
	case 'S':
			linePage = (printHeight * POINTS) / (pointSize);
			break;

	}
	//Output
	cout << "The number of lines that can be printed: " << linePage << endl;
	cout << "The number of characters that can be printed in a line: " << charLine << endl;
	cout << endl;

	system ("pause");

	return 0;
}


