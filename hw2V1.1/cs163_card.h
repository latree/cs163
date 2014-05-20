// CS163 Homework2
// Nan Hu

#ifndef _CARD_H
#define _CARD_H

#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>


class gameCard
{
  public:
    gameCard();
    ~gameCard();
    int createCard(char * question, char * answer);
    int copyCard(const gameCard & copyFrom);
    void display(); 
    int displayQuestion();
    bool checkAnswer(char * matchingAnwer);    

  private:
    char * question;
    char * answer;
};

bool again();

#endif
