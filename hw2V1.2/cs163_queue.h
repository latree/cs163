// CS163 Homework2
// Nan Hu

#ifndef _QUEUE_H
#define _QUEUE_H

#include "cs163_card.h"

const int SIZE = 100;
struct qNode
{
  gameCard card;
  qNode * next; 
};

// This is the circle leaner linked list as the unswered the question
class queue
{
  public:
    queue();
    ~queue();
    
    // display the whole circle list for testing 
    int displayAll();
    // put a card at the bottom of unanswered question deck
    int enqueue(const gameCard & toAdd);
    // pick a card the the top of unanswered question deck
    int dequeue(gameCard & copyTo);
    
  private:
    qNode * rear;
};

// get a unanswered question deck
int buildQueue(char fileName[], queue & pickingDeck, gameCard & card);

#endif
