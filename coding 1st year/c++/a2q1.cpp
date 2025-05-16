#include <iostream>
using namespace std;
class HashTable
{
    int ts;
    int **table;
    int HashFn(int key) // calculates the index where the key should be stored
    {
        return key % ts;
    }
    void rehash() // increases the size of table and reallocate the keys according to the new table
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
    HashTable(int default_ts = 7) // creates the hash table
    {
        ts = default_ts;
        table = new int *[ts];
        for (int i = 0; i < ts; i++)
            table[i] = NULL;
    }
    void insert(int key) // insert the key in the table
    {
        int idx = HashFn(key);
        if (table[idx] == NULL)
        {
            table[idx] = new int(key);
            return;
        }
        else // linear probing
        {
            int probe_idx = (idx + 1) % ts;
            while (probe_idx != idx)
            {
                if (table[probe_idx] == NULL)
                {
                    table[probe_idx] = new int(key);
                    return;
                }
                probe_idx = (probe_idx + 1) % ts;
            }
        }
        rehash();
        insert(key);
    }
    void print() // prints the table
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
    void search(int key) // search for a key
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
                int probe_idx = (idx + 1) % ts;
                while (probe_idx != idx)
                {
                    if (*table[probe_idx] == key)
                    {
                        cout << "Element exists in the hash table at index: " << probe_idx << endl;
                        return;
                    }
                    probe_idx = (probe_idx + 1) % ts;
                }
            }
        }
    }
    void erase(int key) // deletes the key
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
                int probe_idx = (idx + 1) % ts;
                while (probe_idx != idx)
                {
                    if (*table[probe_idx] == key)
                    {
                        table[probe_idx] = NULL;
                        cout << "Element deleted from index: " << probe_idx << endl;
                        return;
                    }
                    probe_idx = (probe_idx + 1) % ts;
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