#include <iostream>
using namespace std;

int main()
{

    string word;
    int counter = 0;

    cout << "input: " << endl;
    getline(cin, word);

    string digits[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int length = word.length();
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j <= 9; j++)
        {

            string temp(1, word.at(i));
            if (digits[j] == temp)
            {
                counter = 0;
                break;
            }
            else
            {
                counter = 1;
            }
        }
        if (counter == 1)
        {
            break;
        }
    }
    if (counter == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}