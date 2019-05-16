// Program: Number.cpp

// Author: Comrade

// Date: 01/13/19

// Description: This program presents the user with the minimum and maximums sizes of signed and
// unsigned ints, longs, and shorts. It does so using Preprocessor Macros and sizeof() and pow() functions.
// This program uses sizeof() and pow() to manually find the macros

// Inputs: Program start/a.out or assigned name

// Outputs: Max and min of signed and insigned  short, integer, and long macros. It also outputs the size of these characters in bytes and what the exponents of 2^8 is.


#include <iostream>     //Library
#include <cmath>        //Allows the use of mathematical calculations such as calculating exponents

using namespace std;

int main() {


	cout<< "climits library without preprocessor macros" <<endl;

 	cout<< "Unsigned Short Max: " << (unsigned short) (pow(2, (sizeof(short))*8)-1) <<endl;
 
	cout<< "Unsigned Int Max: "  << (unsigned int) (pow(2, (sizeof(int))*8)-1) <<endl;     //These grab the values of these characters in bytes

	cout<< "Unsigned Long Max: "  << (pow(2, (sizeof(long))*8)-1) <<endl;
	

 	cout<< "Pow 2,8: " << pow(2, 8)<<endl;   //Calculates the 2^8 exponent


								      //These use the bytes provided and the exponent result to   
                                                                     //calculate the characters actual value.



	cout<< "Max Signed Short: " << pow(256, 2)/2 -1 <<endl;

	cout<< "Max Signed Int: " << pow(256, 4)/2 -1 <<endl;

	cout<< "Max Signed Long: "  << pow(256, 8)/2 -1 <<endl;

	cout<< "Min Signed Short: " << pow(256, 2)/2 *-1 <<endl;
	
	cout<< "Min Signed Int: " << pow(256, 4)/2 *-1 <<endl;

	cout<< "Min Signed Long: " << pow(256, 8)/2 *-1 <<endl;  



	return 0;
}

