#include <iostream>
#include <vector>
using namespace std;
int search(int arr[], int ele, int size)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == ele)
            return i;
    return -1;
}
int main()
{
}