
#include <iostream>
#include <iomanip>

using namespace std; 

void getPrices(double& current, double& priceOneYAgo, double& priceTwoYAgo);
void calculateInflation(double currentP, double priceOneYAgo, double priceTwoYAgo,
                        double& infCurrentY, double& infOneYAgo);

void printResult(double infCurrentY, double infOneYAgo);

int main()
{
	double currentPrice;
    double priceOneYearAgo;
    double priceTwoYearsAgo;
    double infCurrentYear;
    double infOneYearAgo;

    cout << fixed << showpoint << setprecision(2);

    getPrices(currentPrice, priceOneYearAgo, priceTwoYearsAgo);
    calculateInflation(currentPrice, priceOneYearAgo, priceTwoYearsAgo,
                       infCurrentYear, infOneYearAgo);

    printResult(infCurrentYear, infOneYearAgo);
	cout << endl;
	system("pause");
	return 0;
}

void getPrices(double& currentP, double& priceOneYAgo, double& priceTwoYAgo)
{
    cout << "Enter the current price of the item: ";
    cin >> currentP;
    cout << endl;

    cout << "Enter the price of the item one year ago: ";
    cin >> priceOneYAgo;
    cout << endl;

    cout << "Enter the price of the item two years ago: ";
    cin >> priceTwoYAgo;
    cout << endl;
}

void calculateInflation(double currentP, double priceOneYAgo, double priceTwoYAgo,
                        double& infCurrentY, double& infOneYAgo)
{
    infCurrentY = (currentP - priceOneYAgo) / priceOneYAgo;

    infOneYAgo = (priceOneYAgo - priceTwoYAgo) / priceTwoYAgo;
}

void printResult(double infCurrentY, double infOneYAgo)
{
    cout << "Current year inflation: " << infCurrentY << endl;

    cout << "Inflation one year ago: " << infOneYAgo << endl;

    if (infCurrentY > infOneYAgo)
        cout << "Inflation is increasing." << endl;
    else
        cout << "Inflation is not increasing." << endl;
}

    
    