#include "menu.h"

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
}