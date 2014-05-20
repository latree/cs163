#include "cs163_queue.h"


using namespace std;

int main()
{
  char fileName[12] = "trivial.txt";
  gameCard card;
  queue pickingDeck;
  
  buildQueue(fileName, pickingDeck, card); 
  
 
  pickingDeck.displayAll();

  gameCard pickingCard;
  pickingDeck.dequeue(pickingCard);


  cout << "\n\n\n ***************\n\n\n"<< endl;
  pickingDeck.displayAll(); 
  cout <<"\n******************" << endl;
  pickingCard.display();
}
