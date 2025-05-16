#include <iostream>
using namespace std;
int main()
{
    int arr1[] = {1, 2, 3, 4, 5}; // array declatarion and initalization
    cout << "printing arr1: ";
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        cout << arr1[i] << ' ';
    }
}