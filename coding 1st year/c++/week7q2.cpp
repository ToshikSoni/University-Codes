#include <iostream>
using namespace std;
class HashTable
{
    int ts, *table;
    int HashFn(int key)
    {
        return key % ts;
    }
    void rehash()
    {
        int temp[ts], oldts = ts;
        for (int i = 0; i < ts; i++)
            temp[i] = table[i];
        delete[] table;
        ts = (ts * 2) + 1;
        table = new int[ts];
        for (int i = 0; i < ts; i++)
            table[i] = -1;
        for (int i = 0; i < oldts; i++)
            insert(temp[i]);
    }

public:
    HashTable(int size = 7)
    {
        ts = size;
        table = new int[ts];
        for (int i = 0; i < ts; i++)
            table[i] = -1;
    }
    void insert(int value)
    {
        int idx = HashFn(value);
        if (table[idx] == -1)
        {
            table[idx] = value;
            return;
        }
        int i = 1, probe = (idx + i * i) / ts; // for linear probing int probe = (idx + 1) % ts;
        while (probe != idx)
        {
            if (table[probe] == -1)
            {
                table[probe] = value;
                return;
            }
            i++;
            probe = (probe + i * i) % ts; // for linear probing probe = (idx + 1) % ts;
        }
        rehash();
        insert(value);
    }
    void search(int key)
    {
        int idx = HashFn(key);
        if (table[idx] == -1)
        {
            cout << "Element doesnt exist in the table." << endl;
            return;
        }
        if (table[idx] == key)
        {
            cout << "Element found in the table at index: " << idx << endl;
            return;
        }
        int i = 1, probe = (idx + 1) % ts; // for linear probing int probe = (idx + 1) % ts;
        while (probe != idx)
        {
            if (table[probe] == key)
            {
                cout << "Element found in the table at index: " << probe << endl;
                return;
            }
            i++;
            probe = (probe + i * i) % ts; // for linear probing probe = (idx + 1) % ts;
        }
    }
    void erase(int key)
    {
        int idx = HashFn(key);
        if (table[idx] == -1)
        {
            cout << "Element doesnt exist in the table." << endl;
            return;
        }
        if (table[idx] == key)
        {
            cout << "Element deleted from index: " << idx << endl;
            table[idx] = -1;
            return;
        }
        int i = 1, probe = (idx + i * i) % ts; // for linear probing int probe = (idx + 1) % ts;
        while (probe != idx)
        {
            if (table[probe] == key)
            {
                cout << "Element deleted from index: " << probe << endl;
                table[idx] = -1;
                return;
            }
            i++;
            probe = (probe + i * i) % ts; // for linear probing probe = (idx + 1) % ts;
        }
    }
    void print()
    {
        for (int i = 0; i < ts; i++)
            cout << "Index: " << i << ", Value: " << table[i] << endl;
    }
};