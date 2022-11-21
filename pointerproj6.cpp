#include <iostream>
using namespace std;

// Write a function named removeS that accepts one character pointer as a parameter and returns no value.
// The parameter is a C string.This function must remove all of the upper and lower case 's' letters from the string.
// The resulting string must be a valid C string.
// Your function must declare no more than one local variable in addition to the parameter;
// that additional variable must be of a pointer type.
// Your function must not use any square brackets and must not use any of the<cstring> functions such as strlen, strcpy, etc.

void removeS(char *ptr)
{
    char *temp = ptr;
    while (*ptr != '\0')
    {
        if (*ptr == 'S' || *ptr == 's')
        {
            ptr++;
            continue;
        }
        *temp = *ptr;
        temp++;
        ptr++;
    }
    *temp = '\0';
}

int main()
{
    char msg[50] = "She'll shave a massless princess.";
    removeS(msg);
    cout << msg; 
}