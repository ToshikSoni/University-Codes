class MyDataStructure
{
public:
    int size = 0;
    int *arr, *temp;
    MyDataStructure() { arr = new int[size]; }
    MyDataStructure(int s)
    {
        arr = new int[s];
        size = s;
    }
    bool insert(int x)
    {
        for (int i = 0; i < size; i++)
            if (arr[i] == x)
                return false;
        temp = new int[size];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];
        size++;
        delete arr;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = temp[i];
            if (i == size - 1)
                arr[i] = x;
        }
        delete temp;
        return true;
    }
    bool remove(int x)
    {
        if (size == 0)
            return false;
        int index;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == x)
            {
                index = i;
                break;
            }
            if (i == size - 1)
                return false;
        }
        temp = new int[size];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];
        delete arr;
        size--;
        arr = new int[size];
        for (int i = 0; i < size + 1; i++)
            if (i < index)
                arr[i] = temp[i];
            else if (i == index)
                continue;
            else
                arr[i - 1] = temp[i];
        delete temp;
        return true;
    }
    bool search(int x)
    {
        for (int i = 0; i < size; i++)
            if (arr[i] == x)
                return true;
        return false;
    }
    int getRandom() { return arr[time(0) % size]; }
};