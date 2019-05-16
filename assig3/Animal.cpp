#include "Animal.h"

/***********************************************************************************
**Function: Animal
**Description: Constructor that initializes the variables
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: N/A
************************************************************************************/
Animal::Animal(){
    age = 0;
    num_animal = 0;
}

/***********************************************************************************
**Function: Animal (Copy Constructor)
**Description: Copy Constructor that never gets used reeeeeeeeeeeeeeeeeeeeeeeeee
**Parameters: const Animal &Animal_old
**Pre-Condition: const Animal &Animal_old
**Post-Conditions: Everything
************************************************************************************/
Animal::Animal(const Animal &Animal_old){
    age = Animal_old.age;

    num_animal = Animal_old.num_animal;

    cost = Animal_old.cost;

    babies = Animal_old.babies;
    }

/***********************************************************************************
**Function: Animal::operator (AOO)
**Description: Assignment Operator Overload that never gets used reeeeeeeeeeeeeeeeeeeeeeeeee
**Parameters: const Animal &Animal_old
**Pre-Condition: const Animal &Animal_old
**Post-Conditions: Everything
************************************************************************************/
Animal& Animal::operator=(const Animal &Animal_old){
    age = Animal_old.age;

    num_animal = Animal_old.num_animal;

    cost = Animal_old.cost;

    babies = Animal_old.babies;
}

/***********************************************************************************
**Function: set age
**Description: sets the ages of the animals
**Parameters: int animal_age
**Pre-Condition: int animal_age
**Post-Conditions: Everything
************************************************************************************/
void Animal::set_age(int animal_age){
    age = animal_age;
}

/***********************************************************************************
**Function: increment age
**Description: increments the age. Pretty self explanatory
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Animal::increment_age(){
    age++;
}

/***********************************************************************************
**Function: get age
**Description: gets the age. Pretty self explanatory
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
int Animal::get_age(){
    return age;
}

/***********************************************************************************
**Function: set num animal
**Description: Sets the amount of animals present
**Parameters: int Anum_animal
**Pre-Condition: int Anum_animal
**Post-Conditions: Everything
************************************************************************************/
void Animal::set_num_animal(int Anum_animal){
    num_animal = Anum_animal;
}

/***********************************************************************************
**Function: get num animal
**Description: gets the amount of animals present
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
int Animal::get_num_animal(){
    return num_animal;
}