/*
Program: 21 (Blackjack Boiiiiiii)

Name: Comrade

Date: 02/03/19

Input: Amount of users, amount of money, 1 or 2,

Output: card amount after turn, money amount after turn

Description: User and up to 3 other players will play against the dealer in a game of 21. The goal of the game is to have cards that add up to being close or exactly 21 while being closer to 21 than the other players and the dealer. Money is betted to see who would win, and that money is distributed to whoever wins.
*/


#include <iostream>
#include <stdlib.h>
#include <string>    //So many public libraries that the right wing would call this program a socialist system.
#include <ctime>
#include <cstdlib>

using namespace std;

void dealerbust(){
  cout<<"Yeet! The Dealer busted!"<<endl;
}

void dealerwin(){
  cout<<"Oh No! The Dealer beat all players!"<<endl;
}

void dealerdraw(){
  cout<<"The Dealer draws another card"<<endl;
}

bool input_is_valid(string s){  //This boolean is meant to be the error handler.
  
   
    for(int x = 0; x < s.size(); x++){  //This bool uses a check feature, by checking int size, to deduce if there are characters between 0-9.//
      if(!(s.at(x)>= '0' && s.at(x)<= '9')){ //If there are no characters between 0-9, the program will print an error message and prompt the user to reenter.//
        cout<<"Error!"<<endl<<endl;
     
        return false;
      }
      
    }  
    
    return true;

}

int main(){
  
srand(time(NULL));
  
int card;
  
int x;
  
int money;

int money2;

int money3;

int money4;
                        //Just a metric crap-ton of variables for you to feast your eyes upon.//


string s;
  
bool bet = true;  
  

  cout<<"Welcome to 21! The objective of the game is to have numbers that equal the closest to 21 than anyone else. \n each player will be given two cards initially, and then the player will be prompted to draw another card or move on. \n If any player goes above 21, then the player will bust and automatically lose their bet. \n good luck! \n How many players do you want to play? 1 - 4: "<<endl<<endl;
  
  getline(cin, s);
  while (!input_is_valid(s)){
    cout<<"Error! Re-enter a valid input"<<endl; //This uses the previous error function and tests it in a loop. This way th user will be repromted until they enter a correct       
                                                 //character
    getline(cin, s);
  }
  
  //This is where only 1 player plays against the Dealer.//
  
  if (s == "1"){
      cout<<"How much money do you want to start with? "<<endl;
      getline(cin, s);
      while (!input_is_valid(s)){
        cout<<"Error! Re-enter a valid input"<<endl;
        getline(cin, s);
      }
    cout<<"You have "<< s <<" dollars"<<endl;
  
    money = atoi(s.c_str());

    while(bet){
      if(money<=0){
        cout<<"You're out of money!"<<endl;
        exit(0);
        }
      else{
        int p1sum = 0;
        int dsum = 0;
        cout<<"How much money do you wish to bet?: "<<endl;
        cout<<"You have "<< money << " dollars left"<<endl;
        getline(cin, s);
        while (!input_is_valid(s)){
          cout<<"Error! Re-enter a valid input"<<endl;
          getline(cin, s);
        }
        int betmoney = atoi(s.c_str());
        if(atoi(s.c_str())<=money){      //This sets the value of the money/betmoney for each character, and it compares it to the actual money so you don't go over.
          
          cout<<"You've bet: " << money <<endl;
          cout<<"The dealer will now deal your cards."<<endl<<endl;
          cout<<"Card 1: ";
          card = 1 + rand()%11;  
          cout<<card<<endl;
          p1sum += card;
          cout<<"Card 2: ";      //This draws cards and adds them to the player sum
          card = 1 + rand()%11;  
          cout<<card<<endl;
          p1sum += card;
          cout<<p1sum<<endl;
          if(p1sum>21){
            cout<<"You've busted!"<<endl;
          }
          else{
            while(true){
              cout<<"get dealed another card? 1 - yes 2 - no"<<endl;
              getline(cin, s);
              while (!input_is_valid(s)){
                cout<<"Error! Re-enter a valid input"<<endl;
                getline(cin, s);
                }
              if (s == "1"){
                
                cout<<"Card: "<<endl;
                card = 1 + rand()%11;
                cout<<card<<endl;
                p1sum += card;
                cout<<p1sum<<endl;
                if(p1sum>21){
                  cout<<"Oi! You've busted!"<<endl;
                  money -= betmoney;
                  break;
                }
              
              }                
    
              else if(s == "2"){
                cout<<"The Dealer will now deal their own cards"<<endl;
                card= 1 + rand()%11;
                cout<<card<<endl;
                dsum += card; 
                card= 1 + rand()%11;
                cout<<card<<endl;
                dsum += card;
                while(true){
                  if(dsum>p1sum && dsum<21 || dsum==21){
                    dealerwin();           //These functions for the Dealer act as predefined functions to describe the action of the dealer depending on the scenario.
                    money -= betmoney;
                    break;
                    }
                  else if(dsum>21){
                    dealerbust();
                    money += betmoney*2;
                    break;
                    }
                  else{
                    
                    dealerdraw(); 
                    card= 1 + rand()%11;
                    cout<<card<<endl;
                    dsum += card;
                  }
                }
              break;
              }
            }
          }                                //Why don't we get taught ARRAYS SOONER I HATE MY LIFE.
        }
      }
    }
  }
  
  //This is where 2 players will play concurrently.//
  
  /*  If you read the beginnings of most lines, you can mostly understand what is happening. It's mostly made of prints, random number generators, and adding and subtracting.
  It shouldn't be too hard to figure out. The system for the different player amounts are exactly the same as the player 1 system just with an extra player 1 (accurately named
  after the player at that point). 
  */
  
  if (s=="2"){
      cout<<"How much money do you want all players to start with? 1 - 1000: "<<endl;
      getline(cin, s);
      while (!input_is_valid(s)){
        cout<<"Error! Re-enter a valid input"<<endl;
        getline(cin, s);
      }
    cout<<"You all have "<< s <<" dollars"<<endl;
  
    money = atoi(s.c_str());
    money2 = atoi(s.c_str()); //Anything with the "2" "3" or "4" in the future from here will denote the players.
    while(bet){
      if(money<=0){
        cout<<"You're out of money!"<<endl;
        exit(0);
        }                                    //These actions check the money of the players to make sure they still have money to bet
      else if(money2<=0){
        cout<<"You're out of money!"<<endl;
        exit(0);
        }
      else{
        int p1sum = 0;
        int p2sum = 0;    //Massive sums boi. Collects the total amount of cards each player has.
        int dsum = 0;
        cout<<"How much money do you wish to bet?: "<<endl;
        cout<<"You have "<< money << " dollars left"<<endl;
        getline(cin, s);
        while (!input_is_valid(s)){
          cout<<"Error! Re-enter a valid input"<<endl;
          getline(cin, s);
        }
        int betmoney = atoi(s.c_str());    //Collects the cin as a string that will be converted at this point.

        if(atoi(s.c_str())<=money){  //Calls the string
          
          cout<<"You've bet: " << money <<endl;
          cout<<"The dealer will now deal your cards."<<endl<<endl;
          cout<<"Card 1: ";
          card= 1 + rand()%11;
          cout<<card<<endl;
          p1sum += card;
          cout<<"Card 2: ";
          card= 1 + rand()%11;
          cout<<card<<endl;
          p1sum += card;
          cout<<p1sum<<endl;
          while(true){
            cout<<"get dealed another card? 1 - yes 2 - no"<<endl;
            getline(cin, s);
            while (!input_is_valid(s)){
              cout<<"Error! Re-enter a valid input"<<endl;
              getline(cin, s);
              }
            if (s == "1"){
              if(p1sum>21){
                cout<<"You've busted, relinquish your turn."<<endl;
              }
              else{
                cout<<"Card: "<<endl;
                card= 1 + rand()%11;
                cout<<card<<endl;
                p1sum += card;
                cout<<p1sum<<endl;
                if(p1sum>21){
                  cout<<"Oi! You've busted!"<<endl;
                  money -= betmoney;
                        
                }
              }
            }             
  
            else if(s == "2"){
              cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl; //So you can't cheat you dirty cheater you
              cout<<"Player 2 will now be dealt cards"<<endl;
              cout<<"How much money do you wish to bet?: "<<endl;
              cout<<"You have "<< money2 << " dollars left"<<endl;
              getline(cin, s);
              while (!input_is_valid(s)){
                cout<<"Error! Re-enter a valid input"<<endl;
                getline(cin, s);
              }
              int betmoney2 = atoi(s.c_str());
              if(atoi(s.c_str())<=money2){  
                
                cout<<"You've bet: " << money2 <<endl;
                cout<<"The dealer will now deal player 1's cards."<<endl<<endl;
                cout<<"Card 1: ";
                card= 1 + rand()%11;
                cout<<card<<endl;
                p2sum += card;
                cout<<"Card 2: ";
                card= 1 + rand()%11;
                cout<<card<<endl;
                p2sum += card;
                cout<<p2sum<<endl;
                while(true){
                  cout<<"get dealed another card? 1 - yes 2 - no"<<endl;
                  getline(cin, s);
                  while (!input_is_valid(s)){
                    cout<<"Error! Re-enter a valid input"<<endl;
                    getline(cin, s);
                    }
                  if(s == "1"){
                    if(p2sum>21){
                      cout<<"You've busted, relinquish your turn."<<endl;
                    }
                    else{
                      cout<<"Card: "<<endl;
                      card= 1 + rand()%11;
                      cout<<card<<endl;
                      p2sum += card;
                      cout<<p2sum<<endl;
                      if(p2sum>21){
                        cout<<"Oi! You've busted!"<<endl;
                        money -= betmoney;
                        
                      }
                  }
                  }
                  else if(s == "2"){
                    cout<<"The Dealer will now deal their own cards"<<endl;
                    card= 1 + rand()%11;
                    cout<<card<<endl;
                    dsum += card;
                    card= 1 + rand()%11; 
                    cout<<card<<endl;
                    dsum += card;
                    while(true){
                      if(dsum>p1sum && dsum>p2sum && dsum<21 || dsum==21){
                        dealerwin();
                        money -= betmoney;
                        money2 -= betmoney2;
                        break;
                        }
                      else if(dsum>21 && p1sum>p2sum && p1sum<=21){            //MASSIVE F-ING LOOPS WITH SO MANY STATEMENTS BECAUSE UGGGGGGGGGGGGHHHHHHHHH
                        dealerbust();
                        cout<<"Player 1 wins"<<endl;
                        money += betmoney*2;
                        money += betmoney2;
                        money2 -= betmoney2;
                        break;
                        }
                      else if(dsum>21 && p2sum>p1sum && p2sum<=21){
                        dealerbust();
                        cout<<"Player 2 wins!"<<endl;
                        money2 += betmoney2*2;
                        money2 += betmoney;
                        money -= betmoney;
                        break;
                        }
                      else if(dsum>p1sum && p2sum>dsum && p2sum<=21){
                        cout<<"Player 2 wins!"<<endl;
                        money2 += betmoney2;
                        money -= betmoney;
                        break;
                            }
                      else if(dsum>p2sum && p1sum>dsum && p1sum<=21){
                        cout<<"Player 1 wins!"<<endl;
                        money2 += betmoney2;
                        money -= betmoney;
                        break;
                            }
                      else if(dsum>21){
                        dealerbust();
                        money += betmoney;
                        money2 += betmoney2;
                        break;
                      }
                      else{
                            
                        dealerdraw();
                        card= 1 + rand()%11; 
                        cout<<card<<endl;
                        dsum += card;
                      }
                    }
                  break;
                  }
                }
              break;
              }
            }
          }
        }
      }
    }
  }
  
  //This is where you will play with 3 players concurrently.//
  
  if(s=="3"){
    cout<<"How much money do you want all players to start with? 1 - 1000: "<<endl;
    getline(cin, s);
    while (!input_is_valid(s)){
      cout<<"Error! Re-enter a valid input"<<endl;
      getline(cin, s);
      }
    cout<<"You all have "<< s <<" dollars"<<endl;
  
    money = atoi(s.c_str());
    money2 = atoi(s.c_str());
    money3 = atoi(s.c_str());
    while(bet){
      if(money<=0){
        cout<<"You're out of money!"<<endl;
        exit(0);
        }
      else if(money2<=0){
        cout<<"You're out of money!"<<endl;
        exit(0);
        }
      else if(money3<=0){
        cout<<"You're out of money!"<<endl;
        exit(0);
        }
      else{
        int p1sum = 0;
        int p2sum = 0;
        int p3sum = 0;
        int dsum = 0;
        cout<<"How much money does player 1 wish to bet?: "<<endl;
        cout<<"You have "<< money << " dollars left"<<endl;
        getline(cin, s);
        while (!input_is_valid(s)){
          cout<<"Error! Re-enter a valid input"<<endl;
          getline(cin, s);
        }
        int betmoney = atoi(s.c_str());

        if(atoi(s.c_str())<=money){  
          
          cout<<"You've bet: " << money <<endl;
          cout<<"The dealer will now deal Player 1's cards."<<endl<<endl;
          cout<<"Card 1: ";
          card= 1 + rand()%11;
          cout<<card<<endl;
          p1sum += card;
          cout<<"Card 2: ";
          card= 1 + rand()%11;
          cout<<card<<endl;
          p1sum += card;
          cout<<p1sum<<endl;
          while(true){
            cout<<"get dealed another card? 1 - yes 2 - no"<<endl;
            getline(cin, s);
            while (!input_is_valid(s)){
              cout<<"Error! Re-enter a valid input"<<endl;
              getline(cin, s);
              }
            if (s == "1"){
              if(p1sum>21){
                cout<<"You've busted, relinquish your turn."<<endl;
              }
              else{
                cout<<"Card: "<<endl;
                card= 1 + rand()%11;
                cout<<card<<endl;
                p1sum += card;
                cout<<p1sum<<endl;
                if(p1sum>21){
                  cout<<"Oi! You've busted!"<<endl;
                  money -= betmoney;
                        
                }
              }
            }             
  
            else if(s == "2"){
              cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
              cout<<"Player 2 will now be dealt cards"<<endl;
              cout<<"How much money do you wish to bet?: "<<endl;
              cout<<"You have "<< money2 << " dollars left"<<endl;
              getline(cin, s);
              while (!input_is_valid(s)){
                cout<<"Error! Re-enter a valid input"<<endl;
                getline(cin, s);
              }
              int betmoney2 = atoi(s.c_str());
              if(atoi(s.c_str())<=money2){  
                
                cout<<"You've bet: " << money2 <<endl;
                cout<<"The dealer will now deal your cards."<<endl<<endl;
                cout<<"Card 1: ";
                card= 1 + rand()%11;
                cout<<card<<endl;
                cout<<"Card 2: ";
                p2sum += card;
                card= 1 + rand()%11;
                cout<<card<<endl;
                p2sum += card;
                cout<<p2sum<<endl;
                while(true){
                  cout<<"get dealed another card? 1 - yes 2 - no"<<endl;
                  getline(cin, s);
                  while (!input_is_valid(s)){
                    cout<<"Error! Re-enter a valid input"<<endl;
                    getline(cin, s);
                    }
                  if(s == "1"){
                    if(p2sum>21){
                      cout<<"You've busted, relinquish your turn."<<endl;
                    }
                    else{
                      cout<<"Card: "<<endl;
                      card= 1 + rand()%11;
                      cout<<card<<endl;
                      p2sum += card;
                      cout<<p2sum<<endl;
                      if(p2sum>21){
                        cout<<"Oi! You've busted!"<<endl;
                        money -= betmoney;
                        
                      }
                  }
                  }
                  else if(s == "2"){
                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
                    cout<<"Player 3 will now be dealt cards"<<endl;
                    cout<<"How much money do you wish to bet?: "<<endl;
                    cout<<"You have "<< money3 << " dollars left"<<endl;
                    getline(cin, s);
                    while (!input_is_valid(s)){
                      cout<<"Error! Re-enter a valid input"<<endl;
                      getline(cin, s);
                    }
                    int betmoney3 = atoi(s.c_str());
                    if(atoi(s.c_str())<=money3){  
                      
                      cout<<"You've bet: " << money3 <<endl;
                      cout<<"The dealer will now deal your cards."<<endl<<endl;
                      cout<<"Card 1: ";
                      card= 1 + rand()%11;
                      cout<<card<<endl;
                      cout<<"Card 2: ";
                      p3sum += card;
                      card= 1 + rand()%11;
                      cout<<card<<endl;
                      p3sum += card;
                      cout<<p3sum<<endl;
                      while(true){
                        cout<<"get dealed another card? 1 - yes 2 - no"<<endl;
                        getline(cin, s);
                        while (!input_is_valid(s)){
                          cout<<"Error! Re-enter a valid input"<<endl;
                          getline(cin, s);
                          }
                        if(s == "1"){
                          if(p3sum>21){
                            cout<<"You've busted, relinquish your turn."<<endl;
                          }
                          else{
                            cout<<"Card: "<<endl;
                            card= 1 + rand()%11;
                            cout<<card<<endl;
                            p3sum += card;
                            cout<<p3sum<<endl;
                            if(p3sum>21){
                              cout<<"Oi! You've busted!"<<endl;
                              money3 -= betmoney3;
                              
                            }
                        }
                        }
                        else if(s=="2"){
                          cout<<"The Dealer will now deal their own cards"<<endl;
                          card= 1 + rand()%11;
                          cout<<card<<endl;
                          dsum += card;
                          card= 1 + rand()%11; 
                          cout<<card<<endl;
                          dsum += card;
                          while(true){
                            if(dsum>p1sum && dsum>p2sum && dsum>p3sum && dsum<21 || dsum==21){
                              dealerwin();
                              money -= betmoney;
                              money2 -= betmoney2;
                              money3 -= betmoney3;
                              break;
                              }
                            else if(dsum>21 && p1sum>p2sum && p1sum>p3sum && p1sum<=21){
                              dealerbust();
                              cout<<"Player 1 wins"<<endl;
                              money += betmoney;
                              money += betmoney2;
                              money += betmoney3;
                              money2 -= betmoney2;
                              money3 -= betmoney3;
                              break;
                              }
                            else if(dsum>21 && p2sum>p1sum && p2sum>p3sum && p2sum<=21){
                              dealerbust();
                              cout<<"Player 2 wins!"<<endl;
                              money2 += betmoney2;
                              money2 += betmoney;
                              money2 += betmoney3;
                              money -= betmoney;
                              money3 -=betmoney3;
                              break;
                              }
                            else if(dsum>p1sum && p2sum>dsum && p2sum>p3sum && p2sum<=21){ //p3sum>p2sum && p3sum>dsum && && p3sum>p1sum && p3sum<=21
                              cout<<"Player 2 wins!"<<endl;
                              money2 += betmoney2;
                              money2 += betmoney;
                              money2 += betmoney3;
                              money -= betmoney;
                              money3 -=betmoney3;
                              break;
                              }
                            else if(dsum>p2sum && p1sum>dsum && p1sum>p3sum && p1sum<=21){ //p3sum>p2sum && p3sum>dsum && && p3sum>p1sum && p3sum<=21
                              cout<<"Player 1 wins!"<<endl;
                              money += betmoney;
                              money += betmoney2;
                              money += betmoney3;
                              money2 -= betmoney2;
                              money3 -= betmoney3;
                              break;
                              }
                            else if(dsum>21){
                              dealerbust();
                              money += betmoney;
                              money2 += betmoney2;
                              money3 += betmoney3;
                              break;
                              }
                            else if(p3sum>p2sum && p3sum>dsum && p3sum>p1sum && p3sum<=21){
                              cout<<"Player 3 wins!"<<endl;
                              money += betmoney;
                              money += betmoney2;
                              money += betmoney3;
                              money2 -= betmoney2;
                              money3 -= betmoney3;
                              break;
                              }
                            else if(dsum>p2sum && p1sum>dsum && p3sum>p1sum && p1sum<=21){ //p3sum>p2sum && p3sum>dsum && && p3sum>p1sum && p3sum<=21
                              cout<<"Player 3 wins!"<<endl;
                              money += betmoney;
                              money += betmoney2;
                              money += betmoney3;
                              money2 -= betmoney2;
                              money3 -= betmoney3;
                              break;
                              }
                            else if(dsum>p1sum && p2sum>dsum && p3sum>p2sum && p1sum<=21){ //p3sum>p2sum && p3sum>dsum && && p3sum>p1sum && p3sum<=21
                              cout<<"Player 3 wins!"<<endl;
                              money += betmoney;
                              money += betmoney2;
                              money += betmoney3;
                              money2 -= betmoney2;
                              money3 -= betmoney3;
                              break;
                              }
                            
                            else{
                                  
                              dealerdraw();
                              card= 1 + rand()%11; 
                              cout<<card<<endl;
                              dsum += card;
                              }
                              }
                            break;
                            }
                          }
                        break;
                      }
                  }
                }
              break;
              }
            }
          }
         }
        }
       } 
      }  
  
    if(s=="4"){
      cout<<"How much money do you want all players to start with? 1 - 1000: "<<endl;
      getline(cin, s);
      while (!input_is_valid(s)){
        cout<<"Error! Re-enter a valid input"<<endl;
        getline(cin, s);
        }
      cout<<"You all have "<< s <<" dollars"<<endl;
    
      money = atoi(s.c_str());
      money2 = atoi(s.c_str());
      money3 = atoi(s.c_str());
      money4 = atoi(s.c_str());
      while(bet){
        if(money<=0){
          cout<<"You're out of money!"<<endl;
          exit(0);
          }
        else if(money2<=0){
          cout<<"You're out of money!"<<endl;
          exit(0);
          }
        else if(money3<=0){
          cout<<"You're out of money!"<<endl;
          exit(0);
          }
        else if(money4<=0){
          cout<<"You're out of money!"<<endl;
          exit(0);
          }
        else{
          int p1sum = 0;
          int p2sum = 0;
          int p3sum = 0;
          int p4sum = 0;
          int dsum = 0;
          cout<<"How much money does player 1 wish to bet?: "<<endl;
          cout<<"You have "<< money << " dollars left"<<endl;
          getline(cin, s);
          while (!input_is_valid(s)){
            cout<<"Error! Re-enter a valid input"<<endl;
            getline(cin, s);
          }
          int betmoney = atoi(s.c_str());
  
          if(atoi(s.c_str())<=money){  
            
            cout<<"You've bet: " << money <<endl;
            cout<<"The dealer will now deal Player 1's cards."<<endl<<endl;
            cout<<"Card 1: ";
            card= 1 + rand()%11;
            cout<<card<<endl;
            cout<<"Card 2: ";
            p1sum += card;
            card= 1 + rand()%11;
            cout<<card<<endl;
            p1sum += card;
            cout<<p1sum<<endl;
            while(true){
              cout<<"get dealed another card? 1 - yes 2 - no"<<endl;
              getline(cin, s);
              while (!input_is_valid(s)){
                cout<<"Error! Re-enter a valid input"<<endl;
                getline(cin, s);
                }
              if (s == "1"){
                if(p1sum>21){
                  cout<<"You've busted, relinquish your turn."<<endl;
                }
                else{
                  cout<<"Card: "<<endl;
                  card= 1 + rand()%11;
                  cout<<card<<endl;
                  p1sum += card;
                  cout<<p1sum<<endl;
                  if(p1sum>21){
                    cout<<"Oi! You've busted!"<<endl;
                    money -= betmoney;
                          
                  }
                }
              }             
    
              else if(s == "2"){
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
                cout<<"Player 2 will now be dealt cards"<<endl;
                cout<<"How much money do you wish to bet?: "<<endl;
                cout<<"You have "<< money2 << " dollars left"<<endl;
                getline(cin, s);
                while (!input_is_valid(s)){
                  cout<<"Error! Re-enter a valid input"<<endl;
                  getline(cin, s);
                }
                int betmoney2 = atoi(s.c_str());
                if(atoi(s.c_str())<=money2){  
                  
                  cout<<"You've bet: " << money2 <<endl;
                  cout<<"The dealer will now deal your cards."<<endl<<endl;
                  cout<<"Card 1: ";
                  card= 1 + rand()%11;
                  cout<<card<<endl;
                  p2sum += card;
                  cout<<"Card 2: ";
                  card= 1 + rand()%11;
                  cout<<card<<endl;
                  p2sum += card;
                  cout<<p2sum<<endl;
                  while(true){
                    cout<<"get dealed another card? 1 - yes 2 - no"<<endl;
                    getline(cin, s);
                    while (!input_is_valid(s)){
                      cout<<"Error! Re-enter a valid input"<<endl;
                      getline(cin, s);
                      }
                    if(s == "1"){
                      if(p2sum>21){
                        cout<<"You've busted, relinquish your turn."<<endl;
                      }
                      else{
                        cout<<"Card: "<<endl;
                        card= 1 + rand()%11;
                        cout<<card<<endl;
                        p2sum += card;
                        cout<<p2sum<<endl;
                        if(p2sum>21){
                          cout<<"Oi! You've busted!"<<endl;
                          money -= betmoney;
                          
                        }
                    }
                    }
                    else if(s == "2"){
                      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
                      cout<<"Player 3 will now be dealt cards"<<endl;
                      cout<<"How much money do you wish to bet?: "<<endl;
                      cout<<"You have "<< money3 << " dollars left"<<endl;
                      getline(cin, s);
                      while (!input_is_valid(s)){
                        cout<<"Error! Re-enter a valid input"<<endl;
                        getline(cin, s);
                      }
                      int betmoney3 = atoi(s.c_str());
                      if(atoi(s.c_str())<=money3){  
                        
                        cout<<"You've bet: " << money3 <<endl;
                        cout<<"The dealer will now deal your cards."<<endl<<endl;
                        cout<<"Card 1: ";
                        card= 1 + rand()%11;
                        cout<<card<<endl;
                        cout<<"Card 2: ";
                        p3sum += card;
                        card= 1 + rand()%11;
                        cout<<card<<endl;
                        p3sum += card;
                        cout<<p3sum<<endl;
                        while(true){
                          cout<<"get dealed another card? 1 - yes 2 - no"<<endl;
                          getline(cin, s);
                          while (!input_is_valid(s)){
                            cout<<"Error! Re-enter a valid input"<<endl;
                            getline(cin, s);
                            }
                          if(s == "1"){
                            if(p3sum>21){
                              cout<<"You've busted, relinquish your turn."<<endl;
                            }
                            else{
                              cout<<"Card: "<<endl;
                              card= 1 + rand()%11;
                              cout<<card<<endl;
                              p3sum += card;
                              cout<<p3sum<<endl;
                              if(p3sum>21){
                                cout<<"Oi! You've busted!"<<endl;
                                money3 -= betmoney3;
                                
                              }
                          }
                          }
                          else if(s == "2"){
                            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
                            cout<<"Player 4 will now be dealt cards"<<endl;
                            cout<<"How much money do you wish to bet?: "<<endl;
                            cout<<"You have "<< money4 << " dollars left"<<endl;
                            getline(cin, s);
                            while (!input_is_valid(s)){
                              cout<<"Error! Re-enter a valid input"<<endl;
                              getline(cin, s);
                            }
                            int betmoney4 = atoi(s.c_str());
                            if(atoi(s.c_str())<=money4){  
                              
                              cout<<"You've bet: " << money4 <<endl;
                              cout<<"The dealer will now deal your cards."<<endl<<endl;
                              cout<<"Card 1: ";
                              card= 1 + rand()%11;
                              cout<<card<<endl;
                              cout<<"Card 2: ";
                              p4sum += card;
                              card= 1 + rand()%11;
                              cout<<card<<endl;
                              p4sum += card;
                              cout<<p4sum<<endl;
                              while(true){
                                cout<<"get dealed another card? 1 - yes 2 - no"<<endl;
                                getline(cin, s);
                                while (!input_is_valid(s)){
                                  cout<<"Error! Re-enter a valid input"<<endl;
                                  getline(cin, s);
                                  }
                                if(s == "1"){
                                  if(p4sum>21){
                                    cout<<"You've busted, relinquish your turn."<<endl;
                                  }
                                  else{
                                    cout<<"Card: "<<endl;
                                    card= 1 + rand()%11;
                                    cout<<card<<endl;
                                    p4sum += card;
                                    cout<<p4sum<<endl;
                                    if(p4sum>21){
                                      cout<<"Oi! You've busted!"<<endl;
                                      money4 -= betmoney4;
                                      
                                    }
                                }
                                }  
                            
                                else if(s=="2"){
                                  cout<<"The Dealer will now deal their own cards"<<endl;
                                  card= 1 + rand()%11;
                                  cout<<card<<endl;
                                  dsum += card;
                                  card= 1 + rand()%11; 
                                  cout<<card<<endl;
                                  dsum += card;
                                  while(true){
                                    if(dsum>p1sum && dsum>p2sum && dsum>p3sum && dsum<21 || dsum==21){
                                      dealerwin();
                                      money -= betmoney;
                                      money2 -= betmoney2;
                                      money3 -= betmoney3;
                                      money4 -= betmoney4;
                                      break;
                                      }
                                    else if(dsum>21 && p1sum>p2sum && p1sum>p3sum && p1sum<=21){
                                      dealerbust();
                                      cout<<"Player 1 wins"<<endl;
                                      money += betmoney;
                                      money += betmoney2;
                                      money += betmoney3;
                                      money2 -= betmoney2;
                                      money3 -= betmoney3;
                                      money4 -= betmoney4;
                                      break;
                                      }
                                    else if(dsum>21 && p2sum>p1sum && p2sum>p3sum && p2sum<=21){
                                      dealerbust();
                                      cout<<"Player 2 wins!"<<endl;
                                      money2 += betmoney2;
                                      money2 += betmoney;
                                      money2 += betmoney3;
                                      money -= betmoney;
                                      money3 -=betmoney3;
                                      money4 -= betmoney4;
                                      break;
                                      }
                                    else if(dsum>p1sum && p2sum>dsum && p2sum>p3sum && p2sum<=21){ //p3sum>p2sum && p3sum>dsum && && p3sum>p1sum && p3sum<=21
                                      cout<<"Player 2 wins!"<<endl;
                                      money2 += betmoney2;
                                      money2 += betmoney;
                                      money2 += betmoney3;
                                      money -= betmoney;
                                      money3 -=betmoney3;
                                      money4 -= betmoney4;
                                      break;
                                      }
                                    else if(dsum>p2sum && p1sum>dsum && p1sum>p3sum && p1sum<=21){ //p3sum>p2sum && p3sum>dsum && && p3sum>p1sum && p3sum<=21
                                      cout<<"Player 1 wins!"<<endl;
                                      money += betmoney;
                                      money += betmoney2;
                                      money += betmoney3;
                                      money2 -= betmoney2;
                                      money3 -= betmoney3;
                                      money4 -= betmoney4;
                                      break;
                                      }
                                    else if(dsum>21){
                                      dealerbust();
                                      money += betmoney;
                                      money2 += betmoney2;
                                      money3 += betmoney3;
                                      break;
                                      }
                                    else if(p3sum>p2sum && p3sum>dsum && p3sum>p1sum && p3sum<=21){
                                      cout<<"Player 3 wins!"<<endl;
                                      money3 += betmoney;
                                      money3 += betmoney2;
                                      money3 += betmoney3;
                                      money -= betmoney;
                                      money2 -= betmoney2;
                                      money4 -= betmoney4;
                                      break;
                                      }
                                    else if(dsum>p2sum && p1sum>dsum && p3sum>p1sum && p3sum<=21){ //p3sum>p2sum && p3sum>dsum && && p3sum>p1sum && p3sum<=21
                                      cout<<"Player 3 wins!"<<endl;
                                      money3 += betmoney;
                                      money3 += betmoney2;
                                      money3 += betmoney3;
                                      money -= betmoney;
                                      money2 -= betmoney2;
                                      money4 -= betmoney4;
                                      break;
                                      }
                                    else if(dsum>p1sum && p2sum>dsum && p3sum>p2sum && p3sum<=21){ //p3sum>p2sum && p3sum>dsum && && p3sum>p1sum && p3sum<=21
                                      cout<<"Player 3 wins!"<<endl;
                                      money3 += betmoney;
                                      money3 += betmoney2;
                                      money3 += betmoney3;
                                      money -= betmoney;
                                      money2 -= betmoney2;
                                      money4 -= betmoney4;
                                      break;
                                      }
                                    
                                    else if(p4sum>p2sum && p4sum>dsum && p4sum>p1sum && p4sum>p3sum && p4sum<=21){
                                      cout<<"Player 4 wins!"<<endl;
                                      money4 += betmoney;
                                      money4 += betmoney2;
                                      money4 += betmoney3;
                                      money4 += betmoney4;
                                      money -= betmoney;
                                      money2 -= betmoney2;
                                      money3 -= betmoney3;
                                      break;
                                      }
                                    else if(dsum>p2sum && p1sum>dsum && p4sum>p1sum && p4sum>p3sum && p4sum<=21){ 
                                      cout<<"Player 4 wins!"<<endl;
                                      money4 += betmoney;
                                      money4 += betmoney2;
                                      money4 += betmoney3;
                                      money4 += betmoney4;
                                      money -= betmoney;
                                      money2 -= betmoney2;
                                      money3 -= betmoney3;
                                      break;
                                      }
                                    else if(dsum>p1sum && p2sum>dsum && p4sum>p2sum && p4sum>p3sum && p4sum<=21){ 
                                      cout<<"Player 4 wins!"<<endl;
                                      money4 += betmoney;
                                      money4 += betmoney2;
                                      money4 += betmoney3;
                                      money4 += betmoney4;
                                      money -= betmoney;
                                      money2 -= betmoney2;
                                      money3 -= betmoney3;
                                      break;
                                      }
                                    
                                    
                                    else{
                                          
                                      dealerdraw();
                                      card= 1 + rand()%11; 
                                      cout<<card<<endl;
                                      dsum += card;
                                      }
                                      }
                                    break;
                                    }
                                 }
                                break;
                                }
                               }    
                            }
                          break;
                        }
                    }
                }
              break;
              }
            }
          }                                              //I'm done uggggggggghhhhhhhhhhhhhh. All the brackets are because we don't know arrays. Hate my life.
         }
        }
       } 
      }  
      
  return 0;

}









