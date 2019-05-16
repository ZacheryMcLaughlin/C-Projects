/***************************************************************************
Program: Word Frequency

Date: 03/03/19

Name: Comrade

Description: This program takes in a string of sentences or paragraphs from the user. The user will then tell the program how many words to look for, and then the user will input
			 what words they are looking for. The program will tell the user the frequency of those words in the sentence/paragraph and then ask the user if they would want to 
			 repeat the program.

Input: sentence/paragraph, numbers of words to look for, words, 0 or 1 for repeat function

Output: Sentence/paragraph, frequency of words

***************************************************************************/
#include <iostream>
#include <string> //C++ string
#include <string.h> //C-style string
#include <cstdlib>
#include <cctype> //Library that includes the code for using the tolower function.
#include <algorithm> //Library that includes the code for using the Transform function.

using namespace std;

void get_sentence(char *sentence);

void get_word_count(int *word_count);

void retrieve_word(string *word, int word_count);

void frequency_word(string *word, int word_count, char *sentence);

void repeat(int *x);

int main() {
	int word_count;
	char *sentence = NULL;
	string *word = NULL;
	int x;
	
	do {
		sentence = new char[15000]; //Creates it on the heap
		get_sentence(sentence);
		get_word_count(&word_count);

		word = new string[word_count]; //Creates it on the heap

		retrieve_word(word, word_count);

		frequency_word(word, word_count, sentence);

		repeat(&x);

		delete[] sentence; //De-allocates the memory so that there are no leaks
		delete[] word;

	} while (x == 0);

	return 0;

}

/***********************************************************************************
**Function: get_sentence
**Description: Asks the user to enter a sentence/paragraph
**Parameters: char *sentence
**Pre-Condition: N/A
**Post-Conditions: Everything
************************************************************************************/
void get_sentence(char *sentence) {
	cout << "Enter a sentence or a paragraph." << endl;
	cin.getline(sentence, 15000);                //C-style string
	for (int i = 0; i < strlen(sentence); i++) {
		sentence[i] = (tolower(sentence[i])); //converts all characters entered by the user into lowercase letters
	}
	cout << endl;
	cout << sentence << endl;
	cout << endl;
}

/***********************************************************************************
**Function: get_word_count
**Description: Asks for how many words the user wants to look for and error handles.
**Parameters: int *word_count
**Pre-Condition: word_count
**Post-Conditions: Everything
************************************************************************************/
void get_word_count(int *word_count) {
	cout << "How many words do you want to search for?: ";
	string word_count_input;
	bool good = false;
	while (!good) {
		int i;
		cin >> word_count_input;
		for (i = 0; i < word_count_input.size(); i++) {
			if (!(word_count_input.at(i) >= '0' && word_count_input.at(i) <= '9')) { //Error handler that checks every character to see if it's valid
				cout << "Error! Enter a valid input! " << endl;
				break;
			}
		}
		if (word_count_input >= "0" && word_count_input <= "9")
			good = true;
	}
	*word_count = atoi(word_count_input.c_str()); //converts string back into an int
	cin.ignore(1000, '\n');
}

/***********************************************************************************
**Function: retrieve_word
**Description: gets the user input for what words they want to search for.
**Parameters: string *word, int word_count
**Pre-Condition: word, word_count
**Post-Conditions: frequency word, repeat
************************************************************************************/
void retrieve_word(string *word, int word_count ) {
	for (int i = 0; i < word_count; i++) {
		getline(cin, word[i]);
		for (int n = 0; n < word[i].size(); n++) {
			transform(word[i].begin(), word[i].end(), word[i].begin(), ::tolower); //Converts the characters in the string into lowercase letters so that they can match the get_sentence
		}
	}
}


/***********************************************************************************
**Function: frequency_word
**Description: Checks the words the user entered and sees if there are any words in the sentence/paragraph that matches and prints out the frequency.
**Parameters: string *word, int word_count, char *sentence
**Pre-Condition: word, wordd_count, sentence
**Post-Conditions: repeat function
************************************************************************************/
void frequency_word(string *word, int word_count, char *sentence) {
	int freq_total[50]; //Create an array of values on the stack with 50 values
	
	for (int i = 0; i < 50; i++) {
		freq_total[i] = 0;
	}

	for (int i = 0; i < word_count; i++) {
		for (int n = 0; n < strlen(sentence); n++) {
			if (sentence[n] == word[i].at(0)) {
				for (int k = 0; k < word[i].size(); k++) { //Checks all of the words within the user-inputed get_sentence and compares the words the user are looking for
					if (sentence[n + k] == word[i].at(k)) {  //to find how many times those words occur.
						if (word[i].size() - 1 == k) {
							freq_total[i]++;  //If the words completely match, it increments this array up 1.
						}
					}
					else
						break;
				}
			}
		}
	}
	for (int n = 0; n < word_count; n++) {
		cout << "Frequency: " << freq_total[n] << endl;
	}
}

/***********************************************************************************
**Function: repeat
**Description: function that asks the user if they want to repeat the program and error handles it.
**Parameters: int *x
**Pre-Condition: 0 or 1
**Post-Conditions: N/A
************************************************************************************/
void repeat(int *x) {
	cout << "Would you like to enter another sentence or paragraph? yes(0) or no(1)" << endl;
	string rep;
	bool good = false;
	while (!good) {
		int i;
		cin >> rep;
		for (i = 0; i < rep.size(); i++) {
			if (!(rep.at(i) >= '0' && rep.at(i) <= '1')) {
				cout << "Error! Enter a valid input! " << endl; //error handle to make sure the input is correct
				break;
			}
		}
		if (rep >= "0" && rep <= "9")
			good = true;
	}
	*x = atoi(rep.c_str());
	cin.ignore(1000, '\n'); //stops the cin so that it doesn't read past what is inputed.
}
