#include "Deck.h"
#include <vector>
#include <iostream>
using namespace std;

// Function to calculate the value of a hand
int calculateHandValue(const vector<Card>& hand) {
    int total = 0;  // Total hand value
    int aces = 0;   // Count of Aces in the hand

    for (const auto& card : hand) {
        string rank = card.getRank();

        if (rank == "Jack" || rank == "Queen" || rank == "King") {
            total += 10;  // Face cards are worth 10
        } else if (rank == "Ace") {
            total += 11;  // Assume Ace is worth 11 initially
            aces++;
        } else {
            total += stoi(rank);  // Convert numeric ranks (e.g., "2") to integers
        }
    }

    // Adjust for Aces if total exceeds 21
    while (total > 21 && aces > 0) {
        total -= 10;  // Change an Ace from 11 to 1
        aces--;
    }

    return total;
}

int main() {
    Deck deck;                // Create and shuffle the deck
    deck.shuffleDeck();

    vector<Card> playerHand;  // Player's hand
    vector<Card> dealerHand;  // Dealer's hand

    // Deal initial cards
    playerHand.push_back(deck.dealCard());
    playerHand.push_back(deck.dealCard());
    dealerHand.push_back(deck.dealCard());
    dealerHand.push_back(deck.dealCard());

    // Display initial hands
    cout << "Player's hand:" << endl;
    for (const auto& card : playerHand) {
        card.displayCard();
    }
    cout << "Total: " << calculateHandValue(playerHand) << endl;

    cout << "\nDealer's visible card:" << endl;
    dealerHand[0].displayCard();  // Only show the dealer's first card

    // Player's turn
    bool playerTurn = true;
    while (playerTurn) {
        cout << "\nDo you want to (H)it or (S)tand? ";
        char choice;
        cin >> choice;

        if (choice == 'H' || choice == 'h') {
            // Player hits
            playerHand.push_back(deck.dealCard());
            cout << "\nYou drew:" << endl;
            playerHand.back().displayCard();

            int playerTotal = calculateHandValue(playerHand);
            cout << "Total: " << playerTotal << endl;

            if (playerTotal > 21) {
                cout << "You bust! Dealer wins.\n";
                return 0;  // End game if the player busts
            }
        } else if (choice == 'S' || choice == 's') {
            // Player stands
            playerTurn = false;
        } else {
            cout << "Invalid choice. Please enter H or S.";
        }
    }

    // Dealer's turn
    int dealerTotal = calculateHandValue(dealerHand);
    while (dealerTotal < 17) {  // Dealer hits on 16 or less
        cout << "\nDealer hits." << endl;
        dealerHand.push_back(deck.dealCard());
        dealerHand.back().displayCard();
        dealerTotal = calculateHandValue(dealerHand);
    }

    if (dealerTotal > 21) {  // Dealer busts
        cout << "\nDealer busts! Player wins.\n";
        return 0;
    }

    cout << "\nDealer stands with a total of " << dealerTotal << "." << endl;

    // Compare totals to decide the winner
    int playerTotal = calculateHandValue(playerHand);

    cout << "\nFinal Results:" << endl;
    cout << "Player's total: " << playerTotal << endl;
    cout << "Dealer's total: " << dealerTotal << endl;

    if (playerTotal > dealerTotal) {
        cout << "Player wins!\n";
    } else if (playerTotal < dealerTotal) {
        cout << "Dealer wins!\n";
    } else {
        cout << "It's a tie!\n";
    }

    return 0;
}
