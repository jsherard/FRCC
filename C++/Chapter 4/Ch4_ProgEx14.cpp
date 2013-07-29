#include <iostream>
#include <iomanip>

using namespace std;

const int POINTS_IN_INCH = 72;

int main() 
{
    double length;
    double width;

    double leftMargin;
    double rightMargin;

    double topMargin;
    double bottomMargin;

    int charPointSize;
    char lineSpacing;

    double lengthOfALine;
    int numberOfCharactersInALine = 0;
    int numberOfLines = 0;

    cout << fixed << showpoint << setprecision(2);

	cout << "Enter the length of the paper: ";
	cin >> length;
	cout << endl;

	cout << "Enter the width of the paper: ";
	cin >> width;
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
	cin >> charPointSize;
	cout << endl;

    cout << "Enter line spacing, s or S (single spaced), " 
         << "d or D (double spaced): ";
	cin >> lineSpacing;
	cout << endl;

    lengthOfALine = width - leftMargin - rightMargin;
    numberOfCharactersInALine = static_cast<int>(lengthOfALine * POINTS_IN_INCH)
                                                 / charPointSize;

    if (lineSpacing == 's' || lineSpacing == 'S')
        numberOfLines = static_cast<int>(length - topMargin - bottomMargin) 
                                        * POINTS_IN_INCH / charPointSize;
    else if (lineSpacing == 'd' || lineSpacing == 'D')
        numberOfLines = static_cast<int>(length - topMargin - bottomMargin) 
                                        * POINTS_IN_INCH / charPointSize / 2;
    else
        cout << "Invalid line spacing" << endl;

    cout << "The number of lines that can be printed: " << numberOfLines << endl;
    cout << "The number of characters that can be printed in a line: " 
         << numberOfCharactersInALine << endl << endl;
    system("pause");
	return 0;
}
