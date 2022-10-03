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

void ListOfCards() // function for creating a list of cards
{
    vector<int> numberList{2, 3, 4, 5, 6, 7, 8, 9, 10};               // list of numbers in cards
    vector<string> JQKAList{"Jack", "Queen", "King", "Ace"};          // list of face cards
    vector<string> CDHSList{"Clubs", "Diamonds", "Hearts", "Spades"}; // list of suits

    for (int i = 0; i < numberList.size(); i++) // for loop for naming number cards
    {
        for (int j = 0; j < CDHSList.size(); j++)
        {
            cardList.push_back(to_string(numberList.at(i)) + " of " + CDHSList.at(j) + "\n");
        }
    }

    for (int i = 0; i < JQKAList.size(); i++) // for loop for naming face cards
    {
        for (int j = 0; j < CDHSList.size(); j++)
        {
            cardList.push_back((JQKAList.at(i)) + " of " + CDHSList.at(j) + "\n");
        }
    }

    /*for (int i = 1; i < cardList.size(); i++) // print card list test
    {
        cout << cardList.at(i);
    }*/
}

int randInt(int lowest, int highest) // function for producing random number
{
    static random_device rd;
    static default_random_engine generator(rd());
    uniform_int_distribution<> distro(lowest, highest);
    return distro(generator);
}

string CardSelection() // function for choosing random card
{
    string chosenCard = cardList.at(randInt(1, 52));

    return chosenCard;
}

int AssignValue(string selectedCard) // function for assigning blackjack value to cards
{
    int cardValue;
    vector<string>::iterator it = find(cardList.begin(), cardList.end(), selectedCard); 
    int place = distance(cardList.begin(), it);
    cout << place << endl;
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

int main()
{
    ListOfCards();
    string card = CardSelection();
    cout << card;
    // cout << CardSelection();

    cout << AssignValue(card);
}