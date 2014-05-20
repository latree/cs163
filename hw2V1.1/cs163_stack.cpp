#include "cs163_stack.h"

stack::stack()
{
  head = NULL;
  topIndex = 0;
}

stack::~stack()
{
  if (!head) return;
  node * cur = head;
  while(cur)
  {
    cur = cur -> next;
    delete head;
    head = cur;
  }
}

int stack::push(const gameCard & toAdd)
{
  if (!head && topIndex == 0)
  {
    node * temp = new node;
    temp -> cards = new gameCard[MAX];
    
    temp -> cards[topIndex].copyCard(toAdd);
  
    head = temp;
    temp -> next = NULL;
    ++topIndex %= MAX;
  } 
  
  else if(head && topIndex == 0)
  {
    node * temp = new node;
    temp -> cards = new gameCard[MAX];
    
    node * cur = head;
    
    head = temp;
    temp -> next = cur;
    head -> cards[topIndex].copyCard(toAdd);
    
    ++topIndex %= MAX;
  }
  else 
  {
    head -> cards[topIndex].copyCard(toAdd);
    
    ++topIndex %= MAX;
  }
  return 0;
}

int stack::pop()
{
  if(!head) return 0;
  if(head -> next == NULL)
  {
    if (topIndex > 1)
      --topIndex;
    else
    {
      //topIndex = MAX - 1;
      delete [] head -> cards;
      delete head;
      head = NULL;
    }
  } 

  else
  {
    if(topIndex > 1)
      --topIndex;
    else
    {
      topIndex = MAX - 1;
      delete [] head -> cards;
      node * cur = head -> next;
      delete head;
      head = cur;
    }
  }
  return 1;
}

int stack::peek(gameCard & foundAtTop)
{
  if(!head) return 0;
  else
    foundAtTop.copyCard(head->cards[topIndex -1]);
    //head -> cards[topIndex - 1].copyCard(foundAtTop);
  
  return 1; 
}


int stack::displayAll()
{
  node * cur = head;
  int i = 0;
  int j = 0;
  if(!head) return 0;
  
  while(cur)
  {
    if(!cur -> next)
    {
      for (i; i < MAX; ++i)
      {
        cur -> cards[i].display();
      }  
    }
    if(cur -> next == NULL)
    {
      for (j; j < topIndex; ++j)
      {
        cur -> cards[j].display();
      }
    }
    cur = cur -> next;
  }
  return 1;
}
