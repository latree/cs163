// CS163 Homework2
// Nan Hu

#ifndef _STACK_H
#define _STACK_H

#include "cs163_card.h"

struct node
{
  gameCard * cards;
  node * next;
};


const int MAX = 5;

// this is the discard deck. each node contains 
// 5 cards in it. 
class stack
{
  public:
    stack();
    ~stack();
   
    // display list for testing 
    int displayAll();
    // put a card at the top of discard deck
    int push(const gameCard & toAdd);
    // pick a card the top of discard deck
    int pop();
    // take a look the first card in the discard deck
    int peek(gameCard & foundAtTop);
 
  private:
    node * head;
    int topIndex;
};

#endif
