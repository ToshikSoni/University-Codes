#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr{-3, -2, -1, 0, -1, 0, 1, 2, 1, 0, 1, 2, 3, 4, 3, 2, 1, 0, -1, -2, -1, 0, 1, 2, 1, 0, -1};
    int left, right, count = 0, largest_count = 0, largest_peak;
    for (int i = 1; i < arr.size() - 1; i++)
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            left = i;
            right = i;
            while (left > 0 && arr[left] > arr[left - 1])
            {
                count++;
                left--;
            }
            while (right < arr.size() - 1 && arr[right] > arr[right + 1])
            {
                count++;
                right++;
            }
            if (count > largest_count)
            {
                largest_count = count;
                largest_peak = arr[i];
            }
            count = 0;
        }
    cout << "Peak with largest number of elements: " << largest_peak << ", total number of elements: " << largest_count;
}