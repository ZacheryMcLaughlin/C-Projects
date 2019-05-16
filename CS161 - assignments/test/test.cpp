/*********************************************************************
 * ** Program Filename:Assignment5p1.cpp
 * ** Author:
 * ** Date:03/03/2019
 * ** Description:This programs allows you to search words in a paragraph or a sentece, and tell the user the frequency of those words.
 * ** Input: sentence or paragraph, number of words, words
 * ** Output: Frequency of the words
 * *********************************************************************/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <climits>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define max_word_len 1024 // maximum length of a word
#define max_len INT_MAX/max_word_len // maximum length of paragraph(in characters) you can change them

void get_paragraph(char* paragraph)
{
	cout<<"Enter the paragraph or sentence.\n";
	scanf ("%[^\n]%*c", paragraph); 
}

void get_words(char** words, int num_word)
{
	cout<<"Enter the words you want to search.\n";

	for(int i=0; i<num_word; i++)
	{
		*(words+i) = (char*)malloc(max_word_len*sizeof(char));
		cin>>*(words+i);
	}
}

void search(char* paragraph, char** words, int num_word, int* count)
{
	int l1 = strlen(paragraph);
	int l2;
	for(int k=0; k<num_word; k++)
	{
		l2 = strlen(*(words+k));
		for (int i = 0; i < l1;)
		{
			int j = 0;
			int tmp=0;

			while ((tolower(paragraph[i]) == tolower(*(*(words+k)+j))) && paragraph[i] != '\0') 
			{
				tmp++;
				i++;
				j++;
			}

			if (tmp == l2)
			{
				count[k]++;
				tmp = 0;
			}
			else
				i++;
		}
	}
}

void delete_word_memory(char** words, int num_word)
{
	for(int i=0; i<num_word; i++)
	{
		delete *(words+i);
	}
	delete words;
}


void print(char** words, int* count, int num_word)
{
	for(int i=0; i<num_word; i++)
	{
		cout<<setw(16)<<left<<*(words+i)<<count[i]<<endl;
	}
}



int main()
{
	char paragraph[max_len]; 
	get_paragraph(paragraph);

	cout<<"Enter the number of words you want to search:";
	int num_word;
	cin>>num_word;
	char** words = (char**)malloc(num_word*sizeof(char*));
	get_words(words, num_word);


	int* count = new int[num_word];

	search(paragraph, words, num_word, count);

	print(words, count, num_word);

	delete_word_memory(words, num_word);
	return 0;
}
