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
    if (!CheckIntParam(n) || !CheckIntParam(pos))
    {
        return -1;
    }
    if (pos >= n)
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
                // a1 does not contain a2 and n2 is not an empty array
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
    string h[9] = {"rishi", "margaret", "gordon", "tony", "", "john", "liz","gordon", "joe"};
    
    // assert(lookup(h, 7, "john") == 5);
    // assert(lookup(h, 8, "gordon") == 2);
    // assert(lookup(h, 2, "gordon") == -1);
    // assert(lookup(h, 3, "rishi") == 0);
    // assert(lookup(h, 9, "joe") == 8);
    // assert(lookup(h, 0, "joe") == -1);
    // assert(lookup(h, -2, "joe") == -1);

    string v[9] = {"", "margaret", "tony", "tony", "", "john", "liz", "gordon", "zeus"};

    // assert(positionOfMax(h, 7) == 3);
    // assert(positionOfMax(h, 0) == 0);
    // assert(positionOfMax(h, 3) == 0);
    // assert(positionOfMax(h, 3) == 0);

    // assert(positionOfMax(v, 1) == 0);
    // assert(positionOfMax(v, 9) == 8);
    // assert(positionOfMax(v, 5) == 2);
    // assert(positionOfMax(v, -2) == -1);

    string g[4] = {"rishi", "margaret", "liz", "theresa"};
    // assert(rotateLeft(g, 4, 1) == 1 && g[1] == "liz" && g[3] == "margaret");
    // assert(rotateLeft(g, 3, 1) == 1 && g[1] == "liz" && g[3] == "theresa");
    // assert(rotateLeft(g, -2, 1) == -1);
    // assert(rotateLeft(g, 1, -1) == -1);
    // assert(rotateLeft(g, 4, 0) == 0 && g[0] == "margaret" && g[3] == "rishi");
    // assert(rotateLeft(g, 4, 3) == 3 && g[0] == "rishi" && g[3] == "theresa");
    // assert(rotateLeft(g, 0, 2) == 2 && g[0] == "rishi" && g[2] == "liz");
    assert(rotateLeft(g, 3, 4) == -1);

    string e[4] = {"gordon", "tony", "", "john"};
    assert(subsequence(h, 7, e, 4) == 2);

    string d[5] = {"margaret", "margaret", "margaret", "tony", "tony"};
    assert(countRuns(d, 5) == 2);
    assert(countRuns(d, 3) == 1);
    assert(countRuns(d, -1) == -1);
    assert(countRuns(d, 0) == 0);

    string d1[9] = {"tony", "boris", "rishi", "rishi", "gordon", "gordon", "gordon", "rishi", "rishi"};
    assert(countRuns(d1, 9) == 5);

    string d2[5] = {"gordon", "gordon", "gordon", "gordon", "gordon"};
    assert(countRuns(d2, 5) == 1);


    string f[3] = {"liz", "gordon", "tony"};
    assert(flip(f, 3) == 3 && f[0] == "tony" && f[2] == "liz");





    assert(lookupAny(h, 7, f, 3) == 2);
    assert(split(h, 7, "liz") == 3);

    cout << "All tests succeeded" << endl;
}