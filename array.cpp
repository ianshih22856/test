#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;

bool CheckIntParam(int n)
{
    if (n < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int appendToAll(string a[], int n, string value)
{
    int arrayLength = sizeof(a)/sizeof(string);
    if(!CheckIntParam(n) || n > arrayLength)
    {
        n = -1;
    }
    else 
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = a[i] + value;
        }
    }
    return n;
}

// int lookup(const string a[], int n, string target)
// {

// }

// int positionOfMax(const string a[], int n)
// {

// }

// int positionOfMax(const string a[], int n)
// {

// }

// int countRuns(const string a[], int n)
// {

// }

// int flip(string a[], int n)
// {

// }

// int differ(const string a1[], int n1, const string a2[], int n2)
// {

// }

// int subsequence(const string a1[], int n1, const string a2[], int n2)
// {

// }

// int lookupAny(const string a1[], int n1, const string a2[], int n2)
// {

// }

// int split(string a[], int n, string splitter)
// {

// }

int main()
{
    string temp[2] = {"3", "3"};
    int x = appendToAll(temp, 9, "e");
    cout << x << endl;
}