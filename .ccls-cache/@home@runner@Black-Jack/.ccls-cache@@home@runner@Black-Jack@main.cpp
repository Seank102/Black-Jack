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

    char playAgain = 'Y';

    while (playAgain == 'Y' || playAgain == 'y') {
        // Initial deal
        playerHand.clear();
        dealerHand.clear();
        playerHand.push_back(deck.dealCard());
        playerHand.push_back(deck.dealCard());
        dealerHand.push_back(deck.dealCard());
        dealerHand.push_back(deck.dealCard());

        cout << "\nPlayer's hand:" << endl;
        for (const auto& card : playerHand) {
            card.displayCard();
        }
        cout << "Total: " << calculateHandValue(playerHand) << endl;

        cout << "\nDealer's visible card:" << endl;
        dealerHand[0].displayCard();

        // Check for Blackjack
        int playerTotal = calculateHandValue(playerHand);
        int dealerTotal = calculateHandValue(dealerHand);

        if (playerTotal == 21 && dealerTotal == 21) {
            cout << "\nBoth the player and dealer have Blackjack! It's a tie.\n";
            continue;
        } else if (playerTotal == 21) {
            cout << "\nPlayer has Blackjack! Player wins.\n";
            continue;
        } else if (dealerTotal == 21) {
            cout << "\nDealer has Blackjack! Dealer wins.\n";
            continue;
        }

        // Check for pair splitting
        if (playerHand.size() == 2 && playerHand[0].getRank() == playerHand[1].getRank()) {
            cout << "\nYou have a pair of " << playerHand[0].getRank() << "s. Do you want to split? (Y/N): ";
            char splitChoice;
            cin >> splitChoice;

            if (splitChoice == 'Y' || splitChoice == 'y') {
                vector<Card> splitHand1 = { playerHand[0] };
                vector<Card> splitHand2 = { playerHand[1] };

                splitHand1.push_back(deck.dealCard());
                splitHand2.push_back(deck.dealCard());

                cout << "\nPlaying first hand:" << endl;
                playerHand = splitHand1;
                playerTotal = calculateHandValue(playerHand);
                while (playerTotal <= 21) {
                    cout << "Do you want to (H)it or (S)tand? ";
                    char choice;
                    cin >> choice;

                    if (choice == 'H' || choice == 'h') {
                        playerHand.push_back(deck.dealCard());
                        playerHand.back().displayCard();
                        playerTotal = calculateHandValue(playerHand);
                        cout << "Total: " << playerTotal << endl;
                    } else {
                        break;
                    }
                }

                cout << "\nPlaying second hand:" << endl;
                playerHand = splitHand2;
                playerTotal = calculateHandValue(playerHand);
                while (playerTotal <= 21) {
                    cout << "Do you want to (H)it or (S)tand? ";
                    char choice;
                    cin >> choice;

                    if (choice == 'H' || choice == 'h') {
                        playerHand.push_back(deck.dealCard());
                        playerHand.back().displayCard();
                        playerTotal = calculateHandValue(playerHand);
                        cout << "Total: " << playerTotal << endl;
                    } else {
                        break;
                    }
                }
                continue;  // Move to the next round after splitting
            }
        }

        // Check for doubling down
        cout << "\nDo you want to double down? (Y/N): ";
        char doubleChoice;
        cin >> doubleChoice;

        if (doubleChoice == 'Y' || doubleChoice == 'y') {
            playerHand.push_back(deck.dealCard());
            cout << "\nYou drew:" << endl;
            playerHand.back().displayCard();
            playerTotal = calculateHandValue(playerHand);
            cout << "Total: " << playerTotal << endl;

            if (playerTotal > 21) {
                cout << "\nYou bust! Dealer wins.\n";
                continue;
            }
        }

        // Player's regular turn
        bool playerTurn = true;
        while (playerTurn) {
            cout << "\nDo you want to (H)it or (S)tand? ";
            char choice;
            cin >> choice;

            if (choice == 'H' || choice == 'h') {
                playerHand.push_back(deck.dealCard());
                cout << "\nYou drew:" << endl;
                playerHand.back().displayCard();
                playerTotal = calculateHandValue(playerHand);
                cout << "Total: " << playerTotal << endl;

                if (playerTotal > 21) {
                    cout << "You bust! Dealer wins.\n";
                    playerTurn = false;
                }
            } else if (choice == 'S' || choice == 's') {
                playerTurn = false;
            }
        }

        // Dealer's turn
        cout << "\nDealer's hand:" << endl;
        for (const auto& card : dealerHand) {
            card.displayCard();
        }
        dealerTotal = calculateHandValue(dealerHand);

        while (dealerTotal < 17) {
            cout << "\nDealer hits." << endl;
            dealerHand.push_back(deck.dealCard());
            dealerHand.back().displayCard();
            dealerTotal = calculateHandValue(dealerHand);
        }

        if (dealerTotal > 21) {
            cout << "\nDealer busts! Player wins.\n";
            continue;
        }

        cout << "\nDealer stands with a total of " << dealerTotal << "." << endl;

        // Determine winner
        if (playerTotal > dealerTotal) {
            cout << "\nPlayer wins!\n";
        } else if (playerTotal < dealerTotal) {
            cout << "\nDealer wins.\n";
        } else {
            cout << "\nIt's a tie.\n";
        }

        // Replay option
        cout << "\nDo you want to play another round? (Y/N): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!" << endl;
    return 0;
<<<<<<< HEAD
}
=======
} 
>>>>>>> 792680dfcefe57dd451b4a33a5409a76cedbcb85
