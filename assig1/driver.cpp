/******************************************************
** Program: wizard_catalog.cpp
** Author: Zachery McLaughlin
** Date: 04/14/2019
** Description: This program creates a database that stores and sorts data about spells and their uses. The database can only be accessed if the user enters a valid
                ID and password that matches with user information stored in the database.
** Input: ID, Password, What spellbook to see, how to sort, whether to exit or not.
** Output: Spellbooks, information of spellbook, spells, sorting
******************************************************/
#include "wizards_proto.h"

int main(int argc, char ** argv){

   int num_spellbook = 0;
   int num_spells = 0;
   int user_num = 0;
   int num_wizards = 0;
   int spell_total = 0;
   bool is_not_valid;
   
   
   if (argc > 1)
        cout << "argv[1] = " << argv[1] << endl; 
   else {
        cout << "No file name entered. Exiting...";
        return -1;
    }
   if (argc > 2)
        cout << "argv[2] = " << argv[2] << endl; 
   else {
        cout << "No file name entered. Exiting...";
        return -1;
   } 
   
   ifstream f(argv[1]);
   ifstream f2(argv[2]);
   f2 >> num_spellbook;
   
   wizard* db = create_wizard_info(num_wizards);
   spellbook* books = create_spellbooks(num_spellbook);
   spell* spells = create_spells(num_spells);
   
   overall_login(db, f, &user_num);
   get_spellbook_data(books, spells, num_spells, num_spellbook, f2, &spell_total, db, user_num);
   delete_info(db, books, spells, num_spellbook);


   return 0;

}
