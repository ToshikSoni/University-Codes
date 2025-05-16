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
            cout << "Threre is nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (arr[leftindex] < arr[rightindex] && leftindex <= size && rightindex <= size)
            {
                if (leftindex < size && arr[leftindex] > arr[i])
                {
                    swap(arr[i], arr[leftindex]);
                    i = leftindex;
                }
                else
                    return;
            }
            else
            {
                if (rightindex < size && arr[rightindex] > arr[i])
                {
                    swap(arr[i], arr[rightindex]);
                    i = rightindex;
                }
                else
                    return;
            }
        }
    }
    void heapify()
    {
        
    }
    void heapSort()
    {

    }
};
int main()
{
    heap h;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h.insert(x);
    }
    h.deleteHeap();
    for (int i = 1; i <= h.size; i++)
        cout << h.arr[i] << " ";
}
