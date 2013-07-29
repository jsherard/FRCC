// Programmer:  Jeff Sherard
// Date: 07/10/13
// Chapter 7: Page 501 - programming exercise #1

#include <iostream>

using namespace std;

enum triangleType {scalene, isosceles, equilateral, noTriangle};
triangleType triangleShape(double, double, double);

int main()
{
	
	// define variables
	double x, y, z;
	triangleType triType;

	// gather input for the 3 sides of the triangle
	cout << "Enter the length of the sides of a triangle." << endl;
	cout << "x = " ;
	cin >> x;
	cout << "y = " ;
	cin >> y;
	cout << "z = " ;
	cin >> z;
	cout << endl;

	// call function
	triType = triangleShape(x, y, z);
	
	// output results

	switch (triType)
	{
		case 0:
			cout << "Scalene" << endl;
			break;
		case 1:
			cout << "Isoceles" << endl;
			break;
		case 2:
			cout << "Equilateral" << endl;
			break;
		case 3:
			cout << "No Triangle" << endl;
			break;
	}

	cout << endl;

	system("pause");
	
	return 0;
}

triangleType triangleShape(double x, double y,  double z)
{
	// Determine type of triangle
	if ( (x + y < z) || (y + z < x) || (x + z < y))
		return noTriangle;  // No triangle x + y < z
	else if (x == y && x == z)
		return equilateral;  // Equilateral Triangle (Three equal sides) x = y = z
	else if (x == y && y != z)
		return isosceles;  // Isosceles Triange (Two equal sides) x = y or x = z or y = z
	else if (y == z && z != x)
		return isosceles;  // Isosceles Triange (Two equal sides) x = y or x = z or y = z
	else if (x == z && z != y)
		return isosceles;  // Isosceles Triange (Two equal sides) x = y or x = z or y = z
	else if ( x != y && x != z && y != z)
		return scalene;  // Scalene Triangle (No equal sides) x != y != z
}

/*
1.
a.   Define an enumeration type, triangleType, that has the values scalene, isosceles, equilateral, and noTriangle.
b.   Write a function, triangleShape, that takes as parameters three numbers, each of which represents the length of a side of the triangle.
	 The function should return the shape of the triangle. (Note: In a triangle, the sum of the lengths of any two sides is greater than the length of the third side.)
c.   Write a program that prompts the user to input the length of the sides of a triangle and outputs the shape of the triangle.
*/