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
    string codeSection;
    cout << "enter codesection: ";
    getline(cin, codeSection);
    int test = stoi(codeSection);
    cout << test << endl;

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
