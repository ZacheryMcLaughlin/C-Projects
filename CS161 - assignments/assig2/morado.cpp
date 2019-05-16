/*
 * Program: Morado
 *
 * Name: Comrade
 *
 * Date: 01/20/19
 *
 * Description: Morado is a text adventure game where the user will use a series of numbers to make decisions within the game to forward its progress. The game will also feature an element of chance to certain tasks in the game in order to make it replayable. 
 *
 * Inputs: Numbers entered by the user to make decisions i.e. 1 and 2
 *
 * Outputs: Printed text will appear with the result of the user decision and tell the user to continue or that the game is over. A random number generator is also used to output random numbers to correspond with choices in the game that have a chance element to them.
*/

#include <iostream>
#include <cstdlib>  //This library is to allow the use of the random function.
#include <ctime>    //This library is to use the clockspeed of the computer to produce different values for the random number generator.


using namespace std;

int choice;  //integer for the choices to make

bool game_running = true; //This bool is used to fit inside the while loop to create a loop condition. This condition is to say that while the game_running bool is true, the loop will continue; however, once that case is false the loop will be broken.

void Enter_Morado() {    //This is a function to make the code more readable down below in the actual program.
       cout<< "You ride towards the township of Morado at a walking pace. As you ride towards the town, \n you see what seems to be destroyed wagons and left over crates. This is indicitive of the reports \n of Indian attacks in the region, so it isn't out of the question that this might \n have been their doing. You take this information and catalog it, and you contiue your journey. \n A few miles outside of town, you realize that if you don't get their soon you \n will pass out from dehrydration and be left out to whatever this land holds for you. \n However, as you think this, a man is seen to be making his way towards Morado \n as well. You pass him and he yells out \"please Mister! I don't have much \n longer. I need some water or I won't make it another mile! Please Mister!\". You have \n a choice here: do you give the dying man water(1), do you drink it yourself in \n front of him and ride away(2), or do you (3)feel sorry and ride off and \n drink the water out of site of the dying man?" <<endl<<endl;
        
        cin>>choice;
        
        if(choice==1)
        {
          cout<<"You decide to give the dying man water to make it the rest of the journey. \n The dying man hugs you and thanks you heartely. You then saddle up on your horse \n and ride off, unknowing if you might see the poor man again. You feel good knowing \n you helped the stranger; however, you have no more water for you to make it to \n Morado without possibly passing out from dehydration."<<endl<<endl;
        }
        else if(choice==2)
        {
          cout<<"You scoff at the dying man, knowing that in this world only the strong survive. \n You turn your horse towards him, and you take a hefty swig of your canteen in \n front of the dying man to show him that he doesn't have your sympathy. The man \n cries out while you rear your horse the other direction and ride off, not caring if \n the man will survive or not."<<endl<<endl;
        }
        else if(choice==3)
        {
          cout<<"You have sympethy for the poor man, for you are feeling dehydrated yourself; however, you know \n that the hardest of decisions require the strongest of wills. You look at the man with \n sad eyes and mutter \"Sorry Mister, I don't have enough\". The man cries out at you, \n but you rear your horse around and ride off until you're out of site of the \n dying man. At this point you take the final swig of your canteen, wishing not to \n endure the same fate as the dying man."<<endl<<endl;
        }
        else
        {
          cout<< "That's an invalid choice"<<endl<<endl;
        }
}


void inventory(){
  while (game_running){
        
        cout<< "Would you like to inspect: notebook(1), revolver(2), bullets(3), water(4)or return to surroundings(5)?  " <<endl<<endl;
        
        cin >> choice;
        
        if(choice==5)
        {
        break; //If this condition is satisfied, the loop will be broken and go back into the larger loop.
        }
        else if(choice==1)
        {
          cout<<"You open your notebook to the first page."<<endl<<endl;
          cout<<"Feb. 17th, 1889"<<endl;
          cout<<"Another day, another murder. Although now it seems to just be the same day, same murder. \n So many people kiss Lady Death due to such natural and \"unnatural\" circumstances that I'm perplexed \n anyone would hire me to give them the answers that their thoughts already ascertain. However,\n this case is said to have me finding more answers and committing myself to more than \n I advertise with my services they said. nowadays I don't offer much with my services however \n so it's to no surprise. The ignorant family didn't fully realize who they were talking to, \n just thinking I wanted to take their case because of some empathetic, monetary, or moral reason \n as a PI. I did what I did for what I wanted at the time. \n However, It seems this family had heard of enough good works I had done in my \n past life that convinced them to need me and disregard what I do now, or were \n desperate enough to test their already meager amount of luck with a \"washed out, has-been of a PI\". \n In all honesty I don't know why I'm taking this case despite my very vocal reservations \n and blatant refusal at first, but I've been telegrammed to meet this family about the case \n tomorrow. Hopefully it will include a hefty reward and some peace and quiet for awhile so \n I can finally leave this place and start anew."<<endl<<endl;
        }  
        else if(choice==2)
        {
          cout<<"The revolver you carry sheens with its shiny, nickle-plated finish; however, the absence of bluing \n or gunpowder residue on any of the metal is indicative of little use."<<endl<<endl;
        }
        else if(choice==3)
        {
          cout<<"You have 12 bullets on your gun belt, not including the 6 in your revolver. the \n metal finish on the bullets seem to be worn and weathered, possibly due to non-use \n for many months." <<endl<<endl;
        }
        else if(choice==4)
        {
          cout<<"You check your canteen for water, only to realize that it only has a few drops \n left after a few days travel. There isn't much left for you, let alone to give \n to anyone else."<<endl<<endl;
        }
        else
        {  
          cout<< "That's an invalid choice"<<endl<<endl;
          break;
        }  
    }

}



int main() {
beginning:  //This is a label created for the restarting game function. When there's a point in the game where it needs to offer the user to restart, the function will have a 'goto beginning' function to bring it back to here.
srand(time(NULL));  //This is to create unique random numbers after each iteration.
int x = rand() % 11; //choose a random number between 0 and 10.

	cout<< "-------------------------------------------------------------------------------------------------------" << endl;
  cout<< "-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-" << endl;
  cout<< "-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-" << endl;
  cout<< "-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-" << endl;
  cout<< "-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----¦¦¦¦¦¦---¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-" << endl;
  cout<< "-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-" << endl;
  cout<< "-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-" << endl;
  cout<< "-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-" << endl;
  cout<< "-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-----¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-" << endl;
  cout<< "-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-" << endl;
  cout<< "-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-" << endl;
  cout<< "-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-" << endl;
  cout<< "-------------------------------------------------------------------------------------------------------" << endl; 
  cout<< "-------------------------------------------------------------------------------------------------------" << endl;  
  cout<< "-------------------------------------------Press Enter to Start----------------------------------------" << endl;
  cout<< "-------------------------------------------------------------------------------------------------------" << endl;
  cout<< "-------------------------------------------------------------------------------------------------------" << endl << endl << endl;

/*This block above is block text for big letters, not actual 'code'*/

  cin.ignore(); //This is so the 'Enter' key can actually be used to forward the program.
  
  cout<< "The dust of the trail left behind clings to your worn down spirs and boots as you ride into town,whereupon" << endl;
  cout<< "you catch a glimpse of a sign that reads \"Morado\". Morado is like every other Southwest township you've" <<endl;
  cout<< "traveled to; lawless and unforgiving to the innocent and downtrodden, only the strong survive. These facts " << endl;
  cout<< "only make your job more difficult; as a Private Investigator, your job is to discover the killer of a" << endl;
  cout<< "local Baron and to bring him in to the sherrif to be hung. At this point, All leads have indicated that" << endl;
  cout<< "the last place this killer was located was in the township of Morado. You made haste to the town when you heard" << endl;
  cout<< "of this, which brings you to its outskirts to begin your investigation to find the killer. Here in this town is" << endl;
  cout<< "where your story begins; will it be where it ends?" << endl << endl << endl;
  
  cout<< "Press Enter to Continue"<<endl<<endl;
  
  cin.ignore();
  
  while(game_running) {
    cout<< "You're outside of Morado. What do you do?"<<endl<<endl;
    cout<< "Go towards Morado: 1"<<endl<<endl;
    cout<< "Check surroundings: 2"<<endl<<endl;
    cout<< "Check Inventory: 3"<<endl<<endl;
    
    cin >> choice;
    
    if( choice==1 )
    {
      
      Enter_Morado(); //Function from before.
      
      if(choice==1)
      {     
        if(x>=5)  //This is where the first random event occurs. if the random number is above or equal to 5, it'll choose this option, if not it will go with the other.
        {
          cout<<"Despite all odds against you, you stubbornly ride into Morado dehydrated and deathly ill. You're able \n to make out all the buildings down the main road with a multitude of people traveling \n between them. As you make this observation, you fall off your horse onto the desert floor \n below. You wake up after an indistinguishable amount of time on a couch in a house. \n You take a few seconds to gather your bearings and take in the environment. You notice \n that it's a normal, run of the mill style house with a family. While looking around \n you feel an overbearing pain from your ribs, lightheaded, and a dry and scratchy throat, most \n likely a side product of the dehydration. However, an elderly man gets up from a chair \n in the corner of the house to interrupt your perusing and lethargically paces his way over \n to your side. You get startled for a moment but manage to squeeze out a few \n words between labored gasps of air: \n 1. Who are you? \n 2. GET AWAY FROM ME OLD MAN! \n 3. Where am I? \n"<<endl<<endl;
          cin>>choice;
          if(choice==1)
          {
            cout<<"The man stops in his tracks and chuckles, \"I think there are more pressing questions than \n that right now.\" Confused, you let out a final cough before passing out again."<<endl<<endl;
            cout<<"------------------------------------------------------------------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n ------------------------------------------------------------------------ \n -------------------------------------------------------------------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦----¦¦¦¦¦¦---¦¦¦¦¦¦--¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-----¦¦¦¦¦¦-----¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -------------------------------------------------------------------------------- "<<endl<<endl;
           //This code above is for the 'GAME OVER' block text. It's not random or wonky code, it's just block text. This is the same for all of these instances below.
           
           cout<<"Would you like to play again? yes(1) or no(2): "<<endl<<endl;
          
            cin >> choice;
          
            if(choice==1)
            {
              goto beginning; //If this condition is satisfied, it will go to the label stated, so it will go back up top to 'beginning'.
            }
          
            else if(choice==2)
            {
              game_running = false; //This breaks the overal loop to permanently end the game, so the user can actually quite.
            }
            else
            {  
              cout<< "That's an invalid choice" <<endl<<endl;
              goto beginning;
            }    
            
          }
          else if(choice==2)
          {
            cout<<"The man stops in his tracks and chuckles, \"You better watch your tongue around these parts, \n boy\" Confused, you let out a final cough before passing out again. "<<endl<<endl;
            cout<<"------------------------------------------------------------------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n ------------------------------------------------------------------------ \n -------------------------------------------------------------------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦----¦¦¦¦¦¦---¦¦¦¦¦¦--¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-----¦¦¦¦¦¦-----¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n --------------------------------------------------------------------------------" <<endl<<endl;
           cout<<"Would you like to play again? yes(1) or no(2): "<<endl<<endl;
          
            cin >> choice;
          
            if(choice==1)
            {
              goto beginning;
            }
          
            else if(choice==2)
            {
              game_running = false;
            }
            else
            {  
              cout<< "That's an invalid choice" <<endl<<endl;
              goto beginning;
            }    
          }
          else if(choice==3)
          {
            cout<<"The man stops in his tracks and chuckles, \"I think there are more pressing questions than \n that right now.\" Confused, you let out a final cough before passing out again."<<endl<<endl;
            cout<<"------------------------------------------------------------------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n ------------------------------------------------------------------------ \n -------------------------------------------------------------------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦----¦¦¦¦¦¦---¦¦¦¦¦¦--¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-----¦¦¦¦¦¦-----¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -------------------------------------------------------------------------------- "<<endl<<endl;
           cout<<"Would you like to play again? yes(1) or no(2): "<<endl<<endl;
          
            cin >> choice;
          
            if(choice==1)
            {
              goto beginning;
            }
          
            else if(choice==2)
            {
              game_running = false;
            }
            else
            {  
              cout<< "That's an invalid choice" <<endl<<endl;
              goto beginning;
            }    
          }
          else
          {
            cout<< "That's an invalid choice" <<endl<<endl;
            goto beginning;
          }       
        }
        else if(x<5)
        {
          cout<<"You ride along towards Morado, but on the way you feel incredibly lightheaded and dizzy. After \n some swaying for a few minutes, you slide off of your horse and pass out. After \n an unknown amount of time, you wake up to notice that all of your items are \n stolen and that your horse is gone. You walk a few miles and notice another destroyed \n wagon and leftover crates nearby, not shaking the feeling of Deja Vu. This is where you \n think you'll die, but as you're walking a stranger on a horse rides by. You scream \n out to him \"please Mister! I don't have much longer. I need some water or I won't \n make it another mile! Please Mister!\" only to realize the words you muttered was ones you heard from the dying man before. The stranger mutters \"Sorry Mister, I don't have enough\". and you \n yell out to him. The stranger rides off in the distance, not to be seen again. \n As your last hope gallops away, so does the last visage of life in your body \n and you collapse with a hard thud on the ground."<<endl<<endl;
          cout<<  "------------------------------------------------------------------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n ------------------------------------------------------------------------ \n ----------------------------------------------------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦----¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦----- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-----¦¦¦¦¦¦-----¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦- \n -----------------------------------------------------------------" <<endl<<endl;
        
          cout<<"Would you like to play again? yes(1) or no(2): "<<endl<<endl;
          
            cin >> choice;
          
            if(choice==1)
            {
              goto beginning;
            }
          
            else if(choice==2)
            {
              game_running = false;
            }
            else
            {  
              cout<< "That's an invalid choice" <<endl<<endl;
              goto beginning;
            }    
         }
      }
          
        else if(choice==2)
        {
          cout<< "You ride into Morado at the break of dusk after 3 days of travel, kicking off \n the dirt left on your leg from the dying man's hands. The town looks like any \n other town in the South West: a main street with all the main stores, bars, hotels, \n and court houses lining the sides of the road for everyone's conveniance. Morado is more developed \n than most Western town however, as right off the main street are other roads with houses \n hugging the sides. A design taken from the Eastern towns, these roads and houses makes Morado \n seem bigger than it probably actually is, but the main drag looks to strecth for at \n least a mile. You take this all into account as you ride over to the bar \n to get a room and start to get ready to conduct your investigation and find the \n Baron's killer. You're standing outside of the bar doors: \n 1. You walk through the doors and walk over to the bar. \n 2. You kick open the doors to make known your presence. "<<endl<<endl;
          cin>>choice;
          if(choice==1)
          {
            cout<<"You walk through the doors and take in the scene as you move towards the bar. \n You notice a multitude of unsavory folk that are a mix of bounty hunter-types \n and gang members, a common sight in the lawlessness of the West. Among these people are \n aristocrats and common folk as well. Morado seems to really be the town for all kinds \n of folks trying to start anew or make a name for themselves. You arrive at the \n bar counter and ask for a room for the night. The bartender trades you a key for $1 \n and you head to your room, already plotting how you're going to start you attempt at catching \n the Baron killer in the morning."<<endl<<endl;
            cout<<"------------------------------------------------------------------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n ------------------------------------------------------------------------ \n -------------------------------------------------------------------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦----¦¦¦¦¦¦---¦¦¦¦¦¦--¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-----¦¦¦¦¦¦-----¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -------------------------------------------------------------------------------- "<<endl<<endl;
           cout<<"Would you like to play again? yes(1) or no(2): "<<endl<<endl;
          
            cin >> choice;
          
            if(choice==1)
            {
              goto beginning;
            }
          
            else if(choice==2)
            {
              game_running = false;
            }
            else
            {  
              cout<< "That's an invalid choice" <<endl<<endl;
              goto beginning;
            }    
          }
          else if(choice==2)
          {
            cout<<"Without any thought about it, you kick the double doors open and immediately make your presence \n known to the bar's inhabitants. A multitude of unsavory men stand up with haste and hold their \n hands over their six-shooters. You look around and make a gruff \"harumph\" with your growly \n throat. To assert yourself further, you hurl spit into a spitoon with terminal velocity. The aristocrats \n and commoners in the room quickly turn away to avoid your gaze, but the hardy bounty \n hunter-types and gang members don't take kindly to you and sit down with their hands \n still over their guns. You walk over to the bar and demand a room for the \n night. The bartender gives you a key, but for $5. You take the keys and plod \n over to room while thinking about what the next day will hold for this journey."<<endl<<endl;
            cout<<"------------------------------------------------------------------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n ------------------------------------------------------------------------ \n -------------------------------------------------------------------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦----¦¦¦¦¦¦---¦¦¦¦¦¦--¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-----¦¦¦¦¦¦-----¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -------------------------------------------------------------------------------- "<<endl<<endl;
           cout<<"Would you like to play again? yes(1) or no(2): "<<endl<<endl;
          
            cin >> choice;
          
            if(choice==1)
            {
              goto beginning;
            }
          
            else if(choice==2)
            {
              game_running = false;
            }
            else
            {  
              cout<< "That's an invalid choice" <<endl<<endl;
              goto beginning;
            }    
          }
          else
          {
            cout<<"That's an invalid choice"<<endl<<endl;
            goto beginning;
          }
        }
        else if(choice==3)
        {
          cout<<"You ride into Morado at the break of dusk after 3 days of travel. The town \n looks like any other town in the South West: a main street with all the main \n stores, bars, hotels, and court houses lining the sides of the road for everyone's conveniance. Morado \n is more developed than most Western town however, as right off the main street are other \n roads with houses hugging the sides. A design taken from the Eastern towns, these roads and \n houses makes Morado seem bigger than it probably actually is. You take this all into account \n as you ride over to the hotel to get a room and plot your next plan of attack, constantly thinking, \"Now what's next?\"."<<endl<<endl;
          cout<<"------------------------------------------------------------------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n ------------------------------------------------------------------------ \n -------------------------------------------------------------------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦----¦¦¦¦¦¦---¦¦¦¦¦¦--¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-----¦¦¦¦¦¦-----¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -------------------------------------------------------------------------------- "<<endl<<endl;
           cout<<"Would you like to play again? yes(1) or no(2): "<<endl<<endl;
          
            cin >> choice;
          
            if(choice==1)
            {
              goto beginning;
            }
          
            else
            {
              cout<<"That's an invalid choice"<<endl<<endl;
              goto beginning;
            }
        }  
     else if(cin.fail())
     {
       cout<<"That's an invalid choice"<<endl<<endl;
       cin.clear();
       goto beginning;
     }      
  }    
    
    else if( choice==2)
      {
      while(game_running){
        cout<< "You check around the area outside of Morado. As you look around, the expanse of the \n desert is cut off by the creeping wilderness, the region being known as the bridge between \n two worlds: the civilized and the wild. Morado sits on this divide. To your right and\n left is nothing but expansive desert as the wilderness sits behind you. However, as you gaze \n on you notice a tiny shack out within the desert. This shack piques your interest as \n it is the only building between here and Morado. You can either return(1), or ride over \n to the shack(2)"<<endl<<endl;
        
        cin >> choice;
        
        if(choice==1)
        {
          break;
        }
        else if(choice==2)
        {
          cout<<"You ride over to the shack to see if there are any clues as to the \n killer's location or if they had been there. You hop off your horse and open the \n creaking door with ease but slowly. As the door opens, light fills the unlit shack instantly. \n You walk inside, hand over gun, and creep around the shack searching around all its contents \n for any clues. There isn't much within the shack that seems pertinent to your case. \n Do you continue to search to possibly find a lead(1) or leave(2)?" <<endl<<endl;
          cin>>choice;
          
          if(choice==1)
          {
            if(x>=5)
            {
              cout<<"You try to make sense of any of the items in the shack, but you only \n can seem to find rusty pots and cracked crates. while moving the crates around, you \n hear a slight creak come from the ground underneath the crates. You then push all the \n crates to the side to see a small square sticking above the floorboards with sand covering \n it. You brush the sand off to discover a latch. After pulling the latch up, the \n trapdoor follows and reveals a hidden area. There's a ladder that leads down into the darkened \n area. Without knowing what lies ahead, you climb down the ladder and step foot onto some \n wooden boards. Before you can take out your lantern to gain a bearing on your surroundings, \n a large object smashes into the side of your head and knocks you clean out, your \n last thought being \"Now what's next?\""<<endl<<endl;
              cout<<"------------------------------------------------------------------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n ------------------------------------------------------------------------ \n -------------------------------------------------------------------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦----¦¦¦¦¦¦---¦¦¦¦¦¦--¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦---------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-----¦¦¦¦¦¦-----¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦-------¦¦¦¦¦¦--- \n --------------------------------------------------------------------------------"<<endl<<endl;
           cout<<"Would you like to play again? yes(1) or no(2): "<<endl;
          
            cin >> choice;
          
            if(choice==1)
            {
              goto beginning;
            }
              
            }
          else if(x<5)
          {
            cout<<"You try to make sense of any of the items in the shack, but you only \n can seem to find rusty pots and cracked crates. You decide to leave the shack."<<endl<<endl;
            break;
          }
          
          
          else if(choice==2)
          {
            cout<<"You try to make sense of any of the items in the shack, but you only \n can seem to find rusty pots and cracked crates. You decide to leave the shack."<<endl<<endl;
            break;
          }
        }
        
      }
        
        else if(choice==3)
        {
        cout<<"Despite all inclinations, you decide to ride back into the grassy wilderness that produced you. \n Reasoning that whatever would befall you in Morado wasn't worth any price the Baron family would pay."<<endl<<endl;
        cout<<  "------------------------------------------------------------------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n ------------------------------------------------------------------------ \n ----------------------------------------------------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦----¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦----- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-----¦¦¦¦¦¦-----¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦- \n -----------------------------------------------------------------" <<endl<<endl;

        cout<<"Would you like to play again? yes(1) or no(2): "<<endl;
        
        cin >> choice;
        
          if(choice==1)
          {
            goto beginning;
          }
        
          else if(choice==2)
          {
            game_running = false;
          }
        
        }
        else 
        {  
          cout<<"That's an invalid input"<<endl;
          goto beginning;
        }
    }
        
}
      
      
    else if(choice==3)
      {
        cout<< "You check your pockets and your person to see that you have a: notebook, revolver, 12 bullets, and water" << endl<< endl;
        inventory();
        if(cin.fail())
        {
          cout<<"That's an invalid choice"<<endl;
          cin.clear();
          goto beginning;
        }     
      }

    else if(cin.fail())  //This is to catch letter and word characters that would cause C++ to have a seizure and puke its guts out. This stops that and states it as an actual invalid character and restarts the game back to the beginning.
    {  
      cout<<"That's an invalid choice"<<endl;
      cin.clear();
      goto beginning;
    }  
}

        cout<<  "------------------------------------------------------------------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦---------¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦------------ \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦----------¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦---- \n ------------------------------------------------------------------------ \n ----------------------------------------------------------------- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦----¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--- \n -¦¦¦¦¦¦--¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦---------¦¦¦¦¦¦--¦¦¦¦¦¦----- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦---¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦- \n -¦¦¦¦¦¦¦¦¦¦¦¦¦¦-----¦¦¦¦¦¦-----¦¦¦¦¦¦¦¦¦¦¦¦¦¦-¦¦¦¦¦¦--¦¦¦¦¦¦¦¦¦¦- \n -----------------------------------------------------------------" <<endl<<endl;

    
  return 0;
  

}






