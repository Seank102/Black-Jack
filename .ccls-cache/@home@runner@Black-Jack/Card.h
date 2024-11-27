#ifndef CARD_H
#define CARD_H

#include <string>

enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
enum Suit { CLUBS, SPADES, HEARTS, DIAMONDS };

class Card {
private:
    Rank rank;
    Suit suit;
public:
    Card(Rank r, Suit s);
    std::string getRank() const;
    std::string getSuit() const;
    void displayCard() const;
};

#endif