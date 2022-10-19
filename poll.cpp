#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;
bool isValidPollString(string pollData)
{
    vector<string> stateCodeList{"AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA", "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MA", "MD", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"};
    string stateCode = pollData.substr(0, 2);
    vector<string>::iterator it;
    it = find(stateCodeList.begin(), stateCodeList.end(), stateCode);
    if (it == stateCodeList.end())
    {
        return false;
    }
    return true;
}
int countSeats(string pollData, char party, int &seatCount)
{
    return 0;
}

string ConvertToUppercase(string convert)
{
    transform(convert.begin(), convert.end(), convert.begin(), ::toupper);
    return convert;
}

int main()
{
    string test;
    cout << "input: " << endl;
    getline(cin, test);

    string partyCodeList[] = {};
    string newTest = ConvertToUppercase(test);
    bool code = isValidPollString(newTest);
    cout << code << endl;
}