// CS163 Homework2
// Nan Hu
// The program will be a modified trivial pursuit game.
// Each card will have question on it. There will be 
// two decks of cards. The deck of unanswered questions 
// and the discard deck. The player selects a card.
// the player can select the card from the deck of 
// unanswered questions or from the top of the discard
// pile. The question is displayed and the player answer
// the question displayed. If the question is answered 
// correctely, the card is placed at the bottom of the
// deck. If the question is answerd incorrectly it is
// placed on the top of the discard pile. For every 
// correct answer, the player gets 1 point. A score of
// 5 wins the game. 

#ifndef _CARD_H
#define _CARD_H

#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>

// every card has question and answer in it. 
class gameCard
{
  public:
    gameCard();  // constructor
    ~gameCard();  // distructor
    // create a new card by using question and answer
    int createCard(char * question, char * answer);
    // copy a card from the card argument passed in
    int copyCard(const gameCard & copyFrom);
    void display();   //display a card
    // only display the question on a card  
    int displayQuestion(); 
    // check the answer
    bool checkAnswer(char * matchingAnwer);    

  private:
    char * question;
    char * answer;
};

// promt user if they want to play again
bool again();

#endif
