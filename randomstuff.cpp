#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

string ReverseString(string word)
{
    string reverseWord = "";
    int length = word.length();
    for (int i = (length - 1); i >= 0; i--)
    {
        string letter(1, word.at(i));
        reverseWord = reverseWord + letter;
    }
    return reverseWord;
}
int main()
{
    string original;
    cout << "input: " << endl;
    getline(cin, original);
    string userInput = original;

    for (int i = 0; i < userInput.length(); i++)
    {
        string temp(1, userInput.at(i));
        if (temp == " ")
        {
            userInput.replace(i, 1, "");
        }
    }
    string reversedWord = ReverseString(userInput);
    if (reversedWord == userInput)
    {
        cout << "palindrome: " << original << endl;
    }
    else
    {
        cout << "not a palindrome: " << original << endl;
    }

    return 0;
}