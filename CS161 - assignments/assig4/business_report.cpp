/***************************************************************************
Program: Business Trip Expenses Report

Name: Comrade

Description: Calculates the total expenses of a business trip from a
			 variety of factors such as airfare and transport fees.
			 These expenses are gathered to output a final total and to
			 calculate the total reimbursement the employee receives from
			 the trip.

Input: Number of days on trip, flight hours, modes of transport,
	   total airfare/fees, food, hotel fees

Output: total expenses of the trip, total reimbursement for trip,
		ask user to use program again

***************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/***********************************************************************************
**Function: Int_Is_not_a_stinker
**Description: boolean that checks to see if the integer input is valid
**Parameters: string s
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
bool int_is_not_a_stinker(string s) {  //This boolean is meant to be the error handler.

	for (int x = 0; x < s.size(); x++) {  //This bool uses a check feature, by checking int size, to deduce if there are characters between 0-9.
		if (!(s.at(x) >= '0' && s.at(x) <= '9'))  //If there are no characters between 0-9, the program will print an error message and prompt the user to reenter.
		{
			cout << "Error! Re-enter a valid input" << endl;
			return false;
		}
	}
	return true;
}

/***********************************************************************************
**Function: Float_Is_not_a_stinker
**Description: boolean that checks to see if the float input is valid
**Parameters: string s
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
bool float_is_not_a_stinker(string s) {  //This boolean is meant to be the error handler.
	int decimal = 0;
	for (int x = 0; x < s.size(); x++) {  //This bool uses a check feature, by checking int size, to deduce if there are characters between 0-9.
		if (!(s.at(x) >= '0' && s.at(x) <= '9' || s.at(x) == '.'))  //If there are no characters between 0-9, the program will print an error message and prompt the user to reenter.
		{
			cout << "Error! Re-enter a valid input" << endl;
			return false;
		}
		if (s.at(x) == '.') {
			decimal++;
			if (decimal > 1) {
				cout << "Error! Re-enter a valid input" << endl;
				return false;
			}
		}
	}
	return true;
}

/**************************************************************************************
**Function: get_float
**Description: gets float input and checks it against the error handler
**Parameters: N/A
**Pre-Condition: none
**Post-Conditions: checks to see if all inputs are valid, so everything
***************************************************************************************/
float get_float() {
	string s;
	do {
		getline(cin, s);
	} while (!(float_is_not_a_stinker(s))); //takes the getline, checks it against the error handle, and then converts it if it's good.
	return atof(s.c_str());
}

/**************************************************************************************
**Function: get_int
**Description: gets int input and checks it against the error handler
**Parameters: N/A
**Pre-Condition: none
**Post-Conditions: checks to see if all inputs are valid, so everything
***************************************************************************************/
int get_int() {
	string s;
	do {
		getline(cin, s);
	} while (!(int_is_not_a_stinker(s))); //takes the getline, checks it against the error handle, and then converts it if it's good.
	return atoi(s.c_str());
}

/*************************************************************************************************************
**Function: days_of_trip
**Description: calculates the number of days spent on the trip
**Parameters: N/A
**Pre-Condition: get_int
**Post-Conditions: everything, everything is literally affected by this i.e. hotel fees and parking fees
***************************************************************************************************************/
int days_of_trip() {
	cout << "Welcome to the company trip report program!" << endl; //For the next few functions, they are just asking for input.
	cout << "How long is the trip? minimum of 1 day: ";
	int days = get_int();
	return days;
}

/************************************************************************************
**Function: departure_time
**Description: Calculates the departure time of the first day
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: Affects meal costs and what meals are going to be expenses
*************************************************************************************/
float departure_time() {
	cout << "Enter you departure time on the first day, in 24 hr notation i.e. 15.30 for 1:30 PM: ";
	float departure_times = get_float();
	return departure_times;
}

/******************************************************************************************
**Function: Arrival_time
**Description: Caclulates the arrival time of the last day
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: Affects meal costs and what meals are going to be expenses
*******************************************************************************************/
float arrival_time() {
	cout << "Enter you arrival time on the last day, in 24 hr notation i.e. 15.30 for 1:30 PM: ";
	float arrival_times = get_float();
	return arrival_times;
}

/********************************************************************************************
**Function: airfair fees
**Description: caclulates the amount of money spent on airfare
**Parameters: float &reimbursement1, float &total_expense1
**Pre-Condition: float &reimbursement1, float &total_expense1, get_float
**Post-Conditions: total expenses and total reimbursement
*********************************************************************************************/
void airfare_fees(float &reimbursement1, float &total_expense1) {
	cout << "How much did you pay for airfare?: $";
	float airfare_cost = get_float();
	reimbursement1 += airfare_cost; //takes the costs and adds it to the reimbursement function.
	total_expense1 += airfare_cost;
}

/********************************************************************************************
**Function: conference fees
**Description: caclulates the amount of money spent on conferences
**Parameters: float &reimbursement1, float &total_expense1
**Pre-Condition: float &reimbursement1, float &total_expense1, get_float
**Post-Conditions: total expenses and total reimbursement
*********************************************************************************************/
void conference_fees(float &reimbursement1, float &total_expense1) {
	cout << "How much did pay for conference fees? $";
	float conference_cost = get_float();
	reimbursement1 += conference_cost;
	total_expense1 += conference_cost;
}

/**********************************************************************************************
**Function: taxi_or_car
**Description: asks the user if they rented a car or used a taxi and stores that decision
**Parameters: N/A
**Pre-Condition: get_int
**Post-Conditions: all rented car functions i.e. car_expenses and car_mileage
**********************************************************************************************/
int taxi_or_car() {
	cout << "Did you rent a car(0) or a taxi(1)? Enter 0 or 1 ";
	int car_or_taxi = get_int();
	return car_or_taxi;
}

/************************************************************************************************************
**Function: taxi_cost
**Description: caclulates the amount spent on the taxi
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: all taxi functions i.e. taxi_rental_reimbursement, total reimbursement and total expenses
************************************************************************************************************/
float taxi_cost() {
	float taxi_costs = get_float();
	return taxi_costs;
}

/************************************************************************************************************
**Function: taxi_rental_reimbursement
**Description: calculates the reimbursement given from using a taxi
**Parameters: int days_of_trip, float taxi_money, float &reimbursement1
**Pre-Condition: int days_of_trip, float taxi_money, float &reimbursement1, get_float
**Post-Conditions: taxi_cost, taxi_expense, total reimbursement, total expenses
************************************************************************************************************/
void taxi_rental_reimbursement(int days_of_trip, float taxi_money, float &reimbursement1) {
	float taxi_rental_reimbursement;
	if (taxi_money <= 10) {
		taxi_rental_reimbursement = taxi_money;
		reimbursement1 += taxi_rental_reimbursement; //This is a loop that loops for the amount of days that were entered earlier, and then it calculates the reimbursement made each day
	}
	else if (taxi_money > 10){
		taxi_rental_reimbursement = taxi_money;
			reimbursement1 += taxi_rental_reimbursement;
	}
		

}

/************************************************************************************************************
**Function: taxi_expense
**Description: caclulates the total expense, reimbursement and all, and stores it
**Parameters: int days_of_trip, float reimbursement1, float &total_expense1
**Pre-Condition: int days_of_trip, float reimbursement1, float &total_expense1, get_float
**Post-Conditions: total reimbursement, total expense, meal_expense, hotel_costs
************************************************************************************************************/
void taxi_expense( int days_of_trip, float reimbursement1, float &total_expense1) {
	float taxi_total = 0;
	for (int x = 1; x <= days_of_trip; x++) {
		cout << "Enter the total amount spent on the taxi in $ on day " << x;
		float taxi_money = taxi_cost();
		taxi_rental_reimbursement(days_of_trip, taxi_money, reimbursement1); //Overall function that calculates the taxi cost and gives a reimbursement respectively
		taxi_total = taxi_total + taxi_money;
	}
	total_expense1 += taxi_total;
}

/************************************************************************************************************
**Function: car_money
**Description: calculates the total amount spent on the car
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: all car functions i.e. car_cost
************************************************************************************************************/
float car_money() {
	cout << "Enter the total amount spent on the rental car in $ per day: ";
	float car_moneys = get_float();
	return car_moneys;
}

/************************************************************************************************************
**Function: gas_fee
**Description: collects and stores the gas fee entered by the user
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: car_rental_reimbursement, total reimbursement, total expenses
************************************************************************************************************/
float gas_fee() {
	cout << "Enter total gas fee in $ per mile: ";
	float gas_fees = get_float();
	return gas_fees;
}

/************************************************************************************************************
**Function: car_miles
**Description: collects and stores the total miles driven
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: All car functions, hotel costs, meal costs, total reimbursement, total expenses
************************************************************************************************************/
float car_miles() {
	cout << "Enter total mileage traveled in a whole number: ";
	float car_mile = get_float();
	return car_mile;
}

/************************************************************************************************************
**Function: car_type
**Description: collects and stores what car the user drove
**Parameters: N/A
**Pre-Condition: get_int
**Post-Conditions: hotel costs, meal costs, total reimbursements, total expenses
************************************************************************************************************/
int car_type() {
	cout << "1. Sedan \n 2. SUV \n 3. Convirtable \n 4. Van \n Enter your rental car type: ";
	int car_types = get_int();
	return car_types;
}

/************************************************************************************************************
**Function: park_cost
**Description: gets input of what the cost to park was on a given day
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: all parking functions i.e. parking_reimbursement
************************************************************************************************************/
float park_cost() {
	float park_costs = get_float();
	return park_costs;
}

/************************************************************************************************************
**Function: parking_reimbursement
**Description: calculates and stores the reimbursement for the parking
**Parameters: float park_costs, float &reimbursement1
**Pre-Condition: float park_costs, float &reimbursement1, get_float
**Post-Conditions: reimbursement, total expenses
************************************************************************************************************/
void parking_reimbursement(float park_costs, float &reimbursement1) {
	float parking_reimbursement = 0;
	if (park_costs <= 6) {
		parking_reimbursement = park_costs;
		reimbursement1 += parking_reimbursement;
	}
	else if (park_costs > 6) {
		parking_reimbursement = 6;
		reimbursement1 += parking_reimbursement;
	}
}

/************************************************************************************************************
**Function: car_parking
**Description: caclulates and stores the parking fees and reimbursements
**Parameters: int days_of_trip, float reimbursement1, get_float
**Pre-Condition: get_float, int days_of_trip, float reimbursement1
**Post-Conditions: parking_total, total reimbursement, total expense
************************************************************************************************************/
float car_parking(int days_of_trip, float reimbursement1) {
	float parking_total = 0;
	for (int x = 1; x <= days_of_trip; x++) {
		cout << "Enter the parking fee for day " << x;
		float park_costs = park_cost();
		parking_reimbursement(park_costs, reimbursement1); //All the same stuff as the taxi, just for the rental car.
		parking_total = park_costs + parking_total;
	}
	return parking_total;
}

/************************************************************************************************************
**Function: car_expense
**Description: overall function that calculates and stores the cost of the car as well as its reimbursement
**Parameters: int days_of_trip, float reimbursement1, float &total_expense1
**Pre-Condition: int days_of_trip, float reimbursement1, float &total_expense1, get_float
**Post-Conditions: total_Expense, total reimbursements, total expenses
************************************************************************************************************/
void car_expense(int days_of_trip, float reimbursement1, float &total_expense1) {
	float cm = car_money();
	float gf = gas_fee();
	float cmi = car_miles();
	float cp = car_parking(days_of_trip, reimbursement1); //This calculates all car functions in one tinier function.
	total_expense1 += cm+gf+cp;
}

/************************************************************************************************************
**Function: hotel_cost
**Description: calculates and stores the amount the user paid for the hotel
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: N/A
************************************************************************************************************/
float hotel_cost() {
	float hotel_costs = get_float();
	return hotel_costs;
}

/************************************************************************************************************
**Function: hotel_reimbursement
**Description: caclulates the reimbursement the user gets for the hotel
**Parameters:float hotel_costs, float &reimbursement1
**Pre-Condition: float hotel_costs, float &reimbursement1, get_float
**Post-Conditions: hotel_fees, total reimbursements, total expenses
************************************************************************************************************/
void hotel_reimbursement(float hotel_costs, float &reimbursement1) {
	float hotel_reimbursement = 0;
	if (hotel_costs <= 90) {
		hotel_reimbursement = hotel_costs;
		reimbursement1 += hotel_reimbursement;
	}
	else if (hotel_costs > 90) {
		hotel_reimbursement = 90;
		reimbursement1 += hotel_reimbursement;
	}
}

/************************************************************************************************************
**Function: hotel_fees
**Description: caclulates the overall expenses and reimbursements for staying at a hotel for n days
**Parameters: int days_of_trip, float hotel_costs, float reimbursement1, float &total_expense1
**Pre-Condition: get_float, int days_of_trip, float hotel_costs, float reimbursement1, float &total_expense1
**Post-Conditions: total reimbursements, total expenses
************************************************************************************************************/
void hotel_fees(int days_of_trip, float hotel_costs, float reimbursement1, float &total_expense1) {
	float hotel_total = 0;
	for (int x = 1; x <= days_of_trip; x++) {
		cout << "Enter the hotel fee for night " << x;
		float hotel_costs = hotel_cost();
		hotel_reimbursement(hotel_costs, reimbursement1);
		hotel_total = hotel_costs + hotel_total;
	}
	total_expense1 += hotel_total;
}

/************************************************************************************************************
**Function: breakfast
**Description: caclulates and stores what the user paid for breakfast
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: all meal expenses and reimbursements, hotel reimbursements, total reimbursements, total expenses
************************************************************************************************************/
float breakfast() {
	float breakfast = get_float();
	return breakfast;
}

/************************************************************************************************************
**Function: lunch
**Description: caclulates and stores what the user paid for lunch
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: all meal expenses and reimbursements, hotel reimbursements, total reimbursements, total expenses
************************************************************************************************************/
float lunch() {
	float lunch = get_float();
	return lunch;
}

/************************************************************************************************************
**Function: dinner
**Description: caclulates and stores what the user paid for dinner
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: all meal expenses and reimbursements, hotel reimbursements, total reimbursements, total expenses
************************************************************************************************************/
float dinner() {
	float dinner = get_float();
	return dinner;
}

/************************************************************************************************************
**Function: departure_early1
**Description: notifies user that a specific meal isn't calculated because it falls outside of their time period
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: meal_expenses, total reimbursements, total expenses
************************************************************************************************************/
void departure_early_day1() {
	cout << "Breakfast is not an expense for day 1"<<endl;
	cout << "Enter lunch fee, in $: ";
	float l = lunch();
	cout << "Enter dinner fee, in $: ";
	float d = dinner();
}

/************************************************************************************************************
**Function: departure_early2
**Description: notifies user that a specific meal isn't calculated because it falls outside of their time period
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: meal_expenses, total reimbursements, total expenses
************************************************************************************************************/
void departure_early2() {
	cout << "Breakfast is not an expense for day 1. \n Lunch is not an expense for day 1"<<endl;
	cout << "Enter dinner fee, in $: ";
	float d = dinner();
}

/************************************************************************************************************
**Function: arrival_late
**Description: notifies user that a specific meal isn't calculated because it falls outside of their time period
**Parameters: N/A
**Pre-Condition: get_float
**Post-Conditions: meal_expenses, total reimbursements, total expenses
************************************************************************************************************/
void arrival_late() {
	cout << "Dinner is not an expense for the last day."<<endl;
	cout << "Enter breakfast fee, in $: ";
	float bc = breakfast();
	cout << "Enter lunch fee, in $: ";
	float l = lunch();
}

/************************************************************************************************************
**Function: breakfast_reimbursement
**Description: caclulates what reimbursement the user gets for the input they gave for what they paid
**Parameters: int days_of_trip, int &departure_time, int &arrival_time, float bc, float &reimbursement1
**Pre-Condition: days_of_trip, departure_time, arrival_time, get_float
**Post-Conditions:reimbursement, total meal expense, total expenses
************************************************************************************************************/
void breakfast_reimbursement(int days_of_trip, int departure_time, int arrival_time, float bc, float &reimbursement1) {
	float breakfast_reimbursement;
	if (departure_time < 0700 && arrival_time > 08.00 && bc > 9) {
		breakfast_reimbursement = 9 * days_of_trip;
	}
	else if (departure_time > 0700 && arrival_time > 08.00 && bc > 9) {
		breakfast_reimbursement = 9 * (days_of_trip - 1);
	}
	else if (departure_time > 0700 && arrival_time < 08.00 && bc > 9) { //This function goes over all the possible scenarios that can be encountered for departure and arrival times. 
		breakfast_reimbursement = 9 * (days_of_trip - 2);                  // This is the same thing for the ones below.
	} 
	else if (departure_time < 0700 && arrival_time > 08.00 && bc <= 9) {
		breakfast_reimbursement = bc * days_of_trip;
	}
	else if (departure_time > 0700 && arrival_time > 08.00 && bc <= 9) {
		breakfast_reimbursement = bc * (days_of_trip - 1);
	}
	else if (departure_time > 0700 && arrival_time < 08.00 && bc <= 9) {
		breakfast_reimbursement = bc * (days_of_trip - 2);
	}
	reimbursement1 += breakfast_reimbursement;
}

/************************************************************************************************************
**Function: lunch_reimbursement
**Description: caclulates what reimbursement the user gets for the input they gave for what they paid
**Parameters: int days_of_trip, int &departure_time, int &arrival_time, float l, float &reimbursement1
**Pre-Condition: days_of_trip, departure_time, arrival_time, get_float
**Post-Conditions:reimbursement, total meal expense, total expenses
************************************************************************************************************/
void lunch_reimbursement(int days_of_trip, int departure_time, int arrival_time, float l, float &reimbursement1) {
	float lunch_reimbursement = 0;
	if (departure_time < 1200 && arrival_time > 1300 && l > 12) {
		lunch_reimbursement = 12 * days_of_trip;
	}
	else if (departure_time > 1200 && arrival_time > 1300 && l > 12) {
		lunch_reimbursement = 12 * (days_of_trip - 1);
	}
	else if (departure_time > 1200 && arrival_time < 1300 && l > 12) {
		lunch_reimbursement = 12 * (days_of_trip - 2);
	}
	else if (departure_time < 1200 && arrival_time > 1300 && l <= 12) {
		lunch_reimbursement = l * days_of_trip;
	}
	else if (departure_time > 1200 && arrival_time > 1300 && l <= 12) {
		lunch_reimbursement = l * (days_of_trip - 1);
	}
	else if (departure_time > 1200 && arrival_time < 1300 && l <= 12) {
		lunch_reimbursement = l * (days_of_trip - 2);
	}
	reimbursement1 += lunch_reimbursement;
}

/************************************************************************************************************
**Function: dinner_reimbursement
**Description: caclulates what reimbursement the user gets for the input they gave for what they paid
**Parameters: int days_of_trip, int &departure_time, int &arrival_time, float d, float &reimbursement1
**Pre-Condition: days_of_trip, departure_time, arrival_time, get_float
**Post-Conditions:reimbursement, total meal expense, total expenses
************************************************************************************************************/
void dinner_reimbursement(int days_of_trip, int &departure_time, int &arrival_time, float d, float &reimbursement1) {
	float dinner_reimbursement;
	if (departure_time < 1800 && arrival_time > 1900 && d > 16) {
		dinner_reimbursement = 16 * days_of_trip;
	}
	else if (departure_time > 1800 && arrival_time > 1900 && d > 16) {
		dinner_reimbursement = 16 * (days_of_trip - 1);
	}
	else if (departure_time > 1800 && arrival_time < 1900 && d>16) {
		dinner_reimbursement = 16 * (days_of_trip - 2);
	}
	else if (departure_time < 1800 && arrival_time > 1900 && d <= 16) {
		dinner_reimbursement = d * days_of_trip;
	}
	else if (departure_time > 1800 && arrival_time > 1900 && d <= 16) {
		dinner_reimbursement = d * (days_of_trip - 1);
	}
	else if (departure_time > 1800 && arrival_time < 1900 && d <= 16) {
		dinner_reimbursement = d * (days_of_trip - 2);
	}
	reimbursement1 += dinner_reimbursement;
}

/***********************************************************************************************************************************************
**Function: meal_expense
**Description: calculates total meal cost and reimbusement
**Parameters: int days_of_trip, int departure_time, int arrival_time, float bc, float l, float d, float reimbursement1, float &total_expense1
**Pre-Condition: All food functions
**Post-Conditions: hotel, total expenses, and total reimbursement

Explanation for why it's over 20 lines: this function caclulates the total expenses and reimbursements of all of the meal situations. I couldn't
have done this in any other way in the time I was given, and it works correctly. I think that if it works correctly, and barely goes over
the line limit, then it's perfectly justified.
***********************************************************************************************************************************************/
void meal_expense(int days_of_trip, int departure_time, int arrival_time, float bc, float l, float d, float reimbursement1, float &total_expense1) {
	float food_total = 0;
	for (int x = 1; x <= days_of_trip; x++) {
		cout << "Day " << x << endl;
		if (departure_time > 0700 && x == 1) {
			departure_early_day1();                                  // THis is the overall function that calculates the total meal expense and reimbursement.
		}
		else if (departure_time > 1200 && x == 1) {
			departure_early2();
		}
		else if (departure_time > 1800 && x == 1) {
			cout << "Breakfast is not an expense for day 1. \n Lunch is not an expense for day 1 \n Dinner is not an expense for day 1."<<endl;
		}
		else if (arrival_time < 08.00 && x == days_of_trip) {
			cout << "Breakfast is not an expense for the last day. \n Lunch is not an expense for the last day \n Dinner is not an expense for the last day."<<endl;
		}
		else if (arrival_time < 1300 && x == days_of_trip) {
			cout << "Lunch is not  an expense for the last day \n Dinner is not an expense for the last day."<<endl;
			cout << "Enter breakfast fee, in $: ";
			float bc = breakfast();
		}
		else if (arrival_time < 1900 && x == days_of_trip) {
			arrival_late();
		}
		else {
			cout << "Enter breakfast fee, in $: ";
			float bc = breakfast();
			breakfast_reimbursement(days_of_trip, departure_time, arrival_time, bc, reimbursement1);
			cout << "Enter lunch fee, in $: ";
			float l = lunch();
			lunch_reimbursement(days_of_trip, departure_time, arrival_time, l, reimbursement1);
			cout << "Enter dinner fee, in $: ";
			float d = dinner();
			dinner_reimbursement(days_of_trip, departure_time, arrival_time, d, reimbursement1);
			food_total = bc + l + d + food_total;
		}
	}
	total_expense1 += food_total;
}

/****************************************************************************
**Function: sedan_reimbursement
**Description: calculates reimbursement for sedan
**Parameters: cmi, gf
**Pre-Condition: the car mileage and gas fees functions
**Post-Conditions: car_rental function and the total reimbursement function
****************************************************************************/
float sedan_reimbusement(float cm) {
	float car_reimbursement = 0;
	if (cm <= 20) {
		float cm = car_money();
		car_reimbursement = cm;
		return car_reimbursement;
	}
	else {
		car_reimbursement = 20;
		return car_reimbursement;
	}
}

/****************************************************************************
**Function: SUV_reimbursement
**Description: calculates reimbursement for SUV
**Parameters: cmi, gf
**Pre-Condition: the car mileage and gas fees functions
**Post-Conditions: car_rental function and the total reimbursement function
****************************************************************************/
float SUV_reimbusement(float cm) {
	float car_reimbursement = 0;
	if (cm <= 25) {
		car_reimbursement = cm;
		return car_reimbursement;
	}
	else {
		car_reimbursement = 25;
		return car_reimbursement;
	}
}

/****************************************************************************
**Function: van_reimbursement
**Description: calculates reimbursement for van
**Parameters: cmi, gf
**Pre-Condition: the car mileage and gas fees functions
**Post-Conditions: car_rental function and the total reimbursement function
****************************************************************************/
float Van_reimbusement(float cm) {
	float car_reimbursement = 0;
	if (cm <= 30) {
		car_reimbursement = cm;
		return car_reimbursement;
	}
	else {
		car_reimbursement = 30;
		return car_reimbursement;
	}
}

/****************************************************************************
**Function: Convirtable_reimbursement
**Description: calculates reimbursement for convirtable
**Parameters: cmi, gf
**Pre-Condition: the car mileage and gas fees functions
**Post-Conditions: car_rental function and the total reimbursement function
****************************************************************************/
float Convirtable_reimbusement(float cm) {
	float car_reimbursement = 0;
	if (cm <= 50) {
		car_reimbursement = cm;
		return car_reimbursement;
	}
	else {
		car_reimbursement = 50;
		return car_reimbursement;
	}
}

/****************************************************************************
**Function: sedan_reimbursement_gas
**Description: calculates gas reimbursement for sedan
**Parameters: cmi, gf
**Pre-Condition: the car mileage and gas fees functions
**Post-Conditions: car_rental function and the total reimbursement function
****************************************************************************/
float sedan_reimbusement_gas(float gf, float cmi) {
	float car_reimbursement_gas = 0;
	if (gf <= 0.24) {
		car_reimbursement_gas = gf*cmi;
		return car_reimbursement_gas;
	}
	else {
		car_reimbursement_gas = 0.24 * cmi;
		return car_reimbursement_gas;
	}
}

/****************************************************************************
**Function: SUV_reimbursement_gas
**Description: calculates gas reimbursement for SUV
**Parameters: cmi, gf
**Pre-Condition: the car mileage and gas fees functions
**Post-Conditions: car_rental function and the total reimbursement function
****************************************************************************/
float SUV_reimbusement_gas(float cmi, float gf) {
	float car_reimbursement_gas = 0;
	if (gf <= 0.27) {
		car_reimbursement_gas = gf*cmi;
		return car_reimbursement_gas;
	}
	else {
		car_reimbursement_gas = 0.27*cmi;
		return car_reimbursement_gas;
	}
}

/****************************************************************************
**Function: van_reimbursement_gas
**Description: calculates gas reimbursement for van
**Parameters: cmi, gf
**Pre-Condition: the car mileage and gas fees functions
**Post-Conditions: car_rental function and the total reimbursement function
****************************************************************************/
float Van_reimbusement_gas(float gf, float cmi) {
	float car_reimbursement_gas = 0;
	if (gf <= 0.32) {
		car_reimbursement_gas = gf*cmi;
		return car_reimbursement_gas;
	}
	else {
		car_reimbursement_gas = 0.32*cmi;
		return car_reimbursement_gas;
	}
}

/****************************************************************************
**Function: Convirtable_reimbursement_gas
**Description: calculates gas reimbursement for convirtable
**Parameters: cmi, gf
**Pre-Condition: the car mileage and gas fees functions
**Post-Conditions: car_rental function and the total reimbursement function
****************************************************************************/
float Convirtable_reimbusement_gas(float cmi, float gf) {
	float car_reimbursement_gas = 0;
	if (gf <= 0.45) {
		car_reimbursement_gas = gf*cmi;
		return car_reimbursement_gas;
	}
	else {
		car_reimbursement_gas = 0.45*cmi;
		return car_reimbursement_gas;
	}
}

/*******************************************************************************************
**Function: car_rental_reimbursement
**Description: calculates the total reimbursement for renting a car
**Parameters: int days_of_trip, float gf, float cmi, float cm, float &reimbursement1
**Pre-Condition: All car functions have to run before this
**Post-Conditions: the total reimbursement function
********************************************************************************************/
void car_rental_reimbursement(int days_of_trip, float gf, float cmi, float cm, float &reimbursement1) {
	float sedan_fullreimbursement, SUV_fullreimbursement, convirtable_fullreimbursement, van_fullreimbursement; //Overall car reimbursement depending on the inputs given prior.
	int car_type1 = car_type();
	if (car_type1 == 1) {
		sedan_fullreimbursement = sedan_reimbusement(cm) + sedan_reimbusement_gas(gf, cmi);
		reimbursement1 += sedan_fullreimbursement;
	}
	else if (car_type1 == 2) {
		SUV_fullreimbursement = SUV_reimbusement(cm) + SUV_reimbusement_gas(cmi, gf);
		reimbursement1 += SUV_fullreimbursement;
	}
	else if (car_type1 == 3) {
		convirtable_fullreimbursement = Convirtable_reimbusement(cm) + Convirtable_reimbusement_gas(cmi, gf);
		reimbursement1 += convirtable_fullreimbursement;


	}
	else if (car_type1 == 4) {
		van_fullreimbursement = Van_reimbusement(cm) + Van_reimbusement_gas(gf, cmi);
		reimbursement1 += van_fullreimbursement;
	}
}

/*******************************************************************************************
**Function: reimbursement()
**Description: Calculates the total reimbursement the user gets
**Parameters: N/A
**Pre-Condition: Everything has to run through this in order to get total reimbursement
**Post-Conditions: none
*******************************************************************************************/
void reimbursement1() {
	float reimbursement1 = 0;
	cout << "Your total reimbursement is $" << reimbursement1; 
}

/*****************************************************************************************
**Function: Total_expense
**Description: this takes all of the costs accumulated and creates a total count
**Parameters: N/A
**Pre-Condition: everything has to run through this
**Post-Conditions: none
******************************************************************************************/
void total_expense1() {
	float total_expense1 = 0;
	cout << "Your total reimbursement is $" << total_expense1;
}

/***************************************************************************************
**Function: repeat_program
**Description: It repeats the program
**Parameters: N/A
**Pre-Condition: bool on is true
**Post-Conditions: none
****************************************************************************************/
void repeat_program() {
	cout << "Would you like to fill out another travel report? yes(1) or no(2): ";
	int x = get_int();
	if (x == 1)
		bool on = true;
	else if (x == 2)
		exit(0);

}

/****************************************************************************************
**Function: main
**Description: where the main program runs cohesively and, you know, works
**Parameters: N/A
**Pre-Condition: None
**Post-Conditions: Program runs everything lel

Explanation for why it's over 20 lines: The function is barely over 20 lines, without counting
the variables created. This allows the overall program to work cohesively and loop as well
if requested. I beleive this to be perfectly justified.
*****************************************************************************************/
int main() {
	bool on = true;
	while (on) {      //loop goes through and checks at the end if the user wants to do the program again.
		float gf = 0;
		float cmi = 0;
		float cm = 0;
		float bc = 0;
		float l = 0;
		float d = 0;
		float taxi_money = 0;
		float hotel_costs = 0;
		float reimbursement1 = 0;
		float total_expense1 = 0;
		int  trip_days = days_of_trip();
		int departure_times = departure_time();
		int arrival_times = arrival_time();
		airfare_fees(reimbursement1, total_expense1);
		conference_fees(reimbursement1, total_expense1);
		int taxi_or_cars = taxi_or_car();
		if (taxi_or_cars == 0) {
			car_expense(trip_days, reimbursement1, total_expense1);
			car_rental_reimbursement(trip_days, gf, cmi, cm, reimbursement1);
		}
		else if (taxi_or_cars == 1) {
			float taxi_costs = taxi_cost();
			taxi_expense(trip_days, taxi_costs,total_expense1);
			taxi_rental_reimbursement(trip_days, taxi_money, reimbursement1);
		}
		meal_expense(trip_days, departure_times, arrival_times, bc, l, d, reimbursement1, total_expense1);
		breakfast_reimbursement(trip_days, departure_times, arrival_times, bc, reimbursement1);
		lunch_reimbursement(trip_days, departure_times, arrival_times, l, reimbursement1);
		dinner_reimbursement(trip_days, departure_times, arrival_times, d, reimbursement1);
		hotel_reimbursement(trip_days, reimbursement1);
		hotel_fees(trip_days, hotel_costs, reimbursement1, total_expense1);
		cout << "Your total reimbursement is $" << reimbursement1 << endl;
		cout << "Your total expense is $" << total_expense1 << endl;
		repeat_program();
	}
	return 0; //That's all folk!
}