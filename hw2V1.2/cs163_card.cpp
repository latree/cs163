// CS163 Homework2
// Nan Hu

#include "cs163_card.h"
using namespace std;

// constructor 
gameCard::gameCard()
{
  question = NULL;
  answer = NULL;
} 


// distructor
gameCard::~gameCard()
{
  question = NULL;
  answer = NULL;
}


// create a new card and copy the data(question and answer)
// from two arguments
int gameCard::createCard(char * oneQuestion, char * oneAnswer)
{
  question = new char [strlen(oneQuestion) + 1];
  strcpy(question, oneQuestion);
  
  answer = new char [strlen(oneAnswer) + 1];
  strcpy(answer, oneAnswer);
  return 1;
}


// copy the data from argument to current card 
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


// display a card
void gameCard::display()
{
  cout << "question is: " << question << endl;
  cout << "answer is: " << answer << endl;
}


// only display a question
int gameCard::displayQuestion()
{
  cout << "question is: "<< question << endl;
}


// check the card answer by using argument
// return true if the answer is match
// return false if the answer is not match
bool gameCard::checkAnswer(char * matchingAnswer)
{
  if (strcmp(matchingAnswer, answer) == 0)
    return true;
  else 
    return false;
}


// prompt the user if want to play again
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
