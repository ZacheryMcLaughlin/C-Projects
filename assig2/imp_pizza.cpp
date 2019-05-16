#include "pizza.h"

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
}
