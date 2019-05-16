/***************************************************************************
Program: Heat Transfer

Date: 03/17/19

Name: Comrade

Description: This program takes in an input of material characteristics, time intervals, and what type of visualization of the data
			 to calculate the heat transfer that would occur in the material over the specified time interval. It will then output
			 said data onto a wire or plate visualization tool in order to better understand the data.

Input: properties of materials, time interval, repeat

Output: Heat transfer data over a period of time

***************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void wire_temp(float **wire, float constant, int ti, int s);

void set_wire_values(float **wire, int ti, float l_tm, float r_tm, int s, float i_tm);

/***********************************************************************************
**Function: get_ti
**Description: Gets user input and error checks it
**Parameters: float &ti
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void get_ti(int &ti) {
	cout << "Enter the properties of the object being modeled for heat transfer \nEnter the time interval: ";
	cin >> ti;
	if (ti < 0) {
		cout << "Invalid value!" << endl;
		exit(0);
	}
	if (cin.fail()) {
		cout << "Invalid value!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		exit(0);
	}
}

/***********************************************************************************
**Function: get_s
**Description: Gets user input and error checks it
**Parameters: float &s
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void get_s(int &s) {
	cout << "Enter the amount of sections/plate height and width: ";
	cin >> s;
	if (s < 0) {
		cout << "Invalid value!" << endl;
		exit(0);
	}
	if (cin.fail()) {
		cout << "Invalid value!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		exit(0);
	}
}

/***********************************************************************************
**Function: get_user_t
**Description: Gets user input and error checks it
**Parameters: float &user_t
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void get_user_t(float &user_t) {
	cout << "Enter the time of simulation: ";
	cin >> user_t;
	if (user_t < 0) {
		cout << "Invalid value!" << endl;
		exit(0);
	}
	if (cin.fail()) {
		cout << "Invalid value!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		exit(0);
	}
}

/***********************************************************************************
**Function: get_wire_length
**Description: Gets user input and error checks it
**Parameters: float &wire_length
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void get_wire_length(float &wire_length) {
	cout << "Enter the wire length/sections across height and width: ";
	cin >> wire_length;
	if (wire_length < 0) {
		cout << "Invalid value!" << endl;
		exit(0);
	}
	if (cin.fail()) {
		cout << "Invalid value!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		exit(0);
	}
}

/***********************************************************************************
**Function: get_k
**Description: Gets user input and error checks it
**Parameters: float &k
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void get_k(float &k) {
	cout << "Enter k: ";
	cin >> k;
	if (k < 0) {
		cout << "Invalid value!" << endl;
		exit(0);
	}
	if (cin.fail()) {
		cout << "Invalid value!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		exit(0);
	}
}

/***********************************************************************************
**Function: get_c
**Description: Gets user input and error checks it
**Parameters: float &c
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void get_c(float &c) {
	cout << "Enter c: ";
	cin >> c;
	if (c < 0) {
		cout << "Invalid value!" << endl;
		exit(0);
	}
	if (cin.fail()) {
		cout << "Invalid value!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		exit(0);
	}
}

/***********************************************************************************
**Function: get_p
**Description: Gets user input and error checks it
**Parameters: float &p
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void get_p(float &p) {
	cout << "Enter p: ";
	cin >> p;
	if (p < 0) {
		cout << "Invalid value!" << endl;
		exit(0);
	}
	if (cin.fail()) {
		cout << "Invalid value!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		exit(0);
	}
}

/***********************************************************************************
**Function: get_l_tm
**Description: Gets left side temp for wire
**Parameters: float &l_tm
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void get_l_tm(float &l_tm) {
	cout << "Enter left temp: ";
	cin >> l_tm;
	if (l_tm < 0) {
		cout << "Invalid value!" << endl;
		exit(0);
	}
	if (cin.fail()) {
		cout << "Invalid value!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		exit(0);
	}
}

/***********************************************************************************
**Function: get_r_tm
**Description: Gets right side temp for wire
**Parameters: float &r_tm
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void get_r_tm(float &r_tm) {
	cout << "Enter right temp: ";
	cin >> r_tm;
	if (r_tm < 0) {
		cout << "Invalid value!" << endl;
		exit(0);
	}
	if (cin.fail()) {
		cout << "Invalid value!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		exit(0);
	}
}

/***********************************************************************************
**Function: get_plate_tm
**Description: Gets surrounding plate temps
**Parameters: float &plate_tm
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void get_plate_tm(float &plate_tm) {
	cout << "Enter surrounding plate temps: ";
	cin >> plate_tm;
	if (plate_tm < 0) {
		cout << "Invalid value!" << endl;
		exit(0);
	}
	if (cin.fail()) {
		cout << "Invalid value!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		exit(0);
	}
}

/***********************************************************************************
**Function: get_i_tm
**Description: Gets initial temp
**Parameters: float &i_tm
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void get_i_tm(float &i_tm) {
	cout << "Enter initial temp: ";
	cin >> i_tm;
	if (i_tm < 0) {
		cout << "Invalid value!" << endl;
		exit(0);
	}
	if (cin.fail()) {
		cout << "Invalid value!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		exit(0);
	}
}

void set_plate_values(float **array_new, float ** array_old, int s, float i_tm, float plate_tm);

void create_3d(int ti, int s, float **array_new, float **array_old, float constant);

void repeat(int *);

/***********************************************************************************
**Function: int main
**Description: Runs program
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
int main() {

	int ti;
	int s;
	float l_tm;
	float r_tm;
	float i_tm = 0;
  float plate_tm;
	float user_t;
	float wire_length;
	float k;
	float c;
	float p;
	float change_t;
	float change_x;
	float constant;
	int choice;
	int x;
	float **wire = NULL;
	float **array_new = NULL;
	float **array_old = NULL;

	do {
		get_ti(ti);
		get_s(s);
		get_user_t(user_t);
		get_wire_length(wire_length);
		get_k(k);
		get_c(c);
		get_p(p);
    get_i_tm(i_tm);
    

		array_new = new float*[s];

		for (int i = 0; i < s; i++)
			array_new[i] = new float[s];

		array_old = new float*[s];

		for (int i = 0; i < s; i++)
			array_old[i] = new float[s];

		wire = new float*[ti]; //Creates a 2D float array

		cout << "Would you like to visualize data with a plate(0) or a wire(1)? ";
		cin >> choice;
		if (cin.fail()) {
			cout << "Invalid value!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			exit(0);
		}

		if (choice == 0) {

      get_plate_tm(plate_tm);

			set_plate_values(array_new, array_old, s, i_tm, plate_tm);

			change_t = user_t / ti; //Finds the change in temperature
			change_x = wire_length / s; //Finds the change in length

			constant = (k * change_t) / (change_x * change_x * c * p);

			if (change_t <= (change_x * change_x * p * c) / (4 * k)) {
				create_3d(ti, s, array_new, array_old, constant);
			}
			else{
        cout << "Oh no! The inputs entered create an unstabilized system! " << endl;
				exit(0);
      }
		}
		else if (choice == 1) {
  
      get_l_tm(l_tm);
      get_r_tm(r_tm);
      
		  set_wire_values(wire, ti, l_tm, r_tm, s, i_tm);
  
		  change_t = user_t / ti; //Finds the change in temperature
		  change_x = wire_length / s; //Finds the change in length
  
		  constant = (k * change_t) / (change_x * change_x * c * p);
  
      if (constant >= 0.5){
        cout << "Unstable condition! " << endl;
        exit(0);
        }
      else{
        
  			wire_temp(wire, constant, ti, s);
  
  			for (int t = 0; t < ti; t++) {
  				for (int x = 0; x < s; x++) {
  					cout << wire[t][x] << " ";
  					
  				}
  				cout << endl;
  			}
       }
		}
  
		repeat(&x);

	} while (x == 0);

  for (int i = 0; i < ti; i++) {
		  delete[] wire[i];
	  }
  delete[] wire;

  for (int i = 0; i < ti; i++) {
  		delete[] array_old[i];
  		delete[] array_new[i];
  	}
 	delete[] array_old;
 	delete[] array_new;

	return 0;
}

/***********************************************************************************
**Function: wire_temp
**Description: Calculates all the inside values
**Parameters: float **wire, float constant, int ti, int s
**Pre-Condition: User input and arrays
**Post-Conditions: print out
************************************************************************************/
void wire_temp(float **wire, float constant, int ti, int s) {
	for (int t = 0; t < ti - 1; t++)
		for (int x = 1; x < s - 1; x++)
			wire[t + 1][x] = constant * (wire[t][x + 1] - 2 * wire[t][x] + wire[t][x - 1]) + wire[t][x];
}

/***********************************************************************************
**Function: Set_wire_values
**Description: Sets the initial plate values for the sides. It also sets the initial values for the inside values.
**Parameters: float **wire, int ti, float l_tm, float r_tm, int s, float i_tm
**Pre-Condition: Arrays have to be created and set
**Post-Conditions: print out the values.
************************************************************************************/
void set_wire_values(float **wire, int ti, float l_tm, float r_tm, int s, float i_tm) {
	for (int t = 0; t < ti; t++) {
		wire[t] = new float[s];  //for loop that creates a set of values for this array
		wire[t][0] = l_tm; //At the first section, set it equal to 0 always
		wire[t][s - 1] = r_tm; //At the last section, set it equal to 100 always
	}
	for (int x = 1; x < s - 1; x++)
		wire[0][x] = i_tm; //At the first time interval, we're setting the initial temperatures for those spots

}

/***********************************************************************************
**Function: Set_plate_values
**Description: Sets the initial plate values for the corners and sides. It also sets the initial values for the inside values.
**Parameters: float **array_new, float ** array_old, int s, float i_tm
**Pre-Condition: Arrays have to be created and set
**Post-Conditions: create_3d
************************************************************************************/
void set_plate_values(float **array_new, float ** array_old, int s, float i_tm, float plate_tm) {
	for (int i = 0; i < s; i++) {
		array_new[0][i] = plate_tm;
		array_new[s - 1][i] = plate_tm;
		array_new[i][0] = plate_tm;
		array_new[i][s - 1] = plate_tm;
		array_old[0][i] = plate_tm;
		array_old[s - 1][i] = plate_tm;
		array_old[i][0] = plate_tm;
		array_old[i][s - 1] = plate_tm;
	}
	for (int j = 1; j < s - 1; j++) {
		for (int n = 1; n < s - 1; n++) {
			array_new[j][n] = i_tm;
			array_old[j][n] = i_tm;
		}
	}
}

/***********************************************************************************
**Function: Create_3D
**Description: Creates the plates. This function sets up the new array to equal the output of the equation that calculates the plate values for the old array.
**Parameters: int n, int s, float **array_new, float **array_old, float constant
**Pre-Condition: all user inputs
**Post-Conditions: outputs the plate values
************************************************************************************/
void create_3d(int n, int s, float **array_new, float **array_old, float constant) {
	for (int i = 1; i < s - 1; i++) {
		for (int j = 1; j < s - 1; j++) {
			array_new[i][j] = constant * (array_old[i + 1][j] - 2 * array_old[i][j] + array_old[i - 1][j] + array_old[i][j + 1] - 2 * array_old[i][j] + array_old[i][j - 1]) + array_old[i][j]; //Equation to calculate the old array values and set it equal to the new array.
		}
	}
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			cout << array_old[i][j] << " "; //Print out array values
			//write to file
			array_old[i][j] = array_new[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;

	if (n > 1) {
		create_3d(n - 1, s, array_new, array_old, constant); //Recursive statement to loop through the different plate values for the amount of time intervals.
	}
}

/***********************************************************************************
**Function: repeat
**Description: function that asks the user if they want to repeat the program and error handles it.
**Parameters: int *x
**Pre-Condition: 0 or 1
**Post-Conditions: N/A
************************************************************************************/
void repeat(int *x) {
	cout << "Would you like to simulate another heat transfer? yes(0) or no(1)" << endl;
	string rep;
	bool good = false;
	while (!good) {
		int i;
		cin >> rep;
		for (i = 0; i < rep.size(); i++) {
			if (!(rep.at(i) >= '0' && rep.at(i) <= '1')) {
				cout << "Error! Enter a valid input! " << endl; //error handle to make sure the input is correct
				break;
			}
		}
		if (rep >= "0" && rep <= "9")
			good = true;
	}
	*x = atoi(rep.c_str());
	cin.ignore(1000, '\n'); //stops the cin so that it doesn't read past what is inputed.
}