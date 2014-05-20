#include "cs163_card.h"

const int SIZE = 100;
struct qNode
{
  gameCard card;
  qNode * next; 
};

class queue
{
  public:
    queue();
    ~queue();
    
    int displayAll();
    int enqueue(const gameCard & toAdd);
    int dequeue(gameCard & copyTo);
    
  private:
    qNode * rear;
};

int buildQueue(char fileName[], queue & pickingDeck, gameCard & card);
