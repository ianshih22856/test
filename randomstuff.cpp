#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main ()
{
    int codeSection;
    cout << "enter codesection: ";
    cin >> codeSection;

    switch (codeSection)
    {
        case 281:
            cout << "bigamy";
            break;
        case 321:
            cout << "selling illegal lottery tickets";
            break;
        case 322:
            cout << "selling illegal lottery tickets";
            break;
        case 383:
            cout << "selling rancid butter";
            break;
        case 598:
            cout << "injuring a bird in a public cemetery";
            break;
        default:
            cout << "some other crime";
    }
}   