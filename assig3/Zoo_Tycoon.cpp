/**************************************************************************************************************************************
** Program: Zoo_Tycoon.cpp
** Author: Zachery McLaughlin
** Date: 05/12/2019
** Description: This program simulates a realistic game of zoo business management and entrepreneurship wherefore the user progresses,
                week by week, and buys animals and food. This game is continued until the user quits or they go bankrupt.
** Input: Choices
** Output: balance, animals bought, food, special events, type/age of animals
**************************************************************************************************************************************/

#include "Animal.h"
#include "Zoo.h"

int main()
{
    srand(time(NULL));
    int week = 0;
    string choices;
    Zoo z1;
    cout << "Welcome to Zoo Tycoon!" << endl;
    cout << "Week " << week << endl;
    z1.print_balance();
    z1.print_meerkat();
    z1.print_seaotter();
    z1.print_monkey();
    z1.buy_animal();
    week++;
    cout << endl;
    do{
        z1.erase_screen();
        cout << "Week " << week << endl;
        z1.print_balance();
        z1.print_meerkat();
        z1.print_seaotter();
        z1.print_monkey();
        z1.buy_animal();
        cout << "What food do you want to buy for your animals? (1)Premium ($60 to $100) (2)Regular ($30-$50) (3)Cheap ($15-$25)" << endl;
        getline(cin, choices);
        if (z1.int_check(choices) == false)
        {
            exit(0);
        }
        if (choices == "1")
        {
            z1.food_cost_meerkat_premium();
            z1.food_cost_seaotter_premium();
            z1.food_cost_monkey_premium();
            z1.random_event_premium();
            z1.create_revenue_meerkat();
            z1.create_revenue_seaotter();
            z1.create_revenue_monkey();
        }
        else if (choices == "2")
        {
            z1.food_cost_meerkat_regular();
            z1.food_cost_seaotter_regular();
            z1.food_cost_monkey_regular();
            z1.random_event_regular();
            z1.create_revenue_meerkat();
            z1.create_revenue_seaotter();
            z1.create_revenue_monkey();
        }
        else if (choices == "3")
        {
            z1.food_cost_meerkat_cheap();
            z1.food_cost_seaotter_cheap();
            z1.food_cost_monkey_cheap();
            z1.random_event_cheap();
            z1.create_revenue_meerkat();
            z1.create_revenue_seaotter();
            z1.create_revenue_monkey();
        }
        week++;
        cout << endl;
        z1.quite_game();
    }while(z1.game == true);
    return 0;
}