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
    int codeSection;
    cout << "enter codesection: ";
    cin >> codeSection;

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