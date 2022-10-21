#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;

string ConvertToUppercase(string convert)
{
    transform(convert.begin(), convert.end(), convert.begin(), ::toupper);
    return convert;
}

vector<string> SplitPollData(string pollData)
{
    int endPosition = pollData.find(",");
    vector<string> splitList = {};
    if (endPosition < 0)
    {
        splitList.push_back(pollData);
    }
    else
    {
        int startPosition = 0;
        string section;
        while (endPosition >= 0)
        {
            section = pollData.substr(startPosition, endPosition - startPosition);
            splitList.push_back(section);
            startPosition = endPosition + 1;
            endPosition = pollData.find(",", startPosition);
        }
        section = pollData.substr(startPosition, pollData.length() - startPosition);
        splitList.push_back(section);
    }
    return splitList;
}

bool IsValidStatePollString(string statePollString)
{
    vector<string> stateCodeList{"AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA", "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MA", "MD", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"};
    // Verifies first two chars as state code

    string stateCode = statePollString.substr(0, 2);
    vector<string>::iterator it;
    it = find(stateCodeList.begin(), stateCodeList.end(), stateCode);
    if (it == stateCodeList.end())
    {
        return false;
    }

    int position = 2;
    // Used to check consecutive letters
    string letter = "";
    while (position < statePollString.length())
    {
        char x = statePollString.at(position);
        // Convert character to ASCII value
        int xASCII = int(x);
        // If character is number
        if (xASCII >= 48 && xASCII <= 57)
        {
            if (position == (statePollString.length() - 1))
            {
                return false;
            }
            letter = "";
        }
        // If character is in alphabet
        else if (xASCII >= 65 && xASCII <= 90)
        {
            // If there are two consecutive letters or a letter comes after state code
            if (letter != "" || position == 2)
            {
                return false;
            }
            letter = string(1, x);
        }
        else
        {
            return false;
        }
        position++;
    }
    return true;
}

bool isValidPollString(string pollData)
{
    vector<string> statePollStrings = SplitPollData(pollData);

    for (int i = 0; i < statePollStrings.size(); i++)
    {
        string statePollString = statePollStrings.at(i);
        if (!IsValidStatePollString(statePollString))
        {
            return false;
        }
    }
    return true;
}

int countSeats(string pollData, char party, int &seatCount)
{
    int voteCount = 0;
    pollData = ConvertToUppercase(pollData);

    if (!isValidPollString(pollData))
    {
        seatCount = voteCount;
        return 1;
    }
    if (!(int(party) >= 65 && int(party) <= 90 || int(party) >= 97 && int(party) <= 122))
    {
        seatCount = voteCount;
        return 2;
    }

    vector<string> pollStrings = SplitPollData(pollData);
    string uppercaseParty = string(1, party);
    uppercaseParty = ConvertToUppercase(uppercaseParty);

    for (int i = 0; i < pollStrings.size(); i++)
    {
        string stateString = pollStrings.at(i);
        int partyPosition = stateString.find(uppercaseParty);

        if (partyPosition < 0)
        {
            continue;
        }

        int currentPosition = partyPosition - 2;
        while (int(stateString[currentPosition]) >= 48 && int(stateString[currentPosition] <= 57))
        {
            currentPosition--;
        }

        voteCount += stoi(stateString.substr(currentPosition + 1, partyPosition - currentPosition - 1));
    }
    seatCount = voteCount;

    return 0;
}

void TestPollData(string pollData, bool expectedResult)
{
    bool actualResult = IsValidStatePollString(pollData);
    if (actualResult == expectedResult)
    {
        cout << pollData << " || success" << endl;
    }
    else
    {
        cout << pollData << " || fail ############" << endl;
    }
}

void RunTestCases()
{
    TestPollData("CA", true);
    TestPollData("", false);
    TestPollData("NY9R16D1I", true);
    TestPollData("ny", true);
}

void TestCountSeats(string pollString, char party, int expRetValue, int expCount)
{
    int actCount;
    int actRetVal = countSeats(pollString, party, actCount);
    if (actRetVal == expRetValue && actCount == expCount)
    {
        cout << pollString << " || success" << endl;
    }
    else
    {
        if (actRetVal != expRetValue)
        {
            cout << actRetVal << " || " << expRetValue << " || return value (act, exp) fail !!!!!!!!!!!!" << endl;
        }
        else
        {
            cout << actCount << " || " << expCount << " || count (act, exp) fail !!!!!!!!!!!!" << endl;
        }
    }
}

void RunCountSeats()
{
    TestCountSeats("NY8d8r91f", 'd', 0, 8);
    TestCountSeats("NY8d8r91f,CA4d51r", 'd', 0, 12);
    TestCountSeats("Ny 8d3f", 'd', 1, 0);
}

int main()
{
    /*string test;
    cout << "input: " << endl;
    getline(cin, test);

    string newTest = ConvertToUppercase(test);
    bool code = isValidPollString(newTest);
    cout << code << endl;*/
    /*vector<string> temp = SplitPollData("nywgg4");

    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp.at(i) << endl;
    }*/
    RunCountSeats();
}