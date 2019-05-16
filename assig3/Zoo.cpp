#include "Zoo.h"

/***********************************************************************************
**Function: Zoo
**Description: Constructor that initializes the variables
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: N/A
************************************************************************************/
Zoo::Zoo(){
    balance = 100000;
    pop_meerkat.num_pop_adult = 0;
    pop_meerkat.num_pop_teen = 0;
    pop_meerkat.num_pop_baby = 0;
    pop_seaotter.num_pop_adult = 0;
    pop_seaotter.num_pop_teen = 0;
    pop_seaotter.num_pop_baby = 0;
    pop_monkey.num_pop_adult = 0;
    pop_monkey.num_pop_teen = 0;
    pop_monkey.num_pop_baby = 0;
    boom_pop = false;
    game = true;
}

/***********************************************************************************
**Function: erase_screen
**Description: Erases the screen so you can actually read, Pleb.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: N/A
************************************************************************************/
void Zoo::erase_screen(){
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}

/***********************************************************************************
**Function: Zoo (Copy Constructor)
**Description: Copy Constructor that never gets used reeeeeeeeeeeeeeeeeeeeeeeeee
**Parameters: const Zoo &Zoo_old
**Pre-Condition: const Zoo &Zoo_old
**Post-Conditions: Everything
************************************************************************************/
Zoo::Zoo(const Zoo &Zoo_old){
    balance = Zoo_old.balance;

    boom_pop = Zoo_old.boom_pop;
}

/***********************************************************************************
**Function: Zoo::operator (AOO)
**Description: Assignment Operator Overload that never gets used reeeeeeeeeeeeeeeeeeeeeeeeee
**Parameters: const Zoo &Zoo_old
**Pre-Condition: const Zoo &Zoo_old
**Post-Conditions: Everything
************************************************************************************/
Zoo& Zoo::operator=(const Zoo &Zoo_old){
    balance = Zoo_old.balance;

    boom_pop = Zoo_old.boom_pop;
}

/***********************************************************************************
**Function: Int_Check
**Description: Checks the ints to make sure no letters are inputted you fat dumb
**Parameters: string input
**Pre-Condition: input
**Post-Conditions: N/A
************************************************************************************/
bool Zoo::int_check(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (isdigit(input.at(i)) == false)
            return false;
    }
    return true;
}

/***********************************************************************************
**Function: Print balance
**Description: Prints the balance. Boom.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::print_balance(){
    cout << "Balance: " << balance << endl;
}

/***********************************************************************************
**Function: print monkey
**Description: Prints the amount of monkeys
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::print_monkey(){
    cout << "Adult Monkey: " << pop_monkey.num_pop_adult << " " 
         << "Teen Monkey: " << pop_monkey.num_pop_teen << " " 
         << "Baby Monkey: " << pop_monkey.num_pop_baby << endl;
}

/***********************************************************************************
**Function: print meerkat
**Description: Prints the amount of meerkats
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::print_meerkat(){
    cout << "Adult Meerkat: " << pop_meerkat.num_pop_adult << " "
         << "Teen Meerkat: " << pop_meerkat.num_pop_teen << " "
         << "Baby Meerkat: " << pop_meerkat.num_pop_baby << endl;
}

/***********************************************************************************
**Function: print seaotter
**Description: Prints the amount of Sea Otters
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::print_seaotter(){
        cout << "Adult Sea Otter: " << pop_seaotter.num_pop_adult << " " 
             << "Teen Sea Otter: " << pop_seaotter.num_pop_teen << " " 
             << "Baby Sea Otter: " << pop_seaotter.num_pop_baby << endl;

}

/***********************************************************************************
**Function: Create revenue meerkat
**Description: creates the revenue that you get from having meerkats. Where else do you think that money comes from?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::create_revenue_meerkat(){
    int revenue = 0;
    int num_population = pop_meerkat.num_pop_adult + pop_meerkat.num_pop_teen + pop_meerkat.num_pop_baby;
    revenue += 25 * (pop_meerkat.num_pop_adult + pop_meerkat.num_pop_teen);
    revenue += 50 * pop_meerkat.num_pop_baby;
    cout << "You made $" << revenue << " from meerkats this week" << endl;
    balance += revenue;
}

/***********************************************************************************
**Function: Create revenue sea otter
**Description: creates the revenue that you get from having Sea Otters. Where else do you think that money comes from?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::create_revenue_seaotter(){
    int revenue = 0;
    int num_population = pop_seaotter.num_pop_adult + pop_seaotter.num_pop_teen + pop_seaotter.num_pop_baby;
    revenue += 250 * (pop_seaotter.num_pop_adult + pop_seaotter.num_pop_teen);
    revenue += 500 * pop_seaotter.num_pop_baby;
    cout << "You made $" << revenue << " from sea otters this week" << endl;
    balance += revenue;
}

/***********************************************************************************
**Function: Create revenue monkey
**Description: creates the revenue that you get from having monkeys. Where else do you think that money comes from?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::create_revenue_monkey(){
    int boom_money;
    int revenue = 0;
    int num_population = pop_monkey.num_pop_adult + pop_monkey.num_pop_teen + pop_monkey.num_pop_baby;
    revenue += 1500 * (pop_monkey.num_pop_adult + pop_monkey.num_pop_teen);
    revenue += 3000 * pop_monkey.num_pop_baby;
    if(boom_pop == true){
        boom_money = rand()%401+300;
        cout << "You gained an extra $" << boom_money << " from your monkeys this week!" << endl;
        revenue += boom_money * num_population; 
    }
    cout << "You made $" << revenue << " from your monkeys this week" << endl;
    balance += revenue;
    boom_pop = false;
}

/***********************************************************************************
**Function: remove money meerkat
**Description: Its literally a 1 line function that removes money. Why make me suffer?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::remove_money_meerkat(){
    balance -= 500;
}

/***********************************************************************************
**Function: remove money sea otter
**Description: Its literally a 1 line function that removes money. Why make me suffer?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::remove_money_seaotter(){
    balance -= 5000;
}

/***********************************************************************************
**Function: remove money meonkey
**Description: Its literally a 1 line function that removes money. Why make me suffer?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::remove_money_monkey()
{
    balance -= 15000;
}

/***********************************************************************************
**Function: remove money meerkat baby
**Description: Its literally a 1 line function that removes money, but for a baby. Why make me suffer?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::remove_money_meerkat_baby(){
    balance -= 500;
}

/***********************************************************************************
**Function: remove money meerkat adult
**Description: Its literally a 1 line function that removes money, but for an adult. Why make me suffer?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::remove_money_meerkat_adult(){
    balance -= 250;
}

/***********************************************************************************
**Function: remove money sea otter baby
**Description: Its literally a 1 line function that removes money, but for an baby. Why make me suffer?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::remove_money_seaotter_baby(){
    balance -= 5000;
}

/***********************************************************************************
**Function: remove money sea otter adult
**Description: Its literally a 1 line function that removes money, but for an adult. Why make me suffer?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::remove_money_seaotter_adult(){
    balance -= 2500;
}

/***********************************************************************************
**Function: remove money monkey baby
**Description: Its literally a 1 line function that removes money, but for an baby. Why make me suffer?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::remove_money_monkey_baby(){
    balance -= 15000;
}

/***********************************************************************************
**Function: remove money monkey adult
**Description: Its literally a 1 line function that removes money, but for an adult. Why make me suffer?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::remove_money_monkey_adult(){
    balance -= 7500;
}

/***********************************************************************************
**Function: food cost meerkat cheap
**Description: Calculates the cheap food price for extra credit points boiiiiiiiiiiiiiiiiiiiiiiii
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::food_cost_meerkat_cheap()
{
    int food_percent = rand()%9+15;
    int num_population = pop_meerkat.num_pop_adult + pop_meerkat.num_pop_teen + pop_meerkat.num_pop_baby;
    if (balance <= 20 * num_population)
    {
        cout << "You broke loser! You done gone BANKRUPT! GAME OVER!" << endl;
        exit(0);
    }
    int food_loss = food_percent * 1 * num_population;
    balance -= food_loss;
    
}

/***********************************************************************************
**Function: food cost seaotter cheap
**Description: Calculates the cheap food price for extra credit points boiiiiiiiiiiiiiiiiiiiiiiii
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::food_cost_seaotter_cheap()
{
    int food_percent = rand()%9+15;
    int num_population = pop_seaotter.num_pop_adult + pop_seaotter.num_pop_teen + pop_seaotter.num_pop_baby;
    if (balance <= 20 * 2 * food_percent * num_population)
    {
        cout << "You broke loser! You done gone BANKRUPT! GAME OVER!" << endl;
        exit(0);
    }
    int food_loss = food_percent * 2 * num_population;
    balance -= food_loss;
}

/***********************************************************************************
**Function: food cost monkey cheap
**Description: Calculates the cheap food price for extra credit points boiiiiiiiiiiiiiiiiiiiiiiii
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::food_cost_monkey_cheap()
{
    int food_percent = rand()%9+15;
    int num_population = pop_monkey.num_pop_adult + pop_monkey.num_pop_teen + pop_monkey.num_pop_baby;
    if (balance <= 20 * 4 * num_population)
    {
        cout << "You broke loser! You done gone BANKRUPT! GAME OVER!" << endl;
        exit(0);
    }
    int food_loss = food_percent * 4 * num_population;
    balance -= food_loss;
}

/***********************************************************************************
**Function: food cost meerkat regular
**Description: Calculates the regular food price for extra credit points boiiiiiiiiiiiiiiiiiiiiiiii
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::food_cost_meerkat_regular(){
    int food_percent = rand()%21+30;
    int num_population = pop_meerkat.num_pop_adult + pop_meerkat.num_pop_teen + pop_meerkat.num_pop_baby;
    if (balance <= 40 * num_population){
        cout << "You broke loser! You done gone BANKRUPT! GAME OVER!" << endl;
        exit(0);
    }
    int food_loss = 1 * num_population * food_percent;
    balance -= food_loss;
}

/***********************************************************************************
**Function: food cost sea otter regular
**Description: Calculates the regular food price for extra credit points boiiiiiiiiiiiiiiiiiiiiiiii
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::food_cost_seaotter_regular(){
    int food_percent = rand()%21+30;
    int num_population = pop_seaotter.num_pop_adult + pop_seaotter.num_pop_teen + pop_seaotter.num_pop_baby;
    if (balance <= 40 * 2 * num_population){
        cout << "You broke loser! You done gone BANKRUPT! GAME OVER!" << endl;
        exit(0);
    }
    int food_loss = 2 * num_population * food_percent;
    balance -= food_loss;
}

/***********************************************************************************
**Function: food cost monkey regular
**Description: Calculates the regular food price for extra credit points boiiiiiiiiiiiiiiiiiiiiiiii
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::food_cost_monkey_regular(){
    int food_percent = rand()%21+30;
    int num_population = pop_monkey.num_pop_adult + pop_monkey.num_pop_teen + pop_monkey.num_pop_baby;
    if(balance <= 40 * 4 * num_population){
        cout << "You broke loser! You done gone BANKRUPT! GAME OVER!" << endl;
        exit(0);
    }
    int food_loss = 4 * num_population * food_percent;
    balance -= food_loss;
}

/***********************************************************************************
**Function: food cost meerkat premium
**Description: Calculates the premium food price for extra credit points rich boi
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::food_cost_meerkat_premium(){
    int food_percent = rand()%41+60;
    int num_population = pop_meerkat.num_pop_adult + pop_meerkat.num_pop_teen + pop_meerkat.num_pop_baby;
    if (balance <= 80 * num_population)
    {
        cout << "You broke loser! You done gone BANKRUPT! GAME OVER!" << endl;
        exit(0);
    }
    int food_loss = 1 * num_population * food_percent;
    balance -= food_loss;
}

/***********************************************************************************
**Function: food cost sea otter premium
**Description: Calculates the premium food price for extra credit points rich boi
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::food_cost_seaotter_premium(){
    int food_percent = rand()%41+60;
    int num_population = pop_seaotter.num_pop_adult + pop_seaotter.num_pop_teen + pop_seaotter.num_pop_baby;
    if (balance <= 80 * 2 * num_population)
    {
        cout << "You broke loser! You done gone BANKRUPT! GAME OVER!" << endl;
        exit(0);
    }
    int food_loss = 2 * num_population * food_percent;
    balance -= food_loss;
}

/***********************************************************************************
**Function: food cost monkey premium
**Description: Calculates the premium food price for extra credit points rich boi
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::food_cost_monkey_premium(){
    int food_percent = rand()%41+60;
    int num_population = pop_monkey.num_pop_adult + pop_monkey.num_pop_teen + pop_monkey.num_pop_baby;
    if (balance <= 80 * 4 * num_population)
    {
        cout << "You broke loser! You done gone BANKRUPT! GAME OVER!" << endl;
        exit(0);
    }
    int food_loss = 4 * num_population * food_percent;
    balance -= food_loss;
}

/***********************************************************************************
**Function: meerkat baby sick
**Description: Chooses whether a baby lives or dies to sick person.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::meerkat_baby_sick(){
    cout << "EEK GAD! A baby meerkat has fallen ill! (1)Heal for $500 or (2)let it perish: ";
    string choice;
    getline(cin, choice);
    if (int_check(choice) == false)
    {
        cout << "Error! You entered an invalid input!" << endl;
        exit(0);
    }
    if (choice == "1")
    {
        cout << "Baby meerkat was healed!" << endl;
        remove_money_meerkat_baby();
    }
    else if (choice == "2")
    {
        int m_index = rand()%(pop_meerkat.num_pop_baby);
        remove_meerkat(m_index);
    }
}

/***********************************************************************************
**Function: meerkat adult sick
**Description: Chooses whether a adult lives or dies to sick person.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::meerkat_adult_sick(){
    cout << "EEK GAD! A adult/teen meerkat has fallen ill! (1)Heal for $250 or (2)let it perish: ";
    string choice;
    getline(cin, choice);
    if (int_check(choice) == false)
    {
        cout << "Error! You entered an invalid input!" << endl;
        exit(0);
    }
    if (choice == "1")
    {
        cout << "Adult/teen meerkat was healed!" << endl;
        remove_money_meerkat_adult();
    }
    else if (choice == "2")
    {
        int m_index = rand()%(pop_meerkat.num_pop_adult + pop_meerkat.num_pop_teen);
        remove_meerkat(m_index);
    }    
}

/***********************************************************************************
**Function: sea otter baby sick
**Description: Chooses whether a baby lives or dies to sick person.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::seaotter_baby_sick(){
    cout << "EEK GAD! A baby sea otter has fallen ill! (1)Heal for $5000 or (2)let it perish: ";
    string choice;
    getline(cin, choice);
    if (int_check(choice) == false)
    {
        cout << "Error! You entered an invalid input!" << endl;
        exit(0);
    }
    if (choice == "1")
    {
        cout << "Baby sea otter was healed!" << endl;
        remove_money_seaotter_baby();
    }
    else if (choice == "2")
    {
        int m_index = rand()%(pop_seaotter.num_pop_baby);
        remove_seaotter(m_index);
    }
}

/***********************************************************************************
**Function: sea otter adult sick
**Description: Chooses whether a adult lives or dies to sick person.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::seaotter_adult_sick(){
    cout << "EEK GAD! A adult/teen sea otter has fallen ill! (1)Heal for $2500 or (2)let it perish: ";
    string choice;
    getline(cin, choice);
    if (int_check(choice) == false)
    {
        cout << "Error! You entered an invalid input!" << endl;
        exit(0);
    }
    if (choice == "1")
    {
        cout << "Adult/teen sea otter was healed!" << endl;
        remove_money_seaotter_adult();
    }
    else if (choice == "2")
    {
        int m_index = rand()%(pop_seaotter.num_pop_adult + pop_seaotter.num_pop_teen);
        remove_seaotter(m_index);
    }
}

/***********************************************************************************
**Function: monkey baby sick
**Description: Chooses whether a baby lives or dies to sick person.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::monkey_baby_sick(){
    cout << "EEK GAD! A baby monkey has fallen ill! (1)Heal for $15,000 or (2)let it perish: ";
    string choice;
    getline(cin, choice);
    if (int_check(choice) == false)
    {
        cout << "Error! You entered an invalid input!" << endl;
        exit(0);
    }
    if (choice == "1")
    {
        cout << "Baby monkey was healed!" << endl;
        remove_money_monkey_baby();
    }
    else if (choice == "2")
    {
        int m_index = rand()%(pop_monkey.num_pop_baby);
        remove_monkey(m_index);
    }
}

/***********************************************************************************
**Function: monkey adult sick
**Description: Chooses whether a adult lives or dies to sick person.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::monkey_adult_sick(){
    cout << "EEK GAD! A adult/teen monkey has fallen ill! (1)Heal for $7,500 or (2)let it perish: ";
    string choice;
    getline(cin, choice);
    if (int_check(choice) == false)
    {
        cout << "Error! You entered an invalid input!" << endl;
        exit(0);
    }
    if (choice == "1")
    {
        cout << "Adult/teen monkey was healed!" << endl;
        remove_money_monkey_adult();
    }
    else if (choice == "2")
    {
        int m_index = rand()%(pop_monkey.num_pop_adult + pop_monkey.num_pop_teen);      
        remove_monkey(m_index);
    }
}

/***********************************************************************************
**Function: babies born
**Description: A function that just pops babies out. These animals really need to get a room amiright?
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::babies_born(){
    int random_animal = rand() % 3 + 1;
    if(random_animal == 1 && pop_meerkat.num_pop_adult >= 2){
        cout << "Congratulations! A baby meerkat has been brought forth into this cruel world! Isn't it ugly!" << endl;
        create_baby_meerkat();
    }
    else if (random_animal == 2 && pop_seaotter.num_pop_adult >= 2){
        cout << "Congratulations! A baby sea otter has been brought into this cruel world! Don't let anyone hit it with a baseball bat!" << endl;
        create_baby_seaotter();
    }
    else if (random_animal == 3 && pop_monkey.num_pop_adult >= 2){
        cout << "Congratulations! A baby monkey has been airlifted into the compound. Why do the monkeys seem to be plotting something...." << endl;
        create_baby_monkey();
    }
}

/***********************************************************************************
**Function: random event premium
**Description: This function handles all the different types of random events and their chances based on food type bought
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::random_event_premium(){
    int random = rand()%8+1;
    //cout << random << endl;
    if(random == 1){
        int random_animal = rand()%3+1;
        if(random_animal == 1){
            int random_age = rand()%2+1;
            if (random_age == 1 && pop_meerkat.num_pop_baby >= 1)
            {
               meerkat_baby_sick(); 
            }
            else if (random_age == 2 && pop_meerkat.num_pop_adult + pop_meerkat.num_pop_teen >= 1)
            {
                meerkat_adult_sick();
            }
        }
        else if (random_animal == 2)
        {
            int random_age = rand() % 2 + 1;
            //cout << random_age << endl;
            if (random_age == 1 && pop_seaotter.num_pop_baby >= 1)
            {
                seaotter_baby_sick();
            }
            else if (random_age == 2 && pop_seaotter.num_pop_adult + pop_seaotter.num_pop_teen >= 1)
            {
                seaotter_adult_sick();
            }
        }
        else if (random_animal == 3)
        {
            int random_age = rand() % 2 + 1;
            //cout << random_age << endl;
            if (random_age == 1 && pop_monkey.num_pop_baby >= 1)
            {
               monkey_baby_sick(); 
            }
            else if (random_age == 2 && pop_monkey.num_pop_adult + pop_monkey.num_pop_teen >= 1)
            {
                monkey_adult_sick();
            }
        }
    }
    else if(random == 2){
        babies_born();
    }
    else if(random == 3){
        cout << "HUZZAH! A population boom has occurred at the zoo!" << endl;
        if(pop_monkey.num_pop_adult + pop_monkey.num_pop_teen + pop_monkey.num_pop_baby >= 1){
            boom_pop = true;
        }
    }
    else if (random == 4 || random == 5 || random == 6 || random == 7 || random == 8)
    {
        cout << "No special event occurred. Yay?" << endl;
    }
}

/***********************************************************************************
**Function: random event regular
**Description: This function handles all the different types of random events and their chances based on food type bought
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::random_event_regular()
{
    int random = rand() % 4 + 1;
    //cout << random << endl;
    if (random == 1)
    {
        int random_animal = rand() % 3 + 1;
        if (random_animal == 1)
        {
            int random_age = rand() % 2 + 1;
            if (random_age == 1 && pop_meerkat.num_pop_baby >= 1)
            {
                meerkat_baby_sick();
            }
            else if (random_age == 2 && pop_meerkat.num_pop_adult + pop_meerkat.num_pop_teen >= 1)
            {
                meerkat_adult_sick();
            }
        }
        else if (random_animal == 2)
        {
            int random_age = rand() % 2 + 1;
            //cout << random_age << endl;
            if (random_age == 1 && pop_seaotter.num_pop_baby >= 1)
            {
                seaotter_baby_sick();
            }
            else if (random_age == 2 && pop_seaotter.num_pop_adult + pop_seaotter.num_pop_teen >= 1)
            {
                seaotter_adult_sick();
            }
        }
        else if (random_animal == 3)
        {
            int random_age = rand() % 2 + 1;
            //cout << random_age << endl;
            if (random_age == 1 && pop_monkey.num_pop_baby >= 1)
            {
                monkey_baby_sick();
            }
            else if (random_age == 2 && pop_monkey.num_pop_adult + pop_monkey.num_pop_teen >= 1)
            {
                monkey_adult_sick();
            }
        }
    }
    else if (random == 2)
    {
        babies_born();
    }
    else if (random == 3)
    {
        cout << "HUZZAH! A population boom has occurred at the zoo!" << endl;
        if (pop_monkey.num_pop_adult + pop_monkey.num_pop_teen + pop_monkey.num_pop_baby >= 1){
            boom_pop = true;
        }
    }
    else if (random == 4)
    {
        cout << "No special event occurred. Yay?" << endl;
    }
}

/***********************************************************************************
**Function: random event cheap
**Description: This function handles all the different types of random events and their chances based on food type bought
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::random_event_cheap()
{
    int random = rand() % 8 + 1;
    //cout << random << endl;
    if (random == 1 || random == 2 || random == 3 || random == 4 || random == 5)
    {
        int random_animal = rand() % 3 + 1;
        //cout << random_animal << endl;
        if (random_animal == 1)
        {
            int random_age = rand() % 2 + 1;
            //cout << random_age << endl;
            if (random_age == 1 && pop_meerkat.num_pop_baby >= 1)
            {
                meerkat_baby_sick();
            }
            else if (random_age == 2 && pop_meerkat.num_pop_adult + pop_meerkat.num_pop_teen >= 1)
            {
                meerkat_adult_sick();
            }
        }
        else if (random_animal == 2)
        {
            int random_age = rand() % 2 + 1;
            //cout << random_age << endl;
            if (random_age == 1 && pop_seaotter.num_pop_baby >= 1)
            {
                seaotter_baby_sick();
            }
            else if (random_age == 2 && pop_seaotter.num_pop_adult + pop_seaotter.num_pop_teen >= 1)
            {
                seaotter_adult_sick();
            }
        }
        else if (random_animal == 3)
        {
            int random_age = rand() % 2 + 1;
            //cout << random_age << endl;
            if (random_age == 1 && pop_monkey.num_pop_baby >= 1)
            {
                monkey_baby_sick();
            }
            else if (random_age == 2 && pop_monkey.num_pop_adult + pop_monkey.num_pop_teen >= 1)
            {
                monkey_adult_sick();
            }
        }
    }
    else if (random == 6)
    {
        babies_born();
    }
    else if (random == 7)
    {
        cout << "HUZZAH! A population boom has occurred at the zoo!" << endl;
        if (pop_monkey.num_pop_adult + pop_monkey.num_pop_teen + pop_monkey.num_pop_baby >= 1){
            boom_pop = true;
        }
    }
    else if (random == 8)
    {
        cout << "No special event occurred. Yay?" << endl;
    }
}

/***********************************************************************************
**Function: remove monkey
**Description: too many monkeys, too many mooonnnnkkkkeeyyyys. just some animal cleansing no worries.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::remove_monkey(int m_index){
    int num_population = pop_monkey.num_pop_adult + pop_monkey.num_pop_teen + pop_monkey.num_pop_baby;
    Monkey* m1 = new Monkey[num_population - 1];
    int count = 0;
    if(num_population == 0){
        delete[] monkeys;
    }
    else{
        for(int i = 0; i < num_population; i++){
            if(!(m_index == i)){
                m1[count] = monkeys[i];
                count++;
            }
        }
        if(monkeys[m_index].get_age() >= 104)
        {
            pop_monkey.num_pop_adult--;
        }
        else if (monkeys[m_index].get_age() < 104 && monkeys[m_index].get_age() >= 5)
        {
            pop_monkey.num_pop_teen--;
        }
        else if (monkeys[m_index].get_age() < 5)
        {
            pop_monkey.num_pop_baby--;
        }
        delete[] monkeys;
        monkeys = m1;
    }
}

/***********************************************************************************
**Function: create adult monkey
**Description: bringing in the reinforcements with this one. +1 to monkey reserves
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::create_adult_monkey(){
    int num_population = pop_monkey.num_pop_adult + pop_monkey.num_pop_teen + pop_monkey.num_pop_baby;
    Monkey* m2 = new Monkey[num_population + 1];
    for(int i = 0; i < num_population; i++){
        m2[i] = monkeys[i];
    }
    pop_monkey.num_pop_adult++;
    delete[] monkeys;
    monkeys = m2;
}

/***********************************************************************************
**Function: create baby monkey
**Description: bringing in the reinforcements with this one. +1 to monkey reserves and cuteness effect
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::create_baby_monkey(){
    int num_population = pop_monkey.num_pop_adult + pop_monkey.num_pop_teen + pop_monkey.num_pop_baby;
    Monkey *m3 = new Monkey[num_population + 1];
    for (int i = 0; i < num_population; i++)
    {
        m3[i] = monkeys[i];
    }
    monkeys[num_population].set_age(0);
    pop_monkey.num_pop_baby++;
    delete[] monkeys;
    monkeys = m3;
}

/***********************************************************************************
**Function: remove meerkats
**Description: too many meerkats, too many meeerrrrkkkkaaatttss. just some animal cleansing no worries.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::remove_meerkat(int m_index)
{
    int num_population = pop_meerkat.num_pop_adult + pop_meerkat.num_pop_teen + pop_meerkat.num_pop_baby;
    Meerkat *me1 = new Meerkat[num_population - 1];
    int count = 0;
    if(num_population  == 0){
        delete[] meerkats;
    }
    else{
        for (int i = 0; i < num_population; i++)
        {
            if (!(m_index == i))
            {
                me1[count] = meerkats[i];
                count++;
            }
        }
        if (meerkats[m_index].get_age() >= 104)
        {
            pop_meerkat.num_pop_adult--;
        }
        else if (meerkats[m_index].get_age() < 104 && meerkats[m_index].get_age() >= 5)
        {
            pop_meerkat.num_pop_teen--;
        }
        else if (meerkats[m_index].get_age() < 5)
        {
            pop_meerkat.num_pop_baby--;
        }
        delete[] meerkats;
        meerkats = me1;
    }
}

/***********************************************************************************
**Function: create adult meerkat
**Description: bringing in the reinforcements with this one. +1 to meerkat reserves
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::create_adult_meerkat()
{
    int num_population = pop_meerkat.num_pop_adult + pop_meerkat.num_pop_teen + pop_meerkat.num_pop_baby;
    Meerkat *me2 = new Meerkat[num_population + 1];
    for (int i = 0; i < num_population; i++)
    {
        me2[i] = meerkats[i];
    }
    pop_meerkat.num_pop_adult++;
    delete[] meerkats;
    meerkats = me2;
}

/***********************************************************************************
**Function: create baby meerkat
**Description: bringing in the reinforcements with this one. +1 to meerkat reserves and cuteness effect
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::create_baby_meerkat()
{
    int num_population = pop_meerkat.num_pop_adult + pop_meerkat.num_pop_teen + pop_meerkat.num_pop_baby;
    Meerkat *me3 = new Meerkat[num_population + 5];
    for (int i = 0; i < num_population; i++)
    {
        me3[i] = meerkats[i];
    }
    meerkats[num_population].set_age(0);
    pop_meerkat.num_pop_baby++;
    delete[] meerkats;
    meerkats = me3;
}

/***********************************************************************************
**Function: remove sea otter
**Description: too many sea otters, too many sea ooootttteeerrrsss. just some animal cleansing no worries.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::remove_seaotter(int m_index)
{
    int num_population = pop_seaotter.num_pop_adult + pop_seaotter.num_pop_teen + pop_seaotter.num_pop_baby;
    Sea_Otter *s1 = new Sea_Otter[num_population - 1];
    int count = 0;
    if(num_population  == 0){
        delete[] seaotters;
    }
    else{
        for (int i = 0; i < num_population; i++)
        {
            if (!(m_index == i))
            {
                s1[count] = seaotters[i];
                count++;
            }
        }
        if (seaotters[m_index].get_age() >= 104)
        {
            pop_seaotter.num_pop_adult--;
        }
        else if (seaotters[m_index].get_age() < 104 && seaotters[m_index].get_age() >= 5)
        {
            pop_seaotter.num_pop_teen--;
        }
        else if (seaotters[m_index].get_age() < 5)
        {
            pop_seaotter.num_pop_baby--;
        }
        delete[] seaotters;
        seaotters = s1;
    }
}

/***********************************************************************************
**Function: create adult sea otter
**Description: bringing in the reinforcements with this one. +1 to sea otter reserves
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::create_adult_seaotter()
{
    int num_population = pop_seaotter.num_pop_adult + pop_seaotter.num_pop_teen + pop_seaotter.num_pop_baby;
    Sea_Otter *s2 = new Sea_Otter[num_population + 1];
    for (int i = 0; i < num_population; i++)
    {
        s2[i] = seaotters[i];
    }
    pop_seaotter.num_pop_adult++;
    delete[] seaotters;
    seaotters = s2;
}

/***********************************************************************************
**Function: create baby sea otters
**Description: bringing in the reinforcements with this one. +1 to sea otter reserves and cuteness effect
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::create_baby_seaotter()
{
    int num_population = pop_seaotter.num_pop_adult + pop_seaotter.num_pop_teen + pop_seaotter.num_pop_baby;
    Sea_Otter *s3 = new Sea_Otter[num_population + 2];
    for (int i = 0; i < num_population; i++)
    {
        s3[i] = seaotters[i];
    }
    seaotters[num_population].set_age(0);
    pop_seaotter.num_pop_baby++;
    delete[] seaotters;
    seaotters = s3;
}

/***********************************************************************************
**Function: buy animal
**Description: Just a function that buys animals that were stolen from their only known home and natural habitat off of the black market. No biggy. 
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::buy_animal(){
    string choice;
    cout << "Would you like to buy an animal? yes(1) no(2): ";
    getline(cin, choice);
    if (int_check(choice) == false)
    {
        cout << "Error! You entered an invalid input!" << endl;
        exit(0);
    }
    if(choice == "1"){
        string choice2;
        if(balance < 0){
            cout << "You burned through your money faster than an at-home dad day-trading on puts on Robinhood. Have fun being bankrupt!" << endl;
            exit(0);
        }
        else{
            cout << "What animal would you like to purchase?" << endl;
            cout << "(1) Meerkat: $500 \n(2) Sea Otter: $5,000 \n(3) Monkey: $15,000" << endl;
            getline(cin, choice2);
            if (int_check(choice2) == false)
            {
                cout << "Error! You entered an invalid input!" << endl;
                exit(0);
            }
            else if(choice2 == "1"){
                remove_money_meerkat();
                create_adult_meerkat();
            }
            else if(choice2 == "2"){
                remove_money_seaotter();
                create_adult_seaotter();
            }
            else if(choice2 == "3"){
                remove_money_monkey();
                create_adult_monkey();
            }
        }
    }
}

/***********************************************************************************
**Function: quite game
**Description: When life gets really hard, you just quit
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void Zoo::quite_game(){
    string choice;
    cout << "Do you wish to quite the game? yes(1) or no(2): ";
    getline(cin, choice);
    if (int_check(choice) == false){
        cout << "Error! You entered an invalid input!" << endl;
        exit(0);
    }
    else if(choice == "1"){
        game = false;
        cout << "You give up your life long dream of being a Zoo owner; however, you did leave with a modest $" << balance << ". Maybe\n invest it in the stock market, y'know?" << endl;
    }
}

/***********************************************************************************
**Function: ~Zoo
**Description: Delete everything and watch the world burn.
**Parameters: N/A
**Pre-Condition: N/A
**Post-Conditions: N/A
************************************************************************************/
Zoo::~Zoo(){
    delete[] monkeys;
    delete[] meerkats;
    delete[] seaotters;
}