#include "cs163_queue.h"
#include "cs163_stack.h"

using namespace std;

int main()
{
  char fileName[12] = "trivial.txt";
  gameCard card;
  queue pickingDeck;
  stack discardDeck;  
  gameCard pickingCard;
  gameCard peekCard;

  int choice;
  int point = 0;
  char reply;
  char * matchingAnswer;
  bool answerCheck;
  int peekCheck;
  char temp[50];

  buildQueue(fileName, pickingDeck, card); 
  
  do
  {
    cout <<"where do you want to pick card?\n"
         <<"1: question deck\n"
         <<"2: discard deck" << endl;
    cin >> choice;
    cin.ignore(100, '\n');
    if(choice == 1)
    {
      pickingDeck.dequeue(pickingCard);
      pickingCard.displayQuestion();
      cout << "Input your answer: ";
      cin.get(temp, 50, '\n');
      cin.ignore(100, '\n');
      matchingAnswer = new char [strlen(temp) + 1];
      strcpy(matchingAnswer, temp);
      answerCheck = pickingCard.checkAnswer(matchingAnswer);      
      if (answerCheck)
      {
        pickingDeck.enqueue(pickingCard);
        ++point;
        if (point == 5)
        {
          cout << "\n\nWin!!!!!!\n" << endl;
          return 0;
        }
      }
      else
        discardDeck.push(pickingCard);
      
    }
    if(choice == 2)
    {
      peekCheck = discardDeck.peek(peekCard);
      if(peekCheck == 0)
        cout << "no card in discard deck" << endl;
      else
      {
        peekCard.displayQuestion();
        cout << "Do you want to answer?(Y/N): ";
        cin >> reply;
        cin.ignore(100, '\n');
        if (toupper(reply) == 'Y')
        {
           cout << "Input your answer: ";
   	   cin.get(temp, 50, '\n');
	   cin.ignore(100, '\n');
           matchingAnswer = new char [strlen(temp) + 1];
   	   strcpy(matchingAnswer, temp);
           answerCheck = peekCard.checkAnswer(matchingAnswer);      
           if (answerCheck)
           {
             pickingDeck.enqueue(peekCard);
             discardDeck.pop();
             ++point;
             if (point == 5)
             {
               cout << "\n\nWin!!!!!!\n" << endl;
               return 0;
             }
           }
           else
             cout << "Incorrect!!!" << endl;
           //  discardDeck.push(pickingCard);
        }
        
      }
    }
  }while(again());    
   
  return 0;
}
