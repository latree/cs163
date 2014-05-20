// CS163 Homework2
// Nan Hu
// main file for homework 2

#include "cs163_queue.h"
#include "cs163_stack.h"

using namespace std;

int main()
{
  // variables, structs, and class creation
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

  // build the unanswered the question
  buildQueue(fileName, pickingDeck, card); 
  
  do
  {
    // prompt user where they want to pick
    cout <<"where do you want to pick card?\n"
         <<"1: question deck\n"
         <<"2: discard deck" << endl;
    cin >> choice;
    cin.ignore(100, '\n');
    if(choice == 1)  // pick from queue(unanswered question deck)
    {
      pickingDeck.dequeue(pickingCard); // pick a card
      pickingCard.displayQuestion();    

      // prompt user to input answer
      cout << "Input your answer: ";
      cin.get(temp, 50, '\n');
      cin.ignore(100, '\n');
      matchingAnswer = new char [strlen(temp) + 1];
      strcpy(matchingAnswer, temp);

      // check the answer
      answerCheck = pickingCard.checkAnswer(matchingAnswer);     
      // if answer is correct point + 1
      // and put car at the bottom of queue
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
      // if answer is incorrect 
      // put it into stack
      else
        discardDeck.push(pickingCard);
      
    }

    if(choice == 2)    // pick from stack(discard deck)
    {
      peekCheck = discardDeck.peek(peekCard);  // peek a card
      
      // check if the stack is empty
      if(peekCheck == 0)
        cout << "no card in discard deck" << endl;
      // stack is not empty
      else
      {
        peekCard.displayQuestion();
        
        // prompt user if they want to answer the question
        cout << "Do you want to answer?(Y/N): ";
        cin >> reply;
        cin.ignore(100, '\n');
       
        // they want to answer the question
        if (toupper(reply) == 'Y')
        {
           // prompt user to input the answer
           cout << "Input your answer: ";
   	   cin.get(temp, 50, '\n');
	   cin.ignore(100, '\n');
           matchingAnswer = new char [strlen(temp) + 1];
   	   strcpy(matchingAnswer, temp);
           
           // check the answer
           answerCheck = peekCard.checkAnswer(matchingAnswer);      
           // if answer is correct point + 1
           // and put car at the bottom of queue
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
           // the answer is incorrect
           else    
             cout << "Incorrect!!!" << endl;
           //  discardDeck.push(pickingCard);
        }
        
      }
    }
  }while(again());    
   
  return 0;
}
