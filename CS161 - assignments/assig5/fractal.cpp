/***************************************************************************
Program: Recursive Fractals

Date: 03/03/19

Name: Comrade

Description: This program takes in an input of n asterisks to calculate a pattern of asterisks and spaces. It will creates a nice little pattern that looks cool man.

Input: n asterisks, i spaces (but you should enter 0 here)

Output: a cool pattern of asterisks and spaces.

***************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void input(int *n);

void repeat(int *x);

/***********************************************************************************
**Function: Pattern
**Description: Creates the pattern for the fractal series.
**Parameters: int n, int i
**Pre-Condition: everything
**Post-Conditions: N/A
************************************************************************************/
void pattern(int n, int i) {
	string str;
	if (!n)
		return;

	else {

		for (int a = 0; a < i; a++)
			str += "  ";

		for (int a = 0; a < n; a++)
			str += "* ";

		pattern(n / 2, i); //First recursion that goes back into the pattern function for the value inputed. This prints half of the input first

		cout << str << endl;

		pattern(n / 2, n / 2 + i); //Second recursion that goes back into the pattern function for the value inputed. This prints the whole input.

	}
}

/***********************************************************************************
**Function: Int main()
**Description: 
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
int main() {
	int n;
	int x;
	int i = 0;
	do {
		cout << "input asterisks n that are even numbers: ";
		input(&n);
		cout << endl;

		pattern(n, i);
		repeat(&x);
	} while (x == 0);
	return 0;

}

/***********************************************************************************
**Function: Input
**Description: Error checker to check inputs to see if it's valid
**Parameters: int *n
**Pre-Condition: int *n
**Post-Conditions: Everything
************************************************************************************/
void input(int *n) {
	string input;
	bool good = false;
	while (!good) {
		int i;
		cin >> input;
		for (i = 0; i < input.size(); i++) {
			if (!(input.at(i) >= '0' && input.at(i) <= '9')) {  //Error checks the input
				cout << "Error! Enter a valid input! " << endl;
				break;
			}
		}
		if (input >= "0" && input <= "9")
			good = true;
	}
	*n = atoi(input.c_str());
}

/***********************************************************************************
**Function: repeat
**Description: function that asks the user if they want to repeat the program and error handles it.
**Parameters: int *x
**Pre-Condition: 0 or 1
**Post-Conditions: N/A
************************************************************************************/
void repeat(int *x) {
	cout << "Would you like to enter another recursive fractal? yes(0) or no(1)" << endl;
	string rep;
	bool good = false;
	while (!good) {
		int i;
		cin >> rep;
		for (i = 0; i < rep.size(); i++) {
			if (!(rep.at(i) >= '0' && rep.at(i) <= '1')) {
				cout << "Error! Enter a valid input! " << endl;
				break;
			}
		}
		if (rep >= "0" && rep <= "9")
			good = true;
	}
	*x = atoi(rep.c_str());
}