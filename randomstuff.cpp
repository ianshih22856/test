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
    if (codeSection == 281)
        cout << "bigamy";
    else if (codeSection == 321 || codeSection == 322)
        cout << "selling illegal lottery tickets";
    else if (codeSection == 383)
        cout << "selling rancid butter";
    else if (codeSection == 598)
        cout << "injuring a bird in a public cemetery";
    else
        cout << "some other crime";

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