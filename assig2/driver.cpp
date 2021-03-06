imp_pizza.cpp                                                                                       0000660 0016601 0057325 00000017636 13462423042 013324  0                                                                                                    ustar   mclaughz                        upg7553                                                                                                                                                                                                                #include "pizza.h"

/***********************************************************************************
**Function: pizza
**Description: Default Constructor that sets up the initial private var values.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
pizza::pizza()
{
    name = " ";
    small_cost = 0;
    medium_cost = 0;
    large_cost = 0;
    num_ingredients = 0;
    ingredients = NULL;
}

/***********************************************************************************
**Function: pizza (copy constructor)
**Description: Copies all the private information into the imp file for use while also
**             allocation memory.
**Parameters: const pizza& pizza_old
**Pre-Condition: const pizza& pizza_old
**Post-Conditions: Everything
************************************************************************************/
pizza::pizza(const pizza& pizza_old){
    name = pizza_old.name;
    small_cost = pizza_old.small_cost;
    medium_cost = pizza_old.medium_cost;
    large_cost = pizza_old.large_cost;
    num_ingredients = pizza_old.num_ingredients;

    ingredients = new string[num_ingredients];

    for(int i = 0; i < num_ingredients; i++){
        ingredients[i] = pizza_old.ingredients[i];
    }
}

/***********************************************************************************
**Function: Pizza (Assignment Overload Constructor)
**Description: Overloads all assignments that are in the copy constructor for use.
**Parameters: const pizza& pizza_old
**Pre-Condition: const pizza& pizza_old
**Post-Conditions: Everything
************************************************************************************/
pizza& pizza::operator = (const pizza& pizza_old){
    if(ingredients != NULL)
        delete[] ingredients;

    name = pizza_old.name;
    small_cost = pizza_old.small_cost;
    medium_cost = pizza_old.medium_cost;
    large_cost = pizza_old.large_cost;
    num_ingredients = pizza_old.num_ingredients;

    ingredients = new string[num_ingredients];

    for (int i = 0; i < num_ingredients; i++)
    {
        ingredients[i] = pizza_old.ingredients[i];
    }
    return *this;
}

/***********************************************************************************
**Function: set_name
**Description: sets the name
**Parameters: string name
**Pre-Condition: string name
**Post-Conditions: Everything
************************************************************************************/
void pizza::set_name(string name)
{
    this->name = name;
}

/***********************************************************************************
**Function: get_name
**Description: gets the name
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
string pizza::get_name() const
{
    return name;
}

/***********************************************************************************
**Function: set_small_cost
**Description: sets the small_cost
**Parameters: int small_cost
**Pre-Condition: int small_cost
**Post-Conditions: Everything
************************************************************************************/
void pizza::set_small_cost(int small_cost)
{
    this->small_cost = small_cost;
}

/***********************************************************************************
**Function: get_small_cost
**Description: gets the small cost
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
int pizza::get_small_cost() const
{
    return small_cost;
}

/***********************************************************************************
**Function: set_medium_cost
**Description: sets the medium cost
**Parameters: int medium_cost
**Pre-Condition: int medium_cost
**Post-Conditions: Everything
************************************************************************************/
void pizza::set_medium_cost(int medium_cost)
{
    this->medium_cost = medium_cost;
}

/***********************************************************************************
**Function: get_medium_cost
**Description: gets the medium cost
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
int pizza::get_medium_cost() const
{
    return medium_cost;
}

/***********************************************************************************
**Function: set_large_cost
**Description: sets the large cost
**Parameters: int large_cost
**Pre-Condition: large_cost
**Post-Conditions: Everything
************************************************************************************/
void pizza::set_large_cost(int large_cost)
{
    this->large_cost = large_cost;
}

/***********************************************************************************
**Function: get_large_cost
**Description: gets the large cost
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
int pizza::get_large_cost() const
{
    return large_cost;
}

/***********************************************************************************
**Function: set_num_ingredients
**Description: sets the number of ingredients
**Parameters: int num_ingredients
**Pre-Condition: num_ingredients
**Post-Conditions: Everything
************************************************************************************/
void pizza::set_num_ingredients(int num_ingredients)
{
    this->num_ingredients = num_ingredients;
}

/***********************************************************************************
**Function: get_num_ingredients
**Description: gets the number of ingredients
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
int pizza::get_num_ingredients() const
{
    return num_ingredients;
}

/***********************************************************************************
**Function: set_ingredients
**Description: sets the ingredients
**Parameters: string *ingredients
**Pre-Condition: ingredients
**Post-Conditions: Everything
************************************************************************************/
void pizza::set_ingredients(string *ingredients)
{
    this->ingredients;
}

/***********************************************************************************
**Function: get_ingredients
**Description: gets the ingredients
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
string *pizza::get_ingredients() const
{
    return ingredients;
}

/***********************************************************************************
**Function: set_from_file
**Description: Gets all the information about the pizzas from the file
**Parameters: fstream &f
**Pre-Condition: f
**Post-Conditions: Everything
************************************************************************************/
void pizza::set_from_file(fstream &f)
{
    f >> name >> small_cost >> medium_cost >> large_cost >> num_ingredients;
    ingredients = new string[num_ingredients];
    for (int i = 0; i < num_ingredients; i++)
    {
        f >> ingredients[i];
    }
}

/***********************************************************************************
**Function: ~pizza
**Description: Destructor that deletes the allocated memory
**Parameters:  N/A
**Pre-Condition: N/A
**Post-Conditions: N/A
************************************************************************************/
pizza::~pizza()
{
    if(ingredients != NULL)
    delete[] ingredients;
}                                                                                                  restaurant.cpp                                                                                      0000660 0016601 0057325 00000040537 13462477734 013527  0                                                                                                    ustar   mclaughz                        upg7553                                                                                                                                                                                                                #include "menu.h"
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
}                                                                                                                                                                 menu.cpp                                                                                            0000660 0016601 0057325 00000020006 13462477032 012257  0                                                                                                    ustar   mclaughz                        upg7553                                                                                                                                                                                                                #include "menu.h"

/***********************************************************************************
**Function: menu
**Description: Default Constructor that sets up the initial private var values.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
menu::menu(){
    pizzas = NULL;
}

/***********************************************************************************
**Function: print_menu
**Description: prints the pizzas and their respective information depending on search results
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void menu::print_menu(){
    string* ingredients;
    for(int i = 0; i < num_pizzas; i++){
        if(pizzas[i].get_small_cost() != -1){
            cout << pizzas[i].get_name() << " ";
            cout <<"Small Cost: ";
            cout << pizzas[i].get_small_cost() << " ";
            if (pizzas[i].get_medium_cost() != -1){
                cout << "Medium Cost: ";
                cout << pizzas[i].get_medium_cost() << " ";
            }
            if (pizzas[i].get_large_cost() != -1){
                cout << "Large Cost: ";
                cout << pizzas[i].get_large_cost() << " ";
            }
            ingredients = pizzas[i].get_ingredients();
            cout << endl;
            for(int j = 0; j < pizzas[i].get_num_ingredients(); j++){
                cout << ingredients[j] << " " << endl;
            }
        cout << endl;
        cout << endl;
        }
    }
}

/***********************************************************************************
**Function: set_num_pizza
**Description: counts the lines in the pizza file to find how many line there are.
**Parameters: fstream &f
**Pre-Condition: f
**Post-Conditions: Everything
************************************************************************************/
void menu::set_num_pizza(fstream &f)
{
    num_pizzas = 0;
    string line;
    while (f.eof() == false)
    {
        getline(f, line);
        if(line != "")
            num_pizzas++;
    }

    f.clear();
    f.seekg(0, fstream::beg);
}

/***********************************************************************************
**Function: menu (copy constructor)
**Description: Copies all the private information into the imp file for use while also
**             allocation memory.
**Parameters: const menu& menu_old
**Pre-Condition: const menu& menu_old
**Post-Conditions: Everything
************************************************************************************/
menu::menu(const menu &menu_old)
{
    num_pizzas = menu_old.num_pizzas;

    pizzas = new pizza[num_pizzas];

    for (int i = 0; i < num_pizzas; i++)
    {
        pizzas[i] = menu_old.pizzas[i];
    }
}

/***********************************************************************************
**Function: menu (Assignment Overload Constructor)
**Description: Overloads all assignments that are in the copy constructor for use.
**Parameters: const menu& menu_old
**Pre-Condition: const menu& menu_old
**Post-Conditions: Everything
************************************************************************************/
menu& menu::operator = (const menu& menu_old){
    num_pizzas = menu_old.num_pizzas;

    if(pizzas != NULL)
        delete[] pizzas;

    pizzas = new pizza[num_pizzas];

    for(int i = 0; i < num_pizzas; i++){
        pizzas[i] = menu_old.pizzas[i];
    }
}

/***********************************************************************************
**Function: make_pizza
**Description: Creates and array of pizzas
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void menu::make_pizzas()
{
    pizzas = new pizza[num_pizzas];
}

/***********************************************************************************
**Function: get_num_pizza
**Description: Gets the number of pizzas
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
int menu::get_num_pizza() const
{
    return num_pizzas;
}

/***********************************************************************************
**Function: get_pizzas
**Description: gets the arrays of pizzas
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
pizza* menu::get_pizzas(){
    return pizzas;
}

/***********************************************************************************
**Function: Search_pizza_by_cost
**Description: If the pizza cost is above the upper bound set, then the pizza will not show to the user.
**Parameters: int upperb
**Pre-Condition: upperb
**Post-Conditions: Everything
************************************************************************************/
menu menu::search_pizza_by_cost(int upper_bound)
{
    menu tmp_menu = *this;
    for(int i = 0; i < tmp_menu.num_pizzas; i++){
        if(tmp_menu.pizzas[i].get_small_cost() > upper_bound)
            tmp_menu.pizzas[i].set_small_cost(-1);
        if (tmp_menu.pizzas[i].get_medium_cost() > upper_bound)
            tmp_menu.pizzas[i].set_medium_cost(-1);
        if (tmp_menu.pizzas[i].get_large_cost() > upper_bound)
            tmp_menu.pizzas[i].set_large_cost(-1);
    }
    return tmp_menu;
}

/***********************************************************************************
**Function: N/A
**Description: N/A
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
menu menu::search_pizza_by_ingredients_to_include(string * ingredients, int num_ingredients)
{
}

/***********************************************************************************
**Function: N/A
**Description: N/A
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
menu menu::search_pizza_by_ingredients_to_exclude(string * ingredients, int num_ingredients)
{
}

/***********************************************************************************
**Function: N/A
**Description: N/A
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void menu::add_to_menu(pizza pizza_to_add)
{
}

/***********************************************************************************
**Function: N/A
**Description: N/A
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void menu::remove_from_menu(int index_of_pizza_on_menu)
{
}

/***********************************************************************************
**Function: set_from_file_menu
**Description: sets the pizza information from the pizza file and stores them in arrays
**Parameters: fstream &f
**Pre-Condition: f
**Post-Conditions: Everything
************************************************************************************/
void menu::set_from_file_menu(fstream &f){
    set_num_pizza(f);
    pizzas = new pizza[num_pizzas];
    f.clear();
    f.seekg(0, fstream::beg);

    for(int i = 0; i < num_pizzas; i++){
        pizzas[i].set_from_file(f);
    }
    f.clear();
    f.seekg(0, fstream::beg);
}

/***********************************************************************************
**Function: ~menu
**Description: Destructor that deletes the arrays allocated on the heap.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: N/A
************************************************************************************/
menu::~menu()
{
    if(pizzas != NULL)
        delete[] pizzas;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          menu.h                                                                                              0000660 0016601 0057325 00000001601 13462421140 011711  0                                                                                                    ustar   mclaughz                        upg7553                                                                                                                                                                                                                #ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include "pizza.h"

using namespace std;

class menu //*Class that handles functions and vars relating to menu operations.
{
private:
    int num_pizzas;
    pizza *pizzas;

public:

    menu();

    menu(const menu&);
    menu& operator = (const menu&);
    
    pizza* get_pizzas();
    void make_pizzas();
    void set_num_pizza(fstream &);
    int get_num_pizza() const;
    menu search_pizza_by_cost(int upper_bound);
    menu search_pizza_by_ingredients_to_include(string *ingredients, int num_ingredients);
    menu search_pizza_by_ingredients_to_exclude(string *ingredients, int num_ingredients);
    void add_to_menu(pizza pizza_to_add);
    void remove_from_menu(int index_of_pizza_on_menu);
    void set_from_file_menu(fstream &);
    void print_menu();

    ~menu();
};

#endif                                                                                                                                pizza.h                                                                                             0000660 0016601 0057325 00000002005 13462421141 012102  0                                                                                                    ustar   mclaughz                        upg7553                                                                                                                                                                                                                #ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <fstream>

using namespace std;

class pizza
{ //*Class that handles functions and vars relating to pizza operations.
private:
  string name;
  int small_cost;
  int medium_cost;
  int large_cost;
  int num_ingredients;
  string *ingredients;
  fstream f;

public:
  pizza();

  pizza(const pizza &);

  pizza &operator=(const pizza &);

  void set_name(string);
  string get_name() const;
  void set_small_cost(int);
  int get_small_cost() const;
  void set_medium_cost(int);
  int get_medium_cost() const;
  void set_large_cost(int);
  int get_large_cost() const;
  void set_num_ingredients(int);
  int get_num_ingredients() const;
  void set_ingredients(string *);
  string *get_ingredients() const;
  void set_from_file(fstream &f);

  ~pizza();

  //need to include accessor functions and mutator functions for each private member
  //need to include constructors, copy constructors, assignment operator overload,
  //and destructors where appropriate
};

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           restaurant.h                                                                                        0000700 0016601 0057325 00000002650 13462421143 013140  0                                                                                                    ustar   mclaughz                        upg7553                                                                                                                                                                                                                #ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Structs.h"

class restaurant //*Class that handles functions and vars relating to restaurant operations.
{
private:
    menu Menu;
    employee *employees;
    hours *week;
    string name;
    string phone;
    string address;
    int num_employee = 0;
    fstream employee_file;
    fstream menu_file;
    fstream orders_file;
    fstream restaurant_info_file;
    int selection_size;
    int num_ordered;
    pizza* selection;
    pizza* pizza_order;

public:

    restaurant(const restaurant&);

    restaurant &operator=(const restaurant&);

    restaurant();
    bool int_check(string input);
    int enter_id(string idnumber, int num_employee);
    void num_employee_file();
    void get_info();
    void load_data(); //reads from files to correctly populate menu, employees, hours, etc.
    void login();
    void view_menu();
    void view_hours();
    void view_address();
    void view_phone();
    void view_name();
    void search_menu_by_price();
    void search_by_ingredients();
    void get_order();
    void place_order(pizza *selection, int selection_size, int *num_ordered);
    void change_hours();
    void add_to_menu();
    void remove_from_menu();
    void view_orders();
    void remove_orders();
    void front_page_customer();
    void front_page_employee();
    bool choices();

    ~restaurant();
};

#endif                                                                                        Structs.h                                                                                           0000700 0016601 0057325 00000000524 13462421033 012413  0                                                                                                    ustar   mclaughz                        upg7553                                                                                                                                                                                                                #ifndef STRUCTS_H
#define STRUCTS_H

struct employee //*Struct that holds the employee information
{
    int id;
    string password;
    string first_name;
    string last_name;
};

struct hours //*Struct that holds the hours and days information.
{
    string day;
    string open_hour;
    string close_hour;
};

#endif                                                                                                                                                                            Makefile                                                                                            0000660 0016601 0057325 00000001153 13462367013 012246  0                                                                                                    ustar   mclaughz                        upg7553                                                                                                                                                                                                                CC = g++ -g -std=c++11
exe_file = driver
pizza_file = imp_pizza
restaurant_file = restaurant
menu_file = menu
driver_file = driver

$(exe_file): $(pizza_file).o $(restaurant_file).o $(menu_file).o $(driver_file).o
	$(CC) $(pizza_file).o $(restaurant_file).o $(menu_file).o $(driver_file).o -o $(exe_file)
 
$(pizza_file).o: $(pizza_file).cpp
	$(CC) -c $(pizza_file).cpp
 
$(restaurant_file).o: $(restaurant_file).cpp
	$(CC) -c $(restaurant_file).cpp
 
$(menu_file).o: $(menu_file).cpp
	$(CC) -c $(menu_file).cpp
 
$(driver_file).o: $(driver_file).cpp
	$(CC) -c $(driver_file).cpp 
 
clean:
	rm -f *.out *.o $(exe_file)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
