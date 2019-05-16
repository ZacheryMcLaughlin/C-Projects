#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct wizard {
   string name;
   int id;
   string password;
   string position_title;
   float beard_length;
};

struct spellbook {
   string title;
   string author;
   int num_pages;
   int edition;
   int num_spells;
   float avg_success_rate;
   struct spell *s;
};

struct spell {
   string name;
   float success_rate;
   string effect;
};

wizard* create_wizard_info(int);
 
spellbook* create_spellbooks(int);

spell* create_spells(int);

wizard* get_info(ifstream &, int);

int enter_id(wizard *, ifstream &, string, int);
 
void print_user_info(wizard*, int);

void overall_login(wizard *, ifstream &, int *);

spellbook* get_info_spells(ifstream &f, int);
 
spell* get_spellbook_spells(spellbook*, int, int *);
 
spell* get_info_spell_db(ifstream &, int);
 
int effect_value(string);

void print_pages(spellbook*, int, spell*, ifstream &);
 
void print_avg_spell(spellbook*, int, ifstream &);
 
void print_spell_effect(spellbook*, spell*, int, int, ifstream &);

void print_to_screen_pages(spellbook*, int, ifstream &);
 
void print_to_screen_spells(spellbook*, int, spell*, int, ifstream &);
  
void print_to_screen_spell_effect(spell*, int, ifstream &);
 
void sort_pages_screen(spellbook*, int, ifstream &, spell*, int);

void sort_spell_screen(spellbook*, int, spell*, int, ifstream &);

void sort_pages(spellbook*, int, spell*, ifstream &);

void sort_spell(spellbook*, int, spell*, int, ifstream &);

void sort_spell_effect_screen(spell*, int, ifstream &);

void sort_spell_effect_file(spellbook*, spell*, int, int, ifstream &);

void get_spellbook_data(spellbook*, spell*, int, int, ifstream &, int *, wizard*, int);

void delete_info(wizard *, spellbook *, spell*, int);
