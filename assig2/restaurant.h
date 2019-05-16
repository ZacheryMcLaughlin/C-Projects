#ifndef RESTAURANT_H
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

#endif