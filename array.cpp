#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <bits/stdc++.h>
#include <experimental/iterator>
using namespace std;

bool CheckIntParam(int n)
{
    return n >= 0;
}

int appendToAll(string a[], int n, string value)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] + value;
    }
    return n;
}

int lookup(const string a[], int n, string target)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int positionOfMax(const string a[], int n)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int rotateLeft(string a[], int n, int pos)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }
    string target = a[pos];
    for (int i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = target;
    return pos;
}

int countRuns(const string a[], int n)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }

    int consecutiveCounter = 0;
    int i = 0;
    while (i < n)
    {
        if (a[i] == a[i + 1] && i + 1 < n)
        {
            int index = 2;
            while (a[i] == a[i + index] && i + index < n)
            {
                index++;
            }

            i = i + index;
            consecutiveCounter++;
        }
        else
        {
            consecutiveCounter++;
            i++;
        }
    }
    return consecutiveCounter;
}

int flip(string a[], int n)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }

    for (int i = 0; i < n / 2; i++)
    {
        string temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
    return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
    if (!CheckIntParam(n1) || !CheckIntParam(n2))
    {
        return -1;
    }
    int index;
    if (n1 > n2)
    {
        index = n2;
    }
    else
    {
        index = n1;
    }

    for (int i = 0; i < index; i++)
    {
        if (a1[i] != a2[i])
        {
            return i;
        }
    }
    return index;
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    int n = -1;
    if (!CheckIntParam(n1) || !CheckIntParam(n2))
    {
        n = -1;
    }
    else if (n2 == 0)
    {
        n = n2;
    }
    else
    {
        for (int i = 0; i < n1; i++)
        {
            if (a2[0] == a1[i])
            {
                if (i == n1 - 1 && n2 > 1)
                {
                    n = -1;
                }
                else
                {
                    for (int j = 1; j < n2; j++)
                    {
                        if (a2[j] != a1[i + j])
                        {
                            break;
                        }
                        else
                        {
                            n = i;
                            return n;
                        }
                    }
                }
            }
        }
    }
    return n;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{

    if (!CheckIntParam(n1) || !CheckIntParam(n2))
    {
        return -1;
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a1[i] == a2[j])
            {
                return i;
            }
        }
    }
    return -1;
}

int split(string a[], int n, string splitter)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= splitter)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (a[j] >= a[j + 1])
                {
                    string temp;
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    temp.clear();
                }
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        if (a[k] >= splitter)
        {
            return k;
        }
    }
    return n;
}

int main()
{
}