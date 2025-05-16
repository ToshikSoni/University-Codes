#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Function to print an array

// Function to measure execution time
template <typename Func>
void measureTime(Func sortFunc, vector<int> arr, const string &sortName)
{
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << sortName << " took " << duration.count() << " microseconds." << endl;
}
vector<int> generateRandomDataset(int size, int maxValue)
{
    vector<int> dataset(size);
    for (int i = 0; i < size; i++)
    {
        dataset[i] = rand() % maxValue;
    }
    return dataset;
}
int main()
{
    vector<int> arr = generateRandomDataset(10000, 10000);
    vector<int> arr1 = arr;
    measureTime(bubbleSort, arr1, "Bubble Sort");
    vector<int> arr2 = arr;
    measureTime(insertionSort, arr2, "Insertion Sort");
    vector<int> arr3 = arr;
    measureTime(selectionSort, arr3, "Selection Sort");
    return 0;
}
