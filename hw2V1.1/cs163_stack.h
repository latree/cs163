#ifndef _STACK_H
#define _STACK_H

#include "cs163_card.h"

struct node
{
  gameCard * cards;
  node * next;
};


const int MAX = 5;


class stack
{
  public:
    stack();
    ~stack();
    
    int displayAll();
    int push(const gameCard & toAdd);
    int pop();
    int peek(gameCard & foundAtTop);
 
  private:
    node * head;
    int topIndex;
};

#endif
