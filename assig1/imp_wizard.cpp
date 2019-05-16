#include "wizards_proto.h"

/***********************************************************************************
**Function: wizard* create_wizard_info
**Description: struct array that creates an array on the heap.
**Parameters: int num_wizard
**Pre-Condition: num_wizard
**Post-Conditions: Everything
************************************************************************************/
wizard* create_wizard_info(int num_wizards){
  wizard* db = new wizard [num_wizards];
	return db;
}

/***********************************************************************************
**Function: wizard* create_spellbooks
**Description: struct array that creates an array on the heap.
**Parameters: int num_spellbook
**Pre-Condition: num_spellbook
**Post-Conditions: Everything
************************************************************************************/
spellbook* create_spellbooks(int num_spellbook){
  spellbook* books = new spellbook [num_spellbook];
	return books;
}

/***********************************************************************************
**Function: wizard* create_spells
**Description: struct array that creates an array on the heap.
**Parameters: int num_spells
**Pre-Condition: num_spells
**Post-Conditions: Everything
************************************************************************************/
spell* create_spells(int num_spells){
  spell* spells = new spell [num_spells];
	return spells;
}

/***********************************************************************************
**Function: wizard* get_info
**Description: Fills the wizard struct array with information from the wizards.txt file.
**Parameters: ifstream &f, int num_wizards
**Pre-Condition: ifstream &f, int num_wizards
**Post-Conditions: Everything
************************************************************************************/
wizard* get_info(ifstream &f, int num_wizards){
  string temp_str;
  if (!f.is_open()){
     cout << "File doesn't exist! Create an input.txt file!" << endl;
     exit(0);
  }
  
  wizard* wizards = create_wizard_info(num_wizards);
  
  for (int i = 0; i < num_wizards; i++){
      f >> wizards[i].name >> wizards[i].id >> wizards[i].password >> wizards[i].position_title >> wizards[i].beard_length;
      getline(f, temp_str);
    
   }
   return wizards;
}

/***********************************************************************************
**Function: enter_id
**Description: Function that takes in user input for their ID and checks it with the IDs in the wizards.txt file. If correct,
               the function will return true and go onto the rest of the functions. If false, an error will prompt and ask the user
               to enter again.
**Parameters: wizard * wizards, ifstream &f, string idnumber, int num_wizards
**Pre-Condition: wizard * wizards, ifstream &f, string idnumber, int num_wizards
**Post-Conditions: Everything
************************************************************************************/
int enter_id(wizard * wizards, ifstream &f, string idnumber, int num_wizards){
   bool pass;
   do{ 
    cout << "Enter ID number: ";
    getline(cin, idnumber);
    int ID = atoi(idnumber.c_str());
    //cout << ID << endl;
    //cout << wizards[1].id << endl;
    for(int i = 0; i < num_wizards; i++){
      if(ID == wizards[i].id){
        return i;
      }
    }
    
    cout << "Error! Input the correct ID number in INTS or you shall be banished! " <<endl;
    
   }while (pass == false);
}

/***********************************************************************************
**Function: print_user_info
**Description: Takes all of the information gathered from the entered ID and password and prints out the rest of the 
               information regarding the user. 
**Parameters: wizard* wizards, int user_num, int *is_stud
**Pre-Condition: wizard* wizards, int user_num, int *is_stud
**Post-Conditions: Everything
************************************************************************************/
void print_user_info(wizard* wizards, int user_num){
  cout << "Username: " << wizards[user_num].name << endl;
  cout << "ID number: " << wizards[user_num].id << endl;
  cout << "Position: " << wizards[user_num].position_title << endl;
  cout << "Beard Length: " << wizards[user_num].beard_length << endl;
}

/***********************************************************************************
**Function: overall_login
**Description: This function maintains everything that has to do with the login process with the user.
               The function takes in the user ID from the enter_id function, and then it enters a do/while
               loop that will prompt for the password. A counter will track the amount of attempts, and if 3 fails occur
               the program will error and exit. The function will also print out the user info at the end if successful.
**Parameters: wizard * db, ifstream &f, int *user_num, int is_stud
**Pre-Condition: wizard * db, ifstream &f, int *user_num, int is_stud
**Post-Conditions: Everything
************************************************************************************/
void overall_login(wizard * db, ifstream &f, int *user_num) {
  bool pass;
  string idnumber;
  string password;
  int index = 0;
  int num_wizards;
  f >> num_wizards;
  db = get_info(f, num_wizards);
  *user_num = enter_id(db, f, idnumber, num_wizards);
  do{  
    cout << "Enter Password: ";
    getline(cin, password);
    cout << endl;
    for(int i = 0; i < num_wizards; i++){  
          if(password == db[i].password){
            pass = true;
            break;
          }
    }
    if(index < 2 && pass == false){
      cout << "Error! Your password is incorrect!" << endl;
      index++;
    }
    else if(index == 2){
      cout << "Oh no! You've entered an incorrect password 3 times and are thus BANISHED!";
      exit(0);
    }
   }while(pass == false); 
   print_user_info(db, *user_num);
   cout << endl;
}   

/***********************************************************************************
**Function: spellbook* get_info_spells
**Description: Takes the information from the spellbook.txt file and writes it to the spellbook struct array.
               This function also calculates the average success of the spells in each book for later.
**Parameters: ifstream &f2, int num_spellbook, bool is_not_valid
**Pre-Condition: ifstream &f2, int num_spellbook, bool is_not_valid
**Post-Conditions: Everything
************************************************************************************/
spellbook* get_info_spells(ifstream &f2, int num_spellbook){
  string temp_str;
  int counter = 0;
  if (!f2.is_open()){
     cout << "File doesn't exist! Create an input.txt file!" << endl;
     exit(0);
  }
  
  spellbook* spellbooks = create_spellbooks(num_spellbook);
      for (int i = 0; i < num_spellbook; i++){
          f2 >> spellbooks[i].title >> spellbooks[i].author >> spellbooks[i].num_pages >> spellbooks[i].edition >> spellbooks[i].num_spells;
          getline(f2, temp_str);
          spellbooks[i].s = new spell[spellbooks[i].num_spells];
          for(int j = 0; j < spellbooks[i].num_spells; j++){
            f2 >> spellbooks[i].s[j].name >> spellbooks[i].s[j].success_rate  >> spellbooks[i].s[j].effect;
            counter += spellbooks[i].s[j].success_rate;
            getline(f2, temp_str);
             
           }
        
        spellbooks[i].avg_success_rate = (float) counter/ (float) spellbooks[i].num_spells;
        counter = 0;
        }
    return spellbooks;
}

/***********************************************************************************
**Function: spell* get_spellbook_spells
**Description: Struct array that sets the spells to be able to be read from within the spellbook struct.
**Parameters: spellbook* spellbooks, int num_spellbook, int *spell_total
**Pre-Condition: spellbook* spellbooks, int num_spellbook, int *spell_total
**Post-Conditions: Everything
************************************************************************************/
spell* get_spellbook_spells(spellbook* spellbooks, int num_spellbook, int *spell_total){
  *spell_total = 0;
  spell* temp;
  for(int i = 0; i < num_spellbook; i++){
    *spell_total += spellbooks[i].num_spells;
  }
  temp = new spell[*spell_total];
  *spell_total = 0;
  for(int i = 0; i < num_spellbook; i++){
    for(int j = 0; j < spellbooks[i].num_spells; j++){
      temp[j + *spell_total] = spellbooks[i].s[j];
    }
    *spell_total += spellbooks[i].num_spells;
  }
  return temp;
}      

/***********************************************************************************
**Function: spell* get_info_spell_db
**Description: Creates an array to put the information from the spells struct.
**Parameters: ifstream &f2, int num_spells
**Pre-Condition: ifstream &f2, int num_spells
**Post-Conditions: Everything
************************************************************************************/
spell* get_info_spell_db(ifstream &f2, int num_spells){
  string temp_str;
  if (!f2.is_open()){
     cout << "File doesn't exist! Create an input.txt file!" << endl;
     exit(0);
  }
  
  spell* spells = create_spells(num_spells);
  
  for (int i = 0; i < num_spells; i++){
      f2 >> spells[i].name >> spells[i].success_rate >> spells[i].effect;
      getline(f2, temp_str);
      //cout << spells[i].name << spells[i].success_rate << spells[i].effect << endl;
   }
   delete[] spells;
   return spells;
   
}

/***********************************************************************************
**Function: effect_value
**Description: Gives values to all spell effects in order to sort them.
**Parameters: string value
**Pre-Condition: string value
**Post-Conditions: Everything
************************************************************************************/
int effect_value(string value){
    if(value == "bubble")
      return 1;
    else if(value == "memory_loss")
      return 2;
    else if(value == "fire")
      return 3;
    else if(value == "poison")
      return 4;
    else
      return 5;
}
 
/***********************************************************************************
**Function: print_pages
**Description: prints the sorted spellbook data by number of pages to a desired file output.
**Parameters: spellbook* spellbooks, int num_spellbook, spell* spells, ifstream &f2
**Pre-Condition: spellbook* spellbooks, int num_spellbook, spell* spells, ifstream &f2
**Post-Conditions: Everything
************************************************************************************/
void print_pages(spellbook* spellbooks, int num_spellbook, spell* spells, ifstream &f2){
  ofstream fout;
  string name2;
  cout << "Name your output file: ";
  getline(cin, name2);
  fout.open(name2.c_str());
  if(!fout.is_open()){
    cout << "File not open" << endl;
    exit(0);
  }
  for(int i =0; i < num_spellbook; i++){
      cout << spellbooks[i].title << " " << spellbooks[i].num_pages << endl;
  }

  fout << endl;
  fout.close();
  delete[] spellbooks;
}

/***********************************************************************************
**Function: print_avg_spell
**Description: prints the sorted spellbook data by avg. success rate of spells to a desired file output.
**Parameters: spellbook* spellbooks, int num_spellbook, ifstream &f2
**Pre-Condition: spellbook* spellbooks, int num_spellbook, ifstream &f2
**Post-Conditions: Everything
************************************************************************************/
void print_avg_spell(spellbook* spellbooks, int num_spellbook, ifstream &f2){
  ofstream fout;
  string name;
  cout << "Name your output file: ";
  getline(cin, name);
  fout.open(name.c_str());
  if(!fout.is_open()){
    cout << "File not open" << endl;
    exit(0);
  }
  for (int i = 0; i < num_spellbook; i++){
    fout << spellbooks[i].title << " " << spellbooks[i].avg_success_rate << endl;
  }
  fout << endl;
  fout.close();
  delete[] spellbooks;
}

/***********************************************************************************
**Function: print_spell_effect
**Description: prints the sorted spellbook data by avg. success rate of spells to a desired file output.
**Parameters: spellbook* spellbooks, spell* spells, int num_spellbook, int num_spells, ifstream &f2
**Pre-Condition: spellbook* spellbooks, spell* spells, int num_spellbook, int num_spells, ifstream &f2
**Post-Conditions: Everything
************************************************************************************/
void print_spell_effect(spellbook* spellbooks, spell* spells, int num_spellbook, int num_spells, ifstream &f2){
  ofstream fout;
  string name;
  cout << "Name your output file: ";
  getline(cin, name);
  fout.open(name.c_str());
  if(!fout.is_open()){
    cout << "File not open" << endl;
    exit(0);
  }
  for(int i = 0; i < num_spellbook; i++){
    for(int j = 0; j < spellbooks[i].num_spells; j++){
      fout << spellbooks[i].s[j].name << " " << spellbooks[i].s[j].effect << endl;
    }
  }
  fout << endl;
  fout.close();
  delete[] spells;
}

/***********************************************************************************
**Function: print_to_screen_pages
**Description: prints to the screen the information from the spellbook in order of number of pages.
**Parameters: spellbook* spellbooks, int num_spellbook, ifstream &f2
**Pre-Condition: spellbook* spellbooks, int num_spellbook, ifstream &f2
**Post-Conditions: Everything
************************************************************************************/
void print_to_screen_pages(spellbook* spellbooks, int num_spellbook, ifstream &f2){
  for(int i =0; i < num_spellbook; i++){
      cout << spellbooks[i].title << " " << spellbooks[i].num_pages << endl;
  }
}

/***********************************************************************************
**Function: print_to_screen_spells
**Description: prints to the screen the information from the spellbook in order of avg. success rate.
**Parameters: spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2
**Pre-Condition: spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2
**Post-Conditions: Everything
************************************************************************************/
void print_to_screen_spells(spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2){
  for(int i =0; i < num_spellbook; i++){
      cout << spellbooks[i].title << " " << spellbooks[i].avg_success_rate << endl;
  }
}

/***********************************************************************************
**Function: print_to_screen_spell_effect
**Description: prints to the screen the information from the spellbook in order of spell effect.
**Parameters: spell* spells, int num_spells, ifstream &f2
**Pre-Condition: spell* spells, int num_spells, ifstream &f2
**Post-Conditions: Everything
************************************************************************************/
void print_to_screen_spell_effect(spell* spells, int num_spells, ifstream &f2){
  for(int i =0; i < num_spells; i++){
      cout << spells[i].name << " " << spells[i].effect << endl;
  }
}

/***********************************************************************************
**Function: sort_pages_screen
**Description: Sorts the books by number of pages and prints it out
**Parameters: spellbook* spellbooks, int num_spellbook, ifstream &f2, spell* spells, int num_spells, int is_stud
**Pre-Condition: spellbook* spellbooks, int num_spellbook, ifstream &f2, spell* spells, int num_spells, int is_stud
**Post-Conditions: Everything
************************************************************************************/
void sort_pages_screen(spellbook* spellbooks, int num_spellbook, ifstream &f2, spell* spells, int num_spells){
    for(int i=0; i<num_spellbook-1; i++){
      for(int j=0; j<num_spellbook-1; j++){
        if(spellbooks[j].num_pages > spellbooks[j+1].num_pages){
	        spellbook temp = spellbooks[j];
	        spellbooks[j] = spellbooks[j+1];
	        spellbooks[j+1] = temp;
	      }
      }
   }
     print_to_screen_pages(spellbooks, num_spellbook, f2);
}

/***********************************************************************************
**Function: sort_spell_screen
**Description: Sorts the books by avg. success rate and prints it out
**Parameters: spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2, int is_stud
**Pre-Condition: spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2, int is_stud
**Post-Conditions: Everything
************************************************************************************/
void sort_spell_screen(spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2){
    for(int i=0; i<num_spellbook-1; i++){
      for(int j=0; j<num_spellbook-1; j++){
        if(spellbooks[j].avg_success_rate > spellbooks[j+1].avg_success_rate){
	        spellbook temp = spellbooks[j];
	        spellbooks[j] = spellbooks[j+1];
          spellbooks[j+1] = temp;
	      }
      }
   }
     print_to_screen_spells(spellbooks, num_spellbook, spells, num_spells, f2);
}

/***********************************************************************************
**Function: sort_pages
**Description: Sorts the books by number of pages and prints it out to a file.
**Parameters: spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2, int is_stud
**Pre-Condition: spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2, int is_stud
**Post-Conditions: Everything
************************************************************************************/
void sort_pages(spellbook* spellbooks, int num_spellbook, spell* spells, ifstream &f2){
    for(int i=0; i<num_spellbook-1; i++){
      for(int j=0; j<num_spellbook-1; j++){
        if(spellbooks[j].num_pages > spellbooks[j+1].num_pages){
	        spellbook temp = spellbooks[j];
	        spellbooks[j] = spellbooks[j+1];
	        spellbooks[j+1] = temp;
	      }
      }
   }
     print_pages(spellbooks, num_spellbook, spells, f2);
}

/***********************************************************************************
**Function: sort_spell
**Description: Sorts the books by avg. success rate and prints it out to a file.
**Parameters: spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2, int is_stud
**Pre-Condition: spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2, int is_stud
**Post-Conditions: Everything
************************************************************************************/
void sort_spell(spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2){
    for(int i=0; i<num_spellbook-1; i++){
      for(int j=0; j<num_spellbook-1; j++){
        if(spellbooks[j].avg_success_rate > spellbooks[j+1].avg_success_rate){
	        spellbook temp = spellbooks[j];
	        spellbooks[j] = spellbooks[j+1];
	        spellbooks[j+1] = temp;
	      }
      }
   }
     print_avg_spell(spellbooks, num_spellbook, f2);
}

/***********************************************************************************
**Function: sort_spell_effect
**Description: Sorts the books by spell effect and prints it out to the screen
**Parameters: spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2, int is_stud
**Pre-Condition: spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2, int is_stud
**Post-Conditions: Everything
************************************************************************************/
void sort_spell_effect_screen(spell* spells, int num_spells, ifstream &f2){
    for(int i = 0; i < num_spells - 1; i++){
      for(int j = 0; j < num_spells - 1; j++){
        if(effect_value(spells[j].effect) > effect_value(spells[j+1].effect)){
	        spell temp = spells[j];
	        spells[j] = spells[j+1];
	        spells[j+1] = temp;
	      }
      }
   }
     print_to_screen_spell_effect(spells, num_spells, f2);
}

/***********************************************************************************
**Function: sort_spell_effect_file
**Description: Sorts the books spell effect and prints it out to a file
**Parameters: spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2, int is_stud
**Pre-Condition: spellbook* spellbooks, int num_spellbook, spell* spells, int num_spells, ifstream &f2, int is_stud
**Post-Conditions: Everything
************************************************************************************/
void sort_spell_effect_file(spellbook* spellbooks, spell* spells, int num_spellbook, int num_spells, ifstream &f2){
    for(int i = 0; i < num_spells - 1; i++){
      for(int j = 0; j < num_spells - 1; j++){
        if(effect_value(spells[j].effect) > effect_value(spells[j+1].effect)){
	        spell temp = spells[j];
	        spells[j] = spells[j+1];
	        spells[j+1] = temp;
	      }
      }
   }
     print_spell_effect(spellbooks, spells, num_spellbook, num_spells, f2);
}

/***********************************************************************************
**Function: get_spellbook_data
**Description: Overall function that the user uses to tell the program what it wants to sort and how it wants it sorted.
**Parameters: spellbook* spellbooks, spell* spells, int num_spells, int num_spellbook, ifstream &f2, int *spell_total, wizard* wizards, int user_num, int is_stud
**Pre-Condition: spellbook* spellbooks, spell* spells, int num_spells, int num_spellbook, ifstream &f2, int *spell_total, wizard* wizards, int user_num, int is_stud
**Post-Conditions: Everything
************************************************************************************/
void get_spellbook_data(spellbook* spellbooks, spell* spells, int num_spells, int num_spellbook, ifstream &f2, int *spell_total, wizard* wizards, int user_num){
  bool loop;
  string choice;
  string print_choice;
  spellbooks = get_info_spells(f2, num_spellbook);
  spells = get_spellbook_spells(spellbooks, num_spellbook, spell_total);
  do{
    cout << "Which option would you like to choose to sort spellbooks by:\nnumber of pages (Press 1):\nGroup spells by their effect (Press 2):\nSort spellbooks by average success rate (Press 3):\nQuit (Press 4): " << endl;
    getline(cin, choice);
    cout << "How would you like the information displayed?\nPrint to screen (Press 1):\nPrint to File (Press 2): " << endl;
    getline(cin, print_choice);
    if(stoi(print_choice) == 1 && stoi(choice) == 1){
      sort_pages_screen(spellbooks, num_spellbook, f2, spells, num_spells);
      cout << endl;
    }
    else if(stoi(print_choice) == 1 && stoi(choice) == 2){
      sort_spell_effect_screen(spells, *spell_total , f2);
      cout << endl;
    }
    else if(stoi(print_choice) == 1 && stoi(choice) == 3){
      sort_spell_screen(spellbooks, num_spellbook, spells, num_spells, f2);
      cout << endl;
    }
    else if(stoi(print_choice) == 2 && stoi(choice) == 1){
      sort_pages(spellbooks, num_spellbook, spells, f2);
      cout << endl;
    }
    else if(stoi(print_choice) == 2 && stoi(choice) == 2){
      sort_spell_effect_file(spellbooks, spells, num_spellbook, num_spells, f2);
      cout << endl;
    }
    else if(stoi(print_choice) == 2 && stoi(choice) == 3){
      sort_spell(spellbooks, num_spellbook, spells, num_spells, f2);
      cout << endl;
    }
    else if(stoi(choice) == 4)
      exit(0);
    else
      cout << "Enter a valid input!" << endl;
      cout << endl;
  }while (loop == false);
  delete[] spellbooks;
  delete[] spells;
}

/***********************************************************************************
**Function: delete_info
**Description: Deletes memory.
**Parameters: wizard * db, spellbook * books, spell* spells, int num_spellbook
**Pre-Condition: wizard * db, spellbook * books, spell* spells, int num_spellbook
**Post-Conditions: Everything
************************************************************************************/
void delete_info(wizard * db, spellbook * books, spell* spells, int num_spellbook){
  
    delete[] db;
    
    for(int i = 0; i < num_spellbook; i++){
      delete[] books[i].s;
    }
    delete[] books;
    delete[] spells;
    db = NULL;
    books = NULL;
    spells = NULL;
}