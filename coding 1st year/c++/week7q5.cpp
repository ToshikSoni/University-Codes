#include <iostream>
using namespace std;
class heap
{
public:
    int arr[100], size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }
    void deleteHeap()
    {
        if (size == 0)
        {
            cout << "there is nothing to delete";
            return;
        }
        arr[1] = arr[size];

        size--;

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (arr[leftIndex] < arr[rightIndex])
            {
                if (rightIndex < size && arr[i] < arr[rightIndex])
                {
                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;
                }
                else
                    return;
            }
            else
            {
                if (leftIndex < size && arr[i] < arr[leftIndex])
                {
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                }
                else
                    return;
            }
        }
    }
    void heapify(int arr1[], int size1)
    {
        for (int i = 0; i < size1; i++)
        {
            arr[i + 1] = arr1[i];
        }
        size = size1;
        int i = 1;
        while (i < size)
        {
            int left = i * 2;
            int right = i * 2 + 1;
            if (left <= size && right <= size)
            {
                if (arr[i] < arr[left])
                {
                    swap(arr[i], arr[left]);
                    i = 0;
                }
                else if (arr[i] < arr[right])
                {
                    swap(arr[i], arr[right]);
                    i = 0;
                }
            }
            else if (left <= size)
            {
                if (arr[i] < arr[left])
                {
                    swap(arr[i], arr[left]);
                    i = 0;
                }
            }
            else if (left > size && right > size)
            {
                return;
            }
            i++;
        }
    }
    void heapsort()
    {
        int temp = size, temp1 = size, temparr[size];
        for (int i = 0; i < size; i++)
            temparr[i] = arr[i + 1];
        while (temp > 0)
        {
            swap(arr[1], arr[temp]);
            swap(temparr[0], temparr[temp - 1]);
            temp--;
            heapify(temparr, temp);
            for (int i = 0; i < temp; i++)
            {
                temparr[i] = arr[i + 1];
            }
        }
        size = temp1;
    }
};