#include "Deck.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>
using namespace std;

Deck::Deck() {
    for (int s = CLUBS; s <= DIAMONDS; ++s) {
        for (int r = TWO; r <= ACE; ++r) {
            cards.push_back(Card(static_cast<Rank>(r), static_cast<Suit>(s)));
        }
    }
}

void Deck::shuffleDeck() {
    srand(time(0));
    random_shuffle(cards.begin(), cards.end());
}

Card Deck::dealCard() {
    if (!cards.empty()) {
        Card dealtCard = cards.back();
        cards.pop_back();
        return dealtCard;
    }
    throw runtime_error("No cards left in the deck!");
}

void Deck::displayDeck() const {
    for (const auto& card : cards) {
        card.displayCard();
    }
}