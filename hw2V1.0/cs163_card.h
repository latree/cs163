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
    int retrieve(char * matchingQuestion, char * matchingAnswer);
    void display(); 

  private:
    char * question;
    char * answer;
};

bool again();
