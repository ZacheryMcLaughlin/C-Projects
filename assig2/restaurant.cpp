#include "menu.h"
#include "restaurant.h"
#include "Structs.h"
#include <string>

/***********************************************************************************
**Function: menu
**Description: Default Constructor that sets up the initial private var values.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
restaurant::restaurant(){
    employee_file.open("employee.txt");
    menu_file.open("menu.txt");
    orders_file.open("orders.txt");
    restaurant_info_file.open("restaurant_info.txt");
}

/***********************************************************************************
**Function: restaurant (copy constructor)
**Description: Copies all the private information into the imp file for use while also
**             allocation memory.
**Parameters: const restaurant& restaurant_old
**Pre-Condition: const restaurant& restauarant_old
**Post-Conditions: Everything
************************************************************************************/
restaurant::restaurant(const restaurant &restaurant_old){
    Menu = restaurant_old.Menu;

    num_employee = restaurant_old.num_employee;

    employees = new employee[num_employee];

    for(int i = 0; i < num_employee; i++){
        employees[i] = restaurant_old.employees[i];
    }

    week = new hours[7];
    for (int i = 0; i < 7; i++)
    {
        restaurant_info_file >> week[i].day >> week[i].open_hour >> week[i].close_hour;
    }

    name = restaurant_old.name;
    phone = restaurant_old.phone;
    address = restaurant_old.address;
}

/***********************************************************************************
**Function: restaurant (Assignment Overload Constructor)
**Description: Overloads all assignments that are in the copy constructor for use.
**Parameters: const restaurant& restaurant_old
**Pre-Condition: const restaurant& restaurant_old
**Post-Conditions: Everything
************************************************************************************/
restaurant& restaurant::operator=(const restaurant &restaurant_old){
    Menu = restaurant_old.Menu;

    num_employee = restaurant_old.num_employee;

    if(employees != NULL){
        delete[] employees;
    }
    employees = new employee[num_employee];

    for (int i = 0; i < num_employee; i++)
    {
        employees[i] = restaurant_old.employees[i];
    }

    if(week != NULL)
        delete[] week;

    week = new hours[7];
    for (int i = 0; i < 7; i++)
    {
        restaurant_info_file >> week[i].day >> week[i].open_hour >> week[i].close_hour;
    }

    name = restaurant_old.name;
    phone = restaurant_old.phone;
    address = restaurant_old.address;
}

/***********************************************************************************
**Function: num_employee_file
**Description: reads the lines in the employee file to find how many employees there are.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::num_employee_file()
{
    string line;
    while (employee_file.eof() == false)
    {
        getline(employee_file, line);
        num_employee++;
    }
    employee_file.close();
    employee_file.open("employee.txt");
}

/***********************************************************************************
**Function: get_info
**Description: reads into the file to set the values in the employee file to variables to use.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::get_info()
{
    num_employee_file();
    string temp_str;
    if (!employee_file.is_open())
    {
        cout << "File doesn't exist! Create an input.txt file!" << endl;
        exit(0);
    }

    employees = new employee[num_employee];

    for (int i = 0; i < num_employee; i++)
    {
        employee_file >> employees[i].id;
        //cout << employees[i].id << endl;
        employee_file >> employees[i].password;
        //cout << employees[i].password << endl;
        employee_file >> employees[i].first_name;
        //cout << employees[i].first_name << endl;
        employee_file >> employees[i].last_name;
        //cout << employees[i].last_name << endl;
        cout << endl;
    }
}

/***********************************************************************************
**Function: enter_id
**Description: Function that asks the user to enter an id if they are an employee.
**Parameters: string idnumber, int num_employee
**Pre-Condition: string idnumber, int num_employee
**Post-Conditions: Everything
************************************************************************************/
int restaurant::enter_id(string idnumber, int num_employee)
{
    idnumber = "";
    bool pass;
    int id;
    string new_id_number;
    //cin.ignore(1000);
    do
    {
        cout << "Enter ID number: ";

        getline(cin, new_id_number);
        //idnumber = "5";
        id = atoi(new_id_number.c_str());
        for (int i = 0; i < 3; i++)
        {
        
            if (id == employees[i].id)
            {
                cout << "Id number works" << endl;
                return i;
            }
        }

        cout << "Error! Input the correct ID number." << endl;

    } while (pass == false);
}

/***********************************************************************************
**Function: load_data
**Description: Loads all the information from the restaurant file to be used to print later
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::load_data()
{
    Menu.set_from_file_menu(menu_file);
    get_info();
    getline(restaurant_info_file, name);
    getline(restaurant_info_file, phone);
    getline(restaurant_info_file, address);
    week = new hours[7];
    for(int i = 0; i < 7; i++){
        restaurant_info_file >> week[i].day >> week[i].open_hour >> week[i].close_hour;
    }
    login();
}

/***********************************************************************************
**Function: login
**Description: Main login for the employees and customers. Asks fro ID and Password
**             from employees, and just allows users through if they're a customer.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::login()
{
    bool pass;
    string idnumber;
    string password;
    string choice;
    cout << "Welcome! Are you a Customer(1) or an Employee(2)?";
    getline(cin, choice);
    if (choice == "1"){
        front_page_customer();
    }
    else if (choice == "2"){
        get_info();
        enter_id(idnumber, num_employee);
        do
        {
            cout << "Enter Password: ";
            getline(cin, password);
            cout << endl;
            for (int i = 0; i < num_employee; i++)
            {
                if (password == employees[i].password)
                {
                    pass = true;
                    break;
                }
            }
            if (pass == false)
            {
                cout << "Error! Your password is incorrect!" << endl;
            }
        } while (pass == false);
        //delete[] employees;
        cout << endl;
        front_page_employee();
    }
    
}

/***********************************************************************************
**Function: int_check
**Description: Error checking function
**Parameters: string input
**Pre-Condition: input
**Post-Conditions: Everything
************************************************************************************/
bool restaurant::int_check(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (isdigit(input.at(i)) == false)
            return false;
    }
    return true;
}

/***********************************************************************************
**Function: search_menu_by_price
**Description: Function that asks the user to search the menu by a certain price.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::search_menu_by_price()
{
    menu tmp_menu;
    string upperb;
    cout << "What is the upper bound?" << endl;
    getline(cin, upperb);
    if(int_check(upperb) == false){
        exit(0);
    }
    cout << upperb << endl;
    cout << endl;
    tmp_menu = Menu.search_pizza_by_cost(stoi(upperb));
    tmp_menu.print_menu();
}

/***********************************************************************************
**Function: get_order
**Description: Takes the order information from the user of how many pizzas they want and 
**             which ones they want.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::get_order(){
    int selection_size;
    string amount;
    string choice;
    string card;
    pizza *tmp_pizza;
    tmp_pizza = Menu.get_pizzas();
    cout << "How many pizzas do you want to order?  ";
    getline(cin, amount);
    if(int_check(amount) == false)
        exit(0);
    selection_size = stoi(amount);
    pizza* pizza_order = new pizza[selection_size];
    for(int i = 0; i < Menu.get_num_pizza(); i++)
        cout << i << ") " << tmp_pizza[i].get_name() << endl;

    for(int i = 0; i < selection_size; i++){
        cout << "What pizza do you want from the menu?  ";
        getline(cin, choice);
        if(int_check(choice) == false || stoi(choice) > Menu.get_num_pizza() - 1){
            exit(0);
        }    
        pizza_order[i] = tmp_pizza[stoi(choice)];
    }
    cout << "What is your credit card information?" << endl;
    getline(cin, card);
    if (int_check(amount) == false)
        exit(0);
}

/***********************************************************************************
**Function: view_menu
**Description: prints out the regular menu
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::view_menu(){
    menu tmp_menu;
    tmp_menu = Menu.search_pizza_by_cost(50);
    tmp_menu.print_menu();
}

/***********************************************************************************
**Function: View_hours
**Description: prints out the hours of the restaurant
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::view_hours(){
    for (int i = 0; i < 7; i++)
    {
        cout << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
    }
}

/***********************************************************************************
**Function: view_name
**Description: prints out the name of the restaurant
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::view_name(){
    cout << name << endl;
}

/***********************************************************************************
**Function: view_address
**Description: prints out the address of the restaurant
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::view_address(){
    cout << address << endl;
}
/***********************************************************************************
**Function: view_phone
**Description: prints out the phone of the restaurant
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::view_phone(){
    cout << phone << endl;
}

/***********************************************************************************
**Function: wizard* create_wizard_info
**Description: struct array that creates an array on the heap.
**Parameters: int num_wizard
**Pre-Condition: num_wizard
**Post-Conditions: Everything
************************************************************************************/
void restaurant::change_hours(){

}

/***********************************************************************************
**Function: View_orders
**Description: View the orders after placing them
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::view_orders()
{
    for(int i = 0; i < selection_size; i++){
        cout << pizza_order[i].get_name() << endl;
    }
}

/***********************************************************************************
**Function: front_page_customer
**Description: Information displayed to the customer to navigate the restaurant
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::front_page_customer()
{
    bool pass;
    do{
        cout << "What would you like to do: " << endl << endl;
        cout << "View the menu(1) " << endl;
        cout << "order off the menu(2) " << endl;
        cout << "View orders(3)" << endl;
        cout << "narrow search by price(4) " << endl;
        cout << "narrow search by ingredient(5) " << endl;
        cout << "view name/phone/address/hours(6) " << endl;
        cout << "Exit (7)" << endl;
    } while(choices());
}

/***********************************************************************************
**Function: choices
**Description: Pathway that sends the user to their desired destination and then loops until stopped.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
bool restaurant::choices(){
    //cin.ignore(1000);
    string choice;
    getline(cin, choice); 
    if (int_check(choice) == false)
    {
        exit(0);
    }
    else if(choice == "1"){
        view_menu();
    }
    else if(choice == "2"){
        get_order();
    }
    else if(choice == "3"){
        view_orders();
    }
    else if(choice == "4"){
        search_menu_by_price();
    }
    else if(choice == "5"){

    }
    else if(choice == "6"){
        view_name();
        view_phone();
        view_address();
        view_hours();
        cout << endl;
    }
    else if(choice == "7"){
        return false;
    }
    else {
        cout << "Error! type in an actual choice dingus" << endl;
    }
    return true;
}

/***********************************************************************************
**Function: front_page_employee
**Description: Information displayed to the employee to navigate the restaurant
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void restaurant::front_page_employee()
{
    do{
        cout << "What would you like to do: " << endl;
        cout << "View the menu(1) " << endl;
        cout << "order off the menu(2) " << endl;
        cout << "View orders(3)" << endl;
        cout << "narrow search by price(4) " << endl;
        cout << "narrow search by ingredient(5) " << endl;
        cout << "view name/phone/address/hours(6) " << endl;
        cout << "Exit (7)" << endl;
    } while (choices());
}

/***********************************************************************************
**Function: ~restaurant
**Description: Destructor that deletes the allocated memory
**Parameters:  N/A
**Pre-Condition: N/A
**Post-Conditions: N/A
************************************************************************************/
restaurant::~restaurant()
{
    if (employees != NULL)
        delete[] employees;

    if (week != NULL)
        delete[] week;
}