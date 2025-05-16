#include <iostream>
using namespace std;
template <typename T>
void search(T arr[], int size, T element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            cout << "Element found at index: " << i << endl;
            break;
        }
        if (i == size - 1)
            cout << "The element is not in the array." << endl;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int element = 5;
    int size = sizeof(arr) / sizeof(element);
    search(arr, size, element);
}