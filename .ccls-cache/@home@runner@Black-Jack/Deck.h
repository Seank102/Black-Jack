#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
private:
    std::vector<Card> cards;
public:
    Deck();
    void shuffleDeck();
    Card dealCard(); 
    void displayDeck() const;
};

#endif