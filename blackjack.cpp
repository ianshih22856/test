#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

vector<string> cardList{"placeholder"}; // list of cards with placeholder at index 0
vector<string> playerCardList{};
vector<string> dealerCardList{};
int playerAceElevenCounter = 0;
int dealerAceElevenCounter = 0;

void ListOfCards()
// function for creating a list of cards
{
    vector<int> numberList{2, 3, 4, 5, 6, 7, 8, 9, 10};               // list of numbers in cards
    vector<string> JQKAList{"Jack", "Queen", "King", "Ace"};          // list of face cards
    vector<string> CDHSList{"Clubs", "Diamonds", "Hearts", "Spades"}; // list of suits

    for (int i = 0; i < numberList.size(); i++) // for loop for naming number cards
    {
        for (int j = 0; j < CDHSList.size(); j++)
        {
            cardList.push_back(to_string(numberList.at(i)) + " of " + CDHSList.at(j));
        }
    }

    for (int i = 0; i < JQKAList.size(); i++) // for loop for naming face cards
    {
        for (int j = 0; j < CDHSList.size(); j++)
        {
            cardList.push_back((JQKAList.at(i)) + " of " + CDHSList.at(j));
        }
    }

    /*for (int i = 1; i < cardList.size(); i++) // print card list test
    {
        cout << cardList.at(i);
    }*/
}

int RandInt(int lowest, int highest) // function for producing random number
{
    static random_device rd;
    static default_random_engine generator(rd());
    uniform_int_distribution<> distro(lowest, highest);
    return distro(generator);
}

string CardSelection() // function for choosing random card
{
    string chosenCard = cardList.at(RandInt(1, 52));
    return chosenCard;
}

int AssignValue(string selectedCard) // function for assigning blackjack value to cards
{
    int cardValue;
    vector<string>::iterator it = find(cardList.begin(), cardList.end(), selectedCard);
    int place = distance(cardList.begin(), it);
    // cout << place << endl;
    if (place < 37)
    {
        cardValue = ceil((place - 1) / 4 + 2);
    }
    else if (place > 48)
    {
        cardValue = 11;
    }
    else
    {
        cardValue = 10;
    }
    return cardValue;
}

int DetermineAceValue(int currentHandValue, int aceElevenCounter)
{
    if (currentHandValue <= 21)
    {
        currentHandValue = currentHandValue;
    }
    else
    {
        currentHandValue = currentHandValue - 10;
    }
    aceElevenCounter++;
    return aceElevenCounter;
    return currentHandValue;
}

int DealerProtocol(int dealerFirstTwo)
{
    int dealerHandValue;
    dealerHandValue = dealerFirstTwo;
    while (dealerHandValue < 17)
    {
        string newDealerCard = CardSelection();
        dealerCardList.push_back(newDealerCard);
        cout << "dealer pulled: " << newDealerCard << endl;
        dealerHandValue = dealerHandValue + AssignValue(newDealerCard);
        // dealerHandValue = dealerHandValue + AssignValue(CardSelection());
    }
    return dealerHandValue;
}

int Blackjack(string chosenCard, int currentHandValue, int aceElevenCounter)
{
    int chosenCardValue = AssignValue(chosenCard);
    if (chosenCardValue == 11)
    {
        chosenCardValue = DetermineAceValue(currentHandValue, aceElevenCounter);
    }
    int handValue = currentHandValue + chosenCardValue;
    return handValue;
}

int main()
{
    ListOfCards();
    // string card = CardSelection();
    // cout << card;
    //  cout << CardSelection();

    // cout << AssignValue(card);

    string playerFirstCard = CardSelection();

    cout << "Your first card is " << playerFirstCard << ".\n";
    string dealerFirstCard = CardSelection();
    cout << "The dealer's first card is " << dealerFirstCard << ".\n";
    string playerSecondCard = CardSelection();
    cout << "Your second card is " << playerSecondCard << ".\n";
    string dealerSecondCard = CardSelection();
    cout << "The dealer's second card is " << dealerSecondCard << ".\n";

    dealerCardList.push_back(dealerFirstCard);
    dealerCardList.push_back(dealerSecondCard);
    playerCardList.push_back(playerFirstCard);
    playerCardList.push_back(playerSecondCard);

    int dealerHandValue = AssignValue(dealerFirstCard) + AssignValue(dealerSecondCard);
    int playerHandValue = AssignValue(playerFirstCard) + AssignValue(playerSecondCard);
    cout << "player: " << playerHandValue << ", dealer: " << dealerHandValue << endl;

    int finalDealerValue = DealerProtocol(dealerHandValue);

    cout << "final dealer value: " << finalDealerValue << endl;

    for (int i = 0; i < playerCardList.size(); i++) // print player card list test
    {
        cout << playerCardList.at(i) << endl;
    }
    for (int i = 0; i < dealerCardList.size(); i++) // print dealer card list test
    {
        cout << dealerCardList.at(i) << endl;
    }
}
