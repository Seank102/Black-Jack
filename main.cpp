#include "Deck.h"
#include <iostream>
using namespace std;

int main() {
    Deck deck;
    deck.shuffleDeck();

    cout << "Dealing two cards to the player:" << endl;
    Card playerCard1 = deck.dealCard();
    Card playerCard2 = deck.dealCard();

    playerCard1.displayCard();
    playerCard2.displayCard();

    cout << "\nDealing two cards to the dealer:" << endl;
    Card dealerCard1 = deck.dealCard();
    Card dealerCard2 = deck.dealCard();

    dealerCard1.displayCard();
    dealerCard2.displayCard();

    return 0;
}
