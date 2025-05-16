#include <iostream>
using namespace std;
class HashTable
{
    int ts;
    int **table;
    int HashFn(int key)
    {
        return key % ts;
    }
    void rehash()
    {
        int temp[ts], oldts = ts;
        for (int i = 0; i < ts; i++)
            temp[i] = *table[i];
        for (int i = 0; i < ts; i++)
            delete[] table[i];
        delete[] table;
        ts = ts * 2 + 1;
        table = new int *[ts];
        for (int i = 0; i < ts; i++)
            table[i] = NULL;
        for (int i = 0; i < oldts; i++)
            insert(temp[i]);
    }

public:
    HashTable(int default_ts = 7)
    {
        ts = default_ts;
        table = new int *[ts];
        for (int i = 0; i < ts; i++)
            table[i] = NULL;
    }
    void insert(int key)
    {
        bool flag = false;
        int idx = HashFn(key);
        if (table[idx] == NULL)
        {
            flag = true;
            table[idx] = new int(key);
            return;
        }
        else
        {
            int i = 1;
            int probe_idx = (idx + i * i) % ts;
            while (probe_idx != idx)
            {
                if (table[probe_idx] == NULL)
                {
                    flag = true;
                    table[probe_idx] = new int(key);
                    return;
                }
                i++;
                probe_idx = (probe_idx + i * i) % ts;
            }
        }
        if (flag == false)
        {
            rehash();
            insert(key);
        }
    }
    void print()
    {
        for (int i = 0; i < ts; i++)
        {
            cout << "index: " << i << ", value: ";
            if (table[i] == NULL)
                cout << "NULL";
            else
                cout << *table[i];
            cout << endl;
        }
    }
    void search(int key)
    {
        int idx = HashFn(key);
        if (table[idx] == NULL)
        {
            cout << "Element doesnt exist in the hash table." << endl;
            return;
        }
        else
        {
            if (*table[idx] == key)
            {
                cout << "Element exists in the hash table at index: " << idx << endl;
                return;
            }
            else
            {
                int i = 1;
                int probe_idx = (idx + i * i) % ts;
                while (probe_idx != idx)
                {
                    if (*table[probe_idx] == key)
                    {
                        cout << "Element exists in the hash table at index: " << probe_idx << endl;
                        return;
                    }
                    i++;
                    probe_idx = (probe_idx + i * i) % ts;
                }
            }
        }
    }
    void erase(int key)
    {
        int idx = HashFn(key);
        if (table[idx] == NULL)
        {
            cout << "Element doesnt exist in the hash table." << endl;
            return;
        }
        else
        {
            if (*table[idx] == key)
            {
                table[idx] = NULL;
                cout << "Element deleted from index: " << idx << endl;
                return;
            }
            else
            {
                int i = 1;
                int probe_idx = (idx + i * i) % ts;
                while (probe_idx != idx)
                {
                    if (*table[probe_idx] == key)
                    {
                        table[probe_idx] = NULL;
                        cout << "Element deleted from index: " << probe_idx << endl;
                        return;
                    }
                    i++;
                    probe_idx = (probe_idx + i * i) % ts;
                }
            }
        }
    }
};
int main()
{
    HashTable h;
    h.insert(7);
    h.insert(14);
    h.insert(21);
    h.insert(54);
    h.insert(46);
    h.insert(12);
    h.print();
    h.search(7);
    h.erase(7);
    h.print();
}