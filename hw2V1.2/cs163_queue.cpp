// CS163 Homework2
// Nan Hu

#include "cs163_queue.h"
using namespace std;

// constructor
queue::queue()
{
  rear = NULL;
}


// distructor
queue::~queue()
{
  if (!rear) return;
  else
  {
    qNode * cur = rear -> next;
    qNode * head = cur;
    rear -> next = NULL;
    rear =NULL;
    while (cur)
    {
      cur = cur -> next;
      delete head;
      head = cur; 
    }
  }
}


// put a card at the bottom of deck
// which is insert at the end of circle linear linked list 
int queue::enqueue(const gameCard & toAdd)
{
  qNode * temp = new qNode;
  temp -> card.copyCard(toAdd);
  
  if(!rear)
  {
    rear= temp;
    temp -> next = rear;
  }
  if(rear == rear -> next)
  {
    rear -> next = temp;
    temp -> next = rear;
    rear = rear -> next;
  }
  else
  {
    qNode * front = rear -> next;
    rear -> next = temp;
    temp -> next = front;
    rear = rear -> next;
  }
  return 1;
}


// pick a card at the top
// which is take out a card at the begining of circle linear linked list
int queue::dequeue(gameCard & copyTo)
{
  if(!rear)
    return 0;
  if(rear == rear -> next)
  {
    copyTo.copyCard(rear -> card);
    delete rear;
    rear = NULL;
  } 
  else
  {
    qNode * front = rear -> next;
    rear -> next = front -> next;
    copyTo.copyCard(front -> card);
    delete front;
    front = NULL;
  }
  return 1;
}

// display the CLL
int queue::displayAll()
{
  qNode * cur = rear;
  int count = 0;
  
  while(cur && count != 1)
  {
    cur = cur -> next;
    cur -> card.display(); 
    if (cur == rear)
      ++count;
  }
}


// get the unanswered question deck from the external file
int buildQueue(char fileName[], queue &pickingDeck, gameCard & card)
{
  char temp [SIZE];
  char * tempQuestion;
  char * tempAnswer;
  int i = 0;

  ifstream fileIn;
  fileIn.open(fileName);
  if(fileIn)
  { 

    fileIn.get(temp, SIZE, '\t');
    fileIn.ignore(100, '\t');
    tempQuestion = new char [strlen(temp) + 1];
    strcpy(tempQuestion, temp);
    
    while(!fileIn.eof() && i < 7)
    {
      fileIn.get(temp, SIZE, '\n');
      fileIn.ignore(100, '\n');
      tempAnswer = new char [strlen(temp) + 1];
      strcpy(tempAnswer, temp);
      
      card.createCard(tempQuestion, tempAnswer);
      
      pickingDeck.enqueue(card);
      ++i;
      
      fileIn.get(temp, SIZE, '\t');
      fileIn.ignore(100, '\t');
      tempQuestion = new char [strlen(temp) + 1];
      strcpy(tempQuestion, temp);
    } 
    fileIn.close();   
  }
  return 1;
}
