#include "cs163_card.h"
using namespace std;


gameCard::gameCard()
{
  question = NULL;
  answer = NULL;
} 

gameCard::~gameCard()
{
  question = NULL;
  answer = NULL;
}

int gameCard::createCard(char * oneQuestion, char * oneAnswer)
{
  question = new char [strlen(oneQuestion) + 1];
  strcpy(question, oneQuestion);
  
  answer = new char [strlen(oneAnswer) + 1];
  strcpy(answer, oneAnswer);
  return 1;
}


int gameCard::copyCard(const gameCard & copyFrom)
{
  if(copyFrom.question == NULL or 
     copyFrom.answer == NULL)
    return 0;
  
  if(question)
    delete question;
  question = new char [strlen(copyFrom.question) + 1];
  strcpy(question, copyFrom.question);

  if(answer)
    delete answer;
  answer = new char [strlen(copyFrom.answer) + 1];
  strcpy(answer, copyFrom.answer);
 
  return 1;
}

void gameCard::display()
{
  cout << "question is: " << question << endl;
  cout << "answer is: " << answer << endl;
}

int gameCard::displayQuestion()
{
  cout << "question is: "<< question << endl;
}

bool gameCard::checkAnswer(char * matchingAnswer)
{
  if (strcmp(matchingAnswer, answer) == 0)
    return true;
  else 
    return false;
}

bool again()
{
  char response;
  cout << "Play again?(Y/N): ";
  cin >> response;
  cin.ignore(100, '\n');
  if(toupper(response) == 'Y')
    return true;
  else 
    return false;
}
