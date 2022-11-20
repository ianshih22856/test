#include <iostream>
using namespace std;

// return true if two C strings are equal
bool strequal(const char str1[], const char str2[])
{
    int n = 0;
    
    while (str1 != 0 && str2 != 0) // zero bytes at ends
    {
        if (*str1 != *str2) // compare corresponding characters
            {
                cout << "false" << endl;
                return false;
            }
        else
        {
            n++;
            // cout << n << endl;
        }
        str1++; // advance to the next character
        str2++;
    }
    return str1 == str2; // both ended at same time?
}

int main()
{
    char a[15] = "Zhang";
    char b[15] = "Zhang";
    cout << "|" << a[15] << "__" << endl;

    if (strequal(a, b))
        cout << "They're the same person!\n";
    else
    {
        cout << "no";
    } 
    
}