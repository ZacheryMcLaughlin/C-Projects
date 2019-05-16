#ifndef PIZZA_H
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

#endif