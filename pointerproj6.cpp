#include <iostream>
using namespace std;

void findMax(int arr[], int n, int* pToMax)
{
    int temp;
    pToMax = &temp;
    if (n <= 0)
        return; // no items, no maximum!
        
    // cout << pToMax << endl;
    // temp += 2;
    // cout << temp << endl;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > *pToMax)
        {
            *pToMax = arr[i];
            temp += i;
            cout << pToMax << endl;
        }
    }
}

int main()
{
    int nums[4] = {5, 3, 15, 6};
    int *ptr = &nums[0];
    findMax(nums, 4, ptr);
    cout << &nums[0] << endl;
    cout << &nums[2] << endl;
    cout << "The maximum is at address " << ptr << endl;
    cout << "It's at position " << ptr - nums << endl;
    cout << "Its value is " << *ptr << endl;
}