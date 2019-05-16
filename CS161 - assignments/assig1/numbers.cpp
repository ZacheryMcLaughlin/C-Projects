/****************************************
// Program: Numbers.cpp

// Author: Comrade

// Date: 01/13/19

// Description: This program presents the user with the minimum and maximums sizes of signed and
// unsigned ints, longs, and shorts. It does so using Preprocessor Macros and sizeof() and pow() functions.
// This program uses the climits ibrary to find the preprocessor macros

// Inputs: Run program/a.out or assigned name

  Outputs: The minimum and maximum of the signed Short, Integer, and Long as well as their unsigned maxs. There is no unsigned mins because it's always 0.
***********************************************************/

#include <iostream>
#include <climits>       //library that has the Preprocessor Macros already computed with values
#include <cmath>

using namespace std;

int main() {


	cout<< "Climits with preprocessor Macros" << endl << endl;
	cout<< SHRT_MIN <<endl;	 //With the use of 'climits', these shortcuts can be used to find the min and max signed short, int,
	cout<< SHRT_MAX <<endl;  //and long and the unsigned maxs of these characters. The process then prints the values.
	cout<< USHRT_MAX <<endl;
	cout<< INT_MIN <<endl;
	cout<< INT_MAX <<endl;
	cout<< UINT_MAX <<endl;
	cout<< LONG_MIN <<endl;
	cout<< LONG_MAX <<endl;
	cout<< ULONG_MAX << endl <<endl;



	cout<< endl << "climits library without preprocessor macros" << endl << endl;

 	cout<< "Unsigned Short Max: " << (unsigned short) (pow(2, (sizeof(short))*8)-1) << endl;
 
	cout<< "Unsigned Int Max: "  << (unsigned int) (pow(2, (sizeof(int))*8)-1) << endl;     //These grab the values of these characters in bytes

	cout<< "Unsigned Long Max: "  << (long long)  (pow(2, (sizeof(long))*8)-1) << endl << endl;
	

 	cout<< "Pow 2,8: " << pow(2, 8)<< endl << endl;   //Calculates the 2^8 exponent


								      //These use the bytes provided and the exponent result to   
                                                                     //calculate the characters actual value.



	cout<< "Max Signed Short: " << pow(256, 2)/2 -1 << endl;

	cout<< "Max Signed Int: " << pow(256, 4)/2 -1 << endl;

	cout<< "Max Signed Long: "  << pow(256, 8)/2 -1 << endl;

	cout<< "Min Signed Short: " << pow(256, 2)/2 *-1 << endl;
	
	cout<< "Min Signed Int: " << pow(256, 4)/2 *-1 << endl;

	cout<< "Min Signed Long: " << pow(256, 8)/2 *-1 << endl << endl;  




	return 0;                           //No issues reported with the numeric value '0'. The program goes back to the editor and runs the code.
}
