#include "Deck.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    Deck deck;                // Create a new deck
    deck.shuffleDeck();       // Shuffle the deck

    vector<Card> playerHand;  // Player's hand
    vector<Card> dealerHand;  // Dealer's hand

    // Deal two cards to the player
    playerHand.push_back(deck.dealCard());
    playerHand.push_back(deck.dealCard());

    // Deal two cards to the dealer
    dealerHand.push_back(deck.dealCard());
    dealerHand.push_back(deck.dealCard());

    // Display the player's hand
    cout << "Player's hand:" << endl;
    for (const auto& card : playerHand) {
        card.displayCard();
    }

    // Display the dealer's hand
    cout << "\nDealer's hand:" << endl;
    for (const auto& card : dealerHand) {
        card.displayCard();
    }

    return 0;
}
