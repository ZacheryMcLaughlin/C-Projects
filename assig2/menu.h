#ifndef MENU_H
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

#endif 