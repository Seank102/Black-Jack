#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(Rank r, Suit s) : rank(r), suit(s) {}

string Card::getRank() const {
		switch (rank) {
				case TWO: return "2";
				case THREE: return "3";
				case FOUR: return "4";
				case FIVE: return "5";
				case SIX: return "6";
				case SEVEN: return "7";
				case EIGHT: return "8";
				case NINE: return "9";
				case TEN: return "10";
				case JACK: return "Jack";
				case QUEEN: return "Queen";
				case KING: return "King";
				case ACE: return "Ace";
		}
		return "";
}

string Card::getSuit() const {
		switch (suit) {
				case HEARTS: return "Hearts";
				case DIAMONDS: return "Diamonds";
				case CLUBS: return "Clubs";
				case SPADES: return "Spades";
		}
		return "";
}

void Card::displayCard() const {
		cout << getRank() << " of " << getSuit() << endl;
}
