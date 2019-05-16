#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Monkey.h"
#include "Meerkat.h"
#include "Sea_Otter.h"

using namespace std;

struct Population
{
    int num_pop_adult;
    int num_pop_teen;
    int num_pop_baby;
};

class Zoo {
    private:
        string input;
        int balance;
        bool boom_pop;
        Population pop_meerkat;
        Population pop_monkey;
        Population pop_seaotter;
        Monkey* monkeys = NULL;
        Meerkat* meerkats = NULL;
        Sea_Otter* seaotters = NULL;

    public:

        bool game;

        Zoo();

        Zoo(const Zoo&);

        Zoo &operator=(const Zoo&);

        bool int_check(string);

        void remove_monkey(int);
        void create_adult_monkey();
        void create_baby_monkey();
        void remove_meerkat(int);
        void create_adult_meerkat();
        void create_baby_meerkat();
        void remove_seaotter(int);
        void create_adult_seaotter();
        void create_baby_seaotter();
        void create_revenue_monkey();
        void create_revenue_meerkat();
        void create_revenue_seaotter();
        void print_balance();
        void print_meerkat();
        void print_seaotter();
        void print_monkey();
        void remove_money_meerkat();
        void remove_money_seaotter();
        void remove_money_monkey();
        void buy_animal();
        void random_event_premium();
        void random_event_regular();
        void random_event_cheap();
        void remove_money_meerkat_baby();
        void remove_money_meerkat_adult();
        void remove_money_seaotter_baby();
        void remove_money_seaotter_adult();
        void remove_money_monkey_baby();
        void remove_money_monkey_adult();
        void quite_game();
        void food_cost_meerkat_premium();
        void food_cost_seaotter_premium();
        void food_cost_monkey_premium();
        void food_cost_meerkat_regular();
        void food_cost_seaotter_regular();
        void food_cost_monkey_regular();
        void food_cost_meerkat_cheap();
        void food_cost_seaotter_cheap();
        void food_cost_monkey_cheap();
        void erase_screen();
        void meerkat_baby_sick();
        void meerkat_adult_sick();
        void seaotter_baby_sick();
        void seaotter_adult_sick();
        void monkey_baby_sick();
        void monkey_adult_sick();
        void babies_born();

        ~Zoo();
};
#endif